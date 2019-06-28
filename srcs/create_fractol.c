/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_fractol.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zytrams <zytrams@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 15:47:38 by zytrams           #+#    #+#             */
/*   Updated: 2019/06/28 15:50:22 by zytrams          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	create_fractol(char *type, t_fractol_base *fra)
{
	if ((ft_strcmp(type, (char[11]){"mandelbrot"})) == 0)
	{
		fra->type = MANDELBROT;
		init_mandelbrot(fra);
	}
	else if ((ft_strcmp(type, (char[6]){"julia"})) == 0)
	{
		fra->type = JULIA;
		init_julia(fra);
	}
	else if ((ft_strcmp(type, (char[12]){"burningship"})) == 0)
	{
		fra->type = BURNINGSHIP;
		init_burningship(fra);
	}
	else
		error_logger(USAGE);
	fra->palette = palette_generator(0xE69800, 0xFCFFB2, fra->iter);
}
