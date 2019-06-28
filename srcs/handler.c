/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zytrams <zytrams@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 21:05:52 by zytrams           #+#    #+#             */
/*   Updated: 2019/06/28 20:23:01 by zytrams          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int		zoom_handler(int keycode, int x, int y, void *param)
{
	t_fractol_base	*frc;

	frc = (t_fractol_base *)param;
	if (keycode == SCROLL_UP)
	{
		frc->scale += frc->scale * 0.05;
		frc->top -= frc->scale * y * 0.05;
		frc->left -= frc->scale * x * 0.05;
	}
	else if (keycode == SCROLL_DOWN)
	{
		frc->scale -= frc->scale * 0.05;
		frc->top += frc->scale * y * 0.05;
		frc->left += frc->scale * x * 0.05;
	}
	if (keycode == 2)
		frc->jules *= -1;
	run_cl(frc);
	return (0);
}

int		julia_handler(int x, int y, void *param)
{
	t_fractol_base	*frc;

	frc = (t_fractol_base *)param;
	if (frc->jules == 1)
	{
		frc->julesx = (double)(frc->width / 2 - x * 1.5) * 0.0005;
		frc->julesy = (double)(frc->height / 2 - y * 1.5) * 0.0005;
	}
	run_cl(frc);
	return (0);
}

int		handler(int keycode, void *param)
{
	t_fractol_base	*frc;

	frc = (t_fractol_base *)param;
	fractol_reinit(keycode, frc);
	get_palette(keycode, &frc->palette, frc->iter);
	if (keycode == 8)
		frc->color_type *= -1;
	run_cl(frc);
	if (keycode == 53)
		ft_exit(frc);
	return (0);
}

void	fractol_reinit(int keycode, t_fractol_base *frc)
{
	if (keycode == 83)
	{
		init_mandelbrot(frc);
		frc->type = MANDELBROT;
	}
	else if (keycode == 84)
	{
		init_julia(frc);
		frc->type = JULIA;
	}
	else if (keycode == 85)
	{
		init_burningship(frc);
		frc->type = BURNINGSHIP;
	}
}

void	ft_exit(t_fractol_base *frc)
{
	release_resources(&frc->cl_structs);
	exit(0);
}
