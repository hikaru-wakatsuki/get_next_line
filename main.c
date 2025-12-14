/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwakatsu <hwakatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 23:27:42 by hwakatsu          #+#    #+#             */
/*   Updated: 2025/12/14 13:48:45 by hwakatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*line;
	int		i;

	fd = open("test.txt", O_RDONLY);
	if (fd < 0)
		return (1);
	printf("=== START READING ===\n\n");
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
		{
			printf("EOF or error.\n");
			break ;
		}
		printf("LINE%d: %s", i, line);
		i++;
		free(line);
	}
	close(fd);
	printf("\n=== FINISHED ===\n");
	return (0);
}

// #include "get_next_line_bonus.h"
// #include <stdio.h>

// int	main(void)
// {
// 	char	*line1;
// 	char	*line2;
// 	int		fd1;
// 	int		fd2;

// 	fd1 = open("test1.txt", O_RDONLY);
// 	fd2 = open("test2.txt", O_RDONLY);
// 	if (fd1 < 0 || fd2 < 0)
// 		return (1);
// 	printf("=== START READING (BONUS) ===\n\n");
// 	while (1)
// 	{
// 		line1 = get_next_line(fd1);
// 		line2 = get_next_line(fd2);
// 		if (!line1 && !line2)
// 		{
// 			printf("EOF on both files.\n");
// 			break ;
// 		}
// 		if (line1)
// 		{
// 			printf("[FD1] %s", line1);
// 			free(line1);
// 		}
// 		if (line2)
// 		{
// 			printf("[FD2] %s", line2);
// 			free(line2);
// 		}
// 	}
// 	close(fd1);
// 	close(fd2);
// 	printf("\n=== FINISHED ===\n");
// 	return (0);
// }
