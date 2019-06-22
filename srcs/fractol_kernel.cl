/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opencl.cl                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zytrams <zytrams@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 18:26:31 by zytrams           #+#    #+#             */
/*   Updated: 2019/06/20 18:26:33 by zytrams          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct		s_fractol
{
	int				type;
	int				width;
	int				height;
	int				iter;
	int				x;
	int				y;
	int				i;
	int				mi;
	int				color1;
	int				color2;
	int				color;
	__global int	*palette;
	double			cx;
	double			cy;
	double			zx;
	double			zy;
	double			xtemp;
	double			left;
	double			top;
	double			xside;
	double			yside;
	double			scale;
	double			log_zn;
	double			nu;
	double			inter;
}					t_fractol;

double				lerp(double s, double e, double t)
{
	return (s + ( e - s ) * t);
}

void				put_on_image(int x, int y, int color, t_fractol data, __global int *mem_img)
{
	size_t	offset;

	offset = x + data.width * y;
	mem_img[offset] = color;
}

void				julia(t_fractol data, __global int *palette, __global int *mem_img)
{
	data.cx = data.x * data.scale + data.left;
	data.cy = data.y * data.scale + data.top;
	data.zx = 0.0;
	data.zy = 0.0;
	data.i = 0;
	data.mi = data.iter;
	while (((data.zx * data.zx + data.zy * data.zy) <= (1 << 16)) && data.i < data.iter)
	{
		data.xtemp = data.zx * data.zx - data.zy * data.zy;
		data.zy = 2 * data.zx * data.zy  + data.cy;
		data.zx = data.xtemp + data.cx;
		data.i++;
	}
	put_on_image(data.x, data.y, palette[data.i], data, mem_img);
}

void				mandelbrot(t_fractol data, __global int *palette, __global int *mem_img)
{
	data.cx = data.x * data.scale + data.left;
	data.cy = data.y * data.scale + data.top;
	data.zx = 0.0;
	data.zy = 0.0;
	data.i = 0;
	data.mi = data.iter;
	while (((data.zx * data.zx + data.zy * data.zy) <= (1 << 16)) && data.i < data.iter)
	{
		data.xtemp = data.zx * data.zx - data.zy * data.zy + data.cx;
		data.zy = 2.0 * data.zx * data.zy + data.cy;
		data.zx = data.xtemp;
		data.i++;
	}
	/*
	if (data.i < data.mi)
	{
		data.log_zn = (double)log((double)((data.zx) * (data.zx) + (data.zy) * (data.zy))) / 2.0;
		data.nu = (double)log((double)data.log_zn / log(2.0)) / log(2.0);
		data.inter = data.i + 1 - data.nu;
	}
	else
	{
		data.inter = data.i;
	}
	data.color1 = data.palette[data.i];
	data.color2 = data.palette[(data.i + 1)];
	data.color = lerp(data.color1, data.color2, (double)modf(data.i, &data.nu));*/
	put_on_image(data.x, data.y, palette[data.i], data, mem_img);
}

static void			render(t_fractol data, __global int *mem_img)
{
	if (data.type == 1)
		mandelbrot(data, data.palette, mem_img);
	else
		julia(data, data.palette, mem_img);
}

__kernel void		test(__global int *int_mem, __global double *double_mem, __global int *mem_img, __global int *palette)
{
	t_fractol	data;
	int 		gid;
	int 		flg;

	gid = get_global_id(0);
	flg = int_mem[2];
	data.width = int_mem[0];
	data.height = int_mem[1];
	data.x = gid % data.width;
	data.y = gid / data.width;
	data.iter = int_mem[3];
	data.cx = double_mem[0];
	data.cy = double_mem[1];
	data.zx = double_mem[2];
	data.zy = double_mem[3];
	data.left = double_mem[5];
	data.top = double_mem[6];
	data.scale = double_mem[7];
	data.palette = palette;
	render(data, mem_img);
}
