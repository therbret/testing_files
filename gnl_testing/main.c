/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: therbret <therbret@gmx.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 17:31:06 by therbret          #+#    #+#             */
/*   Updated: 2019/12/06 02:27:34 by therbret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <sys/errno.h>
#include "get_next_line.h"

int	main(int ac, char **av)
{
	char 	*line;
	int		ret;
	int 	fd;

	line = NULL;
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		printf("open returns -1\n%s\n", strerror(errno));
		return (-1);
	}
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		puts(line);
		free(line);
	}
	if (ret == 0)
		printf("0:%s\n", line);
	else
		printf("GNL error!\n%s\n", strerror(errno));
	close(fd);
	system("leaks a.out");
	return (1);
	(void)ac;
	(void)av;
}

//check ctrl D EOF
