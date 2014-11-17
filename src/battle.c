#include "battle.h"
#include <pebble.h>

// BEGIN AUTO-GENERATED UI CODE; DO NOT MODIFY
static Window *s_window;
static TextLayer *s_textlayer_1;

static void initialise_ui(void) {
  s_window = window_create();
  window_set_fullscreen(s_window, false);
  
  // s_textlayer_1
  s_textlayer_1 = text_layer_create(GRect(20, 20, 100, 20));
  text_layer_set_text(s_textlayer_1, "test");
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_textlayer_1);
}

static void destroy_ui(void) {
  window_destroy(s_window);
  text_layer_destroy(s_textlayer_1);
}
// END AUTO-GENERATED UI CODE

static void handle_window_unload(Window* window) {
  destroy_ui();
}
static void modif(int nb, short bonus){
  
}

void show_battle(int nb, short bonus) {
  initialise_ui();
  modif(nb, bonus);
  window_set_window_handlers(s_window, (WindowHandlers) {
    .unload = handle_window_unload,
  });
  window_stack_push(s_window, true);
}

void hide_battle(void) {
  window_stack_remove(s_window, true);
}
