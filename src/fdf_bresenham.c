/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bresenham.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessa <dbessa@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 10:46:58 by dbessa            #+#    #+#             */
/*   Updated: 2024/01/30 12:30:01 by dbessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	isometric(float *x, float *y, int z, t_fdf *data)
{
	float	initial_x;
	float	initial_y;

	initial_x = *x;
	initial_y = *y;
	*x = (initial_x - initial_y) * cos(data->angle_x);
	*y = (initial_x + initial_y) * sin(data->angle_y) - z;
}

static int	find_big(t_fdf *data)
{
	int	x;
	int	y;
	int	big_z;

	y = 0;
	big_z = data->matrix[0][0];
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (big_z < data->matrix[y][x])
				big_z = data->matrix[y][x];
			x++;
		}
		y++;
	}
	return (big_z);
}

int	put_color(int z, t_fdf *data)
{
	int	big_z;

	big_z = find_big(data);
	if (z == 0)
		return (0xffffff);
	if (z > 0 && z <= (big_z / 4))
		return (0x0989eb);
	if (z > (big_z / 4) && z <= (big_z / 2))
		return (0x382beb);
	if (z > (big_z / 2) && z <= (3 * big_z / 4))
		return (0x0942eb);
	if (z > (3 * big_z / 4) && z <= big_z)
		return (0x09d0eb);
	else
		return (0x9863eb);
}

void	bresenham(t_point pos, float x1, float y1, t_fdf *data)
{
	float	x_step;
	float	y_step;
	int		max;

	data->z = data->matrix[(int)pos.y][(int)pos.x];
	data->z1 = data->matrix[(int)y1][(int)x1];
	control(&pos, &x1, &y1, data);
	x_step = x1 - pos.x;
	y_step = y1 - pos.y;
	max = fmax(fabs(x_step), fabs(y_step));
	y_step /= max;
	x_step /= max;
	while ((int)(pos.x - x1) || (int)(pos.y - y1))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, pos.x, pos.y, data->color);
		pos.x += x_step;
		pos.y += y_step;
	}
}
