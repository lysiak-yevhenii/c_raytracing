/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylisyak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 15:02:11 by ylisyak           #+#    #+#             */
/*   Updated: 2018/11/11 19:10:10 by ylisyak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef 	RTV_H
#	define	RTV_H
#	include <libft.h>
#	include	<stdio.h>
#	include "SDL.h"
#	include "SDL_image.h"
#	include "SDL_timer.h"
#	include "SDL_ttf.h"
#	include "SDL_mixer.h"

#define	SCREEN_W 1200
#define	SCREEN_H 1200

typedef struct		s_win
{
	
}					t_win;

typedef struct
{
	float			x;
	float			y;
	float			z;
}					vector;

#endif
