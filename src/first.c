#include "first.h"
#include "shop.h"
#include "inventory.h"
#include "quest.h"
#include <pebble.h>

// BEGIN AUTO-GENERATED UI CODE; DO NOT MODIFY
static Window *s_window;
static GBitmap *s_res_image_knight;
static GFont s_res_gothic_18_bold;
static GBitmap *s_res_image_inventory;
static GBitmap *s_res_image_shop;
static GBitmap *s_res_image_quest;
static GFont s_res_gothic_14;
static BitmapLayer *var_perso;
static TextLayer *zix_layer;
static ActionBarLayer *menu_bar;
static TextLayer *rate_layer;
static TextLayer *var_rate_layer;
static TextLayer *var_zix_layer;
static TextLayer *healt_layer;
static TextLayer *mana_layer;
static TextLayer *var_healt_layer;
static TextLayer *var_mana_layer;
static TextLayer *force_layer;
static TextLayer *armure_layer;
static TextLayer *var_force_layer;
static TextLayer *var_armure_layer;

static void initialise_ui(void) {
  s_window = window_create();
  window_set_fullscreen(s_window, 0);
  
  s_res_image_knight = gbitmap_create_with_resource(RESOURCE_ID_IMAGE_KNIGHT);
  s_res_gothic_18_bold = fonts_get_system_font(FONT_KEY_GOTHIC_18_BOLD);
  s_res_image_inventory = gbitmap_create_with_resource(RESOURCE_ID_IMAGE_INVENTORY);
  s_res_image_shop = gbitmap_create_with_resource(RESOURCE_ID_IMAGE_SHOP);
  s_res_image_quest = gbitmap_create_with_resource(RESOURCE_ID_IMAGE_QUEST);
  s_res_gothic_14 = fonts_get_system_font(FONT_KEY_GOTHIC_14);
  // var_perso
  var_perso = bitmap_layer_create(GRect(0, 3, 66, 100));
  bitmap_layer_set_bitmap(var_perso, s_res_image_knight);
  bitmap_layer_set_background_color(var_perso, GColorWhite);
  layer_add_child(window_get_root_layer(s_window), (Layer *)var_perso);
  
  // zix_layer
  zix_layer = text_layer_create(GRect(2, 122, 38, 18));
  text_layer_set_background_color(zix_layer, GColorClear);
  text_layer_set_text(zix_layer, "Zix :");
  text_layer_set_font(zix_layer, s_res_gothic_18_bold);
  layer_add_child(window_get_root_layer(s_window), (Layer *)zix_layer);
  
  // menu_bar
  menu_bar = action_bar_layer_create();
  action_bar_layer_add_to_window(menu_bar, s_window);
  action_bar_layer_set_background_color(menu_bar, GColorBlack);
  action_bar_layer_set_icon(menu_bar, BUTTON_ID_UP, s_res_image_inventory);
  action_bar_layer_set_icon(menu_bar, BUTTON_ID_SELECT, s_res_image_shop);
  action_bar_layer_set_icon(menu_bar, BUTTON_ID_DOWN, s_res_image_quest);
  layer_add_child(window_get_root_layer(s_window), (Layer *)menu_bar);
  
  // rate_layer
  rate_layer = text_layer_create(GRect(2, 105, 39, 20));
  text_layer_set_text(rate_layer, "Rate :");
  text_layer_set_font(rate_layer, s_res_gothic_18_bold);
  layer_add_child(window_get_root_layer(s_window), (Layer *)rate_layer);
  
  // var_rate_layer
  var_rate_layer = text_layer_create(GRect(42, 108, 81, 17));
  text_layer_set_text(var_rate_layer, "var-rate");
  text_layer_set_font(var_rate_layer, s_res_gothic_14);
  layer_add_child(window_get_root_layer(s_window), (Layer *)var_rate_layer);
  
  // var_zix_layer
  var_zix_layer = text_layer_create(GRect(32, 125, 89, 17));
  text_layer_set_text(var_zix_layer, "var-zix");
  text_layer_set_font(var_zix_layer, s_res_gothic_14);
  layer_add_child(window_get_root_layer(s_window), (Layer *)var_zix_layer);
  
  // healt_layer
  healt_layer = text_layer_create(GRect(59, 10, 40, 16));
  text_layer_set_text(healt_layer, "Healt :");
  layer_add_child(window_get_root_layer(s_window), (Layer *)healt_layer);
  
  // mana_layer
  mana_layer = text_layer_create(GRect(59, 27, 38, 16));
  text_layer_set_text(mana_layer, "Mana :");
  layer_add_child(window_get_root_layer(s_window), (Layer *)mana_layer);
  
  // var_healt_layer
  var_healt_layer = text_layer_create(GRect(99, 10, 24, 15));
  text_layer_set_text(var_healt_layer, "100");
  text_layer_set_font(var_healt_layer, s_res_gothic_14);
  layer_add_child(window_get_root_layer(s_window), (Layer *)var_healt_layer);
  
  // var_mana_layer
  var_mana_layer = text_layer_create(GRect(99, 27, 22, 15));
  text_layer_set_text(var_mana_layer, "100");
  text_layer_set_font(var_mana_layer, s_res_gothic_14);
  layer_add_child(window_get_root_layer(s_window), (Layer *)var_mana_layer);
  
  // force_layer
  force_layer = text_layer_create(GRect(57, 79, 46, 16));
  text_layer_set_text(force_layer, "Force :");
  layer_add_child(window_get_root_layer(s_window), (Layer *)force_layer);
  
  // armure_layer
  armure_layer = text_layer_create(GRect(48, 93, 55, 16));
  text_layer_set_text(armure_layer, "Armure :");
  layer_add_child(window_get_root_layer(s_window), (Layer *)armure_layer);
  
  // var_force_layer
  var_force_layer = text_layer_create(GRect(95, 79, 16, 15));
  text_layer_set_text(var_force_layer, "20");
  text_layer_set_font(var_force_layer, s_res_gothic_14);
  layer_add_child(window_get_root_layer(s_window), (Layer *)var_force_layer);
  
  // var_armure_layer
  var_armure_layer = text_layer_create(GRect(95, 93, 16, 14));
  text_layer_set_text(var_armure_layer, "20");
  text_layer_set_font(var_armure_layer, s_res_gothic_14);
  layer_add_child(window_get_root_layer(s_window), (Layer *)var_armure_layer);
}

