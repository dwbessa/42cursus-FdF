/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessa <dbessa@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 10:47:12 by dbessa            #+#    #+#             */
/*   Updated: 2024/01/28 18:47:06 by dbessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>
# include <fcntl.h>
# include "../libft/includes/libft.h"
# include "../minilibx/mlx.h"
# include <X11/keysym.h>
# include <stdio.h>

# define WIDTH 1920
# define HEIGHT 1080

# define ARROW_LEFT 65361
# define ARROW_RIGHT 65363
# define ARROW_DOWN 65364
# define ARROW_UP 65362
# define MINUS 65453
# define PLUS 65451
# define SPACE 32
# define KEY_R 114
# define MOUSE_CLICK_LEFT 1
# define MOUSE_CLICK_RIGHT 2
# define MOUSE_CLICK_MIDDLE 3
# define MOUSE_WHEEL_UP 4
# define MOUSE_WHEEL_DOWN 5
# define ESCAPE 65307

typedef struct s_fdf
{
	int	width;
	int	height;
	int	**matrix;
	int	shift_x;
	int	shift_y;
	int	zoom;
	int	color;
	int	scale;

	void	*mlx_ptr;
	void	*win_ptr;
	char	*img_data;
}	t_fdf;

void	display_map(t_fdf *data);
void	bresenham(float x, float y, float x1, float y1, t_fdf *data);
void	get_map(char *file_name, t_fdf *data);
int		count_width(char const *s, char c);
int		check_file_name(char *file_name);
int		get_infos(char *file_name, t_fdf *data);
void	free_map(t_fdf *data);
void	ft_free(t_fdf *data);

#endif