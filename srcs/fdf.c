/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 22:11:12 by lgerard           #+#    #+#             */
/*   Updated: 2025/03/03 13:54:14 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	error(t_dmlx *vars, char *msg, int ret)
{
	if (*msg)
		ft_printf("%s\n", msg);
	if (vars->tab != NULL)
		free_tabfdf((char **)vars->tab, vars);
	if (vars->map != 0)
		free_map(vars->map, vars);
	if (vars->zpos != 0)
		free_zpos(vars->zpos, vars);
	if (vars->img1 != 0)
		mlx_destroy_image(vars->mlx, vars->img1);
	if (vars->img2 != 0)
		mlx_destroy_image(vars->mlx, vars->img2);
	if (vars->win != 0)
		mlx_destroy_window(vars->mlx, vars->win);
	if (vars->mlx != 0)
	{
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
	}
	exit (ret);
}

static int	ft_close(t_dmlx *vars)
{
	return (error(vars, "Regular end of session on mouse command", 0));
}

void	main_suite(t_dmlx *m)
{
	m->img2 = mlx_new_image(m->mlx, m->width, m->height);
	if (!m->img2)
		error(m, "mlx_new_image failed", 1);
	m->addr2 = mlx_get_data_addr(m->img2, &m->bpp2, &m->llen2, &m->endian2);
	swap_img(m, 0);
	draw_lines(m, m->map);
	mlx_put_image_to_window(m->mlx, m->win, m->img, 0, 0);
	swap_img(m, 1);
	ft_key_init(m);
	mlx_hook(m->win, 2, 1L << 0, ft_key_in, m);
	mlx_hook(m->win, 3, 1L << 1, ft_key_out, m);
	mlx_loop_hook(m->mlx, ft_hook_loop, m);
	mlx_hook(m->win, 17, 0, ft_close, m);
	mlx_loop(m->mlx);
}

int	main(int argc, char **argv)
{
	t_dmlx	m;
	char	*s;

	init_dmlx(&m);
	if (argc != 2)
		return (error(&m, "Argument issue (only path/map_filename)", 1));
	s = &argv[1][0];
	map_get(&m, s);
	m.mlx = mlx_init();
	if (!m.mlx)
		return (error(&m, "mlx_init failed", 1));
	if (mlx_get_screen_size(m.mlx, &m.swidth, &m.sheight) != 0)
		return (error(&m, "mlx was unable to detect screen", 1));
	ft_printf("Screen %dx%d detected\n", m.swidth, m.sheight);
	size_img(&m);
	m.win = mlx_new_window(m.mlx, m.width, m.height, s);
	if (!m.win)
		return (error(&m, "mlx_new_window failed", 1));
	ft_printf ("Windows %dx%d opended\n", m.width, m.height);
	m.img1 = mlx_new_image(m.mlx, m.width, m.height);
	if (!m.img1)
		return (error(&m, "mlx_new_image failed", 1));
	m.addr1 = mlx_get_data_addr(m.img1, &m.bpp1, &m.llen1, &m.endian1);
	main_suite(&m);
	return (0);
}
