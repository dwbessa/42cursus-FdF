/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessa <dbessa@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 10:46:04 by dbessa            #+#    #+#             */
/*   Updated: 2024/01/27 16:24:59 by dbessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>

void	set_default(t_fdf *data)
{
	data->zoom = 20;
	data->shift_x = WIDTH / 3;
	data->shift_y = HEIGHT / 3;
}

void	init_image(t_fdf *data)
{
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, "FdF");
	data->img_data =  mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	data->zoom = 20;
}

int	deal_key(int keysym, t_fdf *data)
{
	printf("TECLA %d APERTADA\n", keysym);
	if (keysym == ARROW_LEFT)
		data->shift_x -= 10;
	if (keysym == ARROW_RIGHT)
		data->shift_x += 10;
	if (keysym == ARROW_DOWN)
		data->shift_y += 10;
	if (keysym == ARROW_UP)
		data->shift_y -= 10;
	if (keysym == PLUS)
		data->zoom += 10;
	if (keysym == MINUS)
		data->zoom -= 10;
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	display_map(data);
	if (keysym != ESCAPE)
		printf("The %d key has been pressed\n\n", keysym);
	else if (keysym == ESCAPE)
	{
		printf("The %d key (ESC) has been pressed\n\n", keysym);
		ft_free((void **)data->matrix);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		free_map(data);
		free(data);
		exit(1);
	}
	return (0);
}

int	close_program(t_fdf *data)
{
	ft_free((void **)data->matrix);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
}

int	main(int argc, char **argv)
{
	char		*file_name;
	t_fdf		*data;

	if (argc == 2)
	{
		check_file_name(argv[1]);
		file_name = argv[1];
		data = malloc(sizeof(t_fdf));
		init_image(data);
		get_map(file_name, data);
		set_default(data);
		display_map(data);
		mlx_key_hook(data->win_ptr, deal_key, data);
		mlx_hook(data->win_ptr, 17, 0, close_program, data);
		mlx_loop(data->mlx_ptr);
	}
	else
		return (1);
}
