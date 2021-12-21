/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjustice <bjustice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 11:37:38 by bjustice          #+#    #+#             */
/*   Updated: 2021/12/20 17:31:05 by bjustice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"get_next_line.h"

char	*ft_makeresult(char **bufstorage)
{
	char	*result;
	char	*temp;
	int		i;

	i = 0;
	if (!(*bufstorage))
		return (NULL);
	while ((*bufstorage)[i] != '\n' && (*bufstorage)[i])
		i++;
	if (ft_strchr(*bufstorage, '\n'))
	{
		result = ft_substr(*bufstorage, 0, i + 1);
		temp = *bufstorage;
		i += 1;
		*bufstorage = ft_substr(*bufstorage, i, ft_strlen(*bufstorage) - i);
		free(temp);
	}
	else
	{
		result = *bufstorage;
		*bufstorage = NULL;
	}
	return (result);
}

char	*ft_makebufstorage(char *bufstorage, char *buf)
{
	char	*temp;

	if (bufstorage == NULL)
		bufstorage = ft_strdup(buf);
	else
	{
		temp = bufstorage;
		bufstorage = ft_strjoin(bufstorage, buf);
		free(temp);
	}
	return (bufstorage);
}

char	*get_next_line(int fd)
{
	static char	*bufstorage;
	char		*buf;
	int			bytes;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buf = (char *)malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	bytes = read(fd, buf, BUFFER_SIZE);
	while (bytes > 0)
	{
		buf[bytes] = '\0';
		bufstorage = ft_makebufstorage(bufstorage, buf);
		if (ft_strchr(bufstorage, '\n'))
			break ;
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes < 0)
			return (NULL);
	}
	free(buf);
	return (ft_makeresult(&bufstorage));
}
