/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwakatsu <hwakatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 17:51:15 by hwakatsu          #+#    #+#             */
/*   Updated: 2025/12/09 19:38:57 by hwakatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*remain_content(char *content, bool *check)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*remain;

	i = 0;
	*check = true;
	while (content[i] && content[i] != '\n')
		i++;
	if (content[i] == '\n')
		i++;
	len = ft_strlen(content);
	if (i == len)
		return (free(content), NULL);
	remain = (char *)malloc(sizeof(char) * (len - i + 1));
	if (!remain)
		return (*check = false, free(content), NULL);
	j = 0;
	while (content[i])
		remain[(j++)] = content[(i++)];
	remain[j] = '\0';
	return (free(content), remain);
}

static char	*extract_line(char *content)
{
	size_t	i;
	char	*line;

	i = 0;
	if (!content || !content[i])
		return (NULL);
	while (content[i] && content[i] != '\n')
		i++;
	if (content[i] == '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (content[i] && content[i] != '\n')
	{
		line[i] = content[i];
		i++;
	}
	if (content[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

static char	*read_until_newline(int fd, char *content)
{
	char	*buf;
	ssize_t	bytes;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (free(content), NULL);
	bytes = 1;
	while (!ft_strchr(content, '\n') && bytes > 0)
	{
		bytes = read(fd, buf, sizeof(char) * BUFFER_SIZE);
		if (bytes < 0)
			return (free(buf), free(content), NULL);
		buf[bytes] = '\0';
		content = strjoin_and_free(content, buf);
		if (!content)
			return (free(buf), NULL);
	}
	free(buf);
	return (content);
}

static char	*content_initialize(char *content)
{
	if (!content)
	{
		content = (char *)malloc(sizeof(char) * 1);
		if (!content)
			return (NULL);
		content[0] = '\0';
	}
	return (content);
}

char	*get_next_line(int fd)
{
	static t_list	*head;
	t_list			*node;
	char			*line;
	bool			check;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	node = get_node(fd, &head);
	if (!node)
		return (NULL);
	node->content = content_initialize(node->content);
	if (!node->content)
		return (remove_node(fd, &head), NULL);
	node->content = read_until_newline(fd, node->content);
	if (!node->content)
		return (remove_node(fd, &head), NULL);
	line = extract_line(node->content);
	if (!line)
		return (remove_node(fd, &head), NULL);
	node->content = remain_content(node->content, &check);
	if (!node->content)
		remove_node(fd, &head);
	if (!check)
		return (free(line), NULL);
	return (line);
}
