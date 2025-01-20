/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdo-na <lucdo-na@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 20:22:10 by lucdo-na          #+#    #+#             */
/*   Updated: 2025/01/20 20:43:00 by lucdo-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *ft_set_str(char *str)
{
    char    *rest;
    ssize_t i;

    i = 0;
    while(str[i] != '\n' && str[i] != '\0')
        i++;
    if (str[i] == 0 || str[1] == 0)
        return (NULL);
    rest = ft_substr(str, i + 1, ft_strlen(str) - i);
    if (rest == 0)
    {
        free (rest);
        return (NULL);
    }
    str[i + 1] = 0;
    return (rest);
}

static char *ft_fill_buff(int fd, char *rest, char *buf)
{
    ssize_t i;
    char    *tmp;

    i = 1;
    while (i > 0)
    {
        i = read(fd, buf, BUFFER_SIZE);
        if (i == -1)
        {
            free(i);
            return(NULL);
        }
        else if(i == 0)
            break;
        buf[i] = 0;
        if(!rest)
            rest = ft_strdup("");
        tmp = rest;
        rest = ft_strjoin(tmp, buffer);
        free(tmp);
        tmp = NULL;
        if (ft_strchr(buf, '\n'))
            break;
    }
    return (rest);
}

char    *get_next_line(int fd)
{
    static char *rest;
    char        *str;
    char        *buf;

    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
    {
        free(rest);
        free(buf);
        rest = NULL;
        buf = NULL;
        return (NULL);
    }
    buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!buf)
        return (0);
    str = ft_fill_buff(fd, rest, buf);
    free(buf);
    buf = NULL;
    if (!str)
        return (NULL);
    rest = ft_set_str(str);
    return (str);
}