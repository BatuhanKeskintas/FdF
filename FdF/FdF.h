/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkeskint <bkeskint@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 15:35:10 by bkeskint          #+#    #+#             */
/*   Updated: 2021/10/21 19:01:22 by bkeskint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include "minilibx_macos/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <string.h>
# include <math.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

# define MAX_FD 1024

typedef struct s_fdf
{
	int		h;
	int		w;
	int		z;
	int		z2;
	float	x;
	float	y;
	float	x2;
	float	y2;
	int		**matrix;
	float	zoom;
	int		color;
	int		shift_x;
	int		shift_y;
	void	*mptr;
	void	*wptr;
	float	step_x;
	float	step_y;
	int		screen_x;
	int		screen_y;
	int		offset_x;
	int		offset_y;
}	t_fdf;

void		reader(char *file_name, t_fdf *data);
void		drawing_bresenham(float x2, float y2, t_fdf *data);
void		caller(int *x, int *y, t_fdf *data);
void		isometric(float *x, float *y, int z);
float		max(float f1, float f2);
void		draw(t_fdf *data);
void		fill_matrix(int *z_line, char *line);
int			getwidth(char *file_name);
size_t		wcounter(char const *s, char c);
int			getheight(char *file_name);
void		color(float x2, float y2, t_fdf *data);
void		shift2(float *x2, float *y2, t_fdf *data);
void		shift(float *x, float *y, t_fdf *data);
void		zoom(float *x, float *y, t_fdf *data);
void		zoom2(float *x2, float *y2, t_fdf *data);
int			get_next_line(int fd, char **line);
int			check(int fd, char **line, char **buf, char *temp);
char		*ft_helper(char *buf, char **line, int byte_read);
char		*ft_call_join(char *temp, char *buf);
char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlcpy(char *dest, const char *src, size_t dest_size);
size_t		ft_strlen(const char *s);
char		*ft_strdup(const char *s1);
char		*ft_strchr(const char *s, int c);
char		*ft_substr(char const *s, unsigned int start, size_t len);

#endif