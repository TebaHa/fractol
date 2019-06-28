/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cl_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zytrams <zytrams@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 17:14:47 by zytrams           #+#    #+#             */
/*   Updated: 2019/06/28 16:09:03 by zytrams          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void			create_device(t_fractol_base *frc)
{
	cl_platform_id	platform;
	cl_device_id	dev;
	int				err;

	err = clGetPlatformIDs(1, &platform, NULL);
	if (err < 0)
		error_logger("Couldn't identify a platform");
	err = clGetDeviceIDs(platform, CL_DEVICE_TYPE_GPU, 1, &dev, NULL);
	if (err == CL_DEVICE_NOT_FOUND)
		err = clGetDeviceIDs(platform, CL_DEVICE_TYPE_CPU, 1, &dev, NULL);
	if (err < 0)
		error_logger("Couldn't access any devices");
	frc->cl_structs.device = dev;
	frc->cl_structs.ret = err;
}

static	void	costil(t_fractol_base *frc, int *mem, double *dmem)
{
	mem[0] = frc->width;
	mem[1] = frc->height;
	mem[2] = frc->type;
	mem[3] = frc->iter;
	mem[5] = frc->calc.i;
	mem[6] = frc->calc.mi;
	mem[7] = frc->type;
	mem[8] = frc->color_type;
	dmem[0] = frc->calc.cx;
	dmem[1] = frc->calc.cy;
	dmem[2] = frc->calc.zx;
	dmem[3] = frc->calc.zy;
	dmem[4] = frc->calc.xtemp;
	dmem[5] = frc->left;
	dmem[6] = frc->top;
	dmem[7] = frc->scale;
	dmem[8] = frc->julesx;
	dmem[9] = frc->julesy;
}

static void		cl_meminit(t_fractol_base *frc)
{
	frc->cl_structs.int_mem = clCreateBuffer(frc->cl_structs.context,
	CL_MEM_READ_WRITE, sizeof(int) * 32, NULL, &frc->cl_structs.ret);
	frc->cl_structs.mem_img = clCreateBuffer(frc->cl_structs.context,
	CL_MEM_READ_ONLY, sizeof(int) * WIDTH * HEIGHT, NULL, &frc->cl_structs.ret);
	frc->cl_structs.double_mem = clCreateBuffer(frc->cl_structs.context,
	CL_MEM_READ_WRITE, sizeof(double) * 32, NULL, &frc->cl_structs.ret);
	frc->cl_structs.palette = clCreateBuffer(frc->cl_structs.context,
	CL_MEM_READ_WRITE, sizeof(int)
	* (frc->iter + 1), NULL, &frc->cl_structs.ret);
	frc->cl_structs.ret = clSetKernelArg(frc->cl_structs.kernel,
	0, sizeof(cl_mem), &frc->cl_structs.int_mem);
	frc->cl_structs.ret = clSetKernelArg(frc->cl_structs.kernel,
	1, sizeof(cl_mem), &frc->cl_structs.double_mem);
	frc->cl_structs.ret = clSetKernelArg(frc->cl_structs.kernel,
	2, sizeof(cl_mem), &frc->cl_structs.mem_img);
	frc->cl_structs.ret = clSetKernelArg(frc->cl_structs.kernel,
	3, sizeof(cl_mem), &frc->cl_structs.palette);
}

void			init_cl(t_fractol_base *frc)
{
	char			*k_str;
	size_t			k_len;

	create_device(frc);
	frc->cl_structs.context = clCreateContext(NULL,
	1, &frc->cl_structs.device, NULL, NULL, &frc->cl_structs.ret);
	frc->cl_structs.queue = clCreateCommandQueue(frc->cl_structs.context,
	frc->cl_structs.device, 0, &frc->cl_structs.ret);
	k_str = read_file(PROGRAM_FILE);
	k_len = ft_strlen(k_str);
	frc->cl_structs.program =
	clCreateProgramWithSource(frc->cl_structs.context, 1,
	(const char**)&k_str, &k_len, &frc->cl_structs.ret);
	if (frc->cl_structs.ret < 0)
		error_logger("Couldn't create the program");
	ft_strdel(&k_str);
	frc->cl_structs.ret = clBuildProgram(frc->cl_structs.program,
											0, NULL, NULL, NULL, NULL);
	frc->cl_structs.kernel = clCreateKernel(frc->cl_structs.program,
										"test", &frc->cl_structs.ret);
	cl_meminit(frc);
}

void			run_cl(t_fractol_base *frc)
{
	size_t		kernel_num;
	int			ret;
	int			mem[32];
	double		dmem[32];

	kernel_num = WIDTH * HEIGHT;
	costil(frc, mem, dmem);
	ret = clEnqueueWriteBuffer(frc->cl_structs.queue, frc->cl_structs.int_mem,
	CL_TRUE, 0, sizeof(int) * 32, mem, 0, NULL, NULL);
	ret = clEnqueueWriteBuffer(frc->cl_structs.queue,
	frc->cl_structs.double_mem,
	CL_TRUE, 0, sizeof(double) * 32, dmem, 0, NULL, NULL);
	ret = clEnqueueWriteBuffer(frc->cl_structs.queue, frc->cl_structs.palette,
	CL_TRUE, 0, sizeof(int) * (frc->iter + 1), frc->palette, 0, NULL, NULL);
	ret = clEnqueueNDRangeKernel(frc->cl_structs.queue,
	frc->cl_structs.kernel,
	1, NULL, &kernel_num, NULL, 0, NULL, NULL);
	ret = clEnqueueReadBuffer(frc->cl_structs.queue,
	frc->cl_structs.mem_img, CL_TRUE, 0, sizeof(int) * frc->width * frc->height,
	frc->img->ptr_data, 0, NULL, NULL);
	mlx_put_image_to_window(frc->ptr_mlx,
	frc->ptr_window, frc->img->ptr_img, 0, 0);
}
