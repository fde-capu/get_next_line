#include<stdio.h> 
#include<fcntl.h> 
#include<unistd.h>
#include<stdbool.h>
#include<string.h>
#include<time.h>
#include "get_next_line.h"

int	main(void)
{
	int fd = open("test.txt",O_RDONLY);
	int fd2 = open("test2.txt",O_RDONLY);
	int	r;
	char	*c;
	int	r2;
	char	*c2;

	r = 1;
	r2 = 1;
	while (r || r2)
	{
		r = get_next_line(fd, &c);
		if (r)
			printf("(%d) %d: _%s_\n", fd, r, c);
		r2 = get_next_line(fd2, &c2);
		if (r2)
			printf("(%d) %d: _%s_\n", fd2, r2, c2);
	}
	return (0);
}
