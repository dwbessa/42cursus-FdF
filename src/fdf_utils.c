/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessa <dbessa@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 10:47:40 by dbessa            #+#    #+#             */
/*   Updated: 2024/01/29 11:08:48 by dbessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

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

int count_width(char const *s, char c)
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
