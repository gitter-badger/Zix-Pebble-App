#include "quest.h"
#include "battle.h"
#include "first.h"
#include "random.h"
#include "kight.h"
#include "crusade.h"
#include <pebble.h>

#define ZIX_PKEY 217
#define RATE_PKEY 222
  
static int RandomNb = 0;
static int zix = 0;
static int rate = 1;

// BEGIN AUTO-GENERATED UI CODE; DO NOT MODIFY
static Window *s_window;
static GBitmap *s_res_image_yes;
static GBitmap *s_res_image_quest;
static GBitmap *s_res_image_no;
static GFont s_res_gothic_24_bold;
static ActionBarLayer *actionbar_quest;
static TextLayer *layer_1;
static TextLayer *layer_2;
static TextLayer *layer_3;
static TextLayer *layer_4;
static TextLayer *layer_5;
static BitmapLayer *s_bitmaplayer_1;
static TextLayer *s_textlayer_1;
static TextLayer *s_textlayer_2;
static InverterLayer *s_inverterlayer_1;

static void initialise_ui(void) {
  s_window = window_create();
  window_set_fullscreen(s_window, false);
  
  s_res_image_yes = gbitmap_create_with_resource(RESOURCE_ID_IMAGE_YES);
  s_res_image_quest = gbitmap_create_with_resource(RESOURCE_ID_IMAGE_QUEST);
  s_res_image_no = gbitmap_create_with_resource(RESOURCE_ID_IMAGE_NO);
  s_res_gothic_24_bold = fonts_get_system_font(FONT_KEY_GOTHIC_24_BOLD);
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
  text_layer_set_text_alignment(layer_2, GTextAlignmentCenter);
  layer_add_child(window_get_root_layer(s_window), (Layer *)layer_2);
  
  // layer_3
  layer_3 = text_layer_create(GRect(4, 98, 116, 24));
  text_layer_set_background_color(layer_3, GColorClear);
  text_layer_set_text_alignment(layer_3, GTextAlignmentCenter);
  layer_add_child(window_get_root_layer(s_window), (Layer *)layer_3);
  
  // layer_4
  layer_4 = text_layer_create(GRect(4, 111, 120, 32));
  text_layer_set_background_color(layer_4, GColorClear);
  text_layer_set_text_alignment(layer_4, GTextAlignmentCenter);
  layer_add_child(window_get_root_layer(s_window), (Layer *)layer_4);
  
  // layer_5
  layer_5 = text_layer_create(GRect(4, 124, 119, 23));
  text_layer_set_background_color(layer_5, GColorClear);
  text_layer_set_text_alignment(layer_5, GTextAlignmentCenter);
  layer_add_child(window_get_root_layer(s_window), (Layer *)layer_5);
  
  // s_bitmaplayer_1
  s_bitmaplayer_1 = bitmap_layer_create(GRect(7, 2, 111, 62));
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_bitmaplayer_1);
  
  // s_textlayer_1
  s_textlayer_1 = text_layer_create(GRect(11, 8, 101, 26));
  text_layer_set_text(s_textlayer_1, "Difficulty");
  text_layer_set_font(s_textlayer_1, s_res_gothic_24_bold);
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_textlayer_1);
  
  // s_textlayer_2
  s_textlayer_2 = text_layer_create(GRect(12, 39, 103, 20));
  text_layer_set_text(s_textlayer_2, "* * * * * * * * * *");
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_textlayer_2);
  
  // s_inverterlayer_1
  s_inverterlayer_1 = inverter_layer_create(GRect(7, 5, 111, 58));
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_inverterlayer_1);
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
  text_layer_destroy(s_textlayer_1);
  text_layer_destroy(s_textlayer_2);
  inverter_layer_destroy(s_inverterlayer_1);
  gbitmap_destroy(s_res_image_yes);
  gbitmap_destroy(s_res_image_quest);
  gbitmap_destroy(s_res_image_no);
}
// END AUTO-GENERATED UI CODE

