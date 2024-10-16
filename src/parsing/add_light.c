/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_light.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabitbol <sabitbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:01:37 by sabitbol          #+#    #+#             */
/*   Updated: 2024/10/16 21:37:12 by sabitbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int add_light(t_scene *scene, char *str)
{
    t_light light;

    while (*str && *str == ' ')
        str++;
    if (*str)
        light.position = get_point(&str);
    else
        return (print_error(E_FILE_PARS));
    if (errno)
        return (print_error(strerror(errno)));
    while (*str && *str == ' ')
        str++;
    if (*str)
        light.intensity = ft_atof(&str);
    else
        return (print_error(E_FILE_PARS));
    if (light.intensity < 0 || light.intensity > 1)
        return (print_error(E_FILE_BRIGHT));
    if (errno)
        return (print_error(strerror(errno)));
    while (*str && *str == ' ')
        str++;
    if (*str)
        light.color = get_color(&str);
    else
        return (print_error(E_FILE_PARS));
    if (errno)
        return (print_error(strerror(errno)));
    if (ft_realloc((void **)&scene->lights, &scene->nb_lights, sizeof(t_light), (void *)&light))
        return (print_error(E_MALLOC));
   return (0);
}
