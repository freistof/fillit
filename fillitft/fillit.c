/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fillit.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fblom <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/15 05:31:07 by fblom         #+#    #+#                 */
/*   Updated: 2019/02/15 05:31:08 by fblom         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		blockcount_letters(t_fillit **head)
{
	t_fillit	*move;
	int			blockcount;
	int			a;
	char		c;

	c = 'A';
	a = 1;
	blockcount = 0;
	move = *head;
	while (move)
	{
		move = move->next;
		blockcount++;
	}
	move = *head;
	while (move)
	{
		move->letter = c;
		c++;
		move = move->next;
		a++;
	}
	return (blockcount);
}

int				main(int argc, char **argv)
{
	t_fillit	*head;
	char		*map;
	int			blockcount;
	int			a;

	a = 1;
	blockcount = 0;
	head = NULL;
	if (argc != 2)
	{
		ft_putendl_fd("usage: ./fillit tetrominos_file", 1);
		return (1);
	}
	if (ft_checkvalidity(argv[1], &head) == 0 || blockcount_letters(&head) > 26)
	{
		ft_putstr("error\n");
		return (0);
	}
	blockcount = blockcount_letters(&head);
	map = map_solver(head, head, 2);
	ft_putstr(map);
	return (0);
}
