/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 08:57:22 by fde-capu          #+#    #+#             */
/*   Updated: 2020/02/05 13:21:02 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*init_fdtable(int fd)
{
	fdt	*m;

	m = malloc(sizeof(fdt));
	m->pt = 0;
	m->fd = fd;
	m->bufa = malloc(sizeof(BUFFER_SIZE));
	m->buf = m->bufa;
	m->nx = 0;
	return (m);
}

fdt		*fdisopen(int fd, fdt *f)
{
	while (f != 0)
	{
		if (f->fd == fd)
			return (f);
		f = f->nx;
	}
	return (0);
}

fdt		*newfd(int fd, fdt *f)
{
	while (f->nx)
		f = f->nx;
	f->nx = init_fdtable(fd);
	return (f->nx);
}

char	*readline(fdt *p)
{
	int	rok;

	rok = read(p->fd, p->buf, 1);
	if (!rok)
		return (0);
	return (p->buf);
}
