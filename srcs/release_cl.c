/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   release_cl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zytrams <zytrams@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 17:27:24 by zytrams           #+#    #+#             */
/*   Updated: 2019/06/19 19:46:56 by zytrams          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <fractol.h>

void	release_resources(t_cl_struct *cl_s)
{
	int ret;

	ret = 0;
	ret += clFinish(cl_s->queue);
	ret += clFlush(cl_s->queue);
	ret += clReleaseMemObject(cl_s->int_mem);
	ret += clReleaseMemObject(cl_s->double_mem);
	ret += clReleaseMemObject(cl_s->double_mem);
	ret += clReleaseKernel(cl_s->kernel);
	ret += clReleaseCommandQueue(cl_s->queue);
	ret += clReleaseProgram(cl_s->program);
	ret += clReleaseContext(cl_s->context);
	ret += clReleaseDevice(cl_s->device);
	exit(0);
}
