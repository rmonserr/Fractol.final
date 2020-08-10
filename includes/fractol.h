/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonserr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 14:39:24 by rmonserr          #+#    #+#             */
/*   Updated: 2020/03/07 14:39:25 by rmonserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDTH 480
# define HEIGHT	480

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "../libft/includes/libft.h"
# include "mlx.h"
# include <math.h>

typedef	struct	s_frac
{
	double		c_re;
	double		c_im;
	int			x;
	int			y;
	double		x1;
	double		y1;
	double		z_re;
	double		z_im;
	double		tmp;
	double		zoom;
	double		shift_x;
	double		shift_y;
	double		shift_value;
	int			move_julia;
	int			start_zoom;
}				t_frac;

typedef struct	s_img
{
	void		*img_ptr;
	int			*img_data;
	int			line;
	int			endian;
	int			bit_depth;
}				t_img;

typedef struct	s_win
{
	void *win_ptr;
	void *mlx_ptr;
}				t_win;

typedef struct	s_fractol
{
	t_win		win;
	t_img		img;
	int			iter_max;
	int			iter;
	int			fract_id;
	int			color;
	t_frac		man;
}				t_fractol;

/*
** -------------------control---------------------
*/

void			zoom(int key, t_fractol data);
void			movement(int key, t_fractol *data);
int				mouse_julia(int x, int y, t_fractol *data);
int				mouse_press(int key, int x, int y, t_fractol *data);
int				deal_key(int key, t_fractol *data);
int				deal_key_exit(void *data);

/*
** ---------------------errors--------------------
*/

void			mlx_error(void);
void			malloc_error(void);

/*
** ---------------------init----------------------
*/

void			struct_init(t_fractol *data);
int				fractol_init(char *file, t_fractol *data);
void			window_init(t_fractol *data);
void			fractol_parsing(t_fractol *data);
void			mandelbrot_init(t_fractol *data);
void			julia_init(t_fractol *data);
void			bs_init(t_fractol *data);

/*
** ---------------------draw----------------------
*/

void			draw_mandelbrot(t_fractol *data);
void			draw_julia(t_fractol *data);
void			draw_bs(t_fractol *data);
void			replace(t_fractol *data);
void			pix_to_img(t_fractol *data, int color);

/*
** -----------------calculations------------------
*/

void			color_calc(t_fractol *data);
void			calc_mandel(t_fractol *data);
void			calc_julia(t_fractol *data);
void			calc_bs(t_fractol *data);

#endif
