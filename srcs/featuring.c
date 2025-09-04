/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   featuring.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 00:56:33 by lgerard           #+#    #+#             */
/*   Updated: 2025/09/04 20:03:52 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	reset_cmds(t_dmlx *mlx)
{
	mlx->px = 0;
	mlx->py = 0;
	mlx->pm = 1;
}

void	magn_change(t_dmlx *mlx, int way)
{
	if (way == 0)
		mlx->pm *= 1.05;
	else
		mlx->pm /= 1.05;
}

void	move_cmds(t_dmlx *mlx, int way)
{
	if (way == 0)
		mlx->py += mlx->crefy / 50;
	if (way == 1)
		mlx->py -= mlx->crefy / 50;
	if (way == 2)
		mlx->px -= mlx->crefx / 50;
	if (way == 3)
		mlx->px += mlx->crefx / 50;
}

int	pre_featuring_0(t_dmlx *mlx, char *f, int *i, int len)
{
	if (ft_strnstr(f, "pyra.fdf", len) != 0)
	{
		mlx->lowdefcol = 0x00492200;
		mlx->topdefcol = 0x00FFFFB5;
		(*i)++;
	}
	if (ft_strnstr(f, "100-6", len) != 0 || ft_strnstr(f, "50-4", len))
	{
		mlx->lowdefcol = 0x00404070;
		(*i)++;
	}
	if (ft_strnstr(f, "pylone.fdf", len) != 0)
	{
		mlx->lowdefcol = 0x00404070;
		(*i)++;
	}
	if (ft_strnstr(f, "mars.fdf", len) != 0)
	{
		mlx->lowdefcol = 0x00440000;
		mlx->topdefcol = 0x00FF0000;
		i++;
	}
	return ((*i));
}

int	pre_featuring(t_dmlx *mlx, char *f, int i, int len)
{
	mlx->lowdefcol = DEF_COLOR;
	mlx->topdefcol = DEF_TOPCOLOR;
	mlx->c42 = 0;
	mlx->iangle = 0.523598776;
	mlx->zangle = 4.71238898;
	mlx->yangle = 0;
	mlx->zfact = 1;
	if (ft_strnstr(f, "42.fdf", len) != 0)
	{
		mlx->lowdefcol = 0x00FFFFFF;
		mlx->optdefcol = 0x00FFFF60;
		mlx->topdefcol = 0x00E783E7;
		mlx->c42 = 1;
		mlx->iangle = 0.733038286;
		mlx->zangle = 0;
		mlx->zfact = 9;
		i++;
	}
	pre_featuring_0(mlx, f, &i, len);
	return (i);
}

/* 
1°   = 0.017453293
5°   = 0,087266463
10°  = 0.174532925
20°  = 0.34906585
30°  = 0.523598776
37°	 = 0.645771823
40°  = 0.698131701
42°  = 0.733038286
45°  = 0.785398163
50°  = 0.872664626
60°  = 1.047197551
90°  = 1.570796327
120° = 2.094395102
150° = 2.617993878
180° = 3.141592654
210° = 3.665191429
240° = 4.188790205
270° = 4.71238898
300° = 5.235987756
330° = 5.759586532
350° = 6.108652382
355° = 6.195918845
357° = 6.23082543
358° = 6.248278722
359° = 6.265732015
360° = 6.283185307

files
10-2
10-70
20-60
50-4
100-6
basictest
elem
elem2 2
elem-col
elem-fract
julia
pentenegpos
plat!
pnp_flat!
pyramide
pylone
t1
t2
*/