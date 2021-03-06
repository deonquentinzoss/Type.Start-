#include "Setup.h"
#include<SDL2/SDL_mixer.h>

Uint32 LETTER_LIFETIME;
double OFFSET;
double SCALESIZE;
double LEVEL_ONE_SPEED;
double LEVEL_SPEED_INCREASE;
double LETTER_SLOW_SPEED;
double WALKING_SPEED;
double WALKING_ANIMATION_CHANGE_SPEED;
double SCREEN_ORIG_WIDTH;
double SCREEN_ORIG_HEIGHT;
double SCREEN_WIDTH;
double SCREEN_HEIGHT;
double TEXT_ROW_OFFSET;
double MULTIPLIER_Y;
double MULTIPLIER_X;
SDL_Color CODE_COLOR;
SDL_Color SHADOW_COLOR;
char CODE_FONT[30];
double SCOREBOARDX;
double SCOREBOARDY;
double SCOREBOARD_FONT_SIZE;
double SCREEN_STARTING_YPOS;
double SCREEN_STARTING_XPOS;
double SCREEN_END_YPOS;
double TEXT_SIZE;
int  NUM_TEXT_ROWS;
int MAX_TEXT_LENGTH;
int FLAG_XPOS;
int FLAG_YPOS;
double MAIN_MENU_FONT_SIZE;
SDL_Color MENU_FONT_COLOR;
SDL_Color MENU_SHADOW_FONT_COLOR;
double TIP_TEXT_XPOS;
double TIP_TEXT_YPOS;
double MENU_FRAMES_SPAWN_Y;
double CHARACTER_SCORE_X;
double CHARACTER_SCORE_Y;
double CHARACTER_SCORE_FONT_SIZE;
int LETTER_TYPED_SCORE;
double GROUND_VALUE;
double MAIN_CHARACTER_OBJECT_Y;
double MAIN_CHARACTER_OBJECT_X;
double MAIN_CHARACTER_OBJECT_W;
double MAIN_CHARACTER_OBJECT_H;
double MAIN_CHARACTER_DESK_SPAWN_Y;
double MAIN_CHARACTER_DESK_SPAWN_X;
double COWORKER_OBJECT_Y;
double COWORKER_OBJECT_X;
double COWORKER_OBJECT_W;
double COWORKER_OBJECT_H;
double COWORKER_SPAWN_X;
double COWORKER_SPAWN_Y;
double COWORKER_COMPUTER_X;
double COWORKER_COMPUTER_Y;
double BOSS_OBJECT_Y;
double BOSS_OBJECT_X;
double BOSS_OBJECT_W;
double BOSS_OBJECT_H;
double BOSS_SPAWN_X;
double BOSS_SPAWN_Y;
int BOSS_BLINK_TIME;
int BOSS_BLINK_DURATION;
double TRASHCAN_SPAWN_X;
double TRASHCAN_SPAWN_Y;
double CLOCK_SPAWN_X;
double CLOCK_SPAWN_Y;
double DOOR_SPAWN_X;
double DOOR_SPAWN_Y;
double WINDOW_WORKER_X;
double WINDOW_WORKER_Y;
double WINDOW_WORKERS_X;
double WINDOW_WORKERS_Y;
double FOUNTAIN_SPAWN_X;
double FOUNTAIN_SPAWN_Y;
double LEFT_FOUNTAIN_HANDLE_SPAWN_X;
double LEFT_FOUNTAIN_HANDLE_SPAWN_Y;
double RIGHT_FOUNTAIN_HANDLE_SPAWN_X;
double RIGHT_FOUNTAIN_HANDLE_SPAWN_Y;
double TROPHY_SPAWN_X;
double TROPHY_HEIGHT;
double TROPHY_WIDTH;
  

bool init(){

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0){
		printf("SDL_Error: %s\n", SDL_GetError());
		return false;	
	}
	if(!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")){
		printf("Warning: Linear texture filtering not enabled!\n");
	}	
	

	int imgFlags = IMG_INIT_PNG;
	if(!(IMG_Init(imgFlags)&imgFlags)){
		printf("SDL_image error: %s\n", IMG_GetError());
		return false;	
	}

	if(TTF_Init() == -1){
		printf("SDL_ttf Error: %s\n", TTF_GetError());
		return false;
	}

  if(Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT,2,1024) == -1){
    return false;
  }
	
	
  return true;
}



bool loadMedia()
{
	return true;
}

void close(SDL_Window *window, SDL_Renderer *renderer)
{
	SDL_DestroyRenderer(renderer);	
	SDL_DestroyWindow(window);
	
	window = NULL;
	renderer = NULL;
	
	SDL_Quit();
	IMG_Quit();

}

