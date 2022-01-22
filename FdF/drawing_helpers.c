/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_helpers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkeskint <bkeskint@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 11:55:09 by bkeskint          #+#    #+#             */
/*   Updated: 2021/10/21 14:31:46 by bkeskint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

void	zoom2(float *x2, float *y2, t_fdf *data)
{
	*x2 *= data->zoom;
	*y2 *= data->zoom;
}

void	zoom(float *x, float *y, t_fdf *data)
{
	*x *= data->zoom;
	*y *= data->zoom;
}

void	shift(float *x, float *y, t_fdf *data)
{	
	*x += data->shift_x;
	*y += data->shift_y;
}

void	shift2(float *x2, float *y2, t_fdf *data)
{	
	*x2 += data->shift_x;
	*y2 += data->shift_y;
}

void	color(float x2, float y2, t_fdf *data)
{
	data->z = data->matrix[(int)data->y][(int)data->x];
	data->z2 = data->matrix[(int)y2][(int)x2];
	if (data->z || data->z2)
		data->color = 0xe80c0c;
	else
		data->color = 0xffffff;
}
