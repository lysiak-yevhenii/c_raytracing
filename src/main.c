/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylisyak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 20:10:53 by ylisyak           #+#    #+#             */
/*   Updated: 2018/11/05 15:44:58 by ylisyak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rtv.h"

int		main(void)
{
	SDL_Window*	window;
	window = NULL;

	SDL_Surface* screen_surface;
	screen_surface = NULL;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		printf("Not working: %s", SDL_GetError());	
	else
	{
		window = SDL_CreateWindow("RTV", SDL_WINDOWPOS_CENTERED,\
			   	SDL_WINDOWPOS_CENTERED, SCREEN_W, SCREEN_H, SDL_WINDOW_SHOWN);
		if (window == NULL)
		   	printf("Window now created %s", SDL_GetError());
		else
		{
			screen_surface = SDL_GetWindowSurface(window);
			SDL_FillRect(screen_surface, NULL, SDL_MapRGB(screen_surface->format, 0xFF, 0xFF, 0xFF));
			SDL_UpdateWindowSurface(window);
			SDL_Delay(2000);
		}
	}
	SDL_DestroyWindow(window);
	SDL_Quit();
	return (0);
}
