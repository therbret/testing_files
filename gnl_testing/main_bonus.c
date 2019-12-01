/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: therbret <therbret@gmx.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 17:09:42 by therbret          #+#    #+#             */
/*   Updated: 2019/11/28 17:17:09 by therbret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <sys/errno.h>
#include "get_next_line_bonus.h"

int	main(int ac, char **av)
{
	char 	*line1;
	char 	*line2;
	int		ret;
	int 	fd1;
	int 	fd2;

	line1 = NULL;
	line2 = NULL;
	fd1 = open(av[1], O_RDONLY);
	fd2 = open(av[2], O_RDONLY);
	if (fd1 == -1 || fd2 == -1)
	{
		printf("open returns -1\n%s\n", strerror(errno));
		return (-1);
	}
	while ((ret = get_next_line(fd1, &line1)) > 0)
	{
		puts(line1);
		free(line1);
	}
	if (ret == -1)
		printf("GNL returns -1\n%s\n", strerror(errno));

	while ((ret = get_next_line(fd2, &line2)) > 0)
	{
		puts(line2);
		free(line2);
	}
	if (ret == -1)
		printf("GNL returns -1\n%s\n", strerror(errno));

	close(fd1);
	close(fd2);
	system("leaks -quiet a.out");
	return (1);
	(void)ac;
	(void)av;
}

//check ctrl D EOF
