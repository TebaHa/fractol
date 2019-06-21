/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_fractol.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zytrams <zytrams@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 18:21:26 by zytrams           #+#    #+#             */
/*   Updated: 2019/06/20 20:52:49 by zytrams          ###   ########.fr       */
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
		fra->type = JULIA;
	else
		error_logger(USAGE);
}
