/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabitbol <sabitbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 18:22:35 by rperrot           #+#    #+#             */
/*   Updated: 2024/10/15 23:09:32 by sabitbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_point
{
	float x;
	float y;
	float z;
}	t_point;

typedef struct s_color
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}	t_color;

typedef struct s_sphere
{
	t_point	center;
	t_color color;
	float 	radius;
} t_sphere;

typedef struct s_camera
{
	t_point	position;
	t_point	vector;
	float	fov;
}	t_camera;

typedef struct s_light
{
	t_point	position;
	t_color color;
	float	ratio;
}	t_light;

typedef struct s_cylinder
{
	t_point	origin;
	t_point	direction;
	float	diameter;
	float	height;
	t_color color;
}	t_cylinder;

typedef struct s_plane
{
	t_point	point;
	t_point vector;
	t_color color;
}	t_plane;

typedef struct s_ambient
{
	t_color	color;
	float	intensity;
}	t_ambient;

typedef struct s_scene
{
	t_ambient	ambient;
	t_sphere	*spheres;
	short		nb_spheres;
	t_light		*lights;
	short		nb_lights;
	t_camera 	cameras;
	t_cylinder	*cylinders;
	short		nb_cylinders;
	t_plane		*planes;
	short		nb_planes;
}	t_scene;

#endif
