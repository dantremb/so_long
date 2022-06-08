/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dantremb <dantremb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 02:09:25 by dantremb          #+#    #+#             */
/*   Updated: 2022/06/07 19:50:34 by dantremb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include "minilibx_opengl/mlx.h"
//# include "minilibx-linux/mlx.h"

typedef struct s_img
{
	void	*img;
	int		x;
	int		y;
}				t_img;

#endif
