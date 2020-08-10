/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonserr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 15:49:16 by rmonserr          #+#    #+#             */
/*   Updated: 2020/03/07 15:49:17 by rmonserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			fractol_parsing(t_fractol *data)
{
	if (data->fract_id == 0)
	{
		mandelbrot_init(data);
		draw_mandelbrot(data);
	}
	if (data->fract_id == 1)
	{
		julia_init(data);
		draw_julia(data);
	}
	if (data->fract_id == 2)
	{
		bs_init(data);
		draw_bs(data);
	}
}

void			window_init(t_fractol *data)
{
	if (!((data->win.mlx_ptr = mlx_init())))
		mlx_error();
	if (!((data->win.win_ptr = mlx_new_window(data->win.mlx_ptr,
		WIDTH, HEIGHT, "fractol"))))
		mlx_error();
	if (!(data->img.img_ptr = mlx_new_image(
		data->win.mlx_ptr, WIDTH, HEIGHT)))
		mlx_error();
	if (!(data->img.img_data = (int *)mlx_get_data_addr(data->img.img_ptr,
			&data->img.bit_depth, &data->img.line, &data->img.endian)))
		mlx_error();
}

int				fractol_init(char *file, t_fractol *data)
{
	if ((ft_strcmp(file, "mandelbrot")) == 0)
	{
		data->fract_id = 0;
		return (0);
	}
	else if ((ft_strcmp(file, "julia")) == 0)
	{
		data->fract_id = 1;
		return (0);
	}
	else if ((ft_strcmp(file, "burningship")) == 0)
	{
		data->fract_id = 2;
		return (0);
	}
	else
		ft_putstr("No such fractol!\n");
	return (1);
}
