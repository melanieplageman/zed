#include <criterion/criterion.h>
#include <stdlib.h>
#include <stdbool.h>
#include "options.h"

Test(options, no_options) {
  options_t options;
  options.noecho = true;

  int argc = 1;
  char *argv[] = { "zed" };

  int e;

  e = parse_options(argc, argv, &options);
  cr_assert(e == 0);
  cr_assert(!options.noecho);
}

Test(options, noecho) {
  options_t options;
  options.noecho = false; 

  int argc = 2;
  char *argv[] = { "zed", "-n" };

  int e;
  e = parse_options(argc, argv, &options);
  cr_assert(e == 0);
  cr_assert(options.noecho);
}

Test(options, expression) {
  options_t options;
  options.expression = NULL;

  int argc = 3;
  char *argv[] = { "zed", "-e", "yolo" };

  int e;
  e = parse_options(argc, argv, &options);
  cr_assert(e == 0);
  cr_assert_str_eq(options.expression, "yolo");
}
