/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonserr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 14:42:01 by rmonserr          #+#    #+#             */
/*   Updated: 2020/03/07 14:42:04 by rmonserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		struct_init(t_fractol *data)
{
	data->color = 0;
	data->iter = 0;
	data->iter_max = 0;
	data->man.c_im = 0;
	data->man.c_re = 0;
	data->man.move_julia = 0;
	data->man.shift_value = 0;
	data->man.shift_x = 0;
	data->man.shift_y = 0;
	data->man.start_zoom = 0;
	data->man.tmp = 0;
	data->man.x1 = 0;
	data->man.x = 0;
	data->man.y1 = 0;
	data->man.y = 0;
	data->man.z_im = 0;
	data->man.z_re = 0;
	data->man.zoom = 0;
}
