#include <pebble.h>
#include "first.h"

int main(void) {
  srand(time(NULL));
     show_first(); 
  app_event_loop();
}