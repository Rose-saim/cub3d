#include "cub3d.h"

void	print_image(t_data *data, t_game *game, int j, int i)
{

	if (game->map[j][i] == '1')
		render_rect(&data->img, (t_rect){i * 52, j * 52, 50, 50, WHITE_PIXEL});
	if (game->map[j][i] == 'P')
	{
		if (0 != game->loc.character_x || 0 != game->loc.character_y)
			render_rect(&data->img, (t_rect){game->loc.character_x * 52, game->loc.character_y * 52, 50, 50, YELLOW_PIXEL});
		else	
		{
			render_rect(&data->img, (t_rect){i * 52, j * 52, 50, 50, YELLOW_PIXEL});
			game->loc.character_x = i;
			game->loc.character_y = j;
		}
	}

}

void	print_map(t_data *data)
{
    t_game  *game = &data->game;
	int	ret;
	int	i;
	int	j;

	i = 0;
	j = 0;
    while (game->map[j])
	{
		i = 0;
		ret = ft_strlen(game->map[j]);
		while (i < ret)
			print_image(data, game, j, i++);
		++j;
	}
}

void	update_map(t_data *data)
{
    t_game  *game;

    game = &data->game;
    mlx_clear_window(data->mlx_ptr, data->win_ptr);
    render(data);
}