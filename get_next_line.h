
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 08:55:57 by fde-capu          #+#    #+#             */
/*   Updated: 2020/02/19 01:47:47 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>//
# define NEW_LINE_CHARS "\n"

//typedef struct	s_fdtable
//{
//	int					fd;
//	char				*line;
//	char				buffer[BUFFER_SIZE];
//	char				*cursor;
//	struct s_fdtable	*nx;
//}				t_fdt;

/*
** get_next_line_utils.c
*/
//t_fdt			*init_fd(int fd);
void			*ft_memmove(void *dst, const void *src, size_t len);
char			*ft_strchr(const char *s, int c);
size_t			ft_strlen(const char *s);
void			*ft_calloc(size_t count, size_t size);
char			*ft_strcat(const char *dst, const char *src);

/*
** get_next_line.c
*/
int				get_next_line(int fd, char **line);

#endif
