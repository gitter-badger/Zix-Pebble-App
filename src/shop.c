#include "shop.h"
#include <pebble.h>

// BEGIN AUTO-GENERATED UI CODE; DO NOT MODIFY
static Window *s_window;
static GBitmap *s_res_image_1;
static GBitmap *s_res_image_2;
static GBitmap *s_res_image_3;
static GBitmap *s_res_image_shop;
static GFont s_res_gothic_14;
static ActionBarLayer *actionbar_shop;
static BitmapLayer *shopman_image;
static TextLayer *shopman1_layer;
static TextLayer *shopman2_layer;
static TextLayer *one_layer;
static TextLayer *two_layer;
static TextLayer *three_layer;
static TextLayer *name1_layer;
static TextLayer *description1_layer;
static TextLayer *name2_layer;
static TextLayer *name3_layer;
static TextLayer *description2_layer;
static TextLayer *description3_layer;

static void initialise_ui(void) {
  s_window = window_create();
  window_set_fullscreen(s_window, false);
  
  s_res_image_1 = gbitmap_create_with_resource(RESOURCE_ID_IMAGE_1);
  s_res_image_2 = gbitmap_create_with_resource(RESOURCE_ID_IMAGE_2);
  s_res_image_3 = gbitmap_create_with_resource(RESOURCE_ID_IMAGE_3);
  s_res_image_shop = gbitmap_create_with_resource(RESOURCE_ID_IMAGE_SHOP);
  s_res_gothic_14 = fonts_get_system_font(FONT_KEY_GOTHIC_14);
  // actionbar_shop
  actionbar_shop = action_bar_layer_create();
  action_bar_layer_add_to_window(actionbar_shop, s_window);
  action_bar_layer_set_background_color(actionbar_shop, GColorBlack);
  action_bar_layer_set_icon(actionbar_shop, BUTTON_ID_UP, s_res_image_1);
  action_bar_layer_set_icon(actionbar_shop, BUTTON_ID_SELECT, s_res_image_2);
  action_bar_layer_set_icon(actionbar_shop, BUTTON_ID_DOWN, s_res_image_3);
  layer_add_child(window_get_root_layer(s_window), (Layer *)actionbar_shop);
  
  // shopman_image
  shopman_image = bitmap_layer_create(GRect(0, 0, 18, 21));
  bitmap_layer_set_bitmap(shopman_image, s_res_image_shop);
  layer_add_child(window_get_root_layer(s_window), (Layer *)shopman_image);
  
  // shopman1_layer
  shopman1_layer = text_layer_create(GRect(17, 3, 108, 18));
  text_layer_set_background_color(shopman1_layer, GColorClear);
  text_layer_set_text(shopman1_layer, "I have things that");
  layer_add_child(window_get_root_layer(s_window), (Layer *)shopman1_layer);
  
  // shopman2_layer
  shopman2_layer = text_layer_create(GRect(3, 20, 118, 17));
  text_layer_set_background_color(shopman2_layer, GColorClear);
  text_layer_set_text(shopman2_layer, "may interest you !");
  layer_add_child(window_get_root_layer(s_window), (Layer *)shopman2_layer);
  
  // one_layer
  one_layer = text_layer_create(GRect(3, 47, 19, 20));
  text_layer_set_text(one_layer, "1 :");
  layer_add_child(window_get_root_layer(s_window), (Layer *)one_layer);
  
  // two_layer
  two_layer = text_layer_create(GRect(3, 79, 17, 16));
  text_layer_set_text(two_layer, "2 :");
  layer_add_child(window_get_root_layer(s_window), (Layer *)two_layer);
  
  // three_layer
  three_layer = text_layer_create(GRect(3, 109, 17, 18));
  text_layer_set_text(three_layer, "3 :");
  layer_add_child(window_get_root_layer(s_window), (Layer *)three_layer);
  
  // name1_layer
  name1_layer = text_layer_create(GRect(18, 47, 127, 15));
  text_layer_set_background_color(name1_layer, GColorClear);
  text_layer_set_text(name1_layer, "Name");
  layer_add_child(window_get_root_layer(s_window), (Layer *)name1_layer);
  
  // description1_layer
  description1_layer = text_layer_create(GRect(17, 61, 125, 16));
  text_layer_set_background_color(description1_layer, GColorClear);
  text_layer_set_text(description1_layer, "Description");
  text_layer_set_font(description1_layer, s_res_gothic_14);
  layer_add_child(window_get_root_layer(s_window), (Layer *)description1_layer);
  
  // name2_layer
  name2_layer = text_layer_create(GRect(17, 78, 122, 15));
  text_layer_set_background_color(name2_layer, GColorClear);
  text_layer_set_text(name2_layer, "Name");
  layer_add_child(window_get_root_layer(s_window), (Layer *)name2_layer);
  
  // name3_layer
  name3_layer = text_layer_create(GRect(17, 108, 123, 15));
  text_layer_set_background_color(name3_layer, GColorClear);
  text_layer_set_text(name3_layer, "Name");
  layer_add_child(window_get_root_layer(s_window), (Layer *)name3_layer);
  
  // description2_layer
  description2_layer = text_layer_create(GRect(17, 92, 100, 17));
  text_layer_set_text(description2_layer, "Description");
  text_layer_set_font(description2_layer, s_res_gothic_14);
  layer_add_child(window_get_root_layer(s_window), (Layer *)description2_layer);
  
  // description3_layer
  description3_layer = text_layer_create(GRect(17, 121, 125, 16));
  text_layer_set_background_color(description3_layer, GColorClear);
  text_layer_set_text(description3_layer, "Description");
  text_layer_set_font(description3_layer, s_res_gothic_14);
  layer_add_child(window_get_root_layer(s_window), (Layer *)description3_layer);
}

static void destroy_ui(void) {
  window_destroy(s_window);
  action_bar_layer_destroy(actionbar_shop);
  bitmap_layer_destroy(shopman_image);
  text_layer_destroy(shopman1_layer);
  text_layer_destroy(shopman2_layer);
  text_layer_destroy(one_layer);
  text_layer_destroy(two_layer);
  text_layer_destroy(three_layer);
  text_layer_destroy(name1_layer);
  text_layer_destroy(description1_layer);
  text_layer_destroy(name2_layer);
  text_layer_destroy(name3_layer);
  text_layer_destroy(description2_layer);
  text_layer_destroy(description3_layer);
  gbitmap_destroy(s_res_image_1);
  gbitmap_destroy(s_res_image_2);
  gbitmap_destroy(s_res_image_3);
  gbitmap_destroy(s_res_image_shop);
}
// END AUTO-GENERATED UI CODE

static void handle_window_unload(Window* window) {
  destroy_ui();
}

void show_shop(void) {
  initialise_ui();
  window_set_window_handlers(s_window, (WindowHandlers) {
    .unload = handle_window_unload,
  });
  window_stack_push(s_window, true);
}

void hide_shop(void) {
  window_stack_remove(s_window, true);
}
