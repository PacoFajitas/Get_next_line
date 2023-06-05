/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiguero <tfiguero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 21:12:46 by tfiguero          #+#    #+#             */
/*   Updated: 2023/06/05 13:19:34 by tfiguero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (ft_strlen(s) <= start)
		len = 0;
	else if (ft_strlen(s + start) < len)
		len = (ft_strlen(s + start));
	str = (char *)malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	while (s[i])
	{
		if (i >= start && j < len)
		{
			str[j] = s[i];
			j++;
		}
		i++;
	}
	str[j] = '\0';
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}

char	*ft_strjoin(tdata ret, char *s2)
{
	size_t	i;
	size_t	j;
	char	*str;
	
	i = 0;
	j = 0;
	str = (char *)malloc(ft_strlen(ret.ptr) + ft_strlen(s2) + 1);
	if (!str)
	{
		free(ret.ptr - ret.i);
        ret.ptr = NULL;
		return (NULL);
	}
	while (ret.ptr[i])
	{
		str[i] = ret.ptr[i];
		i++;
	}
	while (s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	free (ret.ptr - ret.i);
	// ret.ptr = NULL;
	return (str);
}

tdata	ft_output(tdata data)
{

	while (*data.ptr != '\0' && *data.ptr != '\n')
	{
		data.ptr++;
		data.i++;
	}
	if (*data.ptr != '\0')
	{
		data.ptr++;
		data.i++;
	}
	return (data);
}