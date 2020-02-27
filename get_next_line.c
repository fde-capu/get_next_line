/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 08:54:38 by fde-capu          #+#    #+#             */
/*   Updated: 2020/02/19 02:25:05 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*d;
	const char	*s;

	if ((!dst) && (!src))
		return (NULL);
	d = dst;
	s = src;
	while (n--)
		*d++ = *s++;
	return (dst);
}

size_t	ft_strlen(const char *s)
{
	size_t	r;

	r = 0;
	while (*(s + r))
		r++;
	return (r);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*c;
	char	*z;

	c = malloc(count * size);
	if (!c)
		return (NULL);
	z = c;
	while (z - c < count * size)
	{
		*z = 0;
		z++;
	}
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
				return (p - r + 1);
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
