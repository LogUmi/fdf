/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 11:36:40 by lgerard           #+#    #+#             */
/*   Updated: 2025/03/03 17:46:01 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	z_inlist(t_zpos **zpos, double z)
{
	t_zpos	*lst;

	lst = *zpos;
	while (lst)
	{
		if (lst->z == z)
			return (lst->pos);
		lst = lst->next;
	}
	return (-1);
}

void	center_ref(t_dmlx *mlx, t_map **map, double xmid, double ymid)
{
	t_map	*a;

	a = *map;
	xmid = ceil(fabs(mlx->xmax - mlx->xmin) / 2);
	ymid = ceil(fabs(mlx->ymax - mlx->ymin) / 2);
	while (a)
	{
		a->x -= xmid;
		a->y -= ymid;
		list_zpos(mlx, a->z);
		a = a->next;
	}
	mlx->nz = zpos_sort(mlx->zpos, 0, 0);
	if (mlx->nz > 1)
		mlx->nz -= 1;
}

void	set_zcolor(t_dmlx *mlx, t_map **map, int pos, int zlen)
{
	t_map			*a;
	unsigned int	col1;
	unsigned int	col2;

	a = *map;
	col1 = mlx->lowdefcol;
	col2 = mlx->topdefcol;
	printf("Applying this fdf colors defintion (no colors in map)\n");
	while (a)
	{
		pos = z_inlist(mlx->zpos, a->z);
		a->color = intercolor(col1, col2, (double)pos / (double)zlen);
		a = a->next;
	}
}

void	map_get(t_dmlx *mlx, char *filename)
{
	if (pre_featuring(mlx, filename, 0, ft_strlen(filename)) == 0)
		ft_printf("Default feature applied\n");
	else
		ft_printf("Special feature detected and applied\n");
	ft_printf("Loading map ... ");
	map_load(mlx, filename, 0, 0);
	if (mlx->nmap < 2)
		error(mlx, "unappropriate map", 1);
	ft_printf("done\n");
	set_map(mlx->map, 0, 0);
	center_ref(mlx, mlx->map, 0, 0);
	if (mlx->color == 0)
		set_zcolor(mlx, mlx->map, 0, mlx->nz);
	else
		printf("Applying colors definition detected in map\n");
	free_zpos(mlx->zpos, mlx);
}
