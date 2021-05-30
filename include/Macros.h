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
constexpr auto COIN = '*';
constexpr auto WALL = '#';
constexpr auto NOTHING = ' ';
constexpr auto LADDER = 'H';
constexpr auto ROD = '-';
constexpr auto PLAYER_ON_LADDER = 'S';
constexpr auto GIFT = '+';
constexpr auto DOOR = 'D';

//menu answers
constexpr auto QUIT_GAME = 'Q';
constexpr auto PLAY_GAME = 'P';
constexpr auto NONE_CHOSEN = 'N';

//========================== game objects states ============================
//MovingObject pritesheets consts
constexpr auto STAND = 0;
constexpr auto NUM_OF_STAND_SPRITE = 1;
constexpr auto CLIMBING = 1;
constexpr auto NUM_OF_CLIMB_SPRITE = 3;
constexpr auto RUNNING = 4;
constexpr auto NUM_OF_RUNNING_SPRITE = 8;
constexpr auto RODDING = 3;
constexpr auto NUM_OF_RODDING_SPRITE = 8;
constexpr auto FALLING = 2;
constexpr auto NUM_OF_FALLING_SPRITE = 2;

constexpr auto CHARACTER_HEIGHT = 128;
constexpr auto CHARACTER_WIDTH = 128;

constexpr auto DIGG_DURATION = 3.f;
constexpr auto ANIMATIONS_RATE = 0.1f;
constexpr auto WALK_LEFT = 1;
constexpr auto WALK_RIGHT = 2;
//coin
constexpr auto NOT_COLLECTED = 6;
constexpr auto COLLECTED = 7;
//wall
//constexpr auto EXIST = 8;
//constexpr auto DIGGED = 9;
//ladder/rod
constexpr auto CLIMBED = 10;
constexpr auto NOT_CLIMBED = 11;
//gift
constexpr auto TIME_BONUS = 0;
constexpr auto ADD_SCORE = 1;
constexpr auto ADD_LIFE = 2;
constexpr auto ADD_ENEMY = 3;
//=============================== game rules =================================

constexpr auto NUM_OF_LIFE = 3;
constexpr auto NO_LEVEL_TIME = -1;
constexpr auto NUM_OF_GIFT_TYPES = 4;
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
constexpr auto ENEMY_PATH = "enemy.png";
constexpr auto COIN_PATH = "coin.png";
constexpr auto WALL_PATH = "wall.png";
constexpr auto LADDER_PATH = "ladder.png";
constexpr auto ROD_PATH = "rod.png";
constexpr auto GIFT_PATH = "gift.png";
constexpr auto DOOR_PATH = "door.png";
constexpr auto GAME_STATE_PATH = "game_state.jpg";
//--------------------------------- musics -----------------------------------
constexpr auto MENU_MUSIC_PATH = "menuMusic.ogg";
constexpr auto LEVEL1_MUSIC_PATH = "level1Music.ogg";
constexpr auto LEVEL2_MUSIC_PATH = "level2Music.ogg";
constexpr auto LEVEL3_MUSIC_PATH = "level3Music.ogg";
constexpr auto LEVEL4_MUSIC_PATH = "level4Music.ogg";

//--------------------------------- sounds -----------------------------------
constexpr auto COINS_SOUND_PATH = "coinSound.wav";
constexpr auto DIG_SOUND_PATH = "DiggingSound.wav";
constexpr auto FALLING_SOUND_PATH = "fallingSound.wav";
constexpr auto DOOR_SOUND_PATH = "DoorSound.wav";
constexpr auto STEP_SOUND_PATH = "stepSound.wav";
constexpr auto ENEMY_SOUND_PATH = "enemySound.wav";
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
constexpr auto ENEMY_T = 11;
constexpr auto COIN_T = 12;
constexpr auto WALL_T = 13;
constexpr auto LADDER_T = 14;
constexpr auto ROD_T = 15;
constexpr auto GIFT_T = 16;
constexpr auto DOOR_T = 17;

//--------------------------------- sounds -----------------------------------
constexpr auto DIGGING_SOUND = 0;
constexpr auto COIN_COLLECT_SOUND = 1;
constexpr auto FALLING_SOUND = 2;
constexpr auto DOOR_SOUND = 3;
constexpr auto STEP_SOUND = 4;
constexpr auto ENEMY_SOUND = 5;
//--------------------------------- logos ------------------------------------
constexpr auto GAME_LOGO = 26;

//---------------------------------- fonts -----------------------------------
constexpr auto ARIEL_FONT = 1;
