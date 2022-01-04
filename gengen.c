// gengen.c - Generic Generator
// Generate a *.h file for each *.c file to allow polymorphic function calls
// using _Generic.


#include <stdio.h>
#include <string.h>

/*
static char const* str_g = "GEN_LINE(absValue, int, Int_absValue )\n"
                           "GEN_LINE(absValue, long, Long_absValue)\n"
                           "GEN_LINE(absValue, long long, LongLong_absValue)\n"
                           "GEN_LINE(absValue, Real, Real_absValue)\n"
                           "GEN_LINE(add, Real, Real_add)\n"
                           "GEN_LINE(convert, Real, Real_convert)\n"
                           "GEN_LINE(div, Real, Real_div)\n"
                           "GEN_LINE(e, Real, Real_e)\n"
                           "GEN_LINE(init, Real*, Real_init)\n"
                           "GEN_LINE(isEqual, Real, Real_isEqual)\n"
                           "GEN_LINE(isLessEqual, Real, Real_isLessEqual)\n"
                           "GEN_LINE(max, Real, Real_max)\n"
                           "GEN_LINE(min, Real, Real_min)\n"
                           "GEN_LINE(mul, Real, Real_mul)\n"
                           "GEN_LINE(neg, int, Int_neg)\n"
                           "GEN_LINE(neg, long long, LongLong_neg)\n"
                           "GEN_LINE(neg, long, Long_neg)\n"
                           "GEN_LINE(neg, Real, Real_neg)\n"
                           "GEN_LINE(sub, Real, Real_sub)\n";
*/
/*
char*
fileGetLine(char* a_buf, int a_buf_sz, char const* a_file)
{
  static char const* file = NULL;
  static int pos = 0;

  if (file != a_file) {
    file = a_file;
    pos = 0;
  }
  if (a_file[pos] == '\0') {
    return NULL;
  }

  do {
    int i = 0;
    int sz = a_buf_sz - 2;
    char c;
    do {
      c = a_file[pos];
      a_buf[i] = a_file[pos];
      pos++;
      i++;
    } while (i < sz && c != '\n' && c != '\0');
    a_buf[i] = '\0';
  } while (0);
  return a_buf;
}
*/

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
      printf("\n#define %s(m) _Generic((m)", buf1);
    }
    printf(", \\\n\t%s", line);
  }
  printf(" \\\n)((m))\n");
}


int
main()
{
  run();
}