#include "first.h"
#include "shop.h"
#include "inventory.h"
#include "quest.h" 

#define atoa(x) #x
#define ZIX_PKEY 217
#define RATE_PKEY 222
#define HEALT_PKEY 221
#define MANA_PKEY 220
#define FORCE_PKEY 219
#define ARMURE_PKEY 218
  
static int zix = 0;
static int rate = 1;
static int healt = 100;
static int mana = 100;
static int force = 5;
static int armure = 5;
static char Tzix[6] = {"123456"};
static char Trate[6] = {"123456"};
static char Thealt[6] = {"123456"};
static char Tmana[6] = {"123456"};
static char Tforce[6] = {"123456"};
static char Tarmure[6] = {"123456"};

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
static TextLayer *healt_layer;
static TextLayer *mana_layer;
static TextLayer *var_healt_layer;
static TextLayer *var_mana_layer;
static TextLayer *force_layer;
static TextLayer *armure_layer;
static TextLayer *var_force_layer;
static TextLayer *var_armure_layer;
static TextLayer *var_rate_layer;
static TextLayer *var_zix_layer;

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
  rate_layer = text_layer_create(GRect(2, 105, 47, 20));
  text_layer_set_text(rate_layer, "Honor :");
  text_layer_set_font(rate_layer, s_res_gothic_18_bold);
  layer_add_child(window_get_root_layer(s_window), (Layer *)rate_layer);
  
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
  text_layer_set_text(var_healt_layer, "0");
  text_layer_set_font(var_healt_layer, s_res_gothic_14);
  layer_add_child(window_get_root_layer(s_window), (Layer *)var_healt_layer);
  
  // var_mana_layer
  var_mana_layer = text_layer_create(GRect(99, 27, 22, 15));
  text_layer_set_text(var_mana_layer, "0");
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
  text_layer_set_text(var_force_layer, "0");
  text_layer_set_font(var_force_layer, s_res_gothic_14);
  layer_add_child(window_get_root_layer(s_window), (Layer *)var_force_layer);
  
  // var_armure_layer
  var_armure_layer = text_layer_create(GRect(95, 93, 16, 14));
  text_layer_set_text(var_armure_layer, "0");
  text_layer_set_font(var_armure_layer, s_res_gothic_14);
  layer_add_child(window_get_root_layer(s_window), (Layer *)var_armure_layer);
  
  // var_rate_layer
  var_rate_layer = text_layer_create(GRect(48, 108, 78, 19));
  text_layer_set_background_color(var_rate_layer, GColorClear);
  text_layer_set_text(var_rate_layer, "0");
  text_layer_set_font(var_rate_layer, s_res_gothic_14);
  layer_add_child(window_get_root_layer(s_window), (Layer *)var_rate_layer);
  
  // var_zix_layer
  var_zix_layer = text_layer_create(GRect(31, 125, 115, 19));
  text_layer_set_background_color(var_zix_layer, GColorClear);
  text_layer_set_text(var_zix_layer, "0");
  text_layer_set_font(var_zix_layer, s_res_gothic_14);
  layer_add_child(window_get_root_layer(s_window), (Layer *)var_zix_layer);
}

static void destroy_ui(void) {
  window_destroy(s_window);
  bitmap_layer_destroy(var_perso);
  text_layer_destroy(zix_layer);
  action_bar_layer_destroy(menu_bar);
  text_layer_destroy(rate_layer);
  text_layer_destroy(healt_layer);
  text_layer_destroy(mana_layer);
  text_layer_destroy(var_healt_layer);
  text_layer_destroy(var_mana_layer);
  text_layer_destroy(force_layer);
  text_layer_destroy(armure_layer);
  text_layer_destroy(var_force_layer);
  text_layer_destroy(var_armure_layer);
  text_layer_destroy(var_rate_layer);
  text_layer_destroy(var_zix_layer);
  gbitmap_destroy(s_res_image_knight);
  gbitmap_destroy(s_res_image_inventory);
  gbitmap_destroy(s_res_image_shop);
  gbitmap_destroy(s_res_image_quest);
}
// END AUTO-GENERATED UI CODE

void handle_timechange(struct tm *tick_time, TimeUnits units_changed){
      zix += rate;
  //Zix
      snprintf(Tzix, sizeof(Tzix), "%d", zix);
      text_layer_set_text(var_zix_layer, Tzix); 
}
static void Frate(){
  //RATE
    snprintf(Trate, sizeof(Trate), "%d", rate);
    text_layer_set_text(var_rate_layer, Trate);
}
static void Fhealt(){
  //Healt
    snprintf(Thealt, sizeof(Thealt), "%d", healt);
    text_layer_set_text(var_healt_layer, Thealt);
}
static void Fmana(){
    //Mana
    snprintf(Tmana, sizeof(Tmana), "%d", mana);
    text_layer_set_text(var_mana_layer, Tmana);
}
static void Fforce(){
    //Force
    snprintf(Tforce, sizeof(Tforce), "%d", force);
    text_layer_set_text(var_force_layer, Tforce);
}
static void Farmure(){
    //Armure 
    snprintf(Tarmure, sizeof(Tarmure), "%d", armure);
    text_layer_set_text(var_armure_layer, Tarmure);
}
static void modif(){
    tick_timer_service_subscribe(SECOND_UNIT, handle_timechange);
  
    if(persist_exists(ZIX_PKEY)){
	  zix = persist_read_int(ZIX_PKEY);
    }else{
	  zix = 0;
    }
    if(persist_exists(RATE_PKEY)){
	  rate = persist_read_int(RATE_PKEY);
    }else{
	  rate = 1;
    }
    if(persist_exists(HEALT_PKEY)){
	  healt = persist_read_int(HEALT_PKEY);
    }else{
	  healt = 100;
    }
    if(persist_exists(MANA_PKEY)){
	  mana = persist_read_int(MANA_PKEY);
    }else{
	  mana = 100;
    }
    if(persist_exists(FORCE_PKEY)){
	  force = persist_read_int(FORCE_PKEY);
    }else{
	  force = 5;
    }
    if(persist_exists(ARMURE_PKEY)){
	  armure = persist_read_int(ARMURE_PKEY);
    }else{
	  armure = 5;
    }
}

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
  persist_write_int(ZIX_PKEY, zix);
  persist_write_int(RATE_PKEY, rate);
  persist_write_int(HEALT_PKEY, healt);
  persist_write_int(MANA_PKEY, mana);
  persist_write_int(FORCE_PKEY, force);
  persist_write_int(ARMURE_PKEY, armure);
}

static void changevalue(){
  Frate();
  Fhealt();
  Fmana();
  Fforce();
  Farmure();
}
void show_first(void) {
  srand(time(NULL));
  initialise_ui();
  modif();
  changevalue();
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