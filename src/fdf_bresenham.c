/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bresenham.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessa <dbessa@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 10:46:58 by dbessa            #+#    #+#             */
/*   Updated: 2024/01/27 15:37:13 by dbessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	adjust_zoom(float *x, float *y, float *x1, float *y1, t_fdf *data)
{
	*x1 *= data->zoom; // coloquei o zoom na struct 
	*y1 *= data->zoom; // pra ficar mais facil 
	*x *= data->zoom; // de alterar
	*y *= data->zoom; //
}

void	isometric(float *x, float *y, int z)
{
	*x = (*x - *y) * cos(0.8);
	*y = (*x + *y) * sin(0.8) - z;
}

int	find_big(t_fdf *data)
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
		return (0xe80c0c);
	if (z > (big_z / 4) && z <= (big_z / 2))
		return (255);
	if (z > (big_z / 2) && z <= (3 * big_z / 4))
		return (0x008000);
	if (z > (3 * big_z / 4) && z <= big_z)
		return (0xffff00);
	else
		return (0xffa500);
}

void	bresenham(float x, float y, float x1, float y1, t_fdf *data)
{
	float	x_step;
	float	y_step;
	int	max;
	int	z;
	int	z1;

	z = data->matrix[(int)y][(int)x];
	z1 = data->matrix[(int)y1][(int)x1];
	adjust_zoom(&x, &y, &x1, &y1, data);
	data->color = put_color(z, data);
	isometric(&x, &y, z);
	isometric(&x1, &y1, z1);
	x += data->shift_x;
	y += data->shift_y;
	x1 += data->shift_x;
	y1 += data->shift_y;
	x_step = x1 - x;
	y_step = y1 - y;
	max = fmax(fabs(x_step), fabs(y_step));
	y_step /= max;
	x_step /= max;
	while ((int)(x - x1) || (int)(y - y1))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, data->color);
		x += x_step;
		y += y_step;
	}
}