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

#include <stdio.h>

int		tetri_connection(char *str)
{
	int		i;
	int		c; // connections

	c = 0;
	i = 0;
	while (i < 21)
	{
		if (str[i] == '.' || str[i] == '\n')
			;
		else if (str[i] == '#')
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

int		main(void)
{
	int	ret;

	ret = tetri_connection("##..\n##..\n....\n....\n");
	printf("return: %i\n", ret);
	return (0);
}