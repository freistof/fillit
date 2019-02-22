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

static int		count_pounds_and_periods(char *block)
{
	int		i;
	int		pounds;
	int		periods;

	i = 0;
	pounds = 0;
	periods = 0;
	while (block[i] != '\0')
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
	int		i;
	char	*pointer;
	char	*temp;
	char	*address;

	address = ft_strdup("\0");
	temp = ft_strdup("\0");
	i = 0;
	while (i < 4)
	{
		get_next_line(fd, &pointer);
		if (ft_strlen(pointer) != 4)
			return (0);
		temp = ft_strjoin(address, pointer);
		temp = ft_strjoin(temp, "\n");
		free(address);
		free(pointer);
		address = temp;
		i++;
	}
	i = get_next_line(fd, &pointer);
	if (i != 0 && ft_strlen(pointer) != 0)
		return (0);
	if (count_pounds_and_periods(address) == 1)
	{
		ft_memmove(block, address, ft_strlen(address) + 1);
		block[ft_strlen(address) + 1] = '\0';
		printf("%s\n", block);
		printf("connection result: %i\n\n", tetri_connection(block));
		if (i == 0 || tetri_connection(block) != 1)
			return (-3);
		return (1);
	}
	return (0);
}

int				ft_checkvalidity(char *filename)
{
	int			fd;
	int			ret;
	char		*block;

	ret = 1;
	block = ft_strdup("\0");
	fd = open(filename, O_RDONLY);
	while (ret > 0)
		ret = check_four_lines(fd, block);
	if (ret == 0)
		return (0);
	return (ret);
}
