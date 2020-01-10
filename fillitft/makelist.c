/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   makelist.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nde-wild <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/22 11:33:34 by nde-wild      #+#    #+#                 */
/*   Updated: 2019/02/22 11:33:59 by nde-wild      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_fillit		*fl_lstnew(void)
{
	t_fillit *head;

	head = (t_fillit*)malloc(sizeof(t_fillit));
	if (head == NULL)
		return (head);
	head->next = NULL;
	return (head);
}

t_fillit		*fl_lstadd(t_fillit **cor)
{
	t_fillit *move;
	t_fillit *new;

	move = *cor;
	while (move->next)
	{
		move = move->next;
	}
	new = fl_lstnew();
	move->next = new;
	new->next = NULL;
	return (new);
}
