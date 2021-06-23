#pragma once
#include <box2d/box2d.h>
/*
  This file contains :
  #1. Symbols of the game objects.
  #2. macros of the paths to the sprites & sounds of game
  #3. macros of windows sizes.
  #4. states of the game objects.
*/
//========================== game const parameters ===========================
//games parameters
constexpr auto MOVEMENT_SPEED = 10.f;
constexpr auto MUSIC_VOLUME = 50;
constexpr auto RAND_ENEMY_TIME = 1;

// game objects symbols
constexpr auto PLAYER = '@';
constexpr auto EXTERMINATOR = 'E';
constexpr auto OLD_WOMAN = 'W';
constexpr auto SCOOTER = 'S';
constexpr auto SPECIAL_FOOD = 'O';
constexpr auto REGULAR_FOOD = 'o';
constexpr auto TOXIC_FOOD = '*';
constexpr auto ROAD = '#';
constexpr auto ADANIT = '-';
constexpr auto DYNAMIC_FLOOR = '_';
constexpr auto NOTHING = ' ';
constexpr auto TRASH = 'T';
constexpr auto PORTAL_TRASH = 't';
//========================== game objects states ============================
//MovingObject spritesheets consts
//enum to define movement directions of all moving objects (Enemies will not use up/down)
enum ANIMATION_DIRECTIONS { LEFT = 0, RIGHT};
enum ANIMATION_STATE { IDLE = 0, RUN, JUMP, DIE, FALL};
enum EXTERMINATOR_COLLISION { NOT_COLLIDED=0, TRASH_C, ADANIT_C, ROAD_C};
constexpr auto NUM_OF_IDLE_SPRITE = 11;
constexpr auto NUM_OF_JUMP_SPRITE = 12;
constexpr auto NUM_OF_RUNNING_SPRITE = 13;
constexpr auto NUM_OF_DIE_SPRITE = 5;

constexpr auto CHARACTER_HEIGHT = 732;
constexpr auto CHARACTER_WIDTH = 648.6153846154;

constexpr auto ANIMATIONS_RATE = 0.1f;

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
constexpr auto NUM_OF_FOOD_TYPES = 3;
constexpr auto NUM_OF_ENEMIES_TYPES = 3;

//============================== special food bonuses ================================
constexpr auto BONUS_TIME = 20;
constexpr auto BONUS_SCORE = 20;
constexpr auto BONUS_LIFE = 1;

//============================  map's file path ==============================
//-------------------------- data files section ------------------------------
constexpr auto BOARD_PATH = "Levels.txt";

//---------------------------------- fonts -----------------------------------
constexpr auto ARIEL_FONT_PATH = "ARIALBD.TTF";

//---------------------------- picture section -------------------------------
constexpr auto MENU_BACKGROUND_PATH = "MenuBackground.png";
constexpr auto MAIN_MENU_BACKGROUND_PATH = "MainMenuBackground.png";
constexpr auto LIFE_T_PATH = "life.png";

constexpr auto MENU_PATH = "RATBlack.jpg";
constexpr auto HIGHMENU_PATH = "High Score Menu.png";
constexpr auto HELPMENU_PATH = "backgrounds.jpg";

constexpr auto LEVEL1_BACKGROUND_PATH = "level1.jpeg";
constexpr auto LEVEL2_BACKGROUND_PATH = "level2.png";
constexpr auto LEVEL3_BACKGROUND_PATH = "level3.jpeg";
constexpr auto LEVEL4_BACKGROUND_PATH = "level4.jpeg";

constexpr auto PLAYER_PATH = "player.png";
constexpr auto SCOOTER_PATH = "scooter.png";
constexpr auto EXTERMINATOR_PATH = "exterminator.png";
constexpr auto BANANA_PATH = "banana.png";
constexpr auto PIZZA_PATH = "pizza.png";
constexpr auto WATERMELON_PATH = "watermelon.png";
constexpr auto APPLE_PATH = "apple.png";
constexpr auto BURGER_PATH = "burger.png";
constexpr auto ROAD_PATH = "road.png";
constexpr auto ADANIT_KAHOL_PATH = "adanitKahol.png";
constexpr auto ADANIT_SAGOL_PATH = "adanitSagol.png";
constexpr auto ADANIT_KATOM_PATH = "adanitKatom.png";
constexpr auto DYNAMIC_FLOOR_PATH = "dynamicFloor.png";
constexpr auto GAME_STATE_PATH = "game_state.jpg";
constexpr auto TRASH_BLUE_PATH = "trashBlue.png";
constexpr auto TRASH_RED_PATH = "trashRed.png";
constexpr auto PORTAL_TRASH_PATH = "portalTrash.png";

