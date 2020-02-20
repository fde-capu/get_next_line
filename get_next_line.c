/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 08:16:55 by fde-capu          #+#    #+#             */
/*   Updated: 2020/02/20 18:49:26 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	int		r;
	char	*buffer;
	char	bufstack[BUFFER_SIZE + 1];
	char	*p;
	static char	*save;
	char	*foo;

	bufstack[BUFFER_SIZE] = 0;
	bufstack[0] = 0;
	*line = 0;
	r = -2;
	save = save ? save : ft_strcat(0, 0);
	while ((!ft_strchr(&bufstack[0], '\n')) && (r) && (!ft_strchr(save, '\n')))
	{
		buffer = &bufstack[0];
		bufstack[0] = 0;
		r = read(fd, buffer, BUFFER_SIZE);
		if (r == -1)
			return (r);
		bufstack[r] = 0;
//		printf("line: _%s_ b0: _%s_ --> ", *line, &bufstack[0]);
		foo = *line;
		*line = ft_strcat(*line, &bufstack[0]);
		free(foo);
//		printf("line: _%s_ \n", *line);
	}
	r = r == -2 && !ft_strchr(save, '\n') ? 0 : r;
//	printf("save: _%s_ line: _%s_ --> ", save, *line);
	foo = *line;
	*line = ft_strcat(save, *line);
	free(foo);
//	printf("line w: _%s_ ...", *line);
	p = ft_strchr(*line, '\n');
	if (p)
	{
		*p = 0;
		free(save);
		save = ft_strcat(p + 1, 0);
	}
//	printf("line w/o: _%s_ : save: _%s_\n", *line, save);
	return (r ? 1 : 0);
}
