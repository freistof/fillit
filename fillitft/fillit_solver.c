/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fillit_solver.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: fblom <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/25 11:52:33 by fblom         #+#    #+#                 */
/*   Updated: 2019/02/25 11:52:33 by fblom         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char			*mapmaker(int dimension)
{
	char	*map;
	int		x;
	int		y;

	x = 0;
	y = 0;
	map = ft_strnew(dimension * dimension + dimension);
	map[dimension * dimension + dimension] = '\0';
	while (y < dimension * dimension + dimension)
	{
		while (x < dimension)
		{
			map[x + y] = '.';
			x++;
		}
		map[x + y] = '\n';
		x = 0;
		y += dimension + 1;
	}
	return (map);
}

static int		fit_block(char *map, int i, t_fillit *block, int dimension)
{
	int		j;

	j = 0;
	while (j < 4)
	{
		if (map[i + block->x_as[j] + dimension * block->y_as[j]] == '.')
			j++;
		else
			return (0);
	}
	j = 0;
	while (j < 4)
	{
		map[i + block->x_as[j] + dimension * block->y_as[j]] = block->letter;
		j++;
	}
	return (1);
}

static int		rem_block(char *map, int i, t_fillit *block, int dimension)
{
	int		j;

	j = 0;
	while (j < 4)
	{
		if (map[i + block->x_as[j] + dimension * block->y_as[j]] ==\
			block->letter)
		{
			map[i + block->x_as[j] + dimension * block->y_as[j]] = '.';
		}
		j++;
	}
	return (1);
}

int				fillit_solver(char *map, t_fillit *head, t_fillit *block, int d)
{
	int			i;
	int			ret;

	i = 0;
	while (map[i] != '\0')
	{
		if (map[i + block->x_as[0] + d * block->y_as[0]] == '.')
		{
			if (fit_block(map, i, block, d + 1) == 1)
			{
				if (block->next == NULL)
					return (1);
				ret = fillit_solver(map, head, block->next, d);
				if (ret == 1)
					return (1);
				else
					rem_block(map, i, block, d + 1);
			}
		}
		i++;
	}
	return (0);
}

char			*map_solver(t_fillit *head, t_fillit *block, int dimension)
{
	char	*map;
	int		ret;

	map = mapmaker(dimension);
	ret = 0;
	while (ret != 1)
	{
		ret = fillit_solver(map, head, block, dimension);
		if (ret == 1)
			return (map);
		free(map);
		dimension++;
		map = mapmaker(dimension);
	}
	return (map);
}
