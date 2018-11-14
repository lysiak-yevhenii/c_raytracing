/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawing_bpx.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylisyak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 20:44:18 by ylisyak           #+#    #+#             */
/*   Updated: 2018/11/14 22:31:30 by ylisyak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rtv.h" 

void		ft_draw_bpx(int x, int y, size_t color, SDL_Surface *img)
{
	*((unsigned int *)(img->pixels + y * img->pitch + x *\
				img->format->BytesPerPixel)) = color;
}
