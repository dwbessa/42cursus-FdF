/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessa <dbessa@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 10:47:24 by dbessa            #+#    #+#             */
/*   Updated: 2024/01/29 13:23:54 by dbessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	check_file_name(char *file_name)
{
	int	i;

	i = 0;
	while (file_name[i] && file_name[i] != '.')
		i++;
	if (!ft_strncmp(&file_name[i], ".fdf", 4))
		return (0);
	return (1);
}
