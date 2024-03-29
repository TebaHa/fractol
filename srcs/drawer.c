/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zytrams <zytrams@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 19:28:37 by zytrams           #+#    #+#             */
/*   Updated: 2019/06/20 20:34:18 by zytrams          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void		draw(t_fractol_base *frc)
{
	if (frc->type == MANDELBROT)
		mandelbrot(frc, HAPPY);
	mlx_put_image_to_window(frc->ptr_mlx,
	frc->ptr_window, frc->img->ptr_img, 0, 0);
}
