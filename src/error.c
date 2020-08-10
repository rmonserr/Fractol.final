/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonserr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 15:58:55 by rmonserr          #+#    #+#             */
/*   Updated: 2020/03/07 15:58:56 by rmonserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mlx_error(void)
{
	ft_putstr("MLX ERROR");
	exit(1);
}

void	malloc_error(void)
{
	ft_putstr("Malloc error");
	exit(-1);
}
