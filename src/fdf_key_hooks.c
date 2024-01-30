/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_key_hooks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessa <dbessa@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:22:58 by dbessa            #+#    #+#             */
/*   Updated: 2024/01/30 18:11:51 by dbessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	deal_alpha2(int keysym, t_fdf *data)
{
	if (keysym == KEY_Z)
		set_default(data);
	if (keysym == KEY_W)
		data->angle_y += 0.2;
	if (keysym == KEY_S)
		data->angle_y -= 0.2;
	if (keysym == KEY_P)
	{
		data->angle_x = 0.8;
		data->angle_y = 0.8;
	}
	if (keysym == KEY_N)
	{
		data->z1 /= 1.5;
		data->z /= 1.5;
	}
}

static void	deal_alpha1(int keysym, t_fdf *data)
{
	if (keysym == KEY_D)
		data->angle_x += 0.2;
	if (keysym == KEY_A)
		data->angle_x -= 0.2;
	if (keysym == KEY_F)
	{
		data->angle_x -= 3.1415;
		data->angle_y -= 3.1415;
	}
	if (keysym == KEY_I)
	{
		data->angle_x = 0.5235;
		data->angle_y = 2.6179;
	}
	if (keysym == KEY_M)
	{
		data->z1 *= 1.5;
		data->z *= 1.5;
	}
}

static void	deal_arrow(int keysym, t_fdf *data)
{
	if (keysym == ARROW_LEFT)
		data->shift_x -= 10;
	if (keysym == ARROW_RIGHT)
		data->shift_x += 10;
	if (keysym == ARROW_DOWN)
		data->shift_y += 10;
	if (keysym == ARROW_UP)
		data->shift_y -= 10;
}

int	deal_key(int keysym, t_fdf *data)
{
	if (keysym == ESCAPE)
	{
		ft_free(data);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		free(data);
		exit(1);
	}
	if (keysym >= 65361 && keysym <= 65364)
		deal_arrow(keysym, data);
	if (keysym == PLUS || keysym == PLUS_2)
		data->zoom += 10;
	if (keysym == MINUS || keysym == MINUS_2)
		data->zoom -= 10;
	if (keysym >= 97 && keysym <= 109)
		deal_alpha1(keysym, data);
	if (keysym >= 110 && keysym <= 122)
		deal_alpha2(keysym, data);
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	display_map(data);
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
