/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamdoun <shamdoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 19:06:44 by haalouan          #+#    #+#             */
/*   Updated: 2024/10/08 19:06:15 by shamdoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>

char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *str);
int		ft_strncmp(const char *str1, const char *str2, size_t n);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strchr(const char *str, int c);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_malloc(size_t size, int flag);
int		ft_isalpha(int c);
char	**ft_split(char const *s, char c);
int		ft_atoi(const char *str);
#endif