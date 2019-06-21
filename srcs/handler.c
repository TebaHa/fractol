/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zytrams <zytrams@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 21:05:52 by zytrams           #+#    #+#             */
/*   Updated: 2019/06/20 21:51:07 by zytrams          ###   ########.fr       */
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
	run_cl(frc);
	return (0);
}

int		exit_handler(int keycode, void *param)
{
	param = NULL;
	if (keycode == EXIT)
		exit(0);
	return (0);
}
