/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessa <dbessa@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 10:47:40 by dbessa            #+#    #+#             */
/*   Updated: 2024/01/30 12:09:19 by dbessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_map(t_fdf *data)
{
	free(data->mlx_ptr);
	free(data->win_ptr);
	free(data->img_data);
}

void	ft_free(t_fdf *data)
{
	int	i;

	i = 0;
	while (i < data->height)
	{
		free(data->matrix[i]);
		i++;
	}
	free(data->matrix);
}

int	count_width(char const *s, char c)
{
	int	words;

	if (!s)
		return (0);
	words = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			words++;
		while (*s != c && *s)
			s++;
	}
	return (words);
}

void	set_default(t_fdf *data)
{
	data->zoom = 10;
	data->shift_x = (WIDTH - data->width) / 2;
	data->shift_y = HEIGHT / 5;
	data->shift_z = 1.5;
	data->angle_x = 0.5235;
	data->angle_y = 2.6179;
}

void	init_image(t_fdf *data, char *file_name)
{
	char	*window_name;

	window_name = ft_strjoin("FdF - ", file_name);
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, window_name);
	get_map(file_name, data);
	set_default(data);
	free(window_name);
}
