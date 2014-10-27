#include "inventory.h"
#include <pebble.h>

// BEGIN AUTO-GENERATED UI CODE; DO NOT MODIFY
static Window *s_window;
static GBitmap *s_res_image_knight;
static BitmapLayer *inventory_middle_image;

static void initialise_ui(void) {
  s_window = window_create();
  window_set_fullscreen(s_window, false);
  
  s_res_image_knight = gbitmap_create_with_resource(RESOURCE_ID_IMAGE_KNIGHT);
  // inventory_middle_image
  inventory_middle_image = bitmap_layer_create(GRect(40, 23, 62, 101));
  bitmap_layer_set_bitmap(inventory_middle_image, s_res_image_knight);
  layer_add_child(window_get_root_layer(s_window), (Layer *)inventory_middle_image);
}

static void destroy_ui(void) {
  window_destroy(s_window);
  bitmap_layer_destroy(inventory_middle_image);
  gbitmap_destroy(s_res_image_knight);
}
// END AUTO-GENERATED UI CODE

static void handle_window_unload(Window* window) {
  destroy_ui();
}

void show_inventory(void) {
  initialise_ui();
  window_set_window_handlers(s_window, (WindowHandlers) {
    .unload = handle_window_unload,
  });
  window_stack_push(s_window, true);
}

void hide_inventory(void) {
  window_stack_remove(s_window, true);
}
