/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: therbret <therbret@gmx.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 17:31:06 by therbret          #+#    #+#             */
/*   Updated: 2019/11/24 10:48:48 by therbret         ###   ########.fr       */
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

	line = NULL;
	while ((ret = get_next_line(0, &line)) == 1)
	{
		puts(line);
		free(line);
	}
	if (ret == -1)
		printf("GNL returns -1\n%s\n", strerror(errno));
	system("leaks -quiet a.out");
	return (1);
	(void)ac;
	(void)av;
}

//check ctrl D EOF
