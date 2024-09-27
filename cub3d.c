/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamdoun <shamdoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 10:53:35 by haalouan          #+#    #+#             */
/*   Updated: 2024/09/27 22:14:22 by shamdoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int mapValues[10][21] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1},
    {1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
};

void f()
{
	system("leaks cub3d");
}

void init_player(t_map_e *m)
{
	m->player = malloc(sizeof(t_player));
	if (!m->player)
	{
		free(m);
		exit (1);
	}
}

void init_textures(t_map_e *m, t_map *data)
{
	m->all_textures = malloc(sizeof(mlx_texture_t) * 4);
	if (!m->all_textures)
		exit (1);
	if (!(m->all_textures[0] = mlx_load_png(data->ea)) ||
	!(m->all_textures[1] = mlx_load_png(data->we)) ||
	!(m->all_textures[2] = mlx_load_png(data->no)) ||
	!(m->all_textures[3] = mlx_load_png(data->so)))
		exit (1);
}

void calculate_dimensions(t_map_e *m, t_map *data)
{
	int i;
	int height;
	int width;
	int	tmp;

	i = 0;
	height = 0;
	width = 0;
	while (data->map[i++])
		height++;
	i = 0;
	while (data->map[i])
	{
		tmp = ft_strlen(data->map[i]);
		if (tmp > width)
			width = tmp;
		i++;
	}
	m->width = width;
	m->height = height;
}

int row_empty(char *s)
{
	int i;
	int empty;

	i = 0;
	empty = 1;
	while (s[i])
	{
		if (s[i] != ' ' && s[i] != 9)
			empty = 0;
		i++;
	}
	return (empty);
}

int	ft_isalpha(int c)
{
	int	a;
	int	b;

	a = (c <= 90) && (c > 64);
	b = (c <= 122) && (c > 96);
	return (a || b);
}

void	draw_block_v1(mlx_image_t *img, int x, int y, char value)
{
	uint32_t	color;
	int			i;
	int			j;

	if (value == '1')
		color = get_rgba(0, 0, 0, 200);
	else
		color = get_rgba(255, 255, 255, 255);
	i = 0;
	while (i < BLOCK_W - 1)
	{
		j = 0;
		while (j < BLOCK_L - 1)
		{
			mlx_put_pixel(img, (y + j) / 4, (x + i) / 4, color);
			j++;
		}
		i++;
	}
}

double extract_angle(char d)
{
	if (d == 'E')
		return (0);
	if (d == 'N')
		return (90);
	if (d == 'W')
		return (180);
	return (270);
}

void init_player_position(t_player *p, int i, int j, char direction)
{
	p->x_p = j * BLOCK_W + 40;
	p->y_p = i * BLOCK_L + 40;
	p->angle = extract_angle(direction);
}

void	draw_map_v1(t_map_e *m, char **data, int flag)
{
	int	i;
	int	j;
	int k;

	i = 0;
	while (i < m->height)
	{
		if (!row_empty(data[i]))
		{
			j = 0;
			k = ft_strlen(data[i]);
			while (j < k && j < m->width)
			{
				if (data[i][j] != ' ' && data[i][j] != 9)
				{
					draw_block_v1(m->interface->new_img, (i + 1) * (BLOCK_L),
						(j + 1) * (BLOCK_W), data[i][j]);
					if (!flag && ft_isalpha(data[i][j]))
						init_player_position(m->player, i, j, data[i][j]);
				}
				j++;
			}
		}
		i++;
	}
}


void init_all_values(t_map_e *m, t_map *data)
{
	// init_textures(m, data);
	init_player(m);
	calculate_dimensions(m, data);
	m->m_values = data->map;
	m->interface = malloc(sizeof(t_map));
	if (!m->interface)
	{
		free(m);
		free(m->player);
		exit (1);
	}
	m->interface->mlx_ptr = mlx_init(m->width * BLOCK_W,
			m->height * BLOCK_L, "overall_map", false);
	if (!m->interface->mlx_ptr)
	{
		free(m->player);
		free(m->interface);
		free(m);
		exit (1);
	}
	m->interface->new_img = mlx_new_image(m->interface->mlx_ptr,
			m->width * BLOCK_W, m->height * BLOCK_L);
	if (!m->interface->new_img)
	{
		free(m->player);
		free(m->interface->mlx_ptr);
		free(m->interface);
		free(m);
		exit (1);
	}
}

void	start_game(t_map *data)
{
	t_map_e	*map;
	
	map = (t_map_e *)malloc(sizeof(t_map));
	if (!map)
		exit (1);
	init_all_values(map, data);
	draw_map_v1(map, data->map, 0);
	draw_player(map);
	if (mlx_image_to_window(map->interface->mlx_ptr,
			map->interface->new_img, 0, 0))
	{
		free(map->player);
		free(map->interface->mlx_ptr);
		free(map->interface->new_img);
		free(map->interface);
		free(map);
		exit (1);
	}
	mlx_loop_hook(map->interface->mlx_ptr, &key_func, map);
	mlx_loop(map->interface->mlx_ptr);
	mlx_terminate(map->interface->mlx_ptr);
}

int	main(int arc, char **arv)
{
	(void)arv;
	(void)arc;
	t_map	*text;
	text = parssing(arc, arv);
	
	start_game(text);
	free_map(text);
	// atexit(f);
	return (0);
}
