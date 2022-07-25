#include "cub3d.h"

void	print_map(t_data *data)
{
    t_game  *game = &data->game;
	int	ret;
	int	i;
	int	j;

	i = 0;
	j = 0;
	puts("Beg");
    while (game->map[j])
	{
		i = 0;
		ret = ft_strlen(game->map[j]);
		while (i < ret)
		{
			if (game->map[j][i] == 'P')
			{
				game->loc.character_x = i;
				game->loc.character_y = j;

				return ;
			}
			++i;
		}
		++j;
	}
	puts("End");
}

void	update_map(t_data *data)
{
    t_game  *game;

    game = &data->game;
    mlx_clear_window(data->mlx_ptr, data->win_ptr);
    render(data);
}