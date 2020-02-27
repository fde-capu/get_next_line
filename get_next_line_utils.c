/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 08:57:22 by fde-capu          #+#    #+#             */
/*   Updated: 2020/02/19 02:35:30 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*init_fdtable(int fd)
{
	t_fdt		*m;

	m = ft_calloc(sizeof(t_fdt), 1);
	m->fd = fd;
	return (m);
}

t_fdt	*gotofd(int fd, t_fdt *f, int create)
{
	while ((f) && (f->fd != fd))
	{
		if (f->nx)
			f = f->nx;
		else
		{
			if (create)
				f->nx = init_fdtable(fd);
			return (create ? f->nx : 0);
		}
	}
	return (f);
}

void	spitline(t_fdt *p)
{
	char			*r;
	char			*w;
	unsigned int	size;
	char			*tmp;

	size = ft_strlen(p->bf);
	p->line = ft_calloc(size + 1, 1);
	w = p->line;
	r = p->bf;
	while (*r)
	{
		*w = *r;
		r++;
		w++;
	}
	r++;
	p->size -= size;
	tmp = ft_calloc(p->size + 1, 1);
	w = tmp;
	while (*r)
	{
		*w = *r;
		r++;
		w++;
	}
	free(tmp);
	p->bf = tmp;
	return ;
}

int		preparenxtbuf(t_fdt *p, unsigned int size)
{
	char	*tmp;
	char	*r;
	char	*w;

	if (findline(p->bf, NEW_LINE_CHARS))
	{
		spitline(p);
		return (1);
	}
	p->size += size;
	tmp = ft_calloc(p->size + 1, 1);
	w = tmp;
	r = p->bf;
	while (r && *r)
	{
		*w = *r;
		w++;
		r++;
	}
	free(p->bf ? p->bf : 0);
	p->bf = tmp;
	return (0);
}

int		readline(t_fdt *p)
{
	int		rds;
	int		fl;
	char	*wx;

	wx = p->wr;
	rds = read(p->fd, p->wr, BUFFER_SIZE);
	if (rds == -1)
		return (rds);
	fl = findline(rad, NEW_LINE_CHARS);
	if ((fl) || (!rds))
	{
		p->line = ft_calloc(fl ? fl : ft_strlen(wx), 1);
		p->line = ft_memcpy(p->line, rd, fl);
		return (rds);
	}
}
