#ifndef COMMON_FUNCTION_H_
#define COMMON_FUNCTION_H_

#include<Windows.h>
#include<SDL.h>
#include<SDL_image.h>
#include<SDL_mixer.h>
#include<SDL_ttf.h>
#include<string>

static SDL_Window* g_window;
static SDL_Renderer* g_screen;
static SDL_Event g_event;

const int SCREEN_HEIGHT = 700;
const int SCREEN_WIDTH = 1000;
const int SCREEN_BPP = 32;

const int COLOR_KEY_R = 167;
const int COLOR_KEY_G = 175;
const int COLOR_KEY_B = 180;

const std::string WINDOW_TITLE = "GAME PROJECT";
const int RENDER_DRAW_COLOR = 0xff;

#endif // !COMMON_FUNCTION
