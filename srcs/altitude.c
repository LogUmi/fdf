/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   altitude.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 23:57:14 by lgerard           #+#    #+#             */
/*   Updated: 2025/03/02 14:55:27 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_zpos	*ft_newzpos(double z, t_dmlx *mlx)
{
	t_zpos	*nc;

	nc = malloc(sizeof(t_zpos));
	if (nc == 0)
		return (0);
	nc->z = z;
	nc->pos = 0;
	nc->next = NULL;
	if (mlx->zpos == NULL)
	{
		mlx->zpos = malloc(sizeof(t_zpos *));
		if (!mlx->zpos)
			error(mlx, "Memory allocation failed\n", 1);
		*(mlx->zpos) = NULL;
	}
	return (nc);
}

void	free_zpos(t_zpos **lst, t_dmlx *vars)
{
	t_zpos	*tlst;
	t_zpos	*slst;

	tlst = *lst;
	while (tlst)
	{
		slst = tlst->next;
		free(tlst);
		tlst = slst;
	}
	free(vars->zpos);
	vars->zpos = NULL;
}

void	zpos_add_back(t_zpos **lst, t_zpos *new)
{
	t_zpos	*tlst;

	if (!lst || !new)
		return ;
	tlst = *lst;
	if (*lst == 0)
	{
		*lst = new;
		return ;
	}
	while (tlst->next != 0)
		tlst = tlst->next;
	tlst->next = new;
	return ;
}

int	zpos_sort(t_zpos **zpos, int i, double cpz)
{
	t_zpos	*lst;
	t_zpos	*tlst;

	lst = *zpos;
	while (lst)
	{
		lst->pos = i++;
		lst = lst->next;
	}
	lst = *zpos;
	while (lst->next != 0)
	{
		tlst = lst->next;
		if (lst->z > tlst->z)
		{
			cpz = lst->z;
			lst->z = tlst->z;
			tlst->z = cpz;
			lst = *zpos;
		}
		else
			lst = lst->next;
	}
	return (i);
}

void	list_zpos(t_dmlx *mlx, double z)
{
	t_zpos	*zpos;

	if (mlx->zpos == NULL)
	{
		zpos = ft_newzpos(z, mlx);
		if (!zpos)
			error(mlx, "Recording zpos issue\n", 1);
		if (*(mlx->zpos) == NULL)
			*(mlx->zpos) = zpos;
	}
	else
	{
		if (z_inlist(mlx->zpos, z) == -1)
		{
			zpos = ft_newzpos(z, mlx);
			if (!zpos)
				error(mlx, "Recording zpos issue\n", 1);
			zpos_add_back(mlx->zpos, zpos);
		}
	}
}
