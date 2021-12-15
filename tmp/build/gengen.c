// gengen.c - Generic Generator
// Generate a *.h file for each *.c file to allow polymorphic function calls
// using _Generic.


#include <stdio.h>
#include <string.h>


static char*
stripNewline(char* line)
{
  if (line == NULL) {
    return NULL;
  }
  size_t len = strlen(line) - 1;
  if (line[len] == '\n') {
    line[len] = '\0';
  }
  return line;
}


static void
run(void)
{
  enum
  {
    buf_sz = 160,
  };
  static char buf[buf_sz];
  static char buf1[buf_sz];
  static char buf2[buf_sz];
  static char buf3[buf_sz];
  static char buf_name[buf_sz] = { '\0' };

  fputs("#pragma once\n\n"
        "/* macro_name used by generator */\n"
        "#define GEN_LINE(macro_name, type, fn_name) type : fn_name\n\n",
        stdout);

  for (char const *line = stripNewline(fgets(buf, buf_sz, stdin)),
                  *name = buf_name;
       line != NULL;
       line = stripNewline(fgets(buf, buf_sz, stdin))) {
    sscanf(line, "GEN_LINE(%[^, ], %[^,], %s", buf1, buf2, buf3);
    if (strcmp(name, buf1) != 0) {
      if (strcmp(name, "") != 0) {
        printf(" \\\n)((m))\n");
      }
      strncpy(buf_name, buf1, buf_sz);
      printf("\n#define %s(m, ...) _Generic((m)", buf1);
    }
    printf(", \\\n\t%s", line);
  }
  printf(" \\\n)(m, __VA_ARGS__)\n");
}


int
main()
{
  run();
}