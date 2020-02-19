/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 08:54:38 by fde-capu          #+#    #+#             */
/*   Updated: 2020/02/19 00:27:34 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	r;

	r = 0;
	while (*(s + r))
		r++;
	return (r);
}

void	ft_bzero(void *s, size_t n)
{
	char	*p;

	p = s;
	while (n--)
	{
		*p = 0;
		p++;
	}
	return ;
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*c;

	c = malloc(count * size);
	if (!c)
		return (NULL);
	ft_bzero(c, count * size);
	return (c);
}

int		findline(char *r, char const *set)
{
	char	*p;
	char	*s;

	p = r;
	while ((r) && (*p))
	{
		s = (char *)set;
		while (*s)
		{
			if (*s == *p)
			{
				*p = 0;
				return (1);
			}
			s++;
		}
		p++;
	}
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static t_fdt	f;
	t_fdt			*p;
	int				r;

	p = gotofd(fd, &f, 1);
	if (p->finished)
	{
		*line = "";
		return (0);
	}
	r = readline(p);
	if (r == -1)
		return (r);
	*line = p->line;
	return (r ? 1 : 0);
}
