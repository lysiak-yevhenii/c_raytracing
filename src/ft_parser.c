/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylisyak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 18:10:55 by ylisyak           #+#    #+#             */
/*   Updated: 2018/11/13 03:49:35 by ylisyak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rtv.h"

void	ft_default_color(t_win *window, char *line, int id)
{
	if (ft_strncmp(line, "white", ft_strlen_until(line, '>')) == 0)
		window->objects[id].color = 16777215;		
	else if (ft_strncmp(line, "black", ft_strlen_until(line, '>')) == 0)
		window->objects[id].color = 0;
	else if (ft_strncmp(line, "red", ft_strlen_until(line, '>')) == 0)
		window->objects[id].color = 16711680;
	else if (ft_strncmp(line, "green", ft_strlen_until(line, '>')) == 0)
		window->objects[id].color = 65280;
	else if (ft_strncmp(line, "blue", ft_strlen_until(line, '>')) == 0)
		window->objects[id].color = 255;
	else
	{
		printf("\33[0;31m");
		printf("Object name: %s\n", window->objects[id].name);
		printf("Not correct default color in object [id:%d]\n", id);
		printf("\33[0m");
	}
}

void	ft_get_color(t_win *window, char *line, int id)
{
	while (*line != '<' && *line != '\0')
		line++;
	line++;
	if (ft_isalpha(*line))
		ft_default_color(window, line, id);
	if (*line == '0' && (*(line + 1) == 'x' || *(line + 1) == 'X'))
		printf("it's hex");
	else if (ft_isdigit(*line) && (*(line + 1) != 'x' || *(line + 1) != 'X'))
		printf("is rgb");
}

void	ft_parameter(t_win *window, char *line, int *id)
{
	while (*line == 9)
		line++;
	if (ft_isalpha(*line))
		if (ft_strncmp(line, "color", ft_strlen_until(line, ':')) == 0)
			ft_get_color(window, line, *id);
	*id = *id + 1;
}

void	ft_name(t_win *window, char *line, int id)
{
	int		i;

	i = 0;
	window->objects[id].name = (char*)malloc(sizeof(char) * ft_strlen_until(line, ' '));
	ft_bzero(window->objects[id].name, sizeof(ft_strlen_until(line, ' ')));
	ft_memcpy(window->objects[id].name, line, ft_strlen_until(line, ' '));

}

int		ft_parsing(t_win *window, char *input)
{
	int		fd;
	int		id;
	char	*line;

	fd = 0;
	id = 0;
	line = NULL;
	if ((fd = open(input, O_RDONLY)) == -1)
		return (0);
	while (get_next_line(fd, &line))
	{
		if (ft_isalpha(*line))
			ft_name(window, line, id);
		if (*line == 9)
			ft_parameter(window, line, &id);
	}
	return (1);
}

int		ft_create_objects(t_win *window, int mount)
{
	window->objects = (t_objects *)malloc(sizeof(t_objects) * mount);
	if (window->objects != NULL)
		return (1);
	else
	{
		ft_putstr("Can't allocate memory");
		return (0);
	}
}

int			ft_count_objects(char *path)
{
	int		fd;
	int		objects;
	char	*line;

	fd = 0;
	line = NULL;
	objects = 0;
	if ((fd = open(path, O_RDONLY)) == -1)
		return (0);	
	while (get_next_line(fd, &line))
	{	
		if (ft_isalpha(*line))
		{	
			objects++;
		}
		if (*line == '/')				//skip comment
		{	
			free(line);
			line = NULL;
		}
	}
	close(fd);
	return (objects);
}
