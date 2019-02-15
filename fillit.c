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

int		ft_checkvalidity(char *string)
{
	int		fd;
	int		ret;
	char	buf[BUFF_SIZE];

	fd = open(string, O_RDWR);
	ret = BUFF_SIZE;
	while (ret == BUFF_SIZE)
	{
		ret = read(fd, buf, BUFF_SIZE);
		if (ret == 0)
			break ;
		buf[ret] = '\0';
		ft_putstr(buf);
		ret = BUFF_SIZE;
	}
	close(fd);
	return (1);
}

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
	return (0);
}
