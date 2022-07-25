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

void	rotate_vector(t_data *data, int angle)
{
	t_player	*player = &data->player;
	int	tmp_x;

	tmp_x = (player->dir_x * cos(angle)) - (player->dir_y * sin(angle));
	player->dir_y = (player->dir_x * sin(angle)) + (player->dir_y * cos(angle));
	player->dir_x = tmp_x;
}

int	handle_input(int key, t_data *data)
{
	double	moveSpeed = 1;
	double	rotSpeed = 0.05;
	if (key == XK_Escape)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	if (key == 119)
	{
		if (!data->game.map[(int)(data->player.pos_x + data->player.dir_x * moveSpeed)][(int)(data->player.pos_y)])
			data->player.pos_x += data->player.dir_x * moveSpeed;
		if (!data->game.map[(int)(data->player.pos_x)][(int)(data->player.pos_y + data->player.dir_y * moveSpeed)])
			data->player.pos_y += data->player.dir_y * moveSpeed;
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	 }
	//move backwards if no wall behind you
	if (key == K_S)
	{
		if (!data->game.map[(int)(data->player.pos_x - data->player.dir_x * moveSpeed)][(int)(data->player.pos_y)])
			data->player.pos_x -= data->player.dir_x * moveSpeed;
		if (!data->game.map[(int)(data->player.pos_x)][(int)(data->player.pos_y - data->player.dir_y * moveSpeed)])
			data->player.pos_y -= data->player.dir_y * moveSpeed;
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	}
	//rotate to the right
	if (key == K_D)
	{
		//both camera direction and camera plane must be rotated
		double oldDirX = data->player.dir_x;
		data->player.dir_x = data->player.dir_x * cos(-rotSpeed) - data->player.dir_y * sin(-rotSpeed);
		data->player.dir_y = oldDirX * sin(-rotSpeed) + data->player.dir_y * cos(-rotSpeed);
		double oldPlaneX = data->player.plane_x;
		data->player.plane_x = data->player.plane_x * cos(-rotSpeed) - data->player.plane_y * sin(-rotSpeed);
		data->player.plane_y = oldPlaneX * sin(-rotSpeed) + data->player.plane_y * cos(-rotSpeed);
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	}
	//rotate to the left
	if (key == K_A)
	{
		//both camera direction and camera plane must be rotated
		double oldDirX = data->player.dir_x;
		data->player.dir_x = data->player.dir_x * cos(rotSpeed) - data->player.dir_y * sin(rotSpeed);
		data->player.dir_y = oldDirX * sin(rotSpeed) + data->player.dir_y * cos(rotSpeed);
		double oldPlaneX = data->player.plane_x;
		data->player.plane_x = data->player.plane_x * cos(rotSpeed) - data->player.plane_y * sin(rotSpeed);
		data->player.plane_y = oldPlaneX * sin(rotSpeed) + data->player.plane_y * cos(rotSpeed);
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	}
	return (0);
}