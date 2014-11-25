#include "inventory.h"
#include <pebble.h>

// BEGIN AUTO-GENERATED UI CODE; DO NOT MODIFY
static Window *s_window;
static GFont s_res_gothic_14;
static TextLayer *spell_layer;
static TextLayer *name_spell_layer;
static TextLayer *armor_layer;
static TextLayer *name_armor_layer;
static TextLayer *sword_layer;
static TextLayer *name_sword_layer;

static void initialise_ui(void) {
  s_window = window_create();
  window_set_fullscreen(s_window, false);
  
  s_res_gothic_14 = fonts_get_system_font(FONT_KEY_GOTHIC_14);
  // spell_layer
  spell_layer = text_layer_create(GRect(1, 1, 70, 19));
  text_layer_set_background_color(spell_layer, GColorClear);
  text_layer_set_text(spell_layer, "Spell");
  layer_add_child(window_get_root_layer(s_window), (Layer *)spell_layer);
  
  // name_spell_layer
  name_spell_layer = text_layer_create(GRect(1, 14, 66, 20));
  text_layer_set_background_color(name_spell_layer, GColorClear);
  text_layer_set_text(name_spell_layer, "name");
  text_layer_set_font(name_spell_layer, s_res_gothic_14);
  layer_add_child(window_get_root_layer(s_window), (Layer *)name_spell_layer);
  
  // armor_layer
  armor_layer = text_layer_create(GRect(3, 118, 67, 20));
  text_layer_set_background_color(armor_layer, GColorClear);
  text_layer_set_text(armor_layer, "Armor");
  layer_add_child(window_get_root_layer(s_window), (Layer *)armor_layer);
  
  // name_armor_layer
  name_armor_layer = text_layer_create(GRect(3, 131, 67, 20));
  text_layer_set_background_color(name_armor_layer, GColorClear);
  text_layer_set_text(name_armor_layer, "Name");
  text_layer_set_font(name_armor_layer, s_res_gothic_14);
  layer_add_child(window_get_root_layer(s_window), (Layer *)name_armor_layer);
  
  // sword_layer
  sword_layer = text_layer_create(GRect(67, 119, 75, 16));
  text_layer_set_background_color(sword_layer, GColorClear);
  text_layer_set_text(sword_layer, "Sword");
  text_layer_set_text_alignment(sword_layer, GTextAlignmentRight);
  layer_add_child(window_get_root_layer(s_window), (Layer *)sword_layer);
  
  // name_sword_layer
  name_sword_layer = text_layer_create(GRect(67, 131, 74, 20));
  text_layer_set_background_color(name_sword_layer, GColorClear);
  text_layer_set_text(name_sword_layer, "Name");
  text_layer_set_text_alignment(name_sword_layer, GTextAlignmentRight);
  text_layer_set_font(name_sword_layer, s_res_gothic_14);
  layer_add_child(window_get_root_layer(s_window), (Layer *)name_sword_layer);
}

static void destroy_ui(void) {
  window_destroy(s_window);
  text_layer_destroy(spell_layer);
  text_layer_destroy(name_spell_layer);
  text_layer_destroy(armor_layer);
  text_layer_destroy(name_armor_layer);
  text_layer_destroy(sword_layer);
  text_layer_destroy(name_sword_layer);
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
