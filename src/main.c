/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylisyak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 20:10:53 by ylisyak           #+#    #+#             */
/*   Updated: 2018/11/15 02:02:48 by ylisyak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rtv.h"

int			main(int ac, char **av)
{
	int i;
	int		objects_mount;
	t_win	window;

	i = 0;
	ft_bzero(&window, sizeof(t_win));
	if (ac == 2)
		if ((objects_mount = ft_count_objects(av[1])))
			if (ft_create_objects(&window, objects_mount))
				if (ft_parsing(&window, av[1]))
					if (ft_init_sdl(&window)) 
						ft_core(&window);
	while (i < 5)
	{
		printf("Name: %s\n", window.objects[i].name);
		printf("Location: x = %f, y =  %f, z =  %f \n", window.objects[i].pos.x, window.objects[i].pos.y, window.objects[i].pos.z); 
		printf("Color: %d\n", window.objects[i].color);
	   i++;	
	}
	return (0);
}
