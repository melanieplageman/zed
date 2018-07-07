#include <unistd.h>
#include <stdbool.h>
#include "options.h"

int parse_options(int argc, char **argv, options_t *options) {
  options->noecho = false;
  int option;
  while ((option = getopt(argc, argv, "ne:")) != -1) {
    switch (option) {
      case 'n':
        options->noecho = true;
        break;
      case 'e':
        options->expression = optarg;
        break;
      default:
        return 1;
    }
  }
  return 0;
}
