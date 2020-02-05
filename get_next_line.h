/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 08:55:57 by fde-capu          #+#    #+#             */
/*   Updated: 2020/02/05 13:22:19 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <sys/types.h>
# include <sys/uio.h>
# include <stdlib.h>

typedef struct	fdtable
{
	void			*pt;
	int				fd;
	void			*bufa;
	char			*buf;
	struct fdtable	*nx;
} fdt;

int		get_next_line(int fd, char **line);
void	*init_fdtable(int fd);
fdt		*fdisopen(int fd, fdt *f);
fdt		*newfd(int fd, fdt *f);
char	*readline(fdt *p);

#endif
