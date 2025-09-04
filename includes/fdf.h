/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:22:35 by lgerard           #+#    #+#             */
/*   Updated: 2025/09/04 20:00:52 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <stdint.h>
# include "../libft/includes/libft.h"
# include "../mlx_linux/mlx.h"
# include "../mlx_linux/mlx_int.h"

# define XK_ESCAPE 0xff1b
# define XK_PLUS   0xffab
# define XK_MINUS  0xffad
# define XK_UP     0xff52
# define XK_DOWN   0xff54
# define XK_RIGHT  0xff53
# define XK_LEFT   0xff51
# define XK_SPACE  0x0020
# define DEF_COLOR 0x00DDDD20
# define DEF_TOPCOLOR 0x0000FFFF

typedef struct s_map
{
	double			x;
	double			y;
	double			z;
	unsigned int	color;
	void			*next;
	void			*side;
	void			*down;
}					t_map;

typedef struct s_zpos
{
	double	z;
	int		pos;
	void	*next;
}			t_zpos;

typedef struct s_dmlx
{
	void			*mlx;
	void			*win;
	void			*img;
	void			*img1;
	void			*img2;
	t_map			**map;
	t_zpos			**zpos;
	void			*tab;
	int				nz;
	int				swidth;
	int				sheight;
	int				width;
	int				height;
	int				nmap;
	double			magn;
	double			xmin;
	double			xmax;
	double			ymin;
	double			ymax;
	double			zmin;
	double			zmax;
	double			maxdiag;
	int				color;
	unsigned int	lowdefcol;
	unsigned int	optdefcol;
	unsigned int	topdefcol;
	double			iangle;
	double			zangle;
	double			yangle;
	int				c42;
	double			zfact;
	double			crefx;
	double			crefy;
	double			px;
	double			py;
	double			pm;
	char			*addr;
	char			*addr1;
	char			*addr2;
	int				bpp;
	int				bpp1;
	int				bpp2;
	int				llen;
	int				llen1;
	int				llen2;
	int				endian;
	int				endian1;
	int				endian2;
	int				key[7];
}					t_dmlx;

typedef struct s_line
{
	int				x1;
	int				x2;
	int				y1;
	int				y2;
	unsigned int	c1;
	unsigned int	c2;
	int				npoint;
	int				num;
}				t_line;

int		error(t_dmlx *vars, char *msg, int ret);
void	init_dmlx(t_dmlx *vars);
void	map_load(t_dmlx *vars, char *filename, int count, double line);
t_map	*ft_newpoint(double *i, double y, t_dmlx *vars, unsigned int color);
void	ft_mapadd_back(t_map **lst, t_map *new);
void	free_tabfdf(char **tab, t_dmlx *vars);
void	free_map(t_map **lst, t_dmlx *vars);
void	size_img(t_dmlx *vars);
double	direction(double a, double b);
int		intercolor(int color1, int color2, double t);
int		cpy_line(t_dmlx *mlx, t_map *a, t_map *b, t_line *line);
void	draw_lines(t_dmlx *mlx, t_map **map);
void	map_get(t_dmlx *mlx, char *filename);
void	set_map(t_map **map, t_map *a, t_map *b);
t_zpos	*ft_newzpos(double z, t_dmlx *mlx);
void	free_zpos(t_zpos **lst, t_dmlx *vars);
void	zpos_add_back(t_zpos **lst, t_zpos *new);
void	list_zpos(t_dmlx *mlx, double z);
int		z_inlist(t_zpos **zpos, double z);
int		pre_featuring_0(t_dmlx *mlx, char *f, int *i, int len);
int		pre_featuring(t_dmlx *mlx, char *f, int i, int len);
int		zpos_sort(t_zpos **zpos, int i, double cpz);
void	fill_img(t_dmlx *mlx, unsigned int color);
void	magn_change(t_dmlx *mlx, int way);
void	reset_cmds(t_dmlx *mlx);
void	move_cmds(t_dmlx *mlx, int way);
void	swap_img(t_dmlx *mlx, int way);
int		ft_key_in(int keycode, t_dmlx *mlx);
int		ft_key_out(int keycode, t_dmlx *mlx);
void	ft_key_init(t_dmlx *mlx);
int		ft_hook_loop(t_dmlx *mlx);
#endif
