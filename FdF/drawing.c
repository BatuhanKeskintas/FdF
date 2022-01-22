/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkeskint <bkeskint@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 19:41:31 by bkeskint          #+#    #+#             */
/*   Updated: 2021/10/21 14:43:07 by bkeskint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

float	max(float f1, float f2)
{
	if (f1 < 0)
		f1 *= -1;
	if (f2 < 0)
		f2 *= -1;
	if (f1 > f2)
		return (f1);
	else
		return (f2);
}

void	isometric(float *x, float *y, int z)
{
	*x = (*x - *y) * cos(0.8);
	*y = (*x + *y) * sin(0.8) - z;
}

void	drawing_bresenham(float x2, float y2, t_fdf *data)
{
	float	x;
	float	y;
	int		max_r;

	x = data->x;
	y = data->y;
	color(x2, y2, data);
	zoom(&x, &y, data);
	zoom2(&x2, &y2, data);
	isometric(&x, &y, data->z);
	isometric(&x2, &y2, data->z2);
	shift(&x, &y, data);
	shift2(&x2, &y2, data);
	data->step_x = x2 - x;
	data->step_y = y2 - y;
	max_r = max(data->step_x, data->step_y);
	data->step_x /= max_r;
	data->step_y /= max_r;
	while ((int)(x - x2) || (int)(y - y2))
	{
		mlx_pixel_put(data->mptr, data->wptr, x + data->offset_y,
			y + data->offset_y, data->color);
		x += data->step_x;
		y += data->step_y;
	}
}

void	caller(int *x, int *y, t_fdf *data)
{
	int	x2;
	int	y2;

	data->x = *x;
	data->y = *y;
	if (*x < data->w - 1)
	{
		x2 = *x + 1;
		drawing_bresenham(x2, *y, data);
	}
	if (*y < data->h - 1)
	{
		y2 = *y + 1;
		drawing_bresenham(*x, y2, data);
	}
}

void	draw(t_fdf *data)
{
	int		x;
	int		y;

	y = 0;
	while (y < data->h)
	{
		x = 0;
		while (x < data->w)
		{
			caller(&x, &y, data);
			x++;
		}
		y++;
	}
}
