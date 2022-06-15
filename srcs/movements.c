/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dantremb <dantremb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 15:07:49 by dantremb          #+#    #+#             */
/*   Updated: 2022/06/15 00:41:11 by dantremb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"


void	ft_right(t_data *data)
{
	if (data->map[data->y_player][(data->x_player) + 1] == 'E')
	{
		if (data->nb_items == 0)
			ft_exit_game(data);
	}
	else if (ft_strchr("C0P", data->map[data->y_player][(data->x_player) + 1]) != 0)
	{	
		if (data->map[data->y_player][(data->x_player) + 1] == 'C')
			data->nb_items -= 1;
		data->map[data->y_player][data->x_player] = '0';
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->road, data->x_player++ * 64, data->y_player * 64);
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->player, data->x_player * 64, data->y_player * 64);
		data->move += 1;
		printf("Nbs of moves =  %d\n", data->move);
	}
}

void	ft_left(t_data *data)
{
	if (data->map[data->y_player][(data->x_player) - 1] == 'E')
	{
		if (data->nb_items == 0)
			ft_exit_game(data);
	}
	else if (ft_strchr("C0P", data->map[data->y_player][(data->x_player) - 1]) != 0)
	{	
		if (data->map[data->y_player][(data->x_player) - 1] == 'C')
			data->nb_items -= 1;
		data->map[data->y_player][data->x_player] = '0';
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->road, data->x_player-- * 64, data->y_player * 64);
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->player, data->x_player * 64, data->y_player * 64);
		data->move += 1;
		printf("Nbs of moves =  %d\n", data->move);
	}
}

void	ft_backward(t_data *data)
{
	if (data->map[(data->y_player) + 1][data->x_player] == 'E')
	{
		if (data->nb_items == 0)
			ft_exit_game(data);
	}
	else if (ft_strchr("C0P", data->map[(data->y_player) + 1][data->x_player]) != 0)
	{	
		if (data->map[(data->y_player) + 1][data->x_player] == 'C')
			data->nb_items -= 1;
		data->map[data->y_player][data->x_player] = '0';
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->road, data->x_player * 64, data->y_player++ * 64);
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->player, data->x_player * 64, data->y_player * 64);
		data->move += 1;
		printf("Nbs of moves =  %d\n", data->move);
	}
}

void	ft_forward(t_data *data)
{
	if (data->map[(data->y_player) - 1][data->x_player] == 'E')
	{
		if (data->nb_items == 0)
			ft_exit_game(data);
	}
	else if (ft_strchr("C0P", data->map[(data->y_player) - 1][data->x_player]) != 0)
	{	
		if (data->map[(data->y_player) - 1][data->x_player] == 'C')
			data->nb_items -= 1;
		data->map[data->y_player][data->x_player] = '0';
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->road, data->x_player * 64, data->y_player-- * 64);
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->player, data->x_player * 64, data->y_player * 64);
		data->move += 1;
		printf("Nbs of moves =  %d\n", data->move);
	}
}

int	ft_keybind(int key, t_data *data)
{	
	if (key == 13 || key == 119)
		ft_forward(data);
	else if (key == 1 || key == 115)
		ft_backward(data);
	else if (key == 2 || key == 100)
		ft_right(data);
	else if (key == 0 || key == 97)
		ft_left(data);
	else if (key == 53 || key == 65307)
		ft_exit_game(data);
	return (0);
}