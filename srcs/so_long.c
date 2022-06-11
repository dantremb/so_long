/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dantremb <dantremb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 02:09:29 by dantremb          #+#    #+#             */
/*   Updated: 2022/06/10 20:19:22 by dantremb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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

void	ft_forward(t_data *data)
{
	printf("Forward\n");
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->player, 0, 256);
}

void	ft_exit_game(t_data *data)
{
	printf("Exit\n");
	free(data->map);
	mlx_destroy_image(data->mlx, data->player);
	mlx_destroy_image(data->mlx, data->road);
	mlx_destroy_image(data->mlx, data->grass);
	mlx_destroy_image(data->mlx, data->item);
	mlx_destroy_image(data->mlx, data->end);
	mlx_destroy_window(data->mlx, data->mlx_win);
	exit (0);
}

int	ft_keybind(int key, t_data *data)
{
	printf("key = %d\n", key);
	(void) data;
	if (key == 13 || key == 119)
		ft_forward(data);
	else if (key == 1 || key == 115)
		printf("Back\n");
	else if (key == 2 || key == 100)
		printf("Right\n");
	else if (key == 0 || key == 97)
		printf("Left\n");
	else if (key == 53 || key == 65307)
		ft_exit_game(data);
	return (0);
}

void	ft_init_xpm(t_data	*data)
{
	printf("ft_ini_xpm\n");
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
	
	printf("ft_img_to_window\n");
	y = -1;
	while(data->map[++y])
	{
		x = -1;
		while(data->map[y][++x] > 32)
		{
			//printf("put %c in %d x %d\n", data->map[y][x], x, y);
			if (data->map[y][x] == '1')
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->grass, x * data->tile_size, y * data->tile_size);
			else if (data->map[y][x] == 'C')
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->item, x * data->tile_size, y * data->tile_size);
			else if (data->map[y][x] == 'E')
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->end, x * data->tile_size, y * data->tile_size);
			else if (data->map[y][x] == 'P')
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->player, x * data->tile_size, y * data->tile_size);
			else
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->road, x * data->tile_size, y * data->tile_size);
		}
	}
}

void	ft_validate_file(char *file, int count)
{
	printf("ft_validate_file\n");
	if (count != 2)
		ft_send_error("ft_validate_map: choose one map file with '.ber' extension");
	else if (ft_strlen(file) < 5)
		ft_send_error("ft_validate_map: bad map name");
	else if (ft_strncmp((file + (ft_strlen(file) - 4)), ".ber", 4) != 0)
		ft_send_error("ft_validate_map: bad map extension");
}

char	**ft_read_map(char *file, t_data *data)
{
	printf("ft_read_map file = %s\n", file);
	int		fdmap;
	char	**map;
	int		i;
	
	fdmap = open(file, O_RDONLY);
	printf("ft_read_map : open fdmap\n");
	if (fdmap < 0)
		ft_send_error("ft_read_map: file error");
	printf("ft_read_map : calloc map\n");
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
	printf("ft_validate_map\n");
	data->map = ft_read_map(file, data);
	int	y;
	int	x;
	
	y = -1;
	while(data->map[++y])
	{
		//printf("datamap y = %s\n", data->map[y]);
		x = -1;
		while(data->map[y][++x])
		{
			//printf("datamap[%d][%d] = %c\n", y, x, data->map[y][x]);
			if (data->map[y][x] != '1' && data->map[y][x] != '0' && data->map[y][x] != 'P' 
				&& data->map[y][x] != 'E' && data->map[y][x] != 'C')
				ft_free_and_send_error("ft_validate_map: wrong data in map file", data);
			if (data->map[y][x + 1] == '\n' || data->map[y][x + 1] == '\0' )
				break ;
		}
	}
	x++;
	data->x_win = x * 64;
	data->y_win = y * 64;
	printf("window size = %d x %d\n", data->x_win, data->y_win);
}

int	main(int count, char **file)
{
	t_data	data;

	ft_validate_file(file[1], count);
	ft_validate_map(&data, file[1]);
	data.mlx = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx, data.x_win, data.y_win, "So_long");
	ft_init_xpm(&data);
	ft_img_to_window(&data);
	mlx_hook(data.mlx_win, 2, 1L << 0, ft_keybind, &data);
	mlx_loop (data.mlx);
	return (0);
}
