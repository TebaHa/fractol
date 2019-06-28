/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zytrams <zytrams@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 15:35:43 by zytrams           #+#    #+#             */
/*   Updated: 2019/06/28 15:35:56 by zytrams          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

char				*read_file(char *path)
{
	int			fd;
	int			number;
	char		*buff;

	fd = open(path, O_RDONLY);
	buff = (char*)malloc(sizeof(char) * 10000);
	if (fd < 2)
		exit(99);
	number = read(fd, buff, 10000);
	buff[number] = '\0';
	close(fd);
	return (buff);
}
