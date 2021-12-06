run: all
	./a.out
all:
	clear && clang++ -O0 -Weverything -Werror src/*.cpp
