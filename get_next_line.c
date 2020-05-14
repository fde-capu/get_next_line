/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 16:17:57 by fde-capu          #+#    #+#             */
/*   Updated: 2020/05/14 18:44:48 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	clear(char *s)
{
	int	x;

	x = 0;
	while (x < BUFFER_SIZE)
	{
		*(s + x) = 0;
		x++;
	}
	return ;
}

int		get_next_line(int fd, char **line)
{
	static char	save[BUFFER_SIZE + 1];
	int			r;
	char		tmp[BUFFER_SIZE + 1];
	char		*buf;

	if ((!line) || BUFFER_SIZE == 0)
		return (-1);
	*line = concat(NULL, save);
	r = 1;
	while ((r) && (!findnl(*line)))
	{
		buf = tmp;
		r = read(fd, buf, BUFFER_SIZE);
		if (r == -1)
		{
			*line = NULL;
			return (r);
		}
		tmp[r] = 0;
		*line = concat(*line, tmp);
	}
	clear(save);
	dosave(*line, save);
	return (r ? 1 : 0);
}
