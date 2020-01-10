/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validity.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: fblom <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/16 15:04:23 by fblom         #+#    #+#                 */
/*   Updated: 2019/02/16 15:04:25 by fblom         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		tetri_connection(char *str)
{
	int		i;
	int		c;

	c = 0;
	i = 0;
	while (i < 21)
	{
		if (str[i] == '#')
		{
			if (str[i - 5] == '#')
				c++;
			if (str[i + 5] == '#')
				c++;
			if (str[i - 1] == '#')
				c++;
			if (str[i + 1] == '#')
				c++;
		}
		i++;
	}
	if (c == 6 || c == 8)
		return (1);
	return (0);
}

static int		count_pounds_and_periods(char *block)
{
	int		i;
	int		pounds;
	int		periods;

	i = 0;
	pounds = 0;
	periods = 0;
	while (block[i] != '\0' && block[0] != '\n')
	{
		if (block[i] == '.')
			periods++;
		else if (block[i] == '\n')
			;
		else if (block[i] == '#')
			pounds++;
		else
			return (0);
		i++;
	}
	if (pounds == 4 && periods == 12)
		return (1);
	return (0);
}

static int		check_four_lines(int fd, char *block)
{
	int		ret;

	ret = read(fd, block, BUFF_SIZE);
	if (ret == 1)
		return (-3);
	block[ret] = '\0';
	if (ret == 0)
		return (-3);
	if (count_pounds_and_periods(block) == 0 \
		|| tetri_connection(block) == 0 || \
		(ft_strlen(block) != 21 && ft_strlen(block) != 20))
		return (-3);
	if (ret == 20)
		return (-2);
	return (1);
}

int				ft_checkvalidity(char *filename, t_fillit **head)
{
	int			fd;
	int			ret;
	char		block[BUFF_SIZE];
	t_fillit	*thing;

	thing = *head;
	ret = 1;
	fd = open(filename, O_RDONLY);
	while (ret > 0)
	{
		ret = check_four_lines(fd, block);
		if (ret == -3 || (ret == 0 && thing == NULL))
		{
			close(fd);
			return (0);
		}
		if (ret == 0)
			break ;
		thing = findcor(block, thing);
		ft_bzero(block, 21);
	}
	close(fd);
	*head = thing;
	return (1);
}
