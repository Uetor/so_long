/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 20:05:29 by pedrogon          #+#    #+#             */
/*   Updated: 2023/10/29 03:20:32 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_hook(mlx_key_data_t keydata, void* param)
{
	t_data *data = param;

	if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(data->mlx);
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
	{
		if (data->map[data->y - 1][data->x] == '0' || data->map[data->y - 1][data->x] == 'C')
		{
			data->map[data->y][data->x] = '0';
			data->face->instances[0].y -=data->tilesize;
			data->y -= 1;
			ft_catch_item(data);
			data->map[data->y][data->x] = 'P';
		}
	}
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
	{
		if (data->map[data->y + 1][data->x] == '0'|| data->map[data->y + 1][data->x] == 'C')
		{
			data->map[data->y][data->x] = '0';
			data->face->instances[0].y +=data->tilesize;
			data->y += 1;
			ft_catch_item(data);
			data->map[data->y][data->x] = 'P';
		}
	}
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
	{
		if (data->map[data->y][data->x - 1] == '0' || data->map[data->y][data->x - 1] == 'C')
		{

			data->map[data->y][data->x] = '0';
			data->face->instances[0].x -=data->tilesize;
			data->x -= 1;
			ft_catch_item(data);
			data->map[data->y][data->x] = 'P';
		}
	}
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
	{
		if (data->map[data->y][data->x + 1] == '0' || data->map[data->y][data->x + 1] == 'C')
		{
			data->map[data->y][data->x] = '0';
			data->face->instances[0].x +=data->tilesize;
			data->x += 1;
			ft_catch_item(data);
			data->map[data->y][data->x] = 'P';
		}
	}
}

