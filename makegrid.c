#include "header.h"
/**
 * makegrid - function to create a grid
 * @argv: argument array
 * @grid: the given grid
 *
 * Return: nothing
 **/
SDL_Point ***makegrid(char **argv, SDL_Point ***grid)
{

	grid = AllocateM();
	grid_row(grid);
	grid_col(grid);
	makeIsometric(grid, argv);
	return (grid);
}
/**
 * makeIsometric - change the grid to isometric projection
 * @grid: the given grid
 * @argv: array of the arguments
 *
 * Return: nothing
 **/
void makeIsometric(SDL_Point ***grid, char **argv)
{
	int i, j, x_iso, y_iso, x_g, y_g;
	int **altitude;

	altitude = get_altitude(argv);
	for (i = 0; i < nrows; i++)
	{
		for (j = 0; j < ncols; j++)
		{
			x_g = grid[0][i][j].x;
			y_g = grid[0][i][j].y;
			x_iso = Incline * x_g - Incline * y_g;
			y_iso = (1 - Incline) * x_g + (1 - Incline) * y_g - altitude[i][j];
			grid[0][i][j].x = x_iso;
			grid[0][i][j].y = y_iso;
		}
	}
	for (i = 0; i < nrows; i++)
	{
		for (j = 0; j < ncols; j++)
		{
			x_g = grid[1][i][j].x;
			y_g = grid[1][i][j].y;
			x_iso = Incline * x_g - Incline * y_g;
			y_iso = (1 - Incline) * x_g + (1 - Incline) * y_g - altitude[j][i];
			grid[1][i][j].x = x_iso;
			grid[1][i][j].y = y_iso;
		}
	}
	free_numbers(altitude);
}

/**
 * grid_col - create columns for the grid
 * @grid: the given grid
 *
 * Return: nothing
 **/
void grid_col(SDL_Point ***grid)
{
	int total_x, total_y, i, j, x, y, x_initial, y_initial;

	/**
	* total_x = space * nrows;
	* total_y = space * ncols;
	* x_initial = (SCREEN_WIDTH  - total_x )/ 2;
	* y_initial = (SCREEN_HEIGHT - total_y )/ 2;
	* x = x_initial;
	* y = y_initial;
	**/
	x = 700;
	y = 0;
	x_initial = 700;
	y_initial = 0;
	for (i = 0; i < nrows; i++)
	{
		for (j = 0; j < ncols; j++)
		{
			grid[1][i][j].x = x;
			grid[1][i][j].y = y;
			y = y + space;
		}
		y = y_initial;
		x = x + space;
	}
}



/**
 * grid_row - create row for the grid
 * @grid: the given grid
 *
 * Return: nothing
 **/
void grid_row(SDL_Point ***grid)
{
	int total_x, total_y, i, j, x, y, x_initial, y_initial;

	/**
	* total_x = space * nrows;
	* total_y = space * ncols;
	* x_initial = (SCREEN_WIDTH - total_x ) / 2;
	* y_initial = (SCREEN_HEIGHT - total_y) / 2;
	* x = x_initial;
	* y = y_initial;
	**/
	x = 700;
	y = 0;
	x_initial = 700;
	y_initial = 0;
	for (i = 0; i < nrows; i++)
	{
		for (j = 0; j < ncols; j++)
		{
			grid[0][i][j].x = x;
			grid[0][i][j].y = y;
			x = x + space;
		}
		x = x_initial;
		y = y + space;
	}
}

/**
 * AllocateM - allocated memrory for the grid
 *
 * Return: the grid with allocatd memory
 **/
SDL_Point ***AllocateM(void)
{
	int i, j;
	SDL_Point ***g;

	g = malloc(sizeof(SDL_Point **) * 2);
	if (g == NULL)
		return (NULL);
	g[0] = malloc(sizeof(SDL_Point *) * nrows);
	if (g[0] == NULL)
		return (NULL);
	for (i = 0; i < nrows; i++)
		g[0][i] = malloc(sizeof(SDL_Point) * nrows);
	g[1] = malloc(sizeof(SDL_Point *) * ncols);
	if (g[1] == NULL)
		return (NULL);
	for (j = 0 ; j < ncols; j++)
		g[1][j] = malloc(sizeof(SDL_Point) * ncols);
	if (g == NULL)
		return (NULL);
	return (g);
}
