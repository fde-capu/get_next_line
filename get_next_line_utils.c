/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 08:57:22 by fde-capu          #+#    #+#             */
/*   Updated: 2020/02/17 12:57:29 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void		*init_fdtable(int fd)
{
	t_fdt		*m;

	m = ft_calloc(sizeof(t_fdt), 1);
	m->bf = 0;
	m->wr = 0;
	m->fd = fd;
	m->size = BUFFER_SIZE;
	m->nx = 0;
	return (m);
}

t_fdt		*gotofd(int fd, t_fdt *f)
{
	while (f->fd != fd)
	{
		if (f->nx)
			f = f->nx;
		else
		{
			f->nx = init_fdtable(fd);
			return (f->nx);
		}
	}
	return (f);
}

void		preparenxtbuf(t_fdt *p)
{
	char	*cp;
	char	*tmp;
	char	*r;
	char	*w;

	cp = findline(p->bf, NEW_LINE_CHARS);
	p->size = cp ? BUFFER_SIZE : p->size + BUFFER_SIZE;
	tmp = ft_calloc(p->size + 1, 1);
	r = cp ? cp + 1 : p->bf;
	w = tmp;
	while ((p->bf) && (*r))
	{
		*w = *r;
		w++;
		r++;
	}
	if (p->bf)
		free(p->bf);
	p->bf = tmp;
	p->wr = w;
	return ;
}

int			readline(t_fdt *p)
{
	int		r;
	char	*rl;

	preparenxtbuf(p);
	r = read(p->fd, p->wr, BUFFER_SIZE);
	if ((r == -1) || (!r))
		return (r);
	rl = findline(p->wr, NEW_LINE_CHARS);
	if (rl)
		return (1);
	return (readline(p));
}
