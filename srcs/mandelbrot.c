/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zytrams <zytrams@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 19:12:04 by zytrams           #+#    #+#             */
/*   Updated: 2019/06/21 20:49:10 by zytrams          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void		init_mandelbrot(t_fractol_base *fra)
{
	fra->xside = 8;
	fra->yside = 5;
	fra->scale = 0.005;
	fra->top = -3;
	fra->left = -5;
	fra->iter = 100;
	fra->calc.cx = 0.0;
	fra->calc.cy = 0.0;
	fra->calc.zx = 0.0;
	fra->calc.zy = 0.0;
	fra->calc.i = 0;
	fra->calc.mi = fra->iter;
	fra->palette = palette_generator(0xBF003C, 0xBFA200, fra->iter);
}
