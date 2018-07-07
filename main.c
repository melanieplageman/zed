#include <stdio.h>
#include <unistd.h>
#include <pcre.h>
#include "options.h"
#include "expression.h"

int main(int argc, char *argv[]) {
  options_t options;
  expression_t expr;
  int e;

  e = parse_options(argc, argv, &options);

  if (options.noecho)
    return 0;

  if (options.expression == NULL) {
    char in;

    while ((in = getc(stdin)) != EOF) {
      putc(in, stdout);
    }

    return 0;
  }

  if ((e = parse_expression(options.expression, &expr)) != 0)
    return 1;

  if (expr.regex) {
    pcre *compiled_regex = pcre_compile(expr.regex, 0, NULL, NULL, NULL);

    char *line = NULL;
    size_t line_cap = 0;
    ssize_t line_len = 0;
    while (-1 != (line_len = getline(&line, &line_cap, stdin))) {
      // integration test is failing because pcre_exec doesn't match stuff
      if (pcre_exec(compiled_regex, NULL, line, line_len, 0, 0, NULL, 0) > 0) {
        printf("%s", line);
      }
    }

    pcre_free(compiled_regex);
  } else {
    char *line = NULL;
    size_t line_cap = 0;
    ssize_t line_len = 0;
    while (-1 != (line_len = getline(&line, &line_cap, stdin))) {
      printf("%s", line);
    }

  }

  return 0;
}
