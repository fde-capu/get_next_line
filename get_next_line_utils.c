/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 08:57:22 by fde-capu          #+#    #+#             */
/*   Updated: 2020/02/05 15:57:48 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	realocbufa(fdt *m)
{
	void			*na;
	unsigned int	rb;
	unsigned int	zl;
	char			*z;

	rb = 0;
	m->bufs++;
	zl = (m->bufs * BUFFER_SIZE) + 1;
	na = malloc(zl);
	z = na;
	while (zl)
		*(z + zl--) = 0;
	if (m->bufs > 1)
	{
		while (*(m->buf + rb))
		{
			*(z + rb) = *(m->buf + rb);
			rb++;
		}
		free(m->bufa);
	}
	m->bufa = na;
	m->buf = na + ((m->bufs - 1) * BUFFER_SIZE);
	return ;
}

void	*init_fdtable(int fd)
{
	fdt		*m;

	m = malloc(sizeof(fdt));
	m->pt = 0;
	m->fd = fd;
	m->bufa = 0;
	m->buf = 0;
	m->bufs = 0;
	m->nx = 0;
	realocbufa(m);
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
	int				rok;
	int				eol;
	int				eof;
	unsigned int	v;

	eol = 0;
	v = 0;
	while (!eol)
	{
		rok = read(p->fd, p->buf, BUFFER_SIZE);
		if (rok == -1)
			return (0);
		eof = rok ? 0 : 1;
		eol = eof ? 1 : 0;
		while ((*(p->buf + v)) && (!eol))
		{
			printf("%c", *(p->buf + v));
			if (*(p->buf + v) == '\n')
				eol = 1;	
			v++;
		}
		if ((!*(p->buf + v)) && (!eof))
		{
			printf(".");
			realocbufa(p);
		}
	}
	return (p->bufa);
}
