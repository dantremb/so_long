/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dantremb <dantremb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 15:10:59 by dantremb          #+#    #+#             */
/*   Updated: 2022/06/14 15:37:09 by dantremb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_init_xpm(t_data	*data)
{
	data->player = mlx_xpm_file_to_image(data->mlx,
			"./bin/player64.xpm", &data->tile_size, &data->tile_size);
	data->road = mlx_xpm_file_to_image(data->mlx,
			"./bin/road64.xpm", &data->tile_size, &data->tile_size);
	data->grass = mlx_xpm_file_to_image(data->mlx,
			"./bin/grass64.xpm", &data->tile_size, &data->tile_size);
	data->item = mlx_xpm_file_to_image(data->mlx,
			"./bin/item64.xpm", &data->tile_size, &data->tile_size);
	data->end = mlx_xpm_file_to_image(data->mlx,
			"./bin/end64.xpm", &data->tile_size, &data->tile_size);
}

void	ft_img_to_window(t_data	*data)
{
	int	y;
	int	x;
	
	y = -1;
	while(data->map[++y])
	{
		x = -1;
		while(data->map[y][++x] > 32)
		{
			if (data->map[y][x] == '1')
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->grass, x * data->tile_size, y * data->tile_size);
			else if (data->map[y][x] == 'C')
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->item, x * data->tile_size, y * data->tile_size);
			else if (data->map[y][x] == 'E')
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->end, x * data->tile_size, y * data->tile_size);
			else if (data->map[y][x] == '0')
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->road, x * data->tile_size, y * data->tile_size);
			else
			{
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->player, x * data->tile_size, y * data->tile_size);
				data->x_player = x;
				data->y_player = y;
			}
		}
	}
}

void	ft_validate_file(t_data *data, char *file, int count)
{
	if (count != 2)
		ft_send_error("ft_validate_map: choose one map file with '.ber' extension");
	else if (ft_strlen(file) < 5)
		ft_send_error("ft_validate_map: bad map name");
	else if (ft_strncmp((file + (ft_strlen(file) - 4)), ".ber", 4) != 0)
		ft_send_error("ft_validate_map: bad map extension");
	data->nb_items = 0;
	data->nb_end = 0;
	data->nb_start = 0;
}

char	**ft_read_map(char *file, t_data *data)
{
	int		fdmap;
	char	**map;
	int		i;
	
	fdmap = open(file, O_RDONLY);
	if (fdmap < 0)
		ft_send_error("ft_read_map: file error");
	map = ft_calloc(sizeof(map), 16);
	if (!map)
		ft_send_error("ft_read_map: malloc error");
	i = 0;
	while (1)
	{
		map[i] = ft_get_next_line(fdmap);
		if (map[i] == NULL)
			break;
		i++;
	}
	if (map[0] == NULL)
		ft_free_and_send_error("ft_read_map: no data in map file", data);
	return (map);
}

void	ft_validate_map(t_data *data, char *file)
{
	data->map = ft_read_map(file, data);
	int	y;
	int	x;
	
	y = -1;
	while(data->map[++y])
	{
		x = -1;
		while(data->map[y][++x])
		{
			if (data->map[y][x] == 'C')
				data->nb_items += 1;
			else if (data->map[y][x] == 'E')
				data->nb_end += 1;
			else if (data->map[y][x] == 'P')
				data->nb_start += 1;
			if (ft_strchr("CEP01", data->map[y][x]) == 0)
				ft_free_and_send_error("ft_validate_map: wrong data in map file", data);
			if (data->map[y][x + 1] == '\n' || data->map[y][x + 1] == '\0' )
				break ;
		}
	}
	x++;
	data->x_win = x * 64;
	data->y_win = y * 64;
}