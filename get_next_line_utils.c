/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 08:19:32 by fde-capu          #+#    #+#             */
/*   Updated: 2020/02/20 13:34:49 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//t_fdt	*init_fd(int fd)
//{
//	t_fdt	*newfd;
//
//	newfd = ft_calloc(sizeof(t_fdt), 1);
//	if (!newfd)
//		return (0);
//	newfd->fd = fd;
//	newfd->cursor = &newfd->buffer[0];
//	//newfd->line = ft_calloc(1, 1);
//	return (newfd);
//}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*d;
	const char	*s;
	const char	*lasts;
	char		*lastd;

	if ((!dst) && (!src))
		return (NULL);
	d = (char *)dst;
	s = (const char *)src;
	if (d < s)
		while (len--)
			*d++ = *s++;
	else
	{
		lasts = s + (len - 1);
		lastd = d + (len - 1);
		while (len--)
			*lastd-- = *lasts--;
	}
	return (dst);
}

char	*ft_strchr(const char *s, int c)
{
	char	*p;

	p = (char *)s;
	if (!c)
	{
		while ((p) && (*p))
			p++;
		return (p);
	}
	while ((*p) && (*p != c))
		p++;
	return (*p ? p : 0);
}

size_t	ft_strlen(const char *s)
{
	size_t	r;

	if ((!s) || (!*s))
		return (0);
	r = 0;
	while (*(s + r))
		r++;
	return (r);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*c;
	void	*z;

	c = malloc(count * size);
	if (!c)
		return (NULL);
	z = c;
	while (z - c < (long)(count * size))
	{
		*(char *)z = 0;
		z++;
	}
	return (c);
}

char	*ft_strcat(const char *dst, const char *src)
{
	char	*ret;
	char	*r;
	char	*w;

	ret = ft_calloc(ft_strlen(dst) + ft_strlen(src) + 1, 1);
	r = (char *)dst;
	w = (char *)ret;
	while ((r) && (*r))
	{
		*w = *r;
		w++;
		r++;
	}
	r = (char *)src;
	while ((r) && (*r))
	{
		*w = *r;
		w++;
		r++;
	}
	return (ret);
}
