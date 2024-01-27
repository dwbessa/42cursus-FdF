/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_display.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessa <dbessa@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 10:47:33 by dbessa            #+#    #+#             */
/*   Updated: 2024/01/27 14:23:27 by dbessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	display_map(t_fdf *data)
{
	int x;
	int y;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (!(x == data->width - 1)) // if para nao ligar reta quando chegar no x max
				bresenham(x, y, x + 1, y, data);
			if(!(y == data->height - 1)) // if para não ligar reta quando chegar no y max
				bresenham(x, y, x, y + 1, data);
			x++;
		}
		y++;
	}
}