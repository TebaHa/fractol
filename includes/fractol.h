/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zytrams <zytrams@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 19:29:50 by zytrams           #+#    #+#             */
/*   Updated: 2019/06/18 16:35:38 by zytrams          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define USAGE "Usage : ./fractol <fractal_type> [\'mandelbrot\', \'julia\']\n"
# define MANDELBROT 1
# define JULIA 2
# define WHITE 16777215
# define WIDTH 2000
# define HEIGHT 1200
# define SCROLL_UP 4
# define SCROLL_DOWN 5
# define EXIT 53
# define HAPPY ((int[4]){0xA7413C, 0xE4572E, 0xFF9C14, 0xEEC53C})
# define IS_THIS_IT ((int[4]){0x82C0C9, 0xD14A3E, 0xFFC43A, 0x82C0C9})
# include <libft.h>
# include <math.h>
# include <mlx.h>
# include <stdio.h>

typedef struct	s_image
{
	void		*ptr_img;
	void		*ptr_data;
	int			bpp;
	int			size_line;
	int			endian;
}				t_image;

typedef struct	s_fractol
{
	t_image		*img;
	void		*ptr_mlx;
	void		*ptr_window;
	int			type;
	int			width;
	int			height;
	int			iter;
	double		left;
	double		top;
	double		xside;
	double		yside;
	double		scale;
}				t_fractol;

void			create_fractol(char *type, t_fractol *fra);
void			error_logger(char *error);
void			init(t_fractol *fra);
void			put_on_image(int x, int y, int color, t_fractol *frc);
void			mandelbrot(t_fractol *frc, int *palette);
void			mandelbrot_helper(int x, int y, int *palette, t_fractol *frc);
void			draw(t_fractol *frc);
int				zoom_handler(int keycode, int x, int y, void *param);
void			init_mandelbrot(t_fractol *fra);
int				exit_handler(int keycode, void *param);

#endif
