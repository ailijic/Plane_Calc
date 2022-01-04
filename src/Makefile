# Makefile

bin = a.out
src = $(wildcard *.c)
obj = $(src:.c=.o)
dep = $(obj:.o=.d)  # one dependency file for each source

# -MMD : option to generate a .d file during compilation
CFLAGS = -MMD -g3 -ggdb  
LDFLAGS = # -lGL -lglut -lpng -lz -lm

$(bin): $(obj)
	$(CC) -o $@ $^ $(LDFLAGS)

-include $(dep)   # include all dep files in the makefile

.PHONY: clean
clean:
	rm -f $(obj) mygame

.PHONY: cleandep
cleandep:
	rm -f $(dep)