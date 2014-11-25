#include "battle.h"
#include "first.h"
#include <pebble.h>
  
#define ZIX_PKEY 217
#define RATE_PKEY 222
#define HEALT_PKEY 221
#define MANA_PKEY 220
#define ARMURE_PKEY 218
#define FORCE_PKEY 219
  
static int zix = 0;
static int rate = 1;
static int enmeyhealt = 0;
static int enmeyforce;
static int enmeyarmure = 0;
static int mehealt = 0;
static int memana = 0;
static int mearmure = 0;
static int meforce = 0;
static char Thealt[6] = {"123456"};
static char Tforce[6] = {"123456"};
static char Tarmure[6] = {"123456"};
static char Tmehealt[6] = {"123456"};
static char Tmemana[6] = {"123456"};

static bool test = true;

static short int winzix;
static short int failzix;
static short int winrate;
static short int failrate;

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
	  mearmure = 0;
    }
    if(persist_exists(FORCE_PKEY)){
	  meforce = persist_read_int(FORCE_PKEY);
    }else{
	  meforce = 5;
    }
} 
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
    //memana
      snprintf(Tmemana, sizeof(Tmemana), "%d", memana);
      text_layer_set_text(s_textlayer_1, Tmemana);
}
static void modif(int nb, short bonus){
  if(nb == 0 && test == true){
      text_layer_set_text(enemy_layer, " Orgue ");
      enmeyhealt = 50;
      enmeyforce = 2;
      enmeyarmure = 0;
    if(bonus){
      winzix = 200;
      failzix = 75;
      winrate = 10;
      failrate = 5;
    }
    else{
      winzix = 150;
      failzix = 75;
      winrate = 10;
      failrate = 5;
    }
  }
  if(nb == 3 && test == true){
    text_layer_set_text(enemy_layer, "Groupe de Voleur");
    enmeyhealt = 200;
    enmeyforce = 7;
    enmeyarmure = 2;
    winzix = 500;
    failzix = 350;
    winrate = 25;
    failrate = 10;
  }
  if(nb == 4 && test == true){
    text_layer_set_text(enemy_layer, "Dragon");
    enmeyhealt = 350;
    enmeyforce = 10;
    enmeyarmure = 5;
    winzix = 3000;
    failzix = 1500;
    winrate = 100;
    failrate = 25;
  }
  if(nb == 5 && test == true){
    text_layer_set_text(enemy_layer, "Bandit");
    enmeyhealt = 35;
    enmeyforce = 1;
    enmeyarmure = 0;
    winzix = 100;
    failzix = 50;
    winrate = 0;
    failrate = 2;
  }
  if(nb == 7 && test == true){
    text_layer_set_text(enemy_layer, "Assassin");
    enmeyhealt = 75;
    enmeyforce = 3;
    enmeyarmure = 1;
    winzix = 250;
    failzix = 100;
    winrate = 10;
    failrate = 2;
  }
  if(nb == 9 && test == true){
    text_layer_set_text(enemy_layer, "Groupe de Soldat");
    enmeyhealt = 1000;
    enmeyforce = 25;
    enmeyarmure = 10;
    winzix = 5000;
    failzix = 2500;
    winrate = 200;
    failrate = 100;
  }
  if(nb == 10 && test == true){
    text_layer_set_text(enemy_layer, "Troll");
    enmeyhealt = 150;
    enmeyforce = 5;
    enmeyarmure = 2;
    winzix = 500;
    failzix = 250;
    winrate = 50;
    failrate = 25;
  }
    Fhealt();
    Ffroce();
    Farmure();
    Fmehealt();
    Fmemana();
    test = false;
}

//Attaque
static void select_click_handler(ClickRecognizerRef recognizer, void *context) {
        if(enmeyarmure > meforce) mehealt = (mehealt - (enmeyforce-mearmure));
        else if(mearmure >enmeyforce) enmeyhealt = (enmeyhealt - (meforce-enmeyarmure));
        else{
        enmeyhealt = (enmeyhealt - (meforce-enmeyarmure));
        mehealt = (mehealt - (enmeyforce-mearmure));
        }
        if(enmeyhealt <= 0){
        zix += winzix;
        rate += winrate;
        persist_write_int(ZIX_PKEY, zix);
        persist_write_int(RATE_PKEY, rate);
        persist_write_int(HEALT_PKEY, mehealt);
        persist_write_int(MANA_PKEY, memana);
        test = true;
        window_stack_remove(s_window, true);
        show_first();
        }
        if(mehealt <= 0){
        rate -= failrate;
        zix -= failzix;
        persist_write_int(ZIX_PKEY, zix);
        persist_write_int(RATE_PKEY, rate);
        persist_write_int(HEALT_PKEY, mehealt);
        persist_write_int(MANA_PKEY, memana);
        test = true;
        window_stack_remove(s_window, true);
        show_first();
        }
  Fhealt();
  Fmehealt();
}

//Spell
static void up_click_handler(ClickRecognizerRef recognizer, void *context) {
  
}
//Inventory
static void down_click_handler(ClickRecognizerRef recognizer, void *context) {
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
  test = true;
}
void show_battle(int nb, short bonus) {
  initialise_ui();
  var();
  modif(nb, bonus);
  window_set_click_config_provider(s_window, click_config_provider);
  window_set_window_handlers(s_window, (WindowHandlers) {
    .unload = handle_window_unload,
  });
  window_stack_push(s_window, true);
}

void hide_battle(void) {
  persist_write_int(ZIX_PKEY, zix);
  persist_write_int(RATE_PKEY, rate);
  persist_write_int(HEALT_PKEY, mehealt);
  persist_write_int(MANA_PKEY, memana);
  test = true;
  window_stack_remove(s_window, true);
}