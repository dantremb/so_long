/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dantremb <dantremb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 20:40:16 by dantremb          #+#    #+#             */
/*   Updated: 2022/06/19 23:15:00 by dantremb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	**ft_read_map(char *file, t_data *data)
{
	int		fdmap;
	char	**map;
	int		i;

	fdmap = open(file, O_RDONLY);
	if (fdmap < 0)
		ft_send_error("ft_read_map: file error");
	map = ft_calloc(sizeof(char *), 18);
	if (!map)
		ft_send_error("ft_read_map: malloc error");
	i = 0;
	while (i <= 17)
	{
		map[i] = ft_get_next_line(fdmap);
		if (map[i] == NULL)
			break ;
		i++;
	}
	if (map[0] == NULL)
		ft_free_and_send_error("ft_read_map: no data in map file", data);
	if (map[17] != NULL || ft_strlen(map[0]) > 31)
		ft_free_and_send_error("ft_read_map: map must be 30 x 16 max", data);
	return (map);
}

void	ft_validate_map_integrity(t_data *data)
{
	int	y;
	int	x;

	y = -1;
	while (data->map[++y])
	{
		x = -1;
		while (data->map[y][++x])
		{
			if (y == 0 || x == 0 || x == (data->x_win / 64 - 1)
				|| y == (data->y_win / 64 - 1))
			{
				if (data->map[y][x] != '1')
					ft_free_and_send_error("map_integrity: Wall missing", data);
			}
			if (data->map[y][x + 1] == '\n' || data->map[y][x + 1] == '\0' )
				break ;
		}
	}
	if (data->nb_end != 1 || data->nb_start != 1 || data->nb_items < 1)
		ft_free_and_send_error("map_integrity: Wrong tiles config", data);
}

void	ft_validate_tiles(t_data *data, int x, int y)
{
	if (data->map[y][x] == 'C')
		data->nb_items += 1;
	else if (data->map[y][x] == 'E')
		data->nb_end += 1;
	else if (data->map[y][x] == 'P')
		data->nb_start += 1;
	if (ft_strchr("CEP01", data->map[y][x]) == 0)
		ft_free_and_send_error("ft_validate_map: wrong data in map file", data);
}

void	ft_validate_map(t_data *data, char *file)
{
	int	y;
	int	x;
	int	tile;

	data->map = ft_read_map(file, data);
	tile = 0;
	y = -1;
	while (data->map[++y])
	{
		x = -1;
		while (data->map[y][++x])
		{
			tile++;
			ft_validate_tiles(data, x, y);
			if (data->map[y][x + 1] == '\n' || data->map[y][x + 1] == '\0' )
				break ;
		}
	}
	x++;
	if (tile != x * y)
		ft_free_and_send_error("map_integrity: Wrong tiles config", data);
	data->x_win = x * 64;
	data->y_win = y * 64;
	ft_validate_map_integrity(data);
}
