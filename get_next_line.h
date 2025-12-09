/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwakatsu <hwakatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 19:05:39 by hwakatsu          #+#    #+#             */
/*   Updated: 2025/12/09 19:37:17 by hwakatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

// get_next_line_utils.c
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
char	*strjoin_and_free(char *s1, char *s2);
// get_next_line.c
char	*get_next_line(int fd);

#endif
