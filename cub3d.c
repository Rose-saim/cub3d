#include "cub3d.h"

int	main(int ac, char **av)
{
	t_data	data;
    int     fd;
    
    if (ac != 2)
        return 2;
	//Open fd
    fd = open(av[1], O_RDONLY);
	//Get map to char **
    get_map(fd, &data.game);
    close(fd);
	//init windows
	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (EXIT_FAILURE);
	data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "My first window!");
	if (data.win_ptr == NULL)
	{
		free(data.win_ptr);
		return (EXIT_FAILURE);
	}
	puts("MDR");
	//Create background and character
    data.img.mlx_img = mlx_new_image(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	
	data.img.addr = mlx_get_data_addr(data.img.mlx_img, &data.img.bpp,
			&data.img.line_len, &data.img.endian);
	puts("MDR");
	render(&data);
	puts("MDR");
	//Loop about keypress and mouvements
	mlx_loop_hook(data.mlx_ptr, &handle_nothing, &data);
	mlx_hook(data.win_ptr, ClientMessage, LeaveWindowMask, &handle_keypress, &data); /* ADDED */
	mlx_hook(data.win_ptr, KeyRelease, KeyReleaseMask, &handle_input, &data); /* ADDED */
	puts("MDR");
	
    mlx_loop(data.mlx_ptr);

	//Close windows
	mlx_destroy_image(data.mlx_ptr, data.img.mlx_img);
    mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
}