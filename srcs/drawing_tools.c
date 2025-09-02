/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 02:59:48 by lgerard           #+#    #+#             */
/*   Updated: 2025/03/02 19:24:05 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double	direction(double a, double b)
{
	if (a < b)
		return (1);
	if (a > b)
		return (-1);
	return (0);
}

int	intercolor(int color1, int color2, double n)
{
	int	r[3];
	int	g[3];
	int	b[3];

	r[1] = (color1 >> 16) & 0xFF;
	g[1] = (color1 >> 8) & 0xFF;
	b[1] = (color1) & 0xFF;
	r[2] = (color2 >> 16) & 0xFF;
	g[2] = (color2 >> 8) & 0xFF;
	b[2] = (color2) & 0xFF;
	r[0] = (int)(r[1] + n * (r[2] - r[1]));
	g[0] = (int)(g[1] + n * (g[2] - g[1]));
	b[0] = (int)(b[1] + n * (b[2] - b[1]));
	return ((r[0] << 16) | (g[0] << 8) | b[0]);
}

void	fill_img(t_dmlx *mlx, unsigned int color)
{
	char			*dst;
	unsigned int	ofst;
	unsigned int	bpp;

	ofst = 0;
	bpp = mlx->bpp / 8;
	while (ofst < (unsigned int)mlx->llen * ((unsigned int)mlx->height))
	{
		dst = mlx->addr + ofst;
		*(unsigned int *)dst = color;
		ofst += bpp;
	}
}

void	swap_img(t_dmlx *mlx, int way)
{
	if (way == 0 || (way == 1 && mlx->img != mlx->img1))
	{
		mlx->img = mlx->img1;
		mlx->bpp = mlx->bpp1;
		mlx->llen = mlx->llen1;
		mlx->endian = mlx->endian1;
		mlx->addr = mlx->addr1;
	}
	else
	{
		mlx->img = mlx->img2;
		mlx->bpp = mlx->bpp2;
		mlx->llen = mlx->llen2;
		mlx->endian = mlx->endian2;
		mlx->addr = mlx->addr2;
	}
}
