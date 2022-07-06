/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dantremb <dantremb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 02:09:29 by dantremb          #+#    #+#             */
/*   Updated: 2022/06/28 13:17:18 by dantremb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int count, char **file)
{
	printf("test\n");
	t_data	data;
	ft_validate_file(&data, file[1], count);
	ft_validate_map(&data, file[1]);
	data.mlx = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx, data.x_win, data.y_win, "So_long");
	ft_init_xpm(&data);
	ft_img_to_window(&data);
	mlx_hook(data.mlx_win, 2, 1L << 0, ft_keybind, &data);
	mlx_hook(data.mlx_win, 17, 1L << 0, ft_exit_game, &data);
	mlx_loop (data.mlx);
	return (0);
}

void	ft_validate_file(t_data *data, char *file, int count)
{
	if (count != 2)
		ft_send_error("ft_validate_file: need '.ber' maps");
	else if (ft_strlen(file) < 5)
		ft_send_error("ft_validate_file: bad map name");
	else if (ft_strncmp((file + (ft_strlen(file) - 4)), ".ber", 4) != 0)
		ft_send_error("ft_validate_file: bad map extension");
	data->nb_items = 0;
	data->nb_end = 0;
	data->nb_start = 0;
}

void	ft_send_error(char *error)
{
	perror(error);
	exit(1);
}

void	ft_free_and_send_error(char *error, t_data *data)
{
	int	i;

	i = -1;
	while (data->map[++i])
		free(data->map[i]); 
	free(data->map);
	perror(error);
	exit(1);
}

int	ft_exit_game(t_data *data)
{
	int	i;

	if (data->nb_items == 0)
		printf("Victory in %d movements!\n", data->move);
	else
		printf("Failed after %d movements!\n", data->move);
	i = -1;
	while (++i <= data->y_win / 64 - 1)
		free(data->map[i]);
	free(data->map);
	mlx_destroy_image(data->mlx, data->player_down);
	mlx_destroy_image(data->mlx, data->player_top);
	mlx_destroy_image(data->mlx, data->player_right);
	mlx_destroy_image(data->mlx, data->player_left);
	mlx_destroy_image(data->mlx, data->road);
	mlx_destroy_image(data->mlx, data->grass);
	mlx_destroy_image(data->mlx, data->item);
	mlx_destroy_image(data->mlx, data->end);
	mlx_destroy_window(data->mlx, data->mlx_win);
	exit (0);
}
