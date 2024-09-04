/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsse_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haalouan <haalouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 18:16:29 by haalouan          #+#    #+#             */
/*   Updated: 2024/09/04 23:09:42 by haalouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parssing.h"

void    checkValidFor0(char **str, int i, int k)
{
    if (str[i][k + 1] == '\0')
        exit(printf("invalid map (open map)\n"));
    if (k < (int)ft_strlen(str[i + 1]))
    {
        if ( str[i + 1][k] != '1' && str[i + 1][k] != '0'
            && str[i + 1][k] != 'E' && str[i + 1][k] != 'S'
            && str[i + 1][k] != 'W' && str[i + 1][k] != 'N')
            exit(printf("invalid map (open map)\n"));
    }
    else
        exit(printf("invalid map (open map)\n"));
    if (k < (int)ft_strlen(str[i - 1]))
    {
        if (str[i - 1][k] != '1' && str[i - 1][k] != '0'
            && str[i - 1][k] != 'E' && str[i - 1][k] != 'S'
            && str[i - 1][k] != 'W' && str[i - 1][k] != 'N')
            exit(printf("invalid map (open map)\n"));
    }
    else
        exit(printf("invalid map (open map)\n"));
    
}


void    checkValidForPlayer(char **str, int i, int k)
{
    if (str[i][k + 1] == '\0')
        exit(printf("invalid map (player in a wrong position)\n"));
    if (k < (int)ft_strlen(str[i + 1]))
    {
        if (str[i + 1] && str[i + 1][k] != '1' && str[i + 1][k] != '0')
            exit(printf("invalid map (player in a wrong position)\\n"));
    }
    else
        exit(printf("invalid map (player in a wrong position)\n"));
    if (k < (int)ft_strlen(str[i - 1]))
    {
        if (str[i - 1] && str[i - 1][k] != '1' && str[i - 1][k] != '0')
            exit(printf("invalid map (player in a wrong position)\n"));
    }
    else
        exit(printf("invalid map (player in awrong position)\n"));
}

void protecte_map(char c)
{
    if (c != '0' && c != '1' && c != 'E' && c != 'N' && c != 'S' && c != 'W')
        exit(printf("invalid map (unaccepted character)\n"));
}

void    checkLockPlayer(char **str, int i, int k)
{
    if (k < (int)ft_strlen(str[i + 1]) && k < (int)ft_strlen(str[i - 1]))
    {
        if (str[i + 1][k] == '1' && str[i - 1][k] == '1'
            && str[i][k + 1] == '1' && str[i - 1][k] == '1')
            exit(printf("invalid map (player locked)\n"));
    }
    else
        exit(printf("invalid map (player locked)\n"));
}

void check_dup(char **str)
{
    int i;
    int k;
    int flag;

    i = 0;
    flag = 0;
    while (str && str[i])
    {
        k = 0;
        while (str[i] && str[i][k])
        {
            if (str[i][k] == 'E' || str[i][k] == 'N' || str[i][k] == 'S' || str[i][k] == 'W')
                flag++;
            k++;
        }
        i++;
    }
    if (flag > 1)
        exit(printf("invalid map (duplicate player)\n"));
}

void    check_empty_line(char **str)
{
    int i;
    int k;

    i = 0;
    k = 0;
    check_dup(str);
    while (str && str[i])
    {
        k = 0;
        while (str[i][k] && (str[i][k] == ' ' || str[i][k] == '\t'))
                k++;
        while (str[i] && str[i][k])
        {
            protecte_map(str[i][k]);
            if (str[i][k] == '0')
                checkValidFor0(str, i, k);
            if (str[i][k] == 'E' || str[i][k] == 'W' || str[i][k] == 'S' || str[i][k] == 'N')
            {
                checkValidForPlayer(str, i, k);
                checkLockPlayer(str, i, k);
            }
            k++;
        }
        i++;
    }
}

void    parsse_map(char **map)
{
    int i;

    i = 0;
    while (map && map[0] && map[0][i])
    {
        if (map[0][i] != '1')
            exit(printf("invalid map (open map)\n"));
        i++;
    }
    check_empty_line(map);
}

