/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palette.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zytrams <zytrams@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 20:07:02 by zytrams           #+#    #+#             */
/*   Updated: 2019/06/28 15:51:04 by zytrams          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	get_palette(int keycode, int **palette, int iters)
{
	if (keycode == 18)
	{
		free(*palette);
		*palette = palette_generator(0xE69800, 0xFCFFB2, iters);
	}
	else if (keycode == 19)
	{
		free(*palette);
		*palette = palette_generator(0x66B2FF, 0xFFE5FF, iters);
	}
	else if (keycode == 20)
	{
		free(*palette);
		*palette = palette_generator(0x000000, 0xFFFFFF, iters);
	}
	else if (keycode == 21)
	{
		free(*palette);
		*palette = palette_generator(0x000000, 0xFF33FF, iters);
	}
}

int		*palette_generator(int start, int end, int iters)
{
	int		i;
	int		*palette;
	int		rgb[3];

	iters++;
	end -= 0xFFF;
	palette = (int *)ft_memalloc((iters) * sizeof(int));
	i = 0;
	while (i < iters - 1)
	{
		rgb_calc(rgb, (int[2]){start, end}, iters, i);
		palette[i] = rgb[0] << 16 | rgb[1] << 8 | rgb[2];
		i++;
	}
	end += 0xFFF;
	rgb_calc(rgb, (int[2]){start, end}, iters, i);
	palette[i] = rgb[0] << 16 | rgb[1] << 8 | rgb[2];
	return (palette);
}

void	rgb_calc(int rgb[3], int s_e[2], int iters, int i)
{
	rgb[0] = ((s_e[0] & 0xFF0000) >> 16) + (int)((((s_e[1] & 0xFF0000) >> 16)
	- ((s_e[0] & 0xFF0000) >> 16)) * i / iters);
	rgb[1] = ((s_e[0] & 0x00FF00) >> 8) + (int)((((s_e[1] & 0x00FF00) >> 8)
	- ((s_e[0] & 0x00FF00) >> 8)) * i / iters);
	rgb[2] = (s_e[0] & 0x0000FF) + (int)((s_e[1]
	& 0x0000FF - s_e[0] & 0x0000FF) * i / iters);
}
