#include "quest.h"
#include "battle.h"
#include "first.h"
#include <pebble.h>
  
static int RandomNb = 0;

// BEGIN AUTO-GENERATED UI CODE; DO NOT MODIFY
static Window *s_window;
static GBitmap *s_res_image_yes;
static GBitmap *s_res_image_quest;
static GBitmap *s_res_image_no;
static GBitmap *s_res_image_orge;
static ActionBarLayer *actionbar_quest;
static TextLayer *layer_1;
static TextLayer *layer_2;
static TextLayer *layer_3;
static TextLayer *layer_4;
static TextLayer *layer_5;
static BitmapLayer *s_bitmaplayer_1;

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
  
  // layer_1
  layer_1 = text_layer_create(GRect(4, 70, 119, 43));
  text_layer_set_background_color(layer_1, GColorClear);
  text_layer_set_text(layer_1, "Randome Quest");
  text_layer_set_text_alignment(layer_1, GTextAlignmentCenter);
  layer_add_child(window_get_root_layer(s_window), (Layer *)layer_1);
  
  // layer_2
  layer_2 = text_layer_create(GRect(4, 84, 117, 27));
  text_layer_set_background_color(layer_2, GColorClear);
  text_layer_set_text(layer_2, "Text layer");
  text_layer_set_text_alignment(layer_2, GTextAlignmentCenter);
  layer_add_child(window_get_root_layer(s_window), (Layer *)layer_2);
  
  // layer_3
  layer_3 = text_layer_create(GRect(4, 98, 116, 24));
  text_layer_set_background_color(layer_3, GColorClear);
  text_layer_set_text(layer_3, "Text layer");
  text_layer_set_text_alignment(layer_3, GTextAlignmentCenter);
  layer_add_child(window_get_root_layer(s_window), (Layer *)layer_3);
  
  // layer_4
  layer_4 = text_layer_create(GRect(4, 111, 120, 32));
  text_layer_set_background_color(layer_4, GColorClear);
  text_layer_set_text(layer_4, "Text layer");
  text_layer_set_text_alignment(layer_4, GTextAlignmentCenter);
  layer_add_child(window_get_root_layer(s_window), (Layer *)layer_4);
  
  // layer_5
  layer_5 = text_layer_create(GRect(4, 124, 119, 23));
  text_layer_set_background_color(layer_5, GColorClear);
  text_layer_set_text(layer_5, "Text layer");
  text_layer_set_text_alignment(layer_5, GTextAlignmentCenter);
  layer_add_child(window_get_root_layer(s_window), (Layer *)layer_5);
  
  // s_bitmaplayer_1
  s_bitmaplayer_1 = bitmap_layer_create(GRect(7, 2, 111, 62));
  bitmap_layer_set_bitmap(s_bitmaplayer_1, s_res_image_orge);
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_bitmaplayer_1);
}

static void destroy_ui(void) {
  window_destroy(s_window);
  action_bar_layer_destroy(actionbar_quest);
  text_layer_destroy(layer_1);
  text_layer_destroy(layer_2);
  text_layer_destroy(layer_3);
  text_layer_destroy(layer_4);
  text_layer_destroy(layer_5);
  bitmap_layer_destroy(s_bitmaplayer_1);
  gbitmap_destroy(s_res_image_yes);
  gbitmap_destroy(s_res_image_quest);
  gbitmap_destroy(s_res_image_no);
  gbitmap_destroy(s_res_image_orge);
}
// END AUTO-GENERATED UI CODE
static void RandomQuest(){
  if(RandomNb == 0){
    text_layer_set_text(layer_1, "Un ogre");
    text_layer_set_text(layer_2, "mange les");
    text_layer_set_text(layer_3, "plantation des");
    text_layer_set_text(layer_4, "paysans. Vous");
    text_layer_set_text(layer_5, "dever les aides!");
  }
}
//static int RandomNb(){
//  return (rand() % 10);
//}
static void select_click_handler(ClickRecognizerRef recognizer, void *context) {
    RandomQuest();
}
static void up_click_handler(ClickRecognizerRef recognizer, void *context) {
  if(RandomNb == 0){  
  show_battle();
  }
}
static void down_click_handler(ClickRecognizerRef recognizer, void *context) {
    if(RandomNb == 0){  
    show_first();
    }
}
static void click_config_provider(void *context) {
  window_single_click_subscribe(BUTTON_ID_SELECT, select_click_handler);
  window_single_click_subscribe(BUTTON_ID_UP, up_click_handler);
  window_single_click_subscribe(BUTTON_ID_DOWN, down_click_handler);
}

static void handle_window_unload(Window* window) {
  destroy_ui();
}

void show_quest(void) {
  initialise_ui();
  RandomQuest();
  window_set_window_handlers(s_window, (WindowHandlers) {
    .unload = handle_window_unload,
  });
  window_stack_push(s_window, true);
}

void hide_quest(void) {
  window_stack_remove(s_window, true);
}
