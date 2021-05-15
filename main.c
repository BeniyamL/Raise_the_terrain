#include "header.h"

/**
 * main - Entry point for execution
 * @argc: the number of argument
 * @argv: argument array
 *
 * Return: always success
 **/
int main(int argc, char **argv)
{
	SDL_Instance instance;
	SDL_Point ***grid;

	if (init_instance(&instance) != 0)
		return (1);
	grid = makegrid(argv, grid);
	draw(instance, argv, grid);
	while ("C is awesome")
	{
		if (poll_events(argv, instance, grid) == 1)
			break;
	}
	SDL_DestroyRenderer(instance.ren);
	SDL_DestroyWindow(instance.win);
	SDL_Quit();
	return (0);
}

/**
 * poll_events - function to handle events
 * @argv: array of the argument
 * @instance: the istance of SDL
 * @grid: the given grid
 *
 * Return: 0 on suceesss 1 otherwise
 **/
int poll_events(char **argv, SDL_Instance instance, SDL_Point ***grid)
{
	SDL_Event event;
	SDL_KeyboardEvent key;
	int Angle;
	float a;

	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
			case SDL_QUIT:
				return (1);
			case SDL_KEYDOWN:
				key = event.key;
				if (key.keysym.sym == SDLK_ESCAPE)
					return (1);
				else if (key.keysym.sym == SDLK_RIGHT || key.keysym.sym == SDLK_LEFT)
				{
					if (key.keysym.sym == SDLK_RIGHT)
					{
						Angle += 1;
					}
					else if (key.keysym.sym == SDLK_LEFT)
					{
						Angle -= 1;
					}
					a = Angle * M_PI / 180;
					SDL_SetRenderDrawColor(instance.ren, 0, 0, 0, 255);
					SDL_RenderClear(instance.ren);
					grid = AllocateM();
					grid_row(grid);
					grid_col(grid);
					rotate(grid, a);
					makeIsometric(grid, argv);
					draw(instance, argv, grid);

				}
				break;
		}
	}
	return (0);
}
/**
 * draw - draw a grid
 * @instance: the given instance
 * @argv: array of the argument
 * @grid: the given grid
 *
 * Return: nothing
 **/
void draw(SDL_Instance instance, char **argv, SDL_Point ***grid)
{
	int i;

	SDL_SetRenderDrawColor(instance.ren, 255, 255, 255, 255);
	for (i = 0; i < nrows; i++)
		SDL_RenderDrawLines(instance.ren, grid[0][i], nrows);
	for (i = 0; i < ncols; i++)
		SDL_RenderDrawLines(instance.ren, grid[1][i], ncols);
	SDL_RenderPresent(instance.ren);
	free_grid(grid);

}
/**
 * init_instance - intialize all instance
 * @in: the given instance
 *
 * Return: 0 on success 1 otherwise
 **/

int init_instance(SDL_Instance *in)
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		fprintf(stderr, "Unable to initialize SDL: %s\n", SDL_GetError());
		return (1);
	}

	in->win = SDL_CreateWindow("Raise the terrain", 0, 0, SCREEN_WIDTH,
	SCREEN_HEIGHT, SDL_WINDOW_OPENGL);
	if (in->win == NULL)
	{
		fprintf(stderr, "SDL_CreateWindow Error: %s\n", SDL_GetError());
		SDL_Quit();
		return (1);
	}

	in->ren = SDL_CreateRenderer(in->win, -1, SDL_RENDERER_ACCELERATED
	| SDL_RENDERER_PRESENTVSYNC);
	if (in->ren == NULL)
	{
		fprintf(stderr, "SDL_CreateRenderer Error: %s\n", SDL_GetError());
		SDL_Quit();
		return (1);
	}
	return (0);
}
/**
 * rotate - rotate the grid
 * @a: the angle in radian
 * @grid: the given grid
 * Return: nothing
 **/
void rotate(SDL_Point ***grid, float a)
{
	int i, j, k, Rx, Ry, gx, gy;

	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < nrows; j++)
		{
			for (k = 0; k < ncols; k++)
			{
				gx = grid[i][j][k].x - 1050;
				gy = grid[i][j][k].y - 350;
				Rx = (gx * cos(a) - gy * sin(a)) + 1050;
				Ry = (gx * sin(a) + gy * cos(a)) + 350;
				grid[i][j][k].x = Rx;
				grid[i][j][k].y = Ry;
			}
		}
	}
}
