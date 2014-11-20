#include "battle.h"
#include "first.h"
#include <pebble.h>
  
#define ZIX_PKEY 217
#define RATE_PKEY 222
#define HEALT_PKEY 221
#define MANA_PKEY 220
#define ARMURE_PKEY 218
  
int zix = 0;
int rate = 1;
short int enmeyhealt = 0;
short int enmeyforce = 0;  
short int enmeyarmure = 0;
short int mehealt = 0;
short int memana = 0;
short int mearmure = 0;
char Thealt[6] = {"123456"};
char Tforce[6] = {"123456"};
char Tarmure[6] = {"123456"};
char Tmehealt[6] = {"123456"};
char Tmemana[6] = {"123456"};

short int temp = 0;
bool test = true;

short int zixwin = 0;
short int ratewin = 0;
short int zixfall = 0;
short int ratefall = 0;

// BEGIN AUTO-GENERATED UI CODE; DO NOT MODIFY
static Window *s_window;
static GBitmap *s_res_image_1;
static GBitmap *s_res_image_2;
static GBitmap *s_res_image_3;
static GFont s_res_gothic_18_bold;
static GFont s_res_gothic_14;
static ActionBarLayer *s_actionbarlayer_1;
static TextLayer *enemy_layer;
static TextLayer *health_enemie_layer;
static TextLayer *var_health_enemie_layer;
static TextLayer *force_enemy_layer;
static TextLayer *var_force_enemy_layer;
static TextLayer *armure_enemy_layer;
static TextLayer *var_armure_enemy_layer;
static TextLayer *inventory_layer;
static TextLayer *health_me_layer;
static TextLayer *var_health_me_layer;
static TextLayer *mana_me_layer;
static TextLayer *s_textlayer_1;
static TextLayer *spell_layer;
static TextLayer *s_textlayer_2;
static InverterLayer *s_inverterlayer_1;

