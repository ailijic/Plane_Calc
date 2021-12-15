#!/usr/bin/env bash
set -x #echo on

rm -f real.generic.h

clang -O0 -g3 -ggdb -Weverything -Werror -Wno-newline-eof -c gengen.c;
clang -O0 -g3 -ggdb -Weverything -Werror -Wno-newline-eof -o gengen gengen.o;

clang-cpp -I .. -I . ../i4/real.c -o real.i;

# lines.txt - get the relevant lines
grep -oP '[A-Z][a-z0-9][a-zA-Z0-9]*_[a-z][a-zA-Z0-9]*[ \t\v]*\([ a-zA-Z0-9_*]+(?=,|\))' real.i \
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

# set.txt put three files together
paste --delimiters='`' macro_name.txt first_arg.txt fn_name.txt \
> set.txt;

# list.txt - list of macros
awk  -F '`' '{printf("GEN_LINE(%s, %s, %s)\n", $1, $2, $3)}' set.txt \
> list.txt;

# create the generic *.h file
cat list.txt \
| ./gengen \
> real.generic.h;

clang -O0 -g3 -ggdb -I.. -include real.generic.h -Weverything -Werror -Wno-newline-eof -c ../i4/real.c;