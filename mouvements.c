#include "cub3d.h"
# include <math.h>

int	key_up(t_data *data)
{
    t_game  *game;

    game = &data->game;
    if (game->map[game->loc.character_y - 1][game->loc.character_x] == '1')
		return (1);
    game->loc.character_y -= 1;
    update_map(data);
	return (0);
}
int	key_down(t_data *data)
{
    t_game  *game;

    game = &data->game;
	if (game->map[game->loc.character_y + 1][game->loc.character_x] == '1')
		return (1);
	game->loc.character_y += 1;
	if (game->map[game->loc.character_y][game->loc.character_x] == 'C')
	{
		game->map[game->loc.character_y][game->loc.character_x] = '0';
		game->collect.number_item_to_collect -= 1;
	}
	game->loc.move += 1;
	update_map(data);
	return (0);
}

int	key_left(t_data *data)
{
    t_game  *game;

    game = &data->game;
	if (game->map[game->loc.character_y][game->loc.character_x - 1] == '1')
		return (1);
	game->loc.character_x -= 1;
	if (game->map[game->loc.character_y][game->loc.character_x] == 'C')
	{
		game->map[game->loc.character_y][game->loc.character_x] = '0';
		game->collect.number_item_to_collect -= 1;
	}
	game->loc.move += 1;
	update_map(data);
	return (0);
}

int	key_right(t_data *data)
{
    t_game  *game;

    game = &data->game;
	if (game->map[game->loc.character_y][game->loc.character_x + 1] == '1')
		return (1);
	game->loc.character_x += 1;
	if (game->map[game->loc.character_y][game->loc.character_x] == 'C')
	{
		game->map[game->loc.character_y][game->loc.character_x] = '0';
		game->collect.number_item_to_collect -= 1;
	}
	game->loc.move += 1;
	update_map(data);
	return (0);
}

// void	rotate_vector(t_ray *ray, int angle)
// {
// 	int	tmp_x;

// 	tmp_x = (ray->dirx * cos(angle)) - (ray->diry * sin(angle));
// 	ray->diry = (ray->dirx * sin(angle)) + (ray->diry * cos(angle));
// 	ray->dirx = tmp_x;
// }

int	handle_input(int keysym, t_data *data)
{
	int	ret;

	ret = 2;
	if (keysym == XK_Escape)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	else if (keysym == 119)
		ret = key_up(data);
	else if (keysym == 115)
		ret = key_down(data);
	// else if (keysym == 97)
	// 	rotate_vector(&data->ray,  -PI / 36);
	// else if (keysym == 100)
	// 	rotate_vector(&data->ray,  PI / 36);
		// ret = key_right(data);
	return (0);
}
