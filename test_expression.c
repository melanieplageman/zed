#include <criterion/criterion.h>
#include "expression.h"

char *invalid_string = "This string is invalid!";

Test(expression, empty) {
  expression_t expr;

  int e;
  e = parse_expression("", &expr);
  cr_assert(e != 0);
}

Test(expression, noregex) {
  char *raw = "/d";
  expression_t expr;
  expr.regex = (char *) 0xABAD1DEA;
  expr.cmd = '\0';

  int e;
  e = parse_expression(raw, &expr);
  cr_assert(e == 0);
  cr_assert(expr.regex == NULL);
  cr_assert(expr.cmd == 'd');
}

Test(expression, noregex_or_delimiter) {
  char *raw = "d";
  expression_t expr;
  expr.regex = (char *) 0xABAD1DEA;
  expr.cmd = '\0';

  int e;
  e = parse_expression(raw, &expr);

  cr_assert(e == 0);
  cr_assert_null(expr.regex);
  cr_assert(expr.cmd == 'd');
}

Test(expression, delete_regex) {
  char *raw = "hello/d";
  expression_t expr;
  expr.regex = invalid_string;
  expr.cmd = '\0'; 

  int e;
  e = parse_expression(raw, &expr);

  cr_assert(e == 0);
  cr_assert(expr.cmd == 'd');
  cr_assert_str_eq(expr.regex, "hello");
}
