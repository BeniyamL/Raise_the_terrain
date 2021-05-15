#ifndef Demo_h
#define Demo_h

#define SCREEN_WIDTH 1000
#define SCREEN_HEIGHT 800
#define nrows 8
#define ncols 8
#define space ((SCREEN_WIDTH - 360) / nrows)
#define Incline 0.7

#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <math.h>

/**
 * struct SDL_Instance - structure for sdl instance
 * @win: window of sdl
 * @ren: surface to draw
 *
 * Decscription: structure to create window and surface of SDL
**/
typedef struct SDL_Instance
{
	SDL_Window *win;
	SDL_Renderer *ren;
} SDL_Instance;

/** main **/
int poll_events(char **argv, SDL_Instance instance, SDL_Point ***grid);
void draw(SDL_Instance instance, char **argv, SDL_Point ***grid);
int init_instance(SDL_Instance *instance);
void rotate(SDL_Point ***grid, float a);

/** makegrid **/
SDL_Point ***makegrid(char **argv, SDL_Point ***grid);
void makeIsometric(SDL_Point ***grid, char **argv);
void grid_col(SDL_Point ***grid);
void grid_row(SDL_Point ***grid);
SDL_Point ***AllocateM(void);

/** get_altitude **/
int _atoi(char *s);
char *_strdup(char *str);
int _length(char *str);
int **get_altitude(char **argv);
char **str_split(char *str, char *del);

/** free_mem **/
void free_grid(SDL_Point ***grid);
void free_tokens(char **tokens);
void free_cols(char ***cols);
void free_numbers(int **numbers);
#endif
