/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palette.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zytrams <zytrams@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 20:07:02 by zytrams           #+#    #+#             */
/*   Updated: 2019/06/21 20:52:25 by zytrams          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int		*palette_generator(int start, int end, int iters)
{
	int		i;
	int		*palette;
	float	delta;
	float	d;

	palette = (int *)ft_memalloc((iters + 1) * sizeof(int));
	i = 0;
	delta = (end - start) / iters;
	d = start;
	while (i <= iters)
	{
		d += delta;
		palette[i] = rint(d);
		i++;
	}
	return (palette);
}
