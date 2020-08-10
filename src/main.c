/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonserr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 14:38:59 by rmonserr          #+#    #+#             */
/*   Updated: 2020/03/07 14:39:01 by rmonserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		main(int argc, char **argv)
{
	static t_fractol data;

	struct_init(&data);
	if (argc != 2)
	{
		ft_putstr("usage: ./fractol <fractol_name>\n\t--> mandelbrot\n");
		ft_putstr("\t--> julia\n\t--> burningship\n");
		exit(0);
	}
	else
	{
		if (((fractol_init(argv[1], &data)) == 1))
			exit(1);
		window_init(&data);
		fractol_parsing(&data);
		mlx_hook(data.win.win_ptr, 17, 0, deal_key_exit, &data);
		mlx_key_hook(data.win.win_ptr, deal_key, &data);
		mlx_mouse_hook(data.win.win_ptr, mouse_press, &data);
		if (data.fract_id == 1)
			mlx_hook(data.win.win_ptr, 6, 1UL << 6, mouse_julia, &data);
		mlx_loop(data.win.mlx_ptr);
	}
	return (0);
}
