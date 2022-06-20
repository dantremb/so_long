/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dantremb <dantremb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 15:10:59 by dantremb          #+#    #+#             */
/*   Updated: 2022/06/19 20:40:50 by dantremb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_init_xpm(t_data	*data)
{
	data->player_down = mlx_xpm_file_to_image(data->mlx,
			"./bin/player_down.xpm", &data->tile_size, &data->tile_size);
	data->player_top = mlx_xpm_file_to_image(data->mlx,
			"./bin/player_top.xpm", &data->tile_size, &data->tile_size);
	data->player_right = mlx_xpm_file_to_image(data->mlx,
			"./bin/player_right.xpm", &data->tile_size, &data->tile_size);
	data->player_left = mlx_xpm_file_to_image(data->mlx,
			"./bin/player_left.xpm", &data->tile_size, &data->tile_size);
	data->road = mlx_xpm_file_to_image(data->mlx,
			"./bin/road64.xpm", &data->tile_size, &data->tile_size);
	data->grass = mlx_xpm_file_to_image(data->mlx,
			"./bin/grass64.xpm", &data->tile_size, &data->tile_size);
	data->item = mlx_xpm_file_to_image(data->mlx,
			"./bin/item64.xpm", &data->tile_size, &data->tile_size);
	data->end = mlx_xpm_file_to_image(data->mlx,
			"./bin/end64.xpm", &data->tile_size, &data->tile_size);
}

void	ft_put_image_to_window(t_data *data, int x, int y)
{
	if (data->map[y][x] == '1')
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->grass,
			x * data->tile_size, y * data->tile_size);
	else if (data->map[y][x] == 'C')
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->item,
			x * data->tile_size, y * data->tile_size);
	else if (data->map[y][x] == 'E')
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->end,
			x * data->tile_size, y * data->tile_size);
	else if (data->map[y][x] == '0')
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->road,
			x * data->tile_size, y * data->tile_size);
	else
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->player_top, x * data->tile_size, y * data->tile_size);
		data->x_player = x;
		data->y_player = y;
	}
}

void	ft_img_to_window(t_data	*data)
{
	int	y;
	int	x;

	y = -1;
	while (data->map[++y])
	{
		x = -1;
		while (data->map[y][++x] > 32)
			ft_put_image_to_window(data, x, y);
	}
}
