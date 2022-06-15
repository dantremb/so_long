/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dantremb <dantremb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 02:09:29 by dantremb          #+#    #+#             */
/*   Updated: 2022/06/15 00:53:21 by dantremb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int count, char **file)
{
	t_data	data;

	ft_validate_file(&data, file[1], count);
	ft_validate_map(&data, file[1]);
	data.mlx = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx, data.x_win, data.y_win, "So_long");
	ft_init_xpm(&data);
	ft_img_to_window(&data);
	printf("items = %d start = %d, end = %d\n", data.nb_items, data.nb_start, data.nb_end);
	mlx_hook(data.mlx_win, 2, 1L << 0, ft_keybind, &data);
	mlx_hook(data.mlx_win, 17, 1L << 0, ft_exit_game, &data);
	mlx_loop (data.mlx);
	return (0);
}

void	ft_send_error(char *error)
{
	perror(error);
	exit(1);
}

void	ft_free_and_send_error(char *error, t_data *data)
{
	free(data->map);
	perror(error);
	exit(1);
}

int	ft_exit_game(t_data *data)
{
	if (data->nb_items == 0)
			printf("Victory in %d movements!\n", data->move);
	else
			printf("Failed after %d movements!\n", data->move);
	free(data->map);
	mlx_destroy_image(data->mlx, data->player);
	mlx_destroy_image(data->mlx, data->road);
	mlx_destroy_image(data->mlx, data->grass);
	mlx_destroy_image(data->mlx, data->item);
	mlx_destroy_image(data->mlx, data->end);
	mlx_destroy_window(data->mlx, data->mlx_win);
	exit (0);
}
