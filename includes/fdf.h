/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessa <dbessa@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 10:47:12 by dbessa            #+#    #+#             */
/*   Updated: 2024/01/30 18:11:58 by dbessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>
# include <fcntl.h>
# include "../libft/includes/libft.h"
# include "../minilibx/mlx.h"
# include <X11/keysym.h>

# define WIDTH 1920
# define HEIGHT 1080

# define ARROW_LEFT 65361
# define ARROW_RIGHT 65363
# define ARROW_DOWN 65364
# define ARROW_UP 65362
# define MINUS 65453
# define MINUS_2 45
# define PLUS 65451
# define PLUS_2 61
# define SPACE 32
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_I 105
# define KEY_P 112
# define KEY_Z 122
# define KEY_F 102
# define KEY_M 109
# define KEY_N 110
# define MOUSE_CLICK_LEFT 1
# define MOUSE_CLICK_RIGHT 2
# define MOUSE_CLICK_MIDDLE 3
# define MOUSE_WHEEL_UP 4
# define MOUSE_WHEEL_DOWN 5
# define ESCAPE 65307

typedef struct s_fdf
{
	int		width;
	int		height;
	float	x;
	float	y;
	float	z;
	float	z1;
	float	angle_x;
	float	angle_y;
	int		**matrix;
	int		shift_x;
	int		shift_y;
	int		shift_z;
	float	zoom;
	int		color;

	void	*mlx_ptr;
	void	*win_ptr;
	char	*img_data;
}	t_fdf;
typedef struct s_point
{
	float	x;
	float	y;
}	t_point;

void	display_map(t_fdf *data);
void	bresenham(t_point pos, float x1, float y1, t_fdf *data);
void	get_map(char *file_name, t_fdf *data);
int		count_width(char const *s, char c);
int		check_file_name(char *file_name);
int		get_infos(char *file_name, t_fdf *data);
void	free_map(t_fdf *data);
void	ft_free(t_fdf *data);
int		close_program(t_fdf *data);
int		deal_key(int keysym, t_fdf *data);
void	init_image(t_fdf *data, char *file_name);
void	control(t_point *pos, float	*x1, float *y1, t_fdf *data);
void	adjust_zoom(t_point *pos, float *x1, float *y1, t_fdf *data);
void	isometric(float *x, float *y, int z, t_fdf *data);
int		put_color(int z, t_fdf *data);
void	set_default(t_fdf *data);

#endif