#!/usr/bin/env bash
set -x #echo on

rm -f real.generic.h
rm -f real.c.i

clang -O0 -g3 -ggdb -Weverything -Werror -Wno-newline-eof -c gengen.c;
clang -O0 -g3 -ggdb -Weverything -Werror -Wno-newline-eof -o gengen gengen.o;

for file in "$@"
do
	clang-cpp -I .. -I . "${file}" -o ./"${file}".i;

# lines.txt - get the relevant lines
grep -oP '[A-Z][a-z0-9][a-zA-Z0-9]*_[a-z][a-zA-Z0-9]*[ \t\v]*\([ a-zA-Z0-9_*]+[,|\)]' \
< ./"${file}".i \
| sort --field-separator=_ --key=2 -u \
> lines.txt;

# fn_name
cat lines.txt \
| grep -oP '[a-zA-Z0-9_]+(?=\()' \
> fn_name.txt;

# macro_name
cat lines.txt \
| grep -oP '(?<=_)[a-zA-Z0-9]+[ \t\v]*(?=\()' \
> macro_name.txt;

# first_arg
cat lines.txt \
| grep -oP '(?<=\()[a-zA-Z0-9 *_]+[ |*](?=[a-zA-Z0-9_]+)' \
> first_arg.txt;

# num_args.txt
awk '{ gsub(",", " 2"); print }' lines.txt | awk '{ gsub("\)", " 1"); print $NF }' > num_args.txt

# set.txt put three files together
paste --delimiters='`' macro_name.txt num_args.txt first_arg.txt fn_name.txt \
> set.txt;

# list.txt - list of macros
awk  -F '`' '{printf("GEN_LINE(%s, %s, %s, %s)\n", $1, $2, $3, $4)}' set.txt \
> list.txt;

# create the generic *.h file
./gengen \
< list.txt \
> ./"${file}".generic.h;

clang -O0 -g3 -ggdb -I.. -include ./"${file}".generic.h -Weverything -Werror -Wno-newline-eof -c "${file}";
done