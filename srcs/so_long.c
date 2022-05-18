/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dantremb <dantremb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 02:09:29 by dantremb          #+#    #+#             */
/*   Updated: 2022/05/18 02:10:46 by dantremb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int ar, char **av)
{
	if (ar > 1)
		printf("%s\n", av[1]);
	else
	{
		printf("No Argument!\n");
		return (0);
	}
	return (1);
}