constexpr auto BACK = "Back.png";
constexpr auto HI_SCORE = "Hi Score.png";
constexpr auto INFO = "Info.png";
constexpr auto NEW_GAME = "New Game.png";

constexpr auto EXIT = "Exit.png";
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
//---------------------------- sprite sheet control --------------------------
//player:
constexpr auto PLAYER_BOX_WIDTH = 626;
constexpr auto PLAYER_BOX_HEIGHT = 534;
constexpr auto PLAYER_OFFSET = 230;
constexpr auto PLAYER_SPECIAL_OFFSET = 320;

//-------------------------------- textures ----------------------------------
//------------------------------- backgrounds --------------------------------
constexpr auto MENU_BACKGROUND = 1;
constexpr auto LEVEL_BACKGROUND = 2;
constexpr auto MENU = 3;
constexpr auto LIVES = 3;
constexpr auto HIGHMENU = 4;
constexpr auto HELPMENU = 5;
constexpr auto GAME_STATE = 9;
constexpr auto MAIN_MENU_BACKGROUND = 27;
constexpr auto BACKGROUND_WIDTH = 7185; //pixels
constexpr auto BACKGROUND_HEIGHT = 1582;

///statboard
constexpr auto STAT_WIDTH = 0;
constexpr auto STAT_HEIGHT = 60;
//--
constexpr auto BACK_KEY = 6;
constexpr auto HI_SCORE_KEY = 7;
constexpr auto INFO_KEY = 8;
constexpr auto NEW_GAME_KEY = 9;
constexpr auto HI_MENU_KEY = 10;
constexpr auto EXIT_KEY = 28;

//--
const std::string STATS[] = {"Level: ","Score: ","Lives: ", "Time: "};
//------------------------------- objects -------------------------------------
//characters
constexpr auto PLAYER_T = 10;
constexpr auto SCOOTER_T = 11;
constexpr auto EXTERMINATOR_T = 12;
constexpr auto OLD_WOMAN_T = 13;
//food
constexpr auto APPLE_T = 15;
constexpr auto BURGER_T = 16;
constexpr auto WATERMELON_T = 23;
constexpr auto BANANA_T = 24;
constexpr auto PIZZA_T = 25;
//statics
constexpr auto ROAD_T = 17;
constexpr auto TRASH_RED_T = 18;
constexpr auto TRASH_BLUE_T = 19;
constexpr auto ADANIT_KAHOL_T = 20;
constexpr auto ADANIT_SAGOL_T = 21;
constexpr auto ADANIT_KATOM_T = 22;
constexpr auto DYNAMIC_FLOOR_T = 26;
constexpr auto PORTAL_TRASH_T = 30;
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

//---------------------------------- fonts -----------------------------------
constexpr auto ARIEL_FONT = 1;
//---------------------------------- Physics ---------------------------------
//Box2D Parameters:
const float PPM = 64.f;
const float MPP = 0.015625f;
const float TIMESTEP = 1.0f / 60.0f;
const int VELITER = 6;
const int POSITER = 2;
const bool STATIC = false;
const bool DYNAMIC = true;
const float WORLD_GRAVITY = 9.81;
const float MAX_JUMP = 50;
const float ON_GROUND = 0;
//player velocity
const b2Vec2 MUP(0, -6);
const b2Vec2 MRIGHT (2, 0);
const b2Vec2 MLEFT (-2, 0);
const b2Vec2 MDOWN (0, 8);
//enemy velocity
const b2Vec2 EMUP(0, -3);
const b2Vec2 EMRIGHT(1, 0);
const b2Vec2 EMLEFT(-1, 0);
const b2Vec2 EMDOWN(0, 4);

const float ENEMY_DISTANCE_LIMIT = 20.f;

///for menu
const int WIN_WIDTH = 1920;
const int WIN_HEIGHT = 1080;

const int MSG_WIDTH = 100;
const int MSG_HEIGHT = 200;

//
const auto BACK_X_POS = 30;
const auto HISCORE_X_POS = 160;
const auto INFO_X_POS = 390;
const auto STATS_Y_POS = 700;

const auto HEART_WIDTH = 117;
const auto LIFE_T = 29;
//
//for sounds
const auto AUDIOS = 13;
const auto VOL = 30;
