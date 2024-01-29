/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_controls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessa <dbessa@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:03:32 by dbessa            #+#    #+#             */
/*   Updated: 2024/01/29 18:54:23 by dbessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	adjust_zoom(t_point *pos, float *x1, float *y1, t_fdf *data)
{
	*x1 *= data->zoom;
	*y1 *= data->zoom;
	pos->x *= data->zoom;
	pos->y *= data->zoom;
}

void	control(t_point *pos, float	*x1, float *y1, t_fdf *data)
{
	adjust_zoom(pos, x1, y1, data);
	isometric(&pos->x, &pos->y, data->z, data);
	isometric(x1, y1, data->z1, data);
	data->color = put_color(data->z, data);
	pos->x += data->shift_x;
	pos->y += data->shift_y;
	*x1 += data->shift_x;
	*y1 += data->shift_y;
}
