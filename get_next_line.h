/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 08:55:57 by fde-capu          #+#    #+#             */
/*   Updated: 2020/02/17 11:50:37 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h> // REM
# define NEW_LINE_CHARS "\n"

typedef struct	s_fdtable
{
	void				*bf;
	char				*wr;
	int					fd;
	int					size;
	struct s_fdtable	*nx;
}				t_fdt;

void			ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t count, size_t size);
int				get_next_line(int fd, char **line);
void			*init_fdtable(int fd);
t_fdt			*gotofd(int fd, t_fdt *f);
int				readline(t_fdt *p);
char			*findline(char *r, char const *set);
void			preparenxtbuf(t_fdt *p);

#endif
