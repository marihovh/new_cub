/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marihovh <marihovh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:08:06 by marihovh          #+#    #+#             */
/*   Updated: 2024/01/24 16:20:47 by marihovh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int init_win(t_data *data)
{
	data->win_w = 1200;
	data->win_h = 800;
	data->cam_x = 0;
	data->cam_y = 0.66;
	data->dir_x = -1;
	data->dir_y = 0;
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->win_w,
			data->win_h, "Cub3d");
	return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x > 0 && y > 0 && data->win_w > x && data->win_h > y)
	{
		dst = data->img.addr + (y * data->img.line_length + x
				* (data->img.bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}


int do_walls(t_data *data)
{
	(void)data;
	int i = -1;
	while (++i < data->win_w)
	{
	// printf("%i            %i\n", i, data->pos_y);
		my_mlx_pixel_put(data, i, data->pos_y + 100, 0xffffff);
		my_mlx_pixel_put(data, i, data->pos_y + 500, 0xffffff);
	}
	return (0);
}

int just_do_it(t_data *data)
{
	
	data->img.img = mlx_new_image(data->mlx_ptr, data->win_w, data->win_h);
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bits_per_pixel,
			&data->img.line_length, &data->img.endian);
	do_walls(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.img, 0, 0);	
	return (0);
}