#include <stdlib.h>
#include "expression.h"
#include <stdbool.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>

static inline bool is_empty(char *str) {
  return str[0] == '\0';
}

int parse_expression(char *raw, expression_t *expr) {
  if (is_empty(raw))
    return 1;

  if (strlen(raw) == 2) {
    return 1;
  } else if (strlen(raw) > 2) {
    char *regex_buf;
    if ((regex_buf = malloc(100)) == NULL)
      return ENOMEM;
    memcpy(regex_buf, raw, strlen(raw) - 2);
    regex_buf[strlen(raw) - 2] = '\0';
    expr->regex = regex_buf;
  } else {
    expr->regex = NULL;
  }

  expr->cmd = raw[strlen(raw) - 1];

  return 0;
}
