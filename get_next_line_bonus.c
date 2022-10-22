/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hidhmmou <hidhmmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 19:50:00 by hidhmmou          #+#    #+#             */
/*   Updated: 2022/10/21 21:34:53 by hidhmmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*temp[512];
	char		*line;
	char		buffer[BUFFER_SIZE + 1];
	int			ret;
	int			nl_i;

	if (!temp[fd])
		temp[fd] = ft_strdup("");
	ret = read(fd, buffer, BUFFER_SIZE);
	while (ret >= 0)
	{
		buffer[ret] = 0;
		temp[fd] = ft_strjoin(temp[fd], buffer);
		nl_i = ft_find_nl(temp[fd]);
		if (nl_i != -1)
			return (ft_line(&line, &temp[fd], nl_i));
		if (!ret && !temp[fd][0])
			break ;
		if (!ret)
			return (ft_reminder(&temp[fd], 0));
		ret = read(fd, buffer, BUFFER_SIZE);
	}
	free(temp[fd]);
	temp[fd] = NULL;
	return (NULL);
}

int	ft_find_nl(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_reminder(char **str, int nl_i)
{
	char	*reminder;
	int		len;

	len = ft_strlen(*str + nl_i);
	reminder = ft_substr(*str, nl_i, len);
	free(*str);
	*str = NULL;
	return (reminder);
}

char	*ft_line(char **line, char **temp, int nl_i)
{
	*line = ft_substr(*temp, 0, nl_i + 1);
	*temp = ft_reminder(temp, nl_i + 1);
	return (*line);
}

size_t	ft_strlen(const char *s)
{
	size_t	l;

	l = 0;
	while (s[l])
		l++;
	return (l);
}
