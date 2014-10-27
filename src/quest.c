#include "quest.h"
#include <pebble.h>

// BEGIN AUTO-GENERATED UI CODE; DO NOT MODIFY
static Window *s_window;
static GBitmap *s_res_image_yes;
static GBitmap *s_res_image_quest;
static GBitmap *s_res_image_no;
static ActionBarLayer *actionbar_quest;
static TextLayer *s_textlayer_1;

static void initialise_ui(void) {
  s_window = window_create();
  window_set_fullscreen(s_window, false);
  
  s_res_image_yes = gbitmap_create_with_resource(RESOURCE_ID_IMAGE_YES);
  s_res_image_quest = gbitmap_create_with_resource(RESOURCE_ID_IMAGE_QUEST);
  s_res_image_no = gbitmap_create_with_resource(RESOURCE_ID_IMAGE_NO);
  // actionbar_quest
  actionbar_quest = action_bar_layer_create();
  action_bar_layer_add_to_window(actionbar_quest, s_window);
  action_bar_layer_set_background_color(actionbar_quest, GColorBlack);
  action_bar_layer_set_icon(actionbar_quest, BUTTON_ID_UP, s_res_image_yes);
  action_bar_layer_set_icon(actionbar_quest, BUTTON_ID_SELECT, s_res_image_quest);
  action_bar_layer_set_icon(actionbar_quest, BUTTON_ID_DOWN, s_res_image_no);
  layer_add_child(window_get_root_layer(s_window), (Layer *)actionbar_quest);
  
  // s_textlayer_1
  s_textlayer_1 = text_layer_create(GRect(21, 64, 86, 20));
  text_layer_set_text(s_textlayer_1, "Randome Quest");
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_textlayer_1);
}

static void destroy_ui(void) {
  window_destroy(s_window);
  action_bar_layer_destroy(actionbar_quest);
  text_layer_destroy(s_textlayer_1);
  gbitmap_destroy(s_res_image_yes);
  gbitmap_destroy(s_res_image_quest);
  gbitmap_destroy(s_res_image_no);
}
// END AUTO-GENERATED UI CODE

static void handle_window_unload(Window* window) {
  destroy_ui();
}

void show_quest(void) {
  initialise_ui();
  window_set_window_handlers(s_window, (WindowHandlers) {
    .unload = handle_window_unload,
  });
  window_stack_push(s_window, true);
}

void hide_quest(void) {
  window_stack_remove(s_window, true);
}
