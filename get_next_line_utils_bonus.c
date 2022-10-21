/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hidhmmou <hidhmmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 00:14:17 by hidhmmou          #+#    #+#             */
/*   Updated: 2022/10/21 21:09:26 by hidhmmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (ft_strlen(s) <= start + len)
		substr = malloc (ft_strlen(s) - start + 1);
	else
		substr = malloc (len + 1);
	if (!substr)
		return (NULL);
	while (s[start] && i < len)
		substr[i++] = s[start++];
	substr[i] = 0;
	return (substr);
}

char	*ft_strdup(const char *s1)
{
	int		len;
	int		index;
	char	*src_copy;	

	len = 0;
	index = -1;
	while (s1[len])
		len++;
	src_copy = malloc(sizeof(char) * (len + 1));
	if (!src_copy)
		return (NULL);
	while (s1[++index])
		src_copy[index] = s1[index];
	src_copy[index] = 0;
	return (src_copy);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		len_1;
	int		len_2;
	int		i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	len_1 = ft_strlen(s1);
	len_2 = ft_strlen(s2);
	str = malloc(sizeof(char) * len_1 + len_2 + 1);
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
		str[len_1++] = s2[i++];
	str[len_1] = 0;
	free((void *)s1);
	s1 = NULL;
	return (str);
}
