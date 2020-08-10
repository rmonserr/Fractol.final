/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonserr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 17:41:52 by rmonserr          #+#    #+#             */
/*   Updated: 2020/07/17 17:41:55 by rmonserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double		ft_abs(double a)
{
	if (a >= 0)
		return (a);
	else
		return (a * (-1));
}

void		calc_bs(t_fractol *data)
{
	while (data->man.z_re * data->man.z_re +
		data->man.z_im * data->man.z_im < 4
			&& data->iter < data->iter_max)
	{
		data->man.tmp = data->man.z_re;
		data->man.z_re = ft_abs(data->man.z_re * data->man.z_re -
			data->man.z_im * data->man.z_im + data->man.c_re);
		data->man.z_im = ft_abs(2 * data->man.z_im *
			data->man.tmp + data->man.c_im);
		data->iter++;
	}
}

void		draw_bs(t_fractol *data)
{
	while (data->man.y < HEIGHT)
	{
		while (data->man.x < WIDTH)
		{
			data->man.c_re = (data->man.x /
				data->man.zoom - data->man.shift_x) + data->man.x1;
			data->man.c_im = (data->man.y /
				data->man.zoom - data->man.shift_y) + data->man.y1;
			data->man.z_re = 0;
			data->man.z_im = 0;
			calc_bs(data);
			color_calc(data);
			data->iter = 1;
			data->man.x++;
		}
		data->man.y++;
		data->man.x = 0;
	}
	data->man.x = 0;
	data->man.y = 0;
	mlx_put_image_to_window(data->win.mlx_ptr,
		data->win.win_ptr, data->img.img_ptr, 0, 0);
}

void		bs_init(t_fractol *data)
{
	data->man.z_re = 0;
	data->man.z_im = 0;
	data->man.tmp = 0;
	data->man.shift_x = 0.0;
	data->man.shift_y = 0.0;
	data->man.shift_value = 0.1;
	data->man.x = 0;
	data->man.y = 0;
	data->iter = 0;
	data->man.x1 = -2.0;
	data->man.y1 = -2.1;
	data->man.c_re = 0;
	data->man.c_im = 0;
	data->iter_max = 30;
	data->man.start_zoom = 150;
	data->man.zoom = 150;
	data->man.move_julia = 0;
}
