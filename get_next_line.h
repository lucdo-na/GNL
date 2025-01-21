/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdo-na <lucdo-na@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 21:11:18 by lucdo-na          #+#    #+#             */
/*   Updated: 2025/01/21 18:19:19 by lucdo-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#define BUFFER_SIZE 5
# endif
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*get_next_line(int fd);
#endif