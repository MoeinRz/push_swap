/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrezaei <mrezaei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:25:03 by mrezaei           #+#    #+#             */
/*   Updated: 2022/12/11 18:38:38 by mrezaei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//===========================================================================//
//find the next line                                                         //
//===========================================================================//
char	*ft_goto_next(char *str)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	if (!str)
		return (free(str), NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
		return (free(str), NULL);
	line = ft_calloc((ft_strlen(str) - i + 1), sizeof(char));
	if (line == NULL)
		return (free(str), free(line), NULL);
	i++;
	j = 0;
	while (str[i])
		line[j++] = str[i++];
	line[j + 1] = 0;
	return (free(str), line);
}

//===========================================================================//
//seprate first line                                                         //
//===========================================================================//
char	*ft_first_line(char *str)
{
	char	*line;
	int		i;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (str[i])
	{
		line[i] = str[i];
		if (line[i] == '\n')
		{
			i++;
			line[i] = '\0';
			break ;
		}
		i++;
	}
	return (line);
}

//===========================================================================//
//read file                                                                  //
//===========================================================================//
char	*ft_read_file(int fd, char *str)
{
	int		byte_read;
	char	*tmp;

	if (!str)
		str = ft_calloc(1, 1);
	tmp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	byte_read = 1;
	while (byte_read > 0)
	{
		byte_read = read(fd, tmp, BUFFER_SIZE);
		if (byte_read == -1)
			return (free(tmp), NULL);
		tmp[byte_read] = '\0';
		str = ft_strjoin(str, tmp);
		if (ft_strchr(tmp, '\n'))
			break ;
	}
	return (free(tmp), str);
}

//===========================================================================//
//get next line                                                              //
//===========================================================================//
char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	if (fd >= 0 && read(fd, 0, 0) >= 0 && BUFFER_SIZE > 0)
	{
		str = ft_read_file(fd, str);
		if (!str)
			return (NULL);
		line = ft_first_line(str);
		str = ft_goto_next(str);
		return (line);
	}
	else
		return (free(str), str = NULL, NULL);
}

//===========================================================================//
//main for test => gcc -Wall -Werror -Wextra -D BUFFER_SIZE=100 
//get_next_line.c get_next_line_utils.c && ./a.out
//===========================================================================//
// # include <stdlib.h>
// # include <sys/types.h>
// # include <sys/uio.h>
// # include <unistd.h>
// #include <sys/stat.h>
// #include <fcntl.h>
// #include <stdio.h>

// int	main(void)
// {
// 	char	*line;
// 	int		i;
// 	int		fd1;
// 	int		fd2;
// 	int		fd3;
// 	fd1 = open("big.txt", O_RDONLY);
// 	fd2 = open("test2.txt", O_RDONLY);
// 	fd3 = open("test3.txt", O_RDONLY);
// 	i = 1;
// 	while (i < 7)
// 	{
// 		line = get_next_line(fd1);
// 		printf("line [%02d]: %s", i, line);
// 		free(line);
// 		line = get_next_line(fd2);
// 		printf("line [%02d]: %s", i, line);
// 		free(line);
// 		line = get_next_line(fd3);
// 		printf("line [%02d]: %s\n", i, line);
// 		free(line);
// 		i++;
// 	}
// 	close(fd1);
// 	close(fd2);
// 	close(fd3);
// 	return (0);
// }