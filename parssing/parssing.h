/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parssing.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haalouan <haalouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 11:58:11 by haalouan          #+#    #+#             */
/*   Updated: 2024/09/04 21:56:51 by haalouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSSING_H
# define PARSSING_H
# include "../cub3d.h"

typedef struct  s_map
{
	char **map;
	char *no;
	char *so;
	char *ea;
	char *we;
	char *f;
	char *c;
}	t_map;

int		parsse_args(char *str);
void	parssing(int arc, char **arv);
char	**allocate_all_lines(int fd);
char	**parsse_all_lines(char **str);
char	**allocate_str(char **str);
int		check_line_spaces(char *str);
void	parsse_textures(char **str, t_map *textures);
t_map	*allocate_textures(void);
void	put_0_1(char **str, t_map *textures);
int		count_map(char **str);
char	**allocate_map(int i);
void    parsse_map(char **map);
void	check_map(char **str);
char	*escape_spaces(char *str);
int		checkMapValid(char **map);
void	print_textures(t_map *textures);
#endif