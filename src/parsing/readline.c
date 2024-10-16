/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabitbol <sabitbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:57:36 by rperrot           #+#    #+#             */
/*   Updated: 2024/10/16 20:41:59 by sabitbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_scene 	ft_readline(int fd)
{
	char	*line;
	t_scene	scene;
	t_bool	camera;
	t_bool	ambient;

	line = get_next_line(fd);
	camera = false;
	ambient = false;
	scene = (t_scene){0};
	while (line)
	{
		if (add_elem(&scene, line, &camera, &ambient))
		{
			free(line);
			errno = EINVAL;
			return (scene);
		}
		free(line);
		line = get_next_line(fd);
	}
	return (scene);
}