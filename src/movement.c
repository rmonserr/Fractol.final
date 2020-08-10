/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonserr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 17:48:30 by rmonserr          #+#    #+#             */
/*   Updated: 2020/07/17 17:48:32 by rmonserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	replace(t_fractol *data)
{
	mlx_destroy_image(data->win.mlx_ptr, data->img.img_ptr);
	if (!(data->img.img_ptr = mlx_new_image(
			data->win.mlx_ptr, WIDTH, HEIGHT)))
		mlx_error();
	if (!(data->img.img_data = (int *)mlx_get_data_addr(data->img.img_ptr,
	&data->img.bit_depth, &data->img.line, &data->img.endian)))
		mlx_error();
	if (data->fract_id == 0)
		draw_mandelbrot(data);
	if (data->fract_id == 1)
		draw_julia(data);
	if (data->fract_id == 2)
		draw_bs(data);
	mlx_put_image_to_window(data->win.mlx_ptr,
	data->win.win_ptr, data->img.img_ptr, 0, 0);
}

void	mouse_lock(t_fractol *data)
{
	if (data->man.move_julia == 1)
		data->man.move_julia = 0;
	else
		data->man.move_julia = 1;
}

int		mouse_press(int key, int x, int y, t_fractol *data)
{
	if (key == 4)
	{
		data->man.zoom += 10;
		replace(data);
		return (0);
	}
	if (key == 5 && data->man.zoom > data->man.start_zoom)
	{
		data->man.zoom -= 10;
		replace(data);
		return (0);
	}
	x += 0;
	y += 0;
	return (0);
}

void	movement(int key, t_fractol *data)
{
	if (key == 65361)
		data->man.shift_x -= data->man.shift_value;
	if (key == 65363)
		data->man.shift_x += data->man.shift_value;
	if (key == 65362)
		data->man.shift_y -= data->man.shift_value;
	if (key == 65364)
		data->man.shift_y += data->man.shift_value;
	if (data->fract_id == 1 && key == 108)
		mouse_lock(data);
	replace(data);
}

int		mouse_julia(int x, int y, t_fractol *data)
{
	if (data->man.move_julia == 1)
	{
		if (x < WIDTH && y < HEIGHT)
		{
			if (x < WIDTH / 2 && y < HEIGHT / 2)
				data->man.c_re += 0.004;
			if (x > WIDTH / 2 && y < HEIGHT / 2)
				data->man.c_re -= 0.004;
			if (x < WIDTH / 2 && y > HEIGHT / 2)
				data->man.c_im += 0.004;
			if (x > WIDTH / 2 && y > HEIGHT / 2)
				data->man.c_im -= 0.004;
		}
		draw_julia(data);
	}
	return (0);
}
