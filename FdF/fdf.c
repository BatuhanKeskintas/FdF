/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkeskint <bkeskint@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 15:48:39 by bkeskint          #+#    #+#             */
/*   Updated: 2021/10/21 19:38:45 by bkeskint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

static void	clean(t_fdf *data)
{
	int	i;

	i = -1;
	mlx_destroy_window(data->mptr, data->wptr);
	while (data->matrix[++i])
		free(data->matrix[i]);
	free(data->matrix);
	free(data->mptr);
	exit(0);
}

int	key(int key, t_fdf *data)
{
	if (key == 126)
		data->shift_y -= 10;
	if (key == 125)
		data->shift_y += 10;
	if (key == 123)
		data->shift_x -= 10;
	if (key == 124)
		data->shift_x += 10;
	if (key == 34)
		data->zoom += 5;
	if (key == 31 && data->zoom >= 11)
		data->zoom -= 5;
	if (key == 53)
	{
		clean(data);
	}
	mlx_clear_window(data->mptr, data->wptr);
	draw(data);
	return (0);
}

void	init_data(t_fdf *data)
{
	data->screen_x = 1000;
	data->screen_y = 700;
	data->offset_x = data->screen_x / 2;
	data->offset_y = data->screen_y / 2;
	data->zoom = 15;
}

int	main(int argc, char **argv)
{
	t_fdf	data;

	if (argc != 2)
		ft_exit("Correct format: ./fdf map.fdf\n");
	reader(argv[1], &data);
	init_data(&data);
	data.mptr = mlx_init();
	data.wptr = mlx_new_window(data.mptr, data.screen_x, data.screen_y, "FdF");
	draw(&data);
	mlx_key_hook(data.wptr, key, &data);
	mlx_loop(data.mptr);
	return (0);
}
