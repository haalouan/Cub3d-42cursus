/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parssing.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haalouan <haalouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 11:58:11 by haalouan          #+#    #+#             */
/*   Updated: 2024/08/22 15:10:37 by haalouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSSING_H
# define PARSSING_H
# include "../cub3d.h"

typedef struct  s_pars
{
	char **path;
	char **map;
	char **f_c;
}	t_pars;


int		parse_args(char *str);
void	parssing(int arc, char **arv);
char	**allocate_all_lines(int fd);
t_pars	*put_in_struct(char **all_lines);
t_pars	*allocate_cub(void);
char	**allocate_path_fc(int i);
char	**parse_all_lines(char **str);
char	**allocate_str(char **str);
#endif