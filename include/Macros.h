#pragma once
/*
  This file contains :
  #1. Symbols of the game objects.
  #2. macros of the paths to the sprites & sounds of game
  #3. macros of windows sizes.
  #4. states of the game objects.
*/
//========================== game const parameters ===========================
//games parameters
constexpr auto MOVEMENT_SPEED = 250;
constexpr auto MUSIC_VOLUME = 50;
constexpr auto RAND_ENEMY_TIME = 1;

// game objects symbols
constexpr auto PLAYER = '@';
constexpr auto ENEMY = '%';
constexpr auto FOOD = '*';
constexpr auto ROAD = '#';
constexpr auto NOTHING = ' ';
constexpr auto TRASH = 'T';

//menu answers
constexpr auto QUIT_GAME = 'Q';
constexpr auto PLAY_GAME = 'P';
constexpr auto NONE_CHOSEN = 'N';

//========================== game objects states ============================
//MovingObject spritesheets consts
constexpr auto STAND = 0;
constexpr auto NUM_OF_STAND_SPRITE = 1;
constexpr auto JUMPING = 1;
constexpr auto NUM_OF_JUMP_SPRITE = 3;
constexpr auto RUNNING = 4;
constexpr auto NUM_OF_RUNNING_SPRITE = 8;
constexpr auto FALLING = 2;
constexpr auto NUM_OF_FALLING_SPRITE = 2;

constexpr auto CHARACTER_HEIGHT = 128;
constexpr auto CHARACTER_WIDTH = 128;

constexpr auto ANIMATIONS_RATE = 0.1f;
constexpr auto WALK_LEFT = 1;
constexpr auto WALK_RIGHT = 2;
//food
constexpr auto NOT_COLLECTED = 6;
constexpr auto COLLECTED = 7;

//special food
constexpr auto TIME_BONUS = 0;
constexpr auto ADD_SCORE = 1;
constexpr auto ADD_LIFE = 2;
constexpr auto INVISIBLE = 3;
//=============================== game rules =================================

constexpr auto NUM_OF_LIFE = 3;
constexpr auto NO_LEVEL_TIME = -1;
constexpr auto NUM_OF_FOOD_TYPES = 4;
constexpr auto NUM_OF_ENEMIES_TYPES = 3;

//============================== gift bonuses ================================
constexpr auto BONUS_TIME = 20;
constexpr auto BONUS_SCORE = 20;
constexpr auto BONUS_LIFE = 1;

//============================  map's file path ==============================
//-------------------------- data files section ------------------------------
constexpr auto BOARD_PATH = "Levels.txt";

//---------------------------------- fonts -----------------------------------
constexpr auto ARIEL_FONT_PATH = "ARIALBD.TTF";

//---------------------------- picture section -------------------------------
constexpr auto MENU_BACKGROUND_PATH = "MenuBackground.jpg";
constexpr auto LEVEL1_BACKGROUND_PATH = "level1.jpeg";
constexpr auto LEVEL2_BACKGROUND_PATH = "level2.png";
constexpr auto LEVEL3_BACKGROUND_PATH = "level3.jpeg";
constexpr auto LEVEL4_BACKGROUND_PATH = "level4.jpeg";

constexpr auto PLAYER_PATH = "player.png";
constexpr auto SCOOTER_PATH = "scooter.png";
constexpr auto EXTERMINATOR_PATH = "exterminator.png";
constexpr auto OLD_WOMAN_PATH = "old_woman.png";
constexpr auto REGULAR_FOOD_PATH = "regular_food.png";
constexpr auto TOXIC_FOOD_PATH = "toxic_food.png";
constexpr auto SPECIAL_FOOD_PATH = "special_food.png";
constexpr auto ROAD_PATH = "road.png";
constexpr auto GAME_STATE_PATH = "game_state.jpg";
//--------------------------------- musics -----------------------------------
constexpr auto MENU_MUSIC_PATH = "menuMusic.ogg";
constexpr auto LEVEL1_MUSIC_PATH = "level1Music.ogg";
constexpr auto LEVEL2_MUSIC_PATH = "level2Music.ogg";
constexpr auto LEVEL3_MUSIC_PATH = "level3Music.ogg";
constexpr auto LEVEL4_MUSIC_PATH = "level4Music.ogg";

//--------------------------------- sounds -----------------------------------
constexpr auto REGULAR_FOOD_SOUND_PATH = "regular_foodSound.wav";
constexpr auto TOXIC_FOOD_SOUND_PATH = "toxic_foodSound.wav";
constexpr auto SPECIAL_FOOD_SOUND_PATH = "special_foodSound.wav";
constexpr auto JUMP_SOUND_PATH = "jumpSound.wav";
constexpr auto FALLING_SOUND_PATH = "fallingSound.wav";
constexpr auto STEP_SOUND_PATH = "stepSound.wav";
constexpr auto EXTERMINATOR_SOUND_PATH = "exterminatorSound.wav";
constexpr auto SCOOTER_SOUND_PATH = "scooterSound.wav";
constexpr auto OLD_WOMAN_SOUND_PATH = "old_womanSound.wav";
//---------------------------------- logos -----------------------------------
constexpr auto GAME_LOGO_PATH = "Logo.png";

//============================ game files consts =============================
//-------------------------------- textures ----------------------------------
//------------------------------- backgrounds --------------------------------
constexpr auto MENU_BACKGROUND = 1;
constexpr auto LEVEL_BACKGROUND = 2;
constexpr auto GAME_STATE = 9;
//------------------------------- objects -------------------------------------
constexpr auto PLAYER_T = 10;
constexpr auto SCOOTER_T = 11;
constexpr auto EXTERMINATOR_T = 12;
constexpr auto OLD_WOMAN_T = 13;
constexpr auto REGULAR_FOOD_T = 14;
constexpr auto TOXIC_FOOD_T = 15;
constexpr auto SPECIAL_FOOD_T = 16;
constexpr auto ROAD_T = 17;

//--------------------------------- sounds -----------------------------------
constexpr auto REGULAR_FOOD_SOUND = 0;
constexpr auto TOXIC_FOOD_SOUND = 1;
constexpr auto SPECIAL_FOOD_SOUND = 2;
constexpr auto JUMP_SOUND = 3;
constexpr auto FALLING_SOUND = 4;
constexpr auto STEP_SOUND = 5;
constexpr auto EXTERMINATOR_SOUND = 6;
constexpr auto SCOOTER_SOUND = 7;
constexpr auto OLD_WOMAN_SOUND = 8;
//--------------------------------- logos ------------------------------------
constexpr auto GAME_LOGO = 26;

//---------------------------------- fonts -----------------------------------
constexpr auto ARIEL_FONT = 1;