static void initialise_ui(void) {
  s_window = window_create();
  window_set_fullscreen(s_window, false);
  
  s_res_image_1 = gbitmap_create_with_resource(RESOURCE_ID_IMAGE_1);
  s_res_image_2 = gbitmap_create_with_resource(RESOURCE_ID_IMAGE_2);
  s_res_image_3 = gbitmap_create_with_resource(RESOURCE_ID_IMAGE_3);
  s_res_gothic_18_bold = fonts_get_system_font(FONT_KEY_GOTHIC_18_BOLD);
  s_res_gothic_14 = fonts_get_system_font(FONT_KEY_GOTHIC_14);
  // s_actionbarlayer_1
  s_actionbarlayer_1 = action_bar_layer_create();
  action_bar_layer_add_to_window(s_actionbarlayer_1, s_window);
  action_bar_layer_set_background_color(s_actionbarlayer_1, GColorBlack);
  action_bar_layer_set_icon(s_actionbarlayer_1, BUTTON_ID_UP, s_res_image_1);
  action_bar_layer_set_icon(s_actionbarlayer_1, BUTTON_ID_SELECT, s_res_image_2);
  action_bar_layer_set_icon(s_actionbarlayer_1, BUTTON_ID_DOWN, s_res_image_3);
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_actionbarlayer_1);
  
  // enemy_layer
  enemy_layer = text_layer_create(GRect(4, 4, 114, 20));
  text_layer_set_background_color(enemy_layer, GColorClear);
  text_layer_set_text(enemy_layer, "Enemy ");
  text_layer_set_text_alignment(enemy_layer, GTextAlignmentCenter);
  text_layer_set_font(enemy_layer, s_res_gothic_18_bold);
  layer_add_child(window_get_root_layer(s_window), (Layer *)enemy_layer);
  
  // health_enemie_layer
  health_enemie_layer = text_layer_create(GRect(5, 24, 57, 17));
  text_layer_set_text(health_enemie_layer, "Health :");
  layer_add_child(window_get_root_layer(s_window), (Layer *)health_enemie_layer);
  
  // var_health_enemie_layer
  var_health_enemie_layer = text_layer_create(GRect(51, 25, 75, 17));
  text_layer_set_background_color(var_health_enemie_layer, GColorClear);
  text_layer_set_text(var_health_enemie_layer, "0");
  text_layer_set_font(var_health_enemie_layer, s_res_gothic_14);
  layer_add_child(window_get_root_layer(s_window), (Layer *)var_health_enemie_layer);
  
  // force_enemy_layer
  force_enemy_layer = text_layer_create(GRect(5, 41, 51, 19));
  text_layer_set_background_color(force_enemy_layer, GColorClear);
  text_layer_set_text(force_enemy_layer, "Force :");
  layer_add_child(window_get_root_layer(s_window), (Layer *)force_enemy_layer);
  
  // var_force_enemy_layer
  var_force_enemy_layer = text_layer_create(GRect(47, 42, 80, 17));
  text_layer_set_background_color(var_force_enemy_layer, GColorClear);
  text_layer_set_text(var_force_enemy_layer, "0");
  text_layer_set_font(var_force_enemy_layer, s_res_gothic_14);
  layer_add_child(window_get_root_layer(s_window), (Layer *)var_force_enemy_layer);
  
  // armure_enemy_layer
  armure_enemy_layer = text_layer_create(GRect(4, 57, 59, 18));
  text_layer_set_background_color(armure_enemy_layer, GColorClear);
  text_layer_set_text(armure_enemy_layer, "Armure : ");
  layer_add_child(window_get_root_layer(s_window), (Layer *)armure_enemy_layer);
  
  // var_armure_enemy_layer
  var_armure_enemy_layer = text_layer_create(GRect(55, 57, 100, 18));
  text_layer_set_background_color(var_armure_enemy_layer, GColorClear);
  text_layer_set_text(var_armure_enemy_layer, "0");
  text_layer_set_font(var_armure_enemy_layer, s_res_gothic_14);
  layer_add_child(window_get_root_layer(s_window), (Layer *)var_armure_enemy_layer);
  
  // inventory_layer
  inventory_layer = text_layer_create(GRect(3, 107, 100, 20));
  text_layer_set_background_color(inventory_layer, GColorClear);
  text_layer_set_text(inventory_layer, "3.Inventory");
  layer_add_child(window_get_root_layer(s_window), (Layer *)inventory_layer);
  
  // health_me_layer
  health_me_layer = text_layer_create(GRect(2, 137, 86, 20));
  text_layer_set_background_color(health_me_layer, GColorClear);
  text_layer_set_text(health_me_layer, "Her Health :");
  layer_add_child(window_get_root_layer(s_window), (Layer *)health_me_layer);
  
  // var_health_me_layer
  var_health_me_layer = text_layer_create(GRect(73, 137, 60, 20));
  text_layer_set_background_color(var_health_me_layer, GColorClear);
  text_layer_set_text(var_health_me_layer, "0");
  text_layer_set_font(var_health_me_layer, s_res_gothic_14);
  layer_add_child(window_get_root_layer(s_window), (Layer *)var_health_me_layer);
  
  // mana_me_layer
  mana_me_layer = text_layer_create(GRect(2, 125, 76, 16));
  text_layer_set_background_color(mana_me_layer, GColorClear);
  text_layer_set_text(mana_me_layer, "Her Mana :");
  layer_add_child(window_get_root_layer(s_window), (Layer *)mana_me_layer);
  
  // s_textlayer_1
  s_textlayer_1 = text_layer_create(GRect(65, 126, 63, 15));
  text_layer_set_background_color(s_textlayer_1, GColorClear);
  text_layer_set_text(s_textlayer_1, "0");
  text_layer_set_font(s_textlayer_1, s_res_gothic_14);
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_textlayer_1);
  
  // spell_layer
  spell_layer = text_layer_create(GRect(3, 80, 41, 16));
  text_layer_set_background_color(spell_layer, GColorClear);
  text_layer_set_text(spell_layer, "1.Spell");
  layer_add_child(window_get_root_layer(s_window), (Layer *)spell_layer);
  
  // s_textlayer_2
  s_textlayer_2 = text_layer_create(GRect(3, 94, 76, 17));
  text_layer_set_background_color(s_textlayer_2, GColorClear);
  text_layer_set_text(s_textlayer_2, "2.Attack");
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_textlayer_2);
  
  // s_inverterlayer_1
  s_inverterlayer_1 = inverter_layer_create(GRect(3, 4, 119, 73));
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_inverterlayer_1);
}

static void destroy_ui(void) {
  window_destroy(s_window);
  action_bar_layer_destroy(s_actionbarlayer_1);
  text_layer_destroy(enemy_layer);
  text_layer_destroy(health_enemie_layer);
  text_layer_destroy(var_health_enemie_layer);
  text_layer_destroy(force_enemy_layer);
  text_layer_destroy(var_force_enemy_layer);
  text_layer_destroy(armure_enemy_layer);
  text_layer_destroy(var_armure_enemy_layer);
  text_layer_destroy(inventory_layer);
  text_layer_destroy(health_me_layer);
  text_layer_destroy(var_health_me_layer);
  text_layer_destroy(mana_me_layer);
  text_layer_destroy(s_textlayer_1);
  text_layer_destroy(spell_layer);
  text_layer_destroy(s_textlayer_2);
  inverter_layer_destroy(s_inverterlayer_1);
  gbitmap_destroy(s_res_image_1);
  gbitmap_destroy(s_res_image_2);
  gbitmap_destroy(s_res_image_3);
}
// END AUTO-GENERATED UI CODE

