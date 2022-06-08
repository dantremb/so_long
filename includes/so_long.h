/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dantremb <dantremb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 02:09:25 by dantremb          #+#    #+#             */
/*   Updated: 2022/06/08 02:00:58 by dantremb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
//# include "minilibx_opengl/mlx.h"
# include "minilibx-linux/mlx.h"


typedef struct s_data
{
	void	*mlx;
	void	*mlx_win;
	void	*car;
	void	*road;
	void	*grass;
	void	*item;
	void	*start;
	void	*end;
	int		x;
	int		y;
}				t_data;

#endif