static void RandomQuest(){
  RandomNb = rand()%10;
  if(RandomNb == 0){
    RandomNb = 0;
    text_layer_set_text(s_textlayer_2, "* * *");
    text_layer_set_text(layer_1, "Un ogre");
    text_layer_set_text(layer_2, "mange les");
    text_layer_set_text(layer_3, "plantation des");
    text_layer_set_text(layer_4, "paysans. Vous");
    text_layer_set_text(layer_5, "devez les aides!");
  }
  if(RandomNb == 1){
    RandomNb = 1;
    text_layer_set_text(s_textlayer_2, "No difficulty");
    text_layer_set_text(layer_1, "Une dame vous");
    text_layer_set_text(layer_2, "demande 1000 zix");
    text_layer_set_text(layer_3, "pour peut-être");
    text_layer_set_text(layer_4, "gagnier un");
    text_layer_set_text(layer_5, "manifique prix !");
  }
  if(RandomNb == 2){
    RandomNb = 2;
    text_layer_set_text(s_textlayer_2, "No difficulty");
    text_layer_set_text(layer_1, "Un sombre homme");
    text_layer_set_text(layer_2, "vous offres une");
    text_layer_set_text(layer_3, "une vielle carte au");
    text_layer_set_text(layer_4, "trésor pour la");
    text_layer_set_text(layer_5, "somme de 2 000 zix.");
  }
  if(RandomNb == 3){
    RandomNb = 3;
    text_layer_set_text(s_textlayer_2, "No difficulty");
    text_layer_set_text(layer_1, "La princesse du");
    text_layer_set_text(layer_2, "royaume veut");
    text_layer_set_text(layer_3, "vous parler.");
    text_layer_set_text(layer_4, "Voulez-vous aller");
    text_layer_set_text(layer_5, "le rencontrer.");
  }
  if(RandomNb == 4){
    RandomNb = 4;
    text_layer_set_text(s_textlayer_2, "* * * * * * *");
    text_layer_set_text(layer_1, "Un homme a monté");
    text_layer_set_text(layer_2, "la montagne, mais");
    text_layer_set_text(layer_3, "il n'est pas");
    text_layer_set_text(layer_4, "toujours revenu.");
    text_layer_set_text(layer_5, "Sauvé le!");
  }
  if(RandomNb == 5){
    RandomNb = 5;
    text_layer_set_text(s_textlayer_2, "* *");
    text_layer_set_text(layer_1, "Des bandits");
    text_layer_set_text(layer_2, "pille les maisons");
    text_layer_set_text(layer_3, "du village.");
    text_layer_set_text(layer_4, "Vous devez");
    text_layer_set_text(layer_5, "les arrêter!");
  }
  if(RandomNb == 6){
    RandomNb = 6;
    text_layer_set_text(s_textlayer_2, "* * * * * * *");
    text_layer_set_text(layer_1, "On vous propose");
    text_layer_set_text(layer_2, "d'assasiné");
    text_layer_set_text(layer_3, "le roi!");
    text_layer_set_text(layer_4, "Voulez-vous");
    text_layer_set_text(layer_5, "les suivrents");
  }
  if(RandomNb == 7){
    RandomNb = 7;
    text_layer_set_text(s_textlayer_2, "* * * * *");
    text_layer_set_text(layer_1, "Des assasins");
    text_layer_set_text(layer_2, "vous attaque!");
    text_layer_set_text(layer_3, "Défendez-vous (Y)");
    text_layer_set_text(layer_4, "ou fuillé (N).");
    text_layer_set_text(layer_5, "");
  }
  if(RandomNb == 8){
    RandomNb = 8;
    text_layer_set_text(s_textlayer_2, "* * * * * * * * * *");
    text_layer_set_text(layer_1, "Le roi");
    text_layer_set_text(layer_2, "vous demende");
    text_layer_set_text(layer_3, "pour entreprendre");
    text_layer_set_text(layer_4, "une croisade.");
    text_layer_set_text(layer_5, "Asseptez-vous?");
  }
  if(RandomNb == 9){
    RandomNb = 9;
    text_layer_set_text(s_textlayer_2, "* * * * * * * * *");
    text_layer_set_text(layer_1, "Votre royaume");
    text_layer_set_text(layer_2, "déclare la guerre");
    text_layer_set_text(layer_3, "au royaume voisin.");
    text_layer_set_text(layer_4, "Voulez-vous");
    text_layer_set_text(layer_5, "dever les aides!");
  }
  if(RandomNb == 10){
    RandomNb = 10;
    text_layer_set_text(s_textlayer_2, "* * * * *");
    text_layer_set_text(layer_1, "Un troll");
    text_layer_set_text(layer_2, "est au porte");
    text_layer_set_text(layer_3, "du village, en");
    text_layer_set_text(layer_4, "colaire. Vous");
    text_layer_set_text(layer_5, "devez les aides!");
  }
}
static void select_click_handler(ClickRecognizerRef recognizer, void *context) {
    RandomQuest();
}
static void up_click_handler(ClickRecognizerRef recognizer, void *context) {
  if(RandomNb == 0){  
  show_battle(RandomNb, 0); // Orge
  }
  if(RandomNb == 1){
  zix -=1000;
  show_random();
  }
  if(RandomNb == 2){  //Homme
  zix -=2000;
  show_random();
  }
  if(RandomNb == 3){  
  // Faire un randome combat de 5 ennemis
  show_battle(RandomNb,0); 
  }
  if(RandomNb == 4){  
  show_battle(RandomNb,0); // Contre un dragon
  }
  if(RandomNb == 5){ 
  show_battle(RandomNb,0); // Bandit
  }
  if(RandomNb == 6){  
  show_kight(); // La grande quest
  }
  if(RandomNb == 7){  
  show_battle(RandomNb,0);  //Assasin
  }
  if(RandomNb == 8){  
  show_crusade(); // La grande croisade
  }
  if(RandomNb == 9){  
  show_battle(RandomNb,0); // Combat contre quelque soldat de suite
  }
  if(RandomNb == 10){  
  show_battle(RandomNb,0); // Un troll très fort bon lut
  }
}
static void down_click_handler(ClickRecognizerRef recognizer, void *context) {
    if(RandomNb == 0){  
    text_layer_set_text(layer_1, "Le roi");
    text_layer_set_text(layer_2, "vous propose");
    text_layer_set_text(layer_3, "propose un cadeau");
    text_layer_set_text(layer_4, "si vous tuer cette ogre !");
    text_layer_set_text(layer_5, "");
      show_battle(RandomNb, 1); // Orge
    }
    if(RandomNb == 1){
  }
  if(RandomNb == 2){
    text_layer_set_text(layer_1, "Je vous");
    text_layer_set_text(layer_2, "la fait");
    text_layer_set_text(layer_3, "pour 1 000 zix!");
    text_layer_set_text(layer_4, "");
    text_layer_set_text(layer_5, "");
  }
  if(RandomNb == 3){
    text_layer_set_text(layer_1, "C'est");
    text_layer_set_text(layer_2, "urgent !");
    text_layer_set_text(layer_3, "");
    text_layer_set_text(layer_4, "");
    text_layer_set_text(layer_5, "");
  }
  if(RandomNb == 4){
    text_layer_set_text(layer_1, "Maleur");
    text_layer_set_text(layer_2, "a vous!");
    text_layer_set_text(layer_3, "");
    text_layer_set_text(layer_4, "");
    text_layer_set_text(layer_5, "");
  }
  if(RandomNb == 5){
    text_layer_set_text(layer_1, "Les bandits");
    text_layer_set_text(layer_2, "vous on volé");
    text_layer_set_text(layer_3, "5 0000 zix!");
    text_layer_set_text(layer_4, "");
    text_layer_set_text(layer_5, "");
    zix -= 5000;
  }
  if(RandomNb == 6){
    text_layer_set_text(layer_1, "L'homme vous");
    text_layer_set_text(layer_2, "attaque!");
    text_layer_set_text(layer_3, "défender vous!");
    text_layer_set_text(layer_4, "");
    text_layer_set_text(layer_5, "");
    psleep(5000);
    show_battle(RandomNb, 1);
  }
  if(RandomNb == 7){
    text_layer_set_text(layer_1, "Vous");
    text_layer_set_text(layer_2, "n'est qu'un");
    text_layer_set_text(layer_3, "lache. Votre");
    text_layer_set_text(layer_4, "honneur est ");
    text_layer_set_text(layer_5, "de 0.");
    rate = 0;
  }
  if(RandomNb == 8){
    text_layer_set_text(layer_1, "Vous");
    text_layer_set_text(layer_2, "n'est qu'un");
    text_layer_set_text(layer_3, "lache. Votre");
    text_layer_set_text(layer_4, "honneur est ");
    text_layer_set_text(layer_5, "de 0.");
    rate = 0;
  }
  if(RandomNb == 9){
    text_layer_set_text(layer_1, "Un ogre");
    text_layer_set_text(layer_2, "mange les");
    text_layer_set_text(layer_3, "plantation des");
    text_layer_set_text(layer_4, "paysans. Vous");
    text_layer_set_text(layer_5, "dever les aides!");
  }
  if(RandomNb == 10){
    text_layer_set_text(layer_1, "Le troll");
    text_layer_set_text(layer_2, "a détruit toute");
    text_layer_set_text(layer_3, "les maisons");
    text_layer_set_text(layer_4, "à l'extérieur. Vous");
    text_layer_set_text(layer_5, "dever les aides!");
  }
}
static void modif(){
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
}
static void click_config_provider(void *context) {
  window_single_click_subscribe(BUTTON_ID_SELECT, select_click_handler);
  window_single_click_subscribe(BUTTON_ID_UP, up_click_handler);
  window_single_click_subscribe(BUTTON_ID_DOWN, down_click_handler);
}

static void handle_window_unload(Window* window) {
  destroy_ui();
}

void show_quest() {
  initialise_ui();
  modif();
  RandomQuest();
  window_set_click_config_provider(s_window, click_config_provider);
  window_set_window_handlers(s_window, (WindowHandlers) {
    .unload = handle_window_unload,
  });
  window_stack_push(s_window, true);
}

void hide_quest(void) {
  window_stack_remove(s_window, true);
}
