/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjungoo <kjungoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 15:25:00 by kjungoo           #+#    #+#             */
/*   Updated: 2022/09/20 14:11:58 by kjungoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
#include <stdio.h>
#include <fcntl.h>
#define BUFFER_SIZE 5
*/

char	*ft_extract(char *line)
{
	int		i;
	char	*result;

	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
		i++;
	result = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (result == 0)
		return (NULL);
	if (result[0] == '\0')
	{
		free(result);
		result = NULL;
		return (NULL);
	}
	line[i + 1] = '\0';
	return (result);
}

char	*ft_read_line(int fd, char *buf, char *backup)
{
	ssize_t	read_bytes;
	char	*tmp_p;

	while (1)
	{
		read_bytes = read(fd, buf, BUFFER_SIZE);
		if (read_bytes == -1)
			return (0);
		else if (read_bytes == 0)
			break ;
		buf[read_bytes] = '\0';
		if (backup == NULL)
			backup = ft_strdup("");
		tmp_p = backup;
		backup = ft_strjoin(tmp_p, buf);
		if (backup == 0)
			return (NULL);
		free(tmp_p);
		tmp_p = NULL;
		if (is_with_nl(buf, '\n') == 1)
			break ;
	}
	return (backup);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buf;
	static char	*backup;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == NULL)
		return (NULL);
	line = ft_read_line(fd, buf, backup);
	free(buf);
	if (line == NULL)
		return (NULL);
	backup = ft_extract(line);
	return (line);
}

/*
int main()
{
	int		fd;

	fd = open("./test1.txt", O_RDONLY);

	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));

	close(fd);
	return (0);
} */
