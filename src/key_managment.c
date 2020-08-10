/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_manegment.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonserr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 16:15:57 by rmonserr          #+#    #+#             */
/*   Updated: 2020/03/07 16:15:58 by rmonserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		deal_key_exit(void *data)
{
	(void)data;
	exit(1);
}

int		deal_key(int key, t_fractol *data)
{
	if (key == 65307)
		exit(0);
	movement(key, data);
	return (0);
}