bool setup(){
	if(!init()){
		printf("Failed to initialize!");
		return false;
	}
	if(!loadMedia()){
		return false;
	}
  
  Display* disp = XOpenDisplay(NULL);
  Screen*  scrn = DefaultScreenOfDisplay(disp);
  
  SCREEN_ORIG_WIDTH=192;
  SCREEN_ORIG_HEIGHT=108;
  SCREEN_HEIGHT= scrn->height;
  SCREEN_WIDTH  = scrn->width;
  SCALESIZE = SCREEN_HEIGHT/SCREEN_ORIG_HEIGHT;
  
  //SCALESIZE = 5;
  //SCREEN_HEIGHT= SCREEN_ORIG_HEIGHT*SCALESIZE;
  //SCREEN_WIDTH  = SCREEN_ORIG_WIDTH*SCALESIZE;
  
  OFFSET = 32*SCALESIZE;


  //SPEED
  LEVEL_ONE_SPEED = .2*SCALESIZE;
  LEVEL_SPEED_INCREASE = .02*SCALESIZE;
  LETTER_SLOW_SPEED = 10;
  WALKING_SPEED = .19*SCALESIZE;
  WALKING_ANIMATION_CHANGE_SPEED = 220;




  //SCREEN
  TEXT_ROW_OFFSET = 9*SCALESIZE;
  CODE_COLOR = {0xFF,0xFF,0xFF};//WHITE
  SHADOW_COLOR = {0, 0, 0};//BLACK
  SCOREBOARDX = OFFSET + 6*SCALESIZE;
  SCOREBOARDY = 6*SCALESIZE;
  SCOREBOARD_FONT_SIZE = 4*SCALESIZE;
  SCREEN_STARTING_XPOS = OFFSET;
  SCREEN_STARTING_YPOS = -50*SCALESIZE;
  SCREEN_END_YPOS = 2*SCALESIZE; 
  MULTIPLIER_Y = SCREEN_END_YPOS + 6*SCALESIZE;
  MULTIPLIER_X = OFFSET + 28*SCALESIZE;
  TEXT_SIZE = 4*SCALESIZE; 
  NUM_TEXT_ROWS = 10;
  MAX_TEXT_LENGTH = 20;
  FLAG_XPOS = OFFSET + 110*SCALESIZE;
  FLAG_YPOS = SCREEN_END_YPOS+46*SCALESIZE;



  //MAIN MENU STUFF
  MAIN_MENU_FONT_SIZE = 4*SCALESIZE;
  MENU_FONT_COLOR = {65, 111, 153};
  MENU_SHADOW_FONT_COLOR = {92, 109, 109};
  TIP_TEXT_XPOS = 20;
  TIP_TEXT_YPOS = 19;
  MENU_FRAMES_SPAWN_Y = 4*SCALESIZE;

  CHARACTER_SCORE_X = OFFSET + 13*SCALESIZE;	//initial coordinates for values to fly out of
  CHARACTER_SCORE_Y = 86*SCALESIZE;	//computer
  CHARACTER_SCORE_FONT_SIZE = 3*SCALESIZE;



  //SCORES
  LETTER_TYPED_SCORE = 10;

  //LIFETIMES
  LETTER_LIFETIME = 2000;

  //ENVIRONMENT VARIABLES
  GROUND_VALUE = (103*SCALESIZE)-TEXT_SIZE;

  //OBJECTS
  MAIN_CHARACTER_OBJECT_Y = 81;
  MAIN_CHARACTER_OBJECT_X = 11;
  MAIN_CHARACTER_OBJECT_W = MAIN_CHARACTER_OBJECT_X;
  MAIN_CHARACTER_OBJECT_H = 15;
  MAIN_CHARACTER_DESK_SPAWN_Y = GROUND_VALUE - 14*SCALESIZE;
  MAIN_CHARACTER_DESK_SPAWN_X = OFFSET;


  COWORKER_OBJECT_Y = 74;
  COWORKER_OBJECT_X = 52;
  COWORKER_OBJECT_W = 27;
  COWORKER_OBJECT_H = 23;
  COWORKER_SPAWN_X = OFFSET + 85*SCALESIZE;
  COWORKER_SPAWN_Y = 74*SCALESIZE;

  COWORKER_COMPUTER_X = OFFSET + 86*SCALESIZE;
  COWORKER_COMPUTER_Y = 74*SCALESIZE;

  BOSS_OBJECT_Y = 152;
  BOSS_OBJECT_X = 0;
  BOSS_OBJECT_W = 12;
  BOSS_OBJECT_H = 19;
  BOSS_SPAWN_X = OFFSET + 50*SCALESIZE;
  BOSS_SPAWN_Y = 75*SCALESIZE;
  BOSS_BLINK_TIME = 2500;
  BOSS_BLINK_DURATION = 100;

  TRASHCAN_SPAWN_X = OFFSET + 75*SCALESIZE;
  TRASHCAN_SPAWN_Y = 81*SCALESIZE;

  CLOCK_SPAWN_X = OFFSET + 17*SCALESIZE;
  CLOCK_SPAWN_Y = 64*SCALESIZE;

  DOOR_SPAWN_X = OFFSET + 119*SCALESIZE;
  DOOR_SPAWN_Y = 81*SCALESIZE;

  WINDOW_WORKER_X = OFFSET + 60*SCALESIZE;
  WINDOW_WORKER_Y = 69*SCALESIZE;

  WINDOW_WORKERS_X = OFFSET + 55*SCALESIZE;
  WINDOW_WORKERS_Y = 75*SCALESIZE;

  FOUNTAIN_SPAWN_X = OFFSET + 115*SCALESIZE;
  FOUNTAIN_SPAWN_Y = 64*SCALESIZE;
  LEFT_FOUNTAIN_HANDLE_SPAWN_X = FOUNTAIN_SPAWN_X + 1*SCALESIZE;
  LEFT_FOUNTAIN_HANDLE_SPAWN_Y = 80*SCALESIZE;

  RIGHT_FOUNTAIN_HANDLE_SPAWN_X = FOUNTAIN_SPAWN_X + 6*SCALESIZE;
  RIGHT_FOUNTAIN_HANDLE_SPAWN_Y = 80*SCALESIZE;

  TROPHY_SPAWN_X = OFFSET + .5*SCALESIZE;
  TROPHY_HEIGHT = 13*SCALESIZE/4;
  TROPHY_WIDTH= 10*SCALESIZE/4;

  strcpy(CODE_FONT,"fonts/VT323-Regular.ttf");
}

