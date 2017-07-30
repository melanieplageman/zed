#include <unistd.h>
#include <stdbool.h>
#include "options.h"

int parse_options(int argc, char **argv, options_t *options) {
  options->noecho = false;
  int option = getopt(argc, argv, "n");
  if (option == 'n') {
    options->noecho = true;
  }
  return 0;
}
