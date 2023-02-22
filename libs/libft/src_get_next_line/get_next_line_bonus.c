/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egauthey <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 13:28:21 by egauthey          #+#    #+#             */
/*   Updated: 2022/10/23 13:28:32 by egauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

char	*fnextline(char *statstr)
{
	int		i;
	char	*nextline;
	int		j;

	i = 0;
	if (statstr == 0)
		return (NULL);
	while (statstr[i] != '\n' && statstr[i])
		i++;
	if (statstr[i] == '\0')
	{
		free(statstr);
		return (NULL);
	}
	nextline = malloc(sizeof(char) * (fstrlen(statstr) - i + 1));
	if (nextline == NULL)
		return (0);
	i++;
	j = 0;
	while (statstr[i])
		nextline[j++] = statstr[i++];
	nextline[j] = '\0';
	free(statstr);
	return (nextline);
}

char	*fgetline(char *str)
{
	int		i;
	char	*line;

	i = 0;
	if (*str == '\0')
		return (NULL);
	while (str[i] != '\n' && str[i])
		i++;
	if (str[i] == '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	if (line == 0)
		return (NULL);
	i = -1;
	while (str[++i] && str[i] != '\n')
		line[i] = str[i];
	if (str[i] == '\n')
	{
		line[i] = '\n';
		line[i + 1] = '\0';
	}
	else
		line[i] = '\0';
	return (line);
}

char	*freadfd(int fd, char *statstr)
{
	char	buff[BUFFER_SIZE + 1];
	int		byte_read;

	byte_read = 1;
	while (fstrchrn(statstr) == 0 && byte_read != 0)
	{
		byte_read = read(fd, buff, BUFFER_SIZE);
		if (byte_read == -1)
		{
			free(statstr);
			return (NULL);
		}
		buff[byte_read] = '\0';
		if (statstr == NULL)
			statstr = fstrdup("");
		statstr = fstrjoin(statstr, buff);
	}
	return (statstr);
}

char	*get_next_line(int fd)
{
	static char	*static_str[4096];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	static_str[fd] = freadfd(fd, static_str[fd]);
	if (static_str[fd] == 0)
		return (NULL);
	line = fgetline(static_str[fd]);
	static_str[fd] = fnextline(static_str[fd]);
	return (line);
}

/*
int	main()
{
	int		fd;
	int		fd2;
	int		fd3;
	int		fd4;
	char	*line;
	int		i;

	fd = open("file", O_RDONLY);
	if (fd == -1)
		printf("open fd failed.");
	printf("open fd succeeded %d\n", fd);

	fd2 = open("file2", O_RDONLY);
	if (fd == -1)
		printf("open fd2 failed.");
	printf("open fd2 succeeded %d\n", fd);

	fd3 = open("file3", O_RDONLY);
	if (fd == -1)
		printf("open fd3 failed.");
	printf("open fd3 succeeded %d\n", fd);

	fd4 = open("file4", O_RDONLY);
	if (fd == -1)
		printf("open fd4 failed.");
	printf("open fd4 succeeded %d\n", fd);

	i = 1;
	while (i < 7)
	{
	//for (int i = 0; i < 10; i++)
	//{
		line = get_next_line(fd);
		printf("%s", line);
		line = get_next_line(fd2);
		printf("%s", line);
		line = get_next_line(fd3);
		printf("%s", line);
		line = get_next_line(fd4);
		printf("%s", line);
		free(line);
		i++;
	}
	//line  = read(fd, buf, BUFFER_SIZE);
	// buf[retour] = '\0';
	// printf("this is the string we read {%s}\n", buf);
	if (close(fd) == -1)
		printf("close failed.");
	close(fd2);
	close(fd3);
	close(fd4);
	return (0);
}*/