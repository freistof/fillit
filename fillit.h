/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fillit.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fblom <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/15 05:33:24 by fblom         #+#    #+#                 */
/*   Updated: 2019/02/15 05:33:25 by fblom         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <unistd.h>

# include <stdio.h> // REMOVE

int				ft_checkvalidity(char *filename);
int				tetri_connection(char *str);

#endif
