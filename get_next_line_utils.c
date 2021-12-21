/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjustice <bjustice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 12:03:48 by bjustice          #+#    #+#             */
/*   Updated: 2021/12/19 12:04:00 by bjustice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strchr(const char *str, int symb)
{
	while (str)
	{
		if (*str == (char)symb)
			return ((char *)str);
		if (*str == '\0')
			return (NULL);
		str++;
	}
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*newstr;

	i = 0;
	j = 0;
	newstr = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (newstr == NULL)
		return (NULL);
	while (s1[i])
	{
		newstr[j] = s1[i];
		j++;
		i++;
	}
	i = 0;
	while (s2[i])
	{
		newstr[j] = s2[i];
		j++;
		i++;
	}
	newstr[j] = '\0';
	return (newstr);
}

char	*ft_strdup(const char *str1)
{
	size_t	len;
	char	*space;
	char	*s1;

	if (str1 == NULL)
		return (NULL);
	len = ft_strlen(str1);
	space = (char *)malloc(sizeof(char *) * len + 1);
	if (space == NULL)
		return (NULL);
	s1 = (char *)str1;
	while (len--)
	{
		*space = *s1;
		space++;
		s1++;
	}
	*space = '\0';
	return (space - ft_strlen(str1));
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{	
	char	*substring;
	size_t	i;

	i = 0;
	if (!s || (len > ft_strlen(s)) || (start > (ft_strlen(s) - 1)))
		return (0);
	substring = (char *)malloc(len + 1);
	if (!substring)
		return (0);
	while (len > 0)
	{
		substring[i] = s[start];
		i++;
		start++;
		len--;
	}
	substring[i] = '\0';
	return (substring);
}
