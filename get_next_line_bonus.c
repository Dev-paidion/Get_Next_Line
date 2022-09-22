/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjungoo <kjungoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 15:25:00 by kjungoo           #+#    #+#             */
/*   Updated: 2022/09/22 18:59:39 by kjungoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*ft_free_and_null(void *ptr)
{
	if (ptr)
	{	
		free(ptr);
		ptr = NULL;
	}
	return (NULL);
}

char	*get_line_until_nl(char *line)
{
	int		i;
	char	*result;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	result = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (result == 0)
		return (NULL);
	if (result[0] == '\0')
	{
		ft_free_and_null(result);
		return (NULL);
	}
	line[i + 1] = '\0';
	return (result);
}

char	*read_and_join(int fd, char *buf, char *backup)
{
	ssize_t	read_bytes;
	char	*tmp_p;

	while (1)
	{
		read_bytes = read(fd, buf, BUFFER_SIZE);
		if (read_bytes == -1)
			return (ft_free_and_null(backup));
		else if (read_bytes == 0)
			break ;
		buf[read_bytes] = '\0';
		if (backup == NULL)
			backup = ft_strdup("");
		tmp_p = backup;
		backup = ft_strjoin(backup, buf);
		if (backup == 0)
			return (NULL);
		ft_free_and_null(tmp_p);
		if (is_with_nl(buf, '\n') == 1)
			break ;
	}
	return (backup);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buf;
	static char	*backup[OPEN_MAX];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == NULL)
		return (NULL);
	line = read_and_join(fd, buf, backup[fd]);
	ft_free_and_null(buf);
	backup[fd] = NULL;
	if (line == NULL)
		return (NULL);
	backup[fd] = get_line_until_nl(line);
	return (line);
}
