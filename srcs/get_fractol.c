/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_fractol.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zytrams <zytrams@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 18:21:26 by zytrams           #+#    #+#             */
/*   Updated: 2019/06/25 18:52:46 by zytrams          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	create_fractol(char *type, t_fractol_base *fra)
{
	if (ft_strcmp(type, "mandelbrot") == 0)
	{
		fra->type = MANDELBROT;
		init_mandelbrot(fra);
	}
	else if (ft_strcmp(type, "julia") == 0)
	{
		fra->type = JULIA;
		init_julia(fra);
	}
	else if (ft_strcmp(type, "burningship") == 0)
	{
		fra->type = BURNINGSHIP;
		init_burningship(fra);
	}
	else
		error_logger(USAGE);
	fra->palette = palette_generator(YELLOW_FREEDOME fra->iter);
}
