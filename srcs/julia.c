/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zytrams <zytrams@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 18:54:53 by zytrams           #+#    #+#             */
/*   Updated: 2019/06/24 20:46:07 by zytrams          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void		init_julia(t_fractol_base *fra)
{
	fra->xside = 8;
	fra->yside = 5;
	fra->scale = 0.005;
	fra->top = -3;
	fra->left = -5;
	fra->iter = 100;
	fra->color_type = 1;
	fra->calc.cx = 0.0;
	fra->calc.cy = 0.0;
	fra->calc.zx = 0.0;
	fra->calc.zy = 0.0;
	fra->calc.i = 0;
	fra->calc.mi = fra->iter;
	fra->julesx = 0.271250;
	fra->julesy = 0.000000;
	fra->jules = -1;
}
