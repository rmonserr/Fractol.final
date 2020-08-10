/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonserr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 17:38:00 by rmonserr          #+#    #+#             */
/*   Updated: 2020/07/17 17:38:02 by rmonserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		pix_to_img(t_fractol *data, int color)
{
	data->color = mlx_get_color_value(data->win.mlx_ptr, color);
	data->img.img_data[data->man.x + data->man.y * WIDTH] = data->color;
}

void		color_calc(t_fractol *data)
{
	if (data->iter == data->iter_max)
		pix_to_img(data, 0);
	else
	{
		if (data->fract_id == 0)
			pix_to_img(data, (data->iter * 1100000));
		if (data->fract_id == 1)
			pix_to_img(data, (data->iter * 0xFFFFF));
		if (data->fract_id == 2)
			pix_to_img(data, (data->iter * 15));
	}
}
