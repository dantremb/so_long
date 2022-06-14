/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dantremb <dantremb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 02:09:25 by dantremb          #+#    #+#             */
/*   Updated: 2022/06/14 15:31:52 by dantremb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft/includes/libft.h"
//# include "minilibx_opengl/mlx.h"
# include "minilibx-linux/mlx.h"

typedef struct s_data
{
	void	*mlx;
	void	*mlx_win;
	int		x_win;
	int		y_win;
	int		tile_size;
	char	**map;
	int		x_player;
	int		y_player;
	int		nb_items;
	int		nb_end;
	int		nb_start;
	int		move;
	void	*player;
	void	*road;
	void	*grass;
	void	*item;
	void	*end;
}				t_data;

char	*ft_get_next_line(int fd);
int		ft_keybind(int key, t_data *data);
void	ft_validate_map(t_data *data, char *file);
void	ft_validate_file(t_data *data, char *file, int count);
void	ft_img_to_window(t_data	*data);
void	ft_init_xpm(t_data	*data);
void	ft_exit_game(t_data *data);
void	ft_free_and_send_error(char *error, t_data *data);
void	ft_send_error(char *error);

#endif
