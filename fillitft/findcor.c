/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   findcor.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: nde-wild <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/22 11:33:34 by nde-wild      #+#    #+#                 */
/*   Updated: 2019/02/22 11:33:59 by nde-wild      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		fixzero(t_fillit *move)
{
	while (move->x_as[0] != 0 && move->x_as[1] != 0\
		&& move->x_as[2] != 0 && move->x_as[3] != 0)
	{
		move->x_as[0]--;
		move->x_as[1]--;
		move->x_as[2]--;
		move->x_as[3]--;
	}
	while (move->y_as[0] != 0 && move->y_as[1] != 0\
		&& move->y_as[2] != 0 && move->y_as[3] != 0)
	{
		move->y_as[0]--;
		move->y_as[1]--;
		move->y_as[2]--;
		move->y_as[3]--;
	}
}

t_fillit		*findcor(char *s, t_fillit *cor)
{
	int			i;
	int			c;
	t_fillit	*move;

	i = 0;
	c = 0;
	if (cor == NULL)
	{
		move = fl_lstnew();
		cor = move;
	}
	else
		move = fl_lstadd(&cor);
	while (i < 21)
	{
		if (s[i] == '#')
		{
			move->x_as[c] = i % 5;
			move->y_as[c] = i / 5;
			c++;
		}
		i++;
	}
	fixzero(move);
	return (cor);
}
