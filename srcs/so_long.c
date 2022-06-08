/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dantremb <dantremb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 02:09:29 by dantremb          #+#    #+#             */
/*   Updated: 2022/06/08 02:01:56 by dantremb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_init_xpm(t_data	*data)
{
	data->car = mlx_xpm_file_to_image(data->mlx, "./bin/car.xpm", &data->x, &data->y);
	data->road = mlx_xpm_file_to_image(data->mlx, "./bin/road.xpm", &data->x, &data->y);
	data->grass = mlx_xpm_file_to_image(data->mlx, "./bin/grass.xpm", &data->x, &data->y);
	data->item = mlx_xpm_file_to_image(data->mlx, "./bin/item.xpm", &data->x, &data->y);
	data->start = mlx_xpm_file_to_image(data->mlx, "./bin/start.xpm", &data->x, &data->y);
	data->end = mlx_xpm_file_to_image(data->mlx, "./bin/end.xpm", &data->x, &data->y);
}

void	ft_img_to_window(t_data	*data)
{
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->car, 0, 0);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->road, 257, 0);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->grass, 257, 257);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->item, 0, 257);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->start, 515, 257);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->end, 515, 515);

	mlx_loop (data->mlx);
}

int	main(void)
{
	t_data	data;
	
	data.mlx = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx, 1280, 720, "Dantremb");
	ft_init_xpm(&data);
	ft_img_to_window(&data);
}
