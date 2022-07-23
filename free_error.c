#include "cub3d.h"

void	free_map(char **map)
{
	int	x;

	x = 0;
	if (!map)
		return ;
	while (map[x])
	{
		free(map[x]);
		++x;
	}
	free(map);
}

void	write_error(char *str)
{
	write(2, str, ft_strlen(str));
	exit (1);
}

void	map_is_wrong(char *str, char **map)
{
	free_map(map);
	printf("Error\n");
	write_error(str);
}