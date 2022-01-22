/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkeskint <bkeskint@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 15:52:20 by bkeskint          #+#    #+#             */
/*   Updated: 2021/10/21 19:25:05 by bkeskint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

int	getheight(char *file_name)
{
	char	*line;
	int		fd;
	int		h;

	fd = open (file_name, O_RDONLY, 0);
	if (fd < 0)
		ft_exit("getheight - Cannot open file\n");
	h = 0;
	while (get_next_line(fd, &line))
	{
		h++;
		free(line);
	}
	free(line);
	close (fd);
	return (h);
}

size_t	wcounter(char const *s, char c)
{
	size_t	i;
	size_t	count;

	if (!s[0])
		return (0);
	i = 0;
	count = 0;
	while (s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c)
		{
			count++;
			while (s[i] == c)
				i++;
			continue ;
		}
		i++;
	}
	if (s[i - 1] != c)
		count++;
	return (count);
}

int	getwidth(char *file_name)
{
	char	*line;
	int		fd;
	size_t	w;

	fd = open (file_name, O_RDONLY, 0);
	if (fd < 0)
		ft_exit("getwidth - Cannot open file\n");
	get_next_line(fd, &line);
	w = wcounter(line, ' ');
	free(line);
	while (get_next_line(fd, &line))
	{
		if (w != wcounter(line, ' '))
		{
			free(line);
			ft_exit("Invalid map format\n");
		}
		free(line);
	}
	free(line);
	close(fd);
	return (w);
}

void	fill_matrix(int *z_line, char *line)
{
	char	**nums;
	int		i;

	nums = ft_split(line, ' ');
	i = 0;
	while (nums[i])
	{
		z_line[i] = ft_atoi(nums[i]);
		free(nums[i]);
		i++;
	}
	free(nums);
}

void	reader(char *file_name, t_fdf *data)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	data->h = getheight (file_name);
	data->w = getwidth (file_name);
	data->matrix = (int **) malloc(sizeof (int *) * (data->h + 1));
	while (i < data->h)
	{
		data->matrix[i] = (int *) malloc (sizeof (int *) * (data->w + 1));
		i++;
	}
	data->matrix[i] = NULL;
	fd = open(file_name, O_RDONLY, 0);
	i = 0;
	while (get_next_line (fd, &line))
	{
		fill_matrix(data->matrix[i], line);
		free(line);
		i++;
	}
	free(line);
	close(fd);
}
