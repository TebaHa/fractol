/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zytrams <zytrams@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 19:29:50 by zytrams           #+#    #+#             */
/*   Updated: 2019/06/28 20:23:20 by zytrams          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define USAGE "Usage : ./fractol <fractal_type>\n"
# define MANDELBROT 1
# define JULIA 2
# define BURNINGSHIP 3
# define WHITE 16777215
# define WIDTH 2000
# define HEIGHT 1200
# define SCROLL_UP 4
# define SCROLL_DOWN 5
# define EXIT 53
# define HAPPY ((int[4]){0xA7413C, 0xE4572E, 0xFF9C14, 0xEEC53C})
# define PROGRAM_FILE "./srcs/fractol_kernel.cl"
# define YELLOW_FREEDOME 0xE69800, 0xFCFFB2,
# define GREEN_BLUE 0x66B2FF, 0xFFE5FF,
# define BLACK_AND_WHITE 0x000000, 0xFFFFFF,
# define BLUE_AND_BLACK 0x000000, 0xFF33FF,

# include <libft.h>
# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <OpenCL/cl.h>

typedef struct			s_calc
{
	int					i;
	int					mi;
	double				cx;
	double				cy;
	double				zx;
	double				zy;
	double				xtemp;
}						t_calc;

typedef struct			s_image
{
	void				*ptr_img;
	void				*ptr_data;
	int					bpp;
	int					size_line;
	int					endian;
}						t_image;

typedef struct			s_cl_struct
{
	cl_device_id		device;
	cl_context			context;
	cl_program			program;
	cl_kernel			kernel;
	cl_command_queue	queue;
	cl_mem				int_mem;
	cl_mem				double_mem;
	cl_mem				mem_img;
	cl_mem				palette;
	int					ret;
}						t_cl_struct;

typedef struct			s_fractol_base
{
	t_image				*img;
	t_cl_struct			cl_structs;
	t_calc				calc;
	void				*ptr_mlx;
	void				*ptr_window;
	int					type;
	int					width;
	int					height;
	int					iter;
	int					*palette;
	int					color_type;
	int					jules;
	double				left;
	double				top;
	double				xside;
	double				yside;
	double				scale;
	double				julesx;
	double				julesy;
}						t_fractol_base;

void					create_fractol(char *type, t_fractol_base *fra);
void					error_logger(char *error);
void					init(t_fractol_base *fra);
void					put_on_image(int x, int y,
								int color, t_fractol_base *frc);
void					mandelbrot(t_fractol_base *frc, int *palette);
void					mandelbrot_helper(int x, int y,
							int *palette, t_fractol_base *frc);
void					draw(t_fractol_base *frc);
int						zoom_handler(int keycode, int x,
										int y, void *param);
void					init_mandelbrot(t_fractol_base *fra);
int						handler(int keycode, void *param);
void					init_cl(t_fractol_base *frc);
void					create_device(t_fractol_base *frc);
char					*read_file(char *path);
void					run_cl(t_fractol_base *frc);
int						*palette_generator(int start, int end, int iters);
void					init_julia(t_fractol_base *fra);
int						julia_handler(int x, int y, void *param);
void					init_burningship(t_fractol_base *fra);
void					get_palette(int keycode, int **palette, int iters);
void					ft_exit(t_fractol_base *frc);
void					fractol_reinit(int keycode, t_fractol_base *frc);
void					release_resources(t_cl_struct *cl_s);
void					rgb_calc(int rgb[3], int s_e[2], int iters, int i);

#endif
