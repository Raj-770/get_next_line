/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambhar <rpambhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 16:59:37 by rpambhar          #+#    #+#             */
/*   Updated: 2023/11/16 12:16:21 by rpambhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);
char	*ft_read(int fd, char *stash);
char	*ft_get_line(char *stash);
char	*ft_update_stash(char *stash);

char	*ft_strjoin(char *s1, char *s2);
int		ft_strchr(char *str, char c);
int		ft_strlen(const char *s);
void	*ft_calloc(size_t nitems, size_t size);
void	*ft_bzero(void *ptr, size_t n);

#endif
