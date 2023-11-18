/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambhar <rpambhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 16:59:02 by rpambhar          #+#    #+#             */
/*   Updated: 2023/11/17 15:06:01 by rpambhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*stash[FOPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash[fd] = ft_read(fd, stash[fd]);
	if (!stash[fd])
		return (NULL);
	line = ft_get_line(stash[fd]);
	if (line[0] == '\0')
	{
		stash[fd] = ft_update_stash(stash[fd]);
		return (free(line), NULL);
	}
	stash[fd] = ft_update_stash(stash[fd]);
	return (line);
}

char	*ft_read(int fd, char *stash)
{
	int		bytes_read;
	char	temp[BUFFER_SIZE + 1];

	bytes_read = 1;
	ft_bzero(&temp, BUFFER_SIZE + 1);
	while (bytes_read > 0 && !ft_strchr(temp, '\n'))
	{
		bytes_read = read(fd, temp, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free(stash), NULL);
		temp[bytes_read] = '\0';
		stash = ft_strjoin(stash, temp);
	}
	return (stash);
}

char	*ft_get_line(char *stash)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!stash)
		return (NULL);
	while (stash[j] && stash[j] != '\n')
		j++;
	if (stash[j] == '\n')
		j++;
	line = ft_calloc(j + 1, sizeof(char));
	if (!line)
		return (NULL);
	while (stash && stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_update_stash(char *stash)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	j = 0;
	if (!stash)
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
		return (free(stash), NULL);
	temp = ft_calloc((ft_strlen(stash) - i) + 1, sizeof(char));
	if (!temp)
		return (free(stash), NULL);
	i++;
	while (stash[i])
		temp[j++] = stash[i++];
	temp[j] = '\0';
	return (free(stash), temp);
}
