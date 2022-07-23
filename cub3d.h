#ifndef CUB3D_H
# define CUB3D_H

#define WINDOW_WIDTH 900
#define WINDOW_HEIGHT 860

#define WHITE_PIXEL 0xFFFFFF
#define BLACK_PIXEL 00000
#define YELLOW_PIXEL 0XFFFF6B

#include <X11/keysym.h>
# include "mlx/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "gnl/get_next_line.h"

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp; /* bits per pixel */
	int		line_len;
	int		endian;
}	t_img;


typedef struct s_rect
{
	int	x;
	int	y;
	int width;
	int height;
	int color;
}	t_rect;

typedef struct s_window
{
	int	x;
	int	y;
}				t_window;

typedef struct s_image
{
	void	*background;
	void	*character;
	void	*exit;
	void	*item;
	void	*wall;
}				t_image;

typedef struct s_collect
{
	int	number_item_to_collect;
	int	exit_game;
	int	perso;
	int	item;
	int	wall;
}				t_collect;

typedef struct s_localisation
{
	int			move;
	int			character_x;
	int			character_y;
}				t_localisation;

typedef struct s_game
{
	char			**map;
	t_localisation	loc;
	t_image			image;
	t_window		window;
	t_collect		collect;
}				t_game;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
    t_game  game;
	int		cur_img;
}	t_data;

//Create color windows
int		render(t_data *data);
void	get_map(int fd, t_game *game);
void	print_map(t_data *game);
void	update_map(t_data *data);

//Background/rect forms and colors
int render_rect(t_img *img, t_rect rect);

//Free_error
void	free_map(char **map);
void	write_error(char *str);
void	map_is_wrong(char *str, char **map);

//Hooks
int	handle_keypress(t_data *data);
int	handle_keyrelease(int keysym, void *data);
int	handle_nothing(void);
int	handle_input(int keysym, t_data *data);


#endif