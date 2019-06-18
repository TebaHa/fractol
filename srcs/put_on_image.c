/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_on_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zytrams <zytrams@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 22:34:41 by zytrams           #+#    #+#             */
/*   Updated: 2019/06/12 19:05:34 by zytrams          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	put_on_image(int x, int y, int color, t_fractol *frc)
{
	size_t	offset;
	int		*ptr;

	ptr = (int *)frc->img->ptr_data;
	offset = x + frc->width * y;
	ptr[offset] = color;
}
