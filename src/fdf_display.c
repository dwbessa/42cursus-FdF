/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_display.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessa <dbessa@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 10:47:33 by dbessa            #+#    #+#             */
/*   Updated: 2024/01/29 17:30:39 by dbessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	display_map(t_fdf *data)
{
	t_point	pos;

	pos.y = 0;
	while (pos.y < data->height)
	{
		pos.x = 0;
		while (pos.x < data->width)
		{
			if (!(pos.x == data->width - 1))
				bresenham(pos, pos.x + 1, pos.y, data);
			if (!(pos.y == data->height - 1))
				bresenham(pos, pos.x, pos.y + 1, data);
			pos.x++;
		}
		pos.y++;
	}
}
