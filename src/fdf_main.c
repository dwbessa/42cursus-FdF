/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessa <dbessa@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 10:46:04 by dbessa            #+#    #+#             */
/*   Updated: 2024/01/30 11:54:43 by dbessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	char		*file_name;
	t_fdf		*data;

	file_name = argv[1];
	if (argc == 2 && check_file_name(file_name) == 0)
	{
		data = malloc(sizeof(t_fdf));
		init_image(data, file_name);
		display_map(data);
		mlx_key_hook(data->win_ptr, deal_key, data);
		mlx_hook(data->win_ptr, 17, 0, close_program, data);
		mlx_loop(data->mlx_ptr);
	}
	else
	{
		ft_printf("Usage: ./fdf <file.fdf>\n");
		exit(EXIT_FAILURE);
	}
}
