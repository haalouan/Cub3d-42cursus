/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parssing.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamdoun <shamdoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 11:58:11 by haalouan          #+#    #+#             */
/*   Updated: 2024/10/07 19:11:39 by shamdoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSSING_H
# define PARSSING_H
# include "../sources/libft/libft.h"
# include <stdio.h>
# include "../sources/get_next_line/get_next_line.h"
# include <fcntl.h>

typedef struct s_map
{
	char	**map;
	char	*no;
	char	*so;
	char	*ea;
	char	*we;
	char	*f;
	char	*c;
}	t_map;

int		parsse_args(char *str);
t_map	*parssing(int arc, char **arv);
char	**allocate_all_lines(int fd, char **arv);
char	**parsse_all_lines(char **str);
char	**allocate_str(char **str);
int		check_line_spaces(char *str);
void	parsse_textures(char **str, t_map *textures);
t_map	*allocate_textures(void);
void	put_0_1(char **str, t_map *textures);
int		count_map(char **str);
char	**allocate_map(int i);
void	check_map(char **str);
char	*escape_spaces(char *str);
int		check_map_valid(char **map);
void	print_textures(t_map *textures);
void	free_all_lines(char **all_lines);
void	free_map(t_map *Map);
void	check_valid_for0(char **all_lines, t_map *textures, int i, int k);
void	check_valid_for_player(char **all_lines, t_map *textures, int i, int k);
void	check_end_line(char **all_lines, t_map *textures, int k);
void	protecte_map(char **all_lines, t_map *textures, int i, int k);
void	check_empty_line(char **all_lines, t_map *textures);
void	parsse_map(char **all_lines, t_map *textures);
void	check_dup(char **all_lines, t_map *textures);
void	manage_error(char **str, t_map *textures);
void	put_c(char **str, t_map *textures);
void	put_0_1(char **str, t_map *textures);
void	parsse_textures(char **str, t_map *textures);//
char	*escape_spaces(char *str);
char	*put_map(char *str, int plus);
void	put_so(char **str, t_map *textures);
void	put_no(char **str, t_map *textures);
void	put_we(char **str, t_map *textures);
void	put_ea(char **str, t_map *textures);
void	put_f(char **str, t_map *textures);
void	check_dup(char **all_lines, t_map *textures);
void	protecte_map(char **all_lines, t_map *textures, int i, int k);

#endif