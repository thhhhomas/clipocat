#include "../include/animations.h"
#include "../include/configuration.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// change to configuration source code?
const unsigned int STD_SECONDS = 10;

/*
 * m -> Mode - 1 for 'focusing' 2 for 'resting' 3 for 'long break'
 * t -> define Time
 */

const char *options = "m:t:";

int main (int argc, char **argv) {
  int opt;
  unsigned int seconds = 0;
  unsigned short int mode = 0;

  timer_pomodoro_t timer = retrieve_configuration();

  while ((opt = getopt(argc, argv, options)) != -1) {
    switch (opt) {
      case 'm':
        mode = atoi(optarg);
        break;

      case 't':
        seconds = atoi(optarg);
        break;

      case '?':
        /*Unknown arguments*/
        break;
    }
  }

  for (; optind < argc; optind++)
    printf("%s", argv[optind]);
  
  if (mode == 1) {
    if (seconds != 0) timer.focusing_time = seconds;
    cat_focusing(timer.focusing_time);
  }
  else if (mode == 2) {
    if (seconds != 0) timer.resting_time = seconds;
    cat_resting(timer.resting_time);
  }
  else if (mode == 3) {
    if (seconds != 0) timer.long_break = seconds;
    cat_resting(timer.long_break);
  }

  return 0;
}
