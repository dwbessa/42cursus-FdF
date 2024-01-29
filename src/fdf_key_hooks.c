/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_key_hooks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessa <dbessa@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:22:58 by dbessa            #+#    #+#             */
/*   Updated: 2024/01/29 18:52:36 by dbessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	deal_key(int keysym, t_fdf *data)
{
	if (keysym == ARROW_LEFT)
		data->shift_x -= 10;
	if (keysym == ARROW_RIGHT)
		data->shift_x += 10;
	if (keysym == ARROW_DOWN)
		data->shift_y += 10;
	if (keysym == ARROW_UP)
		data->shift_y -= 10;
	if (keysym == PLUS || keysym == PLUS_2)
		data->zoom += 10;
	if (keysym == MINUS || keysym == MINUS_2)
		data->zoom -= 10;
	if (keysym == KEY_Z)
		data->shift_z *= 1.5;
	if (keysym == KEY_W)
		data->angle_y += 0.05;
	if (keysym == KEY_S)
		data->angle_y -= 0.05;
	if (keysym == KEY_D)
		data->angle_x += 0.05;
	if (keysym == KEY_A)
		data->angle_x -= 0.05;
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	display_map(data);
	if (keysym != ESCAPE)
		printf("The %d key has been pressed\n\n", keysym);
	else if (keysym == ESCAPE)
	{
		printf("The %d key (ESC) has been pressed\n\n", keysym);
		ft_free(data);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		free(data);
		exit(1);
	}
	return (0);
}

int	close_program(t_fdf *data)
{
	ft_free(data);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	free(data);
	exit(0);
}
