/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dantremb <dantremb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 02:09:29 by dantremb          #+#    #+#             */
/*   Updated: 2022/06/08 14:57:22 by dantremb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_send_error(char *error)
{
	perror(error);
	exit(1);
}

void	ft_forward(t_data *data)
{
	printf("Forward\n");
	mlx_destroy_image(data->mlx, data->car);
	data->car = mlx_xpm_file_to_image(data->mlx,
			"./bin/car.xpm", &data->x, &data->y);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->car, 0, 256);
}

void	ft_exit_game(t_data *data)
{
	printf("Exit\n");
	mlx_destroy_window(data->mlx, data->mlx_win);
	exit (0);
}

int	ft_game(int key, t_data *data)
{
	(void) data;
	if (key == 13)
		ft_forward(data);
	else if (key == 1)
		printf("Back\n");
	else if (key == 2)
		printf("Right\n");
	else if (key == 0)
		printf("Left\n");
	else if (key == 53)
		ft_exit_game(data);
	return (0);
}

void	ft_init_xpm(t_data	*data)
{
	data->car = mlx_xpm_file_to_image(data->mlx,
			"./bin/car.xpm", &data->x, &data->y);
	data->road = mlx_xpm_file_to_image(data->mlx,
			"./bin/road.xpm", &data->x, &data->y);
	data->grass = mlx_xpm_file_to_image(data->mlx,
			"./bin/grass.xpm", &data->x, &data->y);
	data->item = mlx_xpm_file_to_image(data->mlx,
			"./bin/item.xpm", &data->x, &data->y);
	data->start = mlx_xpm_file_to_image(data->mlx,
			"./bin/start.xpm", &data->x, &data->y);
	data->end = mlx_xpm_file_to_image(data->mlx,
			"./bin/end.xpm", &data->x, &data->y);
}

void	ft_img_to_window(t_data	*data)
{
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->car, 0, 0);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->road, 257, 0);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->grass, 257, 257);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->item, 0, 257);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->start, 515, 257);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->end, 515, 515);
}

void	ft_validate_map(t_data *data, char **argv, int ac)
{
	if (ac != 2)
		ft_send_error("ft_validate_map : need 1 argument\n");
	else if (ft_strlen(argv[1]) < 5)
		ft_send_error("ft_validate_map : bad map name\n");
	else if (ft_strncmp(&argv[1][ft_strlen(argv[1] - 4)], ".ber", 4) != 0)
		ft_send_error("ft_validate_map : bad map extension\n");
	(void) data;
}

int	main(int ac, char **argv)
{
	t_data	data;

	ft_validate_map(&data, argv, ac);
	data.mlx = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx, 1280, 720, "Dantremb");
	ft_init_xpm(&data);
	ft_img_to_window(&data);
	mlx_hook(data.mlx_win, 2, 0, ft_game, &data);
	mlx_loop (data.mlx);
	return (0);
}
