#ifndef EXPRESSION_H
#define EXPRESSION_H

/**
 * An expression is parsed from a string like:
 *
 * /regex/cmd
 *
 * where cmd is one of
 * - d (delete)
 */
typedef struct _expression_t {
  char *regex;
  char cmd;
} expression_t;

int parse_expression(char *raw, expression_t *expr);

#endif /* EXPRESSION_H */
