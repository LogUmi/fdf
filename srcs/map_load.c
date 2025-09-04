/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_load.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 21:37:26 by lgerard           #+#    #+#             */
/*   Updated: 2025/09/04 20:04:26 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

double	ft_atoifdf(char *str, double *error, int i, int flag)
{
	double	sign;
	double	n;

	sign = 1;
	n = 0;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-' && str[i + 1] > 47 && str[i + 1] < 58)
			sign = -1;
		flag++;
		i++;
	}
	while (str[i] > 47 && str[i] < 58)
	{
		n *= 10;
		n += str[i++] - 48;
	}
	n *= sign;
	if (flag > 1 || n < -2147483648 || n > 2147483647)
		(*error) = -1;
	if (str[i] != 0)
		(*error) = (double)str[i];
	return (n);
}

unsigned int	extract_color(char *s, char *b, int i, t_dmlx *vars)
{
	unsigned int	n;
	int				j;

	n = 0;
	while (s[i] == '-' || s[i] == '+')
		i++;
	while (s[i] > 47 && s[i] < 58)
		i++;
	if (ft_strlen(&s[i]) < 5)
		return (error(vars, "File format color issue\n", 1));
	if (ft_strncmp(&s[i], ",0x", 3) != 0)
		return (error(vars, "File format color separator issue\n", 1));
	i += 3;
	while (s[i] != 0)
	{
		j = 0;
		while ((b[j] != s[i] && (j < 9 && s[i] != b[j] + 32)) && b[j] != 0)
			j++;
		if (j == 16)
			return (error(vars, "File format color hexadecimal issue\n", 1));
		n *= 16;
		n += j;
		i++;
	}
	return (n);
}

void	record_point(t_dmlx *vars, double *i, unsigned int pcolor, double line)
{
	t_map	*map;

	map = ft_newpoint(i, line, vars, pcolor);
	if (!map)
		error(vars, "Recording map issue\n", 1);
	if (*(vars->map) == NULL)
		*(vars->map) = map;
	else
		ft_mapadd_back(vars->map, map);
	if (map->x < vars->xmin)
		vars->xmin = map->x;
	if (map->y < vars->ymin)
		vars->ymin = map->y;
	if (map->z < vars->zmin)
		vars->zmin = map->z;
	if (map->x > vars->xmax)
		vars->xmax = map->x;
	if (map->y > vars->ymax)
		vars->ymax = map->y;
	if (map->z > vars->zmax)
		vars->zmax = map->z;
	vars->nmap += 1;
}

int	take_line(char **tab, t_dmlx *vars, int count, double *line)
{
	double			i[3];
	unsigned int	pcolor;

	i[0] = 0;
	i[1] = 0;
	while (tab[(int)i[0]])
	{
		i[2] = 0;
		i[1] = ft_atoifdf(tab[(int)i[0]], &i[2], 0, 0);
		if (i[2] != 44 && i[2] != 0 && i[2] != '\n')
			return (error(vars, "File format issue", 1));
		if (i[2] == 44)
			vars->color++;
		if (i[2] == 44)
			pcolor = extract_color(tab[(int)i[0]], "0123456789ABCDEF", 0, vars);
		else
			pcolor = vars->lowdefcol;
		record_point(vars, i, pcolor, (*line));
		count++;
		i[0]++;
	}
	if ((i[0] - 1) != vars->xmax && i[0] != 0)
		return (error(vars, "Missing point detected in map file", 1));
	(*line)++;
	return (count);
}

void	map_load(t_dmlx *vars, char *filename, int count, double line)
{
	int		fd;
	char	*str;
	char	**tab;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		error(vars, "Failed to load file", 1);
	while (line >= 0)
	{
		str = get_next_lined(fd);
		if (!str)
			line = -1;
		else
		{
			tab = ft_split(str, 32);
			free(str);
			if (!tab)
				error(vars, "Split issue", 1);
			vars->tab = (void *)tab;
			count = take_line(tab, vars, count, &line);
			free_tabfdf(tab, vars);
		}
	}
	close(fd);
}
