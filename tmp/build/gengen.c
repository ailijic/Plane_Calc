// gengen.c - Generic Generator
// Generate a *.h file for each *.c file to allow polymorphic function calls
// using _Generic.

#include <stdbool.h>
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
  static char buf_args[buf_sz];
  static char buf_name[buf_sz] = { '\0' };

  fputs(
    "#pragma once\n\n"
    "/* macro_name and num_args used by generator */\n"
    "#define GEN_LINE(macro_name, num_args, type, fn_name) type : fn_name\n\n",
    stdout);

  char const* name = buf_name;
  char const* line = stripNewline(fgets(buf, buf_sz, stdin));
  if (line == NULL) {
    return;
  }
  sscanf(line, "GEN_LINE(%[^,], %[^,], %[^,], %s", buf1, buf_args, buf2, buf3);
  strncpy(buf_name, buf1, buf_sz);
  for (;;) {
    bool is_single_arg = (buf_args[0] == '1') ? true : false;
    if (is_single_arg) {
      printf("\n#define %s(m) _Generic((m)", buf1);
    } else {
      printf("\n#define %s(m, ...) _Generic((m)", buf1);
    }
    for (;;) {
      printf(", \\\n\t%s", line);
      line = stripNewline(fgets(buf, buf_sz, stdin));
      if (line == NULL) {
        break;
      }
      sscanf(
        line, "GEN_LINE(%[^,], %[^,], %[^,], %s", buf1, buf_args, buf2, buf3);
      if (strcmp(name, buf1) != 0) {
        break;
      }
    }
    strncpy(buf_name, buf1, buf_sz);
    if (is_single_arg) {
      printf(" \\\n)((m))\n");
    } else {
      printf(" \\\n)((m), __VA_ARGS__)\n");
    }
    if (line == NULL) {
      break;
    }
  }
}

int
main()
{
  run();
}