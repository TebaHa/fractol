/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zytrams <zytrams@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 19:29:32 by zytrams           #+#    #+#             */
/*   Updated: 2019/06/23 19:56:51 by zytrams          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void			init(t_fractol_base *fra)
{
	fra->width = WIDTH;
	fra->height = HEIGHT;
	fra->ptr_mlx = mlx_init();
	fra->ptr_window = mlx_new_window(fra->ptr_mlx,
										fra->width, fra->height, "fractol");
	fra->img->ptr_img = mlx_new_image(fra->ptr_mlx, fra->width, fra->height);
	fra->img->ptr_data = mlx_get_data_addr(fra->img->ptr_img, &fra->img->bpp,
									&fra->img->size_line, &fra->img->endian);
}

int				main(int argc, char **argv)
{
	t_fractol_base	fractol;
	t_image			img;

	fractol.img = &img;
	if (argc != 2)
		error_logger(USAGE);
	init(&fractol);
	create_fractol(argv[1], &fractol);
	init_cl(&fractol);
	run_cl(&fractol);
	mlx_key_hook(fractol.ptr_window, exit_handler, &fractol);
	mlx_mouse_hook(fractol.ptr_window, zoom_handler, &fractol);
	mlx_loop(fractol.ptr_mlx);
	return (0);
}
