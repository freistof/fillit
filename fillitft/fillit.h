/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fillit.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nde-wild <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/22 11:33:34 by nde-wild      #+#    #+#                 */
/*   Updated: 2019/02/22 11:33:59 by nde-wild      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILLIT_H
# define FT_FILLIT_H

# include "../libft/libft.h"
# include <fcntl.h>

typedef struct			s_fillit
{
	int					x_as[4];
	int					y_as[4];
	char				letter;
	struct s_fillit		*next;
}						t_fillit;

int						ft_checkvalidity(char *filename, t_fillit **head);
t_fillit				*findcor(char *s, t_fillit *cor);
char					*mapmaker(int dimension);
int						fillit_solver(char *map, t_fillit *head,\
						t_fillit *block, int dimension);
char					*map_solver(t_fillit *head, t_fillit *block, int d);
t_fillit				*fl_lstnew(void);
t_fillit				*fl_lstadd(t_fillit **cor);

#endif
