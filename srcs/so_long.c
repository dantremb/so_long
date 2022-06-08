/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dantremb <dantremb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 02:09:29 by dantremb          #+#    #+#             */
/*   Updated: 2022/06/07 21:01:44 by dantremb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_img	car;

	car.x = 256;
	car.y = 256;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1280, 720, "Dantremb");
	car.img = mlx_xpm_file_to_image(mlx, "../tiles/car.xpm", &car.x, &car.y);
	mlx_put_image_to_window(mlx, mlx_win, car.img, car.x, car.y);
	mlx_loop (mlx);
}
