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

int		main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putendl_fd("usage: ./fillit tetrominos_file", 1);
		return (1);
	}
	if (ft_checkvalidity(argv[1]) == 1)
	{
		;
	}
	while (1);
	return (0);
}
