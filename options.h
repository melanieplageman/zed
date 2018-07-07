#ifndef OPTIONS_H
#define OPTIONS_H

#include <stdbool.h>

typedef struct _options_t {
  bool noecho;
  char *expression;
} options_t;

int parse_options(int argc, char **argv, options_t *options);

#endif /* OPTIONS_H */
