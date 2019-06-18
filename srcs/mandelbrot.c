/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zytrams <zytrams@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 19:12:04 by zytrams           #+#    #+#             */
/*   Updated: 2019/06/18 21:37:03 by zytrams          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void		init_mandelbrot(t_fractol *fra)
{
	fra->xside = 8;
	fra->yside = 5;
	fra->scale = 0.005;
	fra->top = -3;
	fra->left = -5;
	fra->iter = 40;
}

void		mandelbrot(t_fractol *frc, int *palette)
{
	int		x;
	int		y;

	y = 0;
	while (y < frc->height)
	{
		x = 0;
		while (x < frc->width)
		{
			mandelbrot_helper(x, y, palette, frc);
			x++;
		}
		y++;
	}
}

void		mandelbrot_helper(int x, int y, int *palette, t_fractol *frc)
{
	double	cx;
	double	cy;
	double	zx;
	double	zy;
	int		i;
	int		mi;
	double	xtemp;

	cx = x * frc->scale + frc->left;
	cy = y * frc->scale + frc->top;
	zx = 0.0;
	zy = 0.0;
	i = 0;
	mi = frc->iter;
	while (((zx * zx + zy * zy) < 4) && i < mi)
	{
		xtemp = zx * zx - zy * zy + cx;
		zy = 2 * zx * zy + cy;
		zx = xtemp;
		i++;
	}
	put_on_image(x, y, palette[i % 4], frc);
}