static void destroy_ui(void) {
  window_destroy(s_window);
  bitmap_layer_destroy(var_perso);
  text_layer_destroy(zix_layer);
  action_bar_layer_destroy(menu_bar);
  text_layer_destroy(rate_layer);
  text_layer_destroy(var_rate_layer);
  text_layer_destroy(var_zix_layer);
  text_layer_destroy(healt_layer);
  text_layer_destroy(mana_layer);
  text_layer_destroy(var_healt_layer);
  text_layer_destroy(var_mana_layer);
  text_layer_destroy(force_layer);
  text_layer_destroy(armure_layer);
  text_layer_destroy(var_force_layer);
  text_layer_destroy(var_armure_layer);
  gbitmap_destroy(s_res_image_knight);
  gbitmap_destroy(s_res_image_inventory);
  gbitmap_destroy(s_res_image_shop);
  gbitmap_destroy(s_res_image_quest);
}
// END AUTO-GENERATED UI CODE


static void select_click_handler(ClickRecognizerRef recognizer, void *context) {
  show_shop();
}

static void up_click_handler(ClickRecognizerRef recognizer, void *context) {
  show_inventory();
}

static void down_click_handler(ClickRecognizerRef recognizer, void *context) {
  show_quest();
}

static void click_config_provider(void *context) {
  window_single_click_subscribe(BUTTON_ID_SELECT, select_click_handler);
  window_single_click_subscribe(BUTTON_ID_UP, up_click_handler);
  window_single_click_subscribe(BUTTON_ID_DOWN, down_click_handler);
}

static void handle_window_unload(Window* window) {
  destroy_ui();
}

void show_first(void) {
  initialise_ui();
  window_set_click_config_provider(s_window, click_config_provider);
  window_set_window_handlers(s_window, (WindowHandlers) {
    .unload = handle_window_unload,
  });
  const bool animated = true;
  window_stack_push(s_window, animated);
}

void hide_first(void) {
  window_stack_remove(s_window, true);
}