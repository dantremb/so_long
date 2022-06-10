/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dantremb <dantremb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 02:09:25 by dantremb          #+#    #+#             */
/*   Updated: 2022/06/09 22:08:48 by dantremb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "libft/includes/libft.h"
# include "get_next_line/includes/get_next_line.h"
//# include "minilibx_opengl/mlx.h"
# include "minilibx-linux/mlx.h"

typedef struct s_data
{
	void	*mlx;
	void	*mlx_win;
	int		x_win;
	int		y_win;
	void	*player;
	void	*road;
	void	*grass;
	void	*item;
	void	*start;
	void	*end;
	int		tile_size;
	char	*map;
}				t_data;

#endif
