/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 20:51:34 by lgerard           #+#    #+#             */
/*   Updated: 2025/03/01 16:01:45 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void print_t_map(t_map **map)
{
	t_map	*lst;

	lst = *map;
	printf("\n\nStructure t_map\n\n");
	printf("**map %p, *map %p\n", map, lst);
	while (lst)
	{
		printf("%p, x %f, y %f, z %f, color %X, next %p, side %p, down %p\n"
		, lst, lst->x, lst->y, lst->z, lst->color, lst->next, lst->side, lst->down);
		lst =lst->next;
	}
}
void	print_display(t_xvar *dis)
{
	printf("\n\nStructure t_xvar\n\n");
	printf("display %p, root %ld, screen %d, depth %d, visual %p, cmap %ld, private_cmap %d, win_list %p\n"
	, dis->display, dis->root, dis->screen, dis->depth, dis->visual, dis->cmap, dis->private_cmap, dis->win_list);
	printf("(*loop_hook) %p, *loop_param %p, use_xshm %d, pshm_format %d, do_flush %d\n"
	, dis->loop_hook, dis->loop_param, dis->use_xshm, dis->pshm_format, dis->do_flush);
	printf("rcrgb[6] %i %i %i %i %i %i,wm_delete_window %ld, wm_protocols %ld, end_loop %d\n"
	, dis->decrgb[0], dis->decrgb[1], dis->decrgb[2], dis->decrgb[3], dis->decrgb[4], dis->decrgb[5], dis->wm_delete_window, dis->wm_protocols, dis->end_loop);
}

void	print_struct(t_dmlx *vars)
{
	printf ("\n\nStructure t_dmlx *vars\n\n");
	printf("*mlx %p, *win %p, *img %p, *map %p, *tab %p\n", vars->mlx, vars->win,
			vars->img, vars->map, vars->tab);
	printf("swidth %d, sheight %d, width %d, height %d, magn %f, iangle %f, zangle %f, zfact %f\nxmin %f, xmax %f, ymin %f, ymax %f, zmin %f, zmax %f, maxdiag %f\n"
			, vars->swidth, vars->sheight, vars->width, vars->height, vars->magn, vars->iangle, vars->zangle, vars->zfact, vars->xmin, vars->xmax, vars->ymin
			,vars->ymax, vars->zmin, vars->zmax, vars->maxdiag);
	printf("color %i, lowdefcol %X, topdefcol %X, crefx %f, crefy %f\n"
			, vars->color, vars->lowdefcol, vars->topdefcol, vars->crefx, vars->crefy);		
	printf("*addr %p, bpp %i, llen %i, endian %i\n", vars->addr, vars->bpp, vars->llen, vars->endian);
	print_t_map((t_map**)vars->map);
	print_display(vars->mlx);
}
/* 
 char    *addr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;


typedef struct	s_win_list
{
	Window				window;
	GC					gc;
	struct s_win_list	*next;
	int					(*mouse_hook)();
	int					(*key_hook)();
	int					(*expose_hook)();
	void				*mouse_param;
	void				*key_param;
	void				*expose_param;
	t_event_list		hooks[MLX_MAX_EVENT];
}				t_win_list;


typedef struct	s_img
{
	XImage			*image;
	Pixmap			pix;
	GC				gc;
	int				size_line;
	int				bpp;
	int				width;
	int				height;
	int				type;
	int				format;
	char			*data;
	XShmSegmentInfo	shm;
}				t_img;

typedef struct	s_xvar
{
	Display		*display;
	Window		root;
	int			screen;
	int			depth;
	Visual		*visual;
	Colormap	cmap;
	int			private_cmap;
	t_win_list	*win_list;
	int			(*loop_hook)();
	void		*loop_param;
	int			use_xshm;
	int			pshm_format;
	int			do_flush;
	int			decrgb[6];
	Atom		wm_delete_window;
	Atom		wm_protocols;
	int 		end_loop;
}				t_xvar; */