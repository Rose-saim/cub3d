#include "cub3d.h"

char	*copy(char *str)
{
	int		i;
	char	*new_string;

	i = 0;
	new_string = NULL;
	if (!str)
		return (NULL);
	new_string = (char *)malloc(sizeof(char) *(ft_strlen(str) + 1));
	if (!new_string)
		return (NULL);
	while (str[i])
	{
		new_string[i] = str[i];
		++i;
	}
	new_string[i] = '\0';
	return (new_string);
}

void	recopy_map(char **map, char **new_map, char *new_line)
{
	int	i;

	i = 0;
	while (map && map[i])
	{
		new_map[i] = copy(map[i]);
		if (!new_map[i])
		{
			free(new_line);
			free_map(map);
			map_is_wrong("Malloc", new_map);
		}
		++i;
	}
	free_map(map);
	new_map[i] = copy(new_line);
	if (!new_map[i])
	{
		free(new_line);
		map_is_wrong("Malloc", new_map);
	}
}

char	**get_line(char **map, char *new_line)
{
	static int	row = 0;
	char		**new_map;

	row += 1;
	new_map = malloc(sizeof(char *) * (row + 1));
	if (!new_map)
	{
		free(new_line);
		map_is_wrong("Malloc", map);
	}
	new_map[row] = NULL;
	recopy_map(map, new_map, new_line);
	return (new_map);
}

void	get_map(int fd, t_game *game)
{
	int		ret;
	char	*line;

	line = NULL;
	game->map = NULL;
	ret = get_next_line(fd, &line);
	while (ret > 0)
	{
		game->map = get_line(game->map, line);
		free(line);
		ret = get_next_line(fd, &line);
	}
	game->map = get_line(game->map, line);
	free(line);
}
