/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwakatsu <hwakatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 17:52:37 by hwakatsu          #+#    #+#             */
/*   Updated: 2025/12/09 19:01:22 by hwakatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

typedef struct s_list
{
	int				fd;
	char			*content;
	struct s_list	*next;
}					t_list;

// get_next_line_utils_bonus.c
char				*ft_strchr(const char *s, int c);
size_t				ft_strlen(const char *s);
char				*strjoin_and_free(char *s1, char *s2);
t_list				*get_node(int fd, t_list **head);
void				remove_node(int fd, t_list **head);
// get_next_line_bonus.c
char				*get_next_line(int fd);

#endif
