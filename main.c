/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 08:51:38 by fde-capu          #+#    #+#             */
/*   Updated: 2020/02/05 15:25:28 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int	main(void)
{
	printf("\nget_next_line\n=============\n==== fde-capu\n\n");
	int		fd = open("testfile.txt", O_RDONLY);	
	printf("Buffer size: %d\nFile fd = %d\n", BUFFER_SIZE, fd);
	char	**line = 0;
	char	*cursor = 0;
	line = &cursor;
	int		r = get_next_line(fd, line);
	printf("Return (1 ok, 0 eof, -1 err): %d\n", r);
	printf("Line:>>%s<<", *line);
	printf("<<< EOF\n");
	printf("\n");
	close(fd);
	return (0);
}
