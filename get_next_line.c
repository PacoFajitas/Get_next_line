/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiguero <tfiguero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 11:43:25 by tfiguero          #+#    #+#             */
/*   Updated: 2023/06/12 20:29:49 by tfiguero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char **buffer)
{
	free(*buffer);
	*buffer = NULL;
	return (NULL);
}

char	*ft_fill_data(char *data, int fd, int flag)
{
	char	*buffer;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (ft_free(&data));
	while (!ft_strchr(data, '\n') && flag > 0)
	{
		flag = read(fd, buffer, BUFFER_SIZE);
		if (flag == -1)
		{
			free (buffer);
			return (ft_free(&data));
		}
		buffer[flag] = '\0';
		if (flag > 0)
		{
			data = ft_strjoin(data, buffer);
			if (!data)
			{
				//free(buffer); Si descomento esto me da ko abort en todos los nullchecks KO
				return (NULL);
			}
		}
	}
	free (buffer);
	if ((data && ft_strlen(data) == 0) && flag == 0)
		return (ft_free(&data));
	return (data);
}

char	*ft_clean_buffer(char *data)
{
	char	*nl;
	size_t	len_nl;
	size_t	len_og;
	size_t	x;

	len_og = ft_strlen(data);
	if (!(ft_strchr(data, '\n') + 1))
		return (NULL);
	len_nl = ft_strlen(ft_strchr(data, '\n') + 1);
	nl = (char *)malloc((len_nl + 1) * sizeof(char));
	if (!nl)
		return (NULL);
	nl[len_nl] = '\0';
	x = 0;
	data = ft_strchr(data, '\n') + 1;
	while (x < len_nl)
	{
		nl[x] = data[x];
		x++;
	}
	data = data - (len_og - len_nl);
	free (data);
	data = NULL;
	data = nl;
	return (data);
}

char	*get_next_line(int fd)
{
	static char	*data;
	char		*ret;

	if (fd < 0)
		return (NULL);
	if (!data)
	{
		data = (char *)malloc(sizeof(char) * 1);
		if (!data)
			return (NULL);
		data[0] = '\0';
	}
	data = ft_fill_data(data, fd, 1);
	if (!data)
		return (NULL);
	if (ft_strchr(data, '\n'))
	{
		ret = ft_substr(data, 0, ft_strlen(data) - ft_strlen(ft_strchr
					(data, '\n')) + 1);
		if (!ret)
			return (ft_free(&data));
		data = ft_clean_buffer(data);
		if (!data)
			return (ft_free(&data));
	}
	else
	{
		ret = data;
		data = NULL;
	}
	return (ret);
}
