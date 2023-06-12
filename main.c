/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiguero <tfiguero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 11:44:28 by tfiguero          #+#    #+#             */
/*   Updated: 2023/06/12 20:15:07 by tfiguero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
# include <fcntl.h>
#include <stdio.h>

int	main()
{
	int	fd;
	char *x;

	fd = open("text", O_RDONLY);
	x =  get_next_line(fd);
	while(x)
	{
		printf("%s",x);
		x = get_next_line(fd);
	}
  return (0);
}