static void Fhealt(){
      //Healt
      snprintf(Thealt, sizeof(Thealt), "%d", enmeyhealt);
      text_layer_set_text(var_health_enemie_layer, Thealt);
}
static void Ffroce(){
    //Force
      snprintf(Tforce, sizeof(Tforce), "%d", enmeyforce);
      text_layer_set_text(var_force_enemy_layer, Tforce);
}
static void Farmure(){
    //Armure
      snprintf(Tarmure, sizeof(Tarmure), "%d", enmeyarmure);
      text_layer_set_text(var_armure_enemy_layer, Tarmure);
}
static void Fmehealt(){
    //mehealt
      snprintf(Tmehealt, sizeof(Tmehealt), "%d", mehealt);
      text_layer_set_text(var_health_me_layer, Tmehealt);
}
static void Fmemana(){
    //Armure
      snprintf(Tmemana, sizeof(Tmemana), "%d", memana);
      text_layer_set_text(s_textlayer_1, Tmemana);
}
static void modif(int nb, short bonus){
  if(test){
  mehealt = persist_read_int(HEALT_PKEY);
  memana = persist_read_int(MANA_PKEY);
    if(nb == 0 ){
        text_layer_set_text(enemy_layer, " Orgue ");
        enmeyhealt = 50;
        enmeyforce = 2;
        enmeyarmure = 3;
        temp = 0;
      
        zixwin = 500;
        zixfall = 250;
        ratefall = 5;
        ratewin = 10;
    }
  if(nb == 1){
    
  }
  if(nb == 2){
    
  }
  if(nb == 3){
    
  }
  if(nb == 4){
    
  }
  if(nb == 5){
    
  }
  if(nb == 6){
    
  }
  if(nb == 7){
    
  }
  if(nb == 8){
    
  }
  if(nb == 9){
    
  }
  if(nb == 10){
    
  }
  }
    Fhealt();
    Ffroce();
    Farmure();
    Fmehealt();
    Fmemana();
    test = false;
}
static void var(){
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
	  mehealt = persist_read_int(HEALT_PKEY);
    }else{
	  mehealt = 100;
    }
    if(persist_exists(MANA_PKEY)){
	  memana = persist_read_int(MANA_PKEY);
    }else{
	  memana = 100;
    }
    if(persist_exists(ARMURE_PKEY)){
	  mearmure = persist_read_int(ARMURE_PKEY);
    }else{
	  mearmure = 5;
    }
}
//Attaque
static void select_click_handler(ClickRecognizerRef recognizer, void *context) {
   switch (temp){
    case 0 :
        enmeyhealt -= 5-enmeyarmure;
         mehealt -= 2;
         if(mehealt <= 0){
        zix -= zixfall;
        rate -= ratefall;
        hide_battle();
        }
      if(enmeyhealt <= 1){
      zix += zixwin;
     rate += ratewin;
      hide_battle();
       }
      break;
    case 1 :
          
      break;
    case 2 :
          
      break;
    case 3 :
          
      break;
    case 4 :
          
      break;
    case 5 :
          
      break;
     case 6 :
          
      break;
     case 7 :
          
      break;
     case 8 :
          
      break;
     case 9 :
          
      break;
     case 10 :
          
      break;
  }
      Fmehealt();
      Fhealt();
}
//Spell
static void up_click_handler(ClickRecognizerRef recognizer, void *context) {
     switch (temp){
    case 0 :
       
      break;
    case 1 :
          
      break;
    case 2 :
          
      break;
    case 3 :
          
      break;
    case 4 :
          
      break;
    case 5 :
          
      break;
     case 6 :
          
      break;
     case 7 :
          
      break;
     case 8 :
          
      break;
     case 9 :
          
      break;
     case 10 :
          
      break;
  }
}
//Inventory
static void down_click_handler(ClickRecognizerRef recognizer, void *context) {
   switch (temp){
    case 0 :
         enmeyhealt -= 5-enmeyarmure;
         mehealt -= 2;
      break;
    case 1 :
          
      break;
    case 2 :
          
      break;
    case 3 :
          
      break;
    case 4 :
          
      break;
    case 5 :
          
      break;
     case 6 :
          
      break;
     case 7 :
          
      break;
     case 8 :
          
      break;
     case 9 :
          
      break;
     case 10 :
          
      break;
  }
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
  persist_write_int(HEALT_PKEY, mehealt);
  persist_write_int(MANA_PKEY, memana);
  persist_write_int(ARMURE_PKEY, mearmure);
}
void show_battle(int nb, short bonus) {
  initialise_ui();
  modif(nb, bonus);
  var();
  window_set_click_config_provider(s_window, click_config_provider);
  window_set_window_handlers(s_window, (WindowHandlers) {
    .unload = handle_window_unload,
  });
  window_stack_push(s_window, true);
}

void hide_battle(void) {
  destroy_ui();
  persist_write_int(ZIX_PKEY, zix);
  persist_write_int(RATE_PKEY, rate);
  persist_write_int(HEALT_PKEY, mehealt);
  persist_write_int(MANA_PKEY, memana);
  window_stack_remove(s_window, true);
}
