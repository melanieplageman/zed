#include <stdio.h>
#include <unistd.h>
#include "options.h"

int main(int argc, char *argv[]) {
  options_t options;
  options.noecho = false; 

  int e;
  e = parse_options(argc, argv, &options);

  if (options.noecho)
    return 0;

  char in;

  while ((in = getc(stdin)) != EOF) {
    putc(in, stdout);
  }

  return 0;
}
