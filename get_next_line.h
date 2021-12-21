/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjustice <bjustice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 11:41:35 by bjustice          #+#    #+#             */
/*   Updated: 2021/12/19 11:55:22 by bjustice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include	<unistd.h>
# include	<stdlib.h>
# include	<fcntl.h>

char	*get_next_line(int fd);

char	*ft_strchr(const char *str, int symb);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *str1);
char	*ft_substr(char const *s, unsigned int start, size_t len);

size_t	ft_strlen(const char *str);

#endif