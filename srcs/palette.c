/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palette.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zytrams <zytrams@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 20:07:02 by zytrams           #+#    #+#             */
/*   Updated: 2019/06/22 18:34:28 by zytrams          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int		*palette_generator(int start, int end, int iters)
{
	int		i;
	int		*palette;
	int		raver;
	int		gaver;
	int		baver;

	iters++;
	palette = (int *)ft_memalloc((iters) * sizeof(int));
	i = 0;
	while (i < iters)
	{
		raver = ((start & 0xFF0000) >> 16) + (int)((((end & 0xFF0000) >> 16) - ((start & 0xFF0000) >> 16)) * i / iters);
		gaver = ((start & 0x00FF00) >> 8) + (int)((((end & 0x00FF00) >> 8) - ((start & 0x00FF00) >> 8)) * i / iters);
		baver = (start & 0x0000FF) + (int)((end & 0x0000FF - start & 0x0000FF) * i / iters);
		printf("%04x %04x %04x\n", raver, gaver, baver);
		palette[i] = raver << 16 | gaver << 8 | baver;
		i++;
	}
	return (palette);
}
