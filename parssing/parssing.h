/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parssing.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haalouan <haalouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 11:58:11 by haalouan          #+#    #+#             */
/*   Updated: 2024/08/23 15:05:24 by haalouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSSING_H
# define PARSSING_H
# include "../cub3d.h"

typedef struct  s_textures
{
	char **map;
	char *no;
	char *so;
	char *ea;
	char *we;
	char *f;
	char *c;
}	t_textures;

int		parse_args(char *str);
void	parssing(int arc, char **arv);
char	**allocate_all_lines(int fd);
char	**parse_all_lines(char **str, t_textures *textures);
char	**allocate_str(char **str);
int		check_line_spaces(char *str);
void	parse_textures(char **str, t_textures *textures);
t_textures	*allocate_textures(void);
#endif