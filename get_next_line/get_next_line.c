/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiguero <tfiguero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 23:59:53 by tfiguero          #+#    #+#             */
/*   Updated: 2023/06/05 15:48:58 by tfiguero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd) {
  static  tdata data;
  char    *buffer;
  char    *ret;
  int     flag;
  // char    *temp;

  flag = 1;
  if (fd < 0)
    return (NULL);
  buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
  if (!buffer)
    return (NULL);
  if (!data.ptr) {
    data.ptr = (char *)malloc(sizeof(char) * 1);
    if (!data.ptr) {
      free(buffer);
      return (NULL);
    }
    data.ptr[0] = '\0';
  }
  // printf("%p\n", data.ptr);
  // printf("%p\n", buffer);
  buffer[0] = '\0';
  while (flag > 0 && !ft_strchr(buffer, '\n')) {
    flag = read(fd, buffer, BUFFER_SIZE);
    if(flag == -1)
    {
	    free(buffer);
      free(data.ptr - data.i);
      data.i = 0;
      data.ptr = NULL;
      return(NULL);
    }
    else
      *(buffer + flag) = '\0';
    if (flag > 0) {
      data.ptr = ft_strjoin(data, buffer);
      if (!data.ptr) {
        free(buffer);
        return (NULL);
      }
      if (data.i != 0)
        data.i = 0;
    }
  }
  free(buffer);
  if ((data.ptr && ft_strlen(data.ptr) == 0) && flag == 0) 
  {
    free(data.ptr - data.i);
    data.i = 0;
    data.ptr = NULL;
    return (NULL);
  }
  data = ft_output(data);
  ret = ft_substr(data.ptr - data.i, 0, data.i);
  if (!ret) {
    free(data.ptr-data.i);
    data.i = 0;
    data.ptr = NULL;
    return (NULL);
  }
  if (ft_strlen(ret) == 0)
    ret = NULL;
  if (!ft_strchr(ret, '\n')) {
    free(data.ptr - data.i);
    data.ptr = NULL;
    data.i = 0;
  }
  return (ret);
}