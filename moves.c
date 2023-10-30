/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 20:05:29 by pedrogon          #+#    #+#             */
/*   Updated: 2023/10/30 05:30:20 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_hook(mlx_key_data_t keydata, void* param)
{
	t_data *data = param;

	if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(data->mlx);
	ft_move_w(keydata, data);
	ft_move_s(keydata, data);
	ft_move_a(keydata, data);
	ft_move_d(keydata, data);	
}

void ft_move_w(mlx_key_data_t keydata, t_data *data)
{
		if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
	{
		if (data->map[data->y - 1][data->x] == '0' 
			|| data->map[data->y - 1][data->x] == 'C' 
				|| data->map[data->y - 1][data->x] == 'E')
		{
			data->map[data->y][data->x] = '0';
			data->face->instances[0].y -=data->tilesize;
			data->y -= 1;
			ft_catch_item(data);
			data->map[data->y][data->x] = 'P';
			data->steps++;
			ft_printf("%d\n", data->steps);
			close_exit(data);
		}
	}
}

void ft_move_s(mlx_key_data_t keydata, t_data *data)
{
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
	{
		if (data->map[data->y + 1][data->x] == '0'
			|| data->map[data->y + 1][data->x] == 'C' 
				|| data->map[data->y + 1][data->x] == 'E')
		{
			data->map[data->y][data->x] = '0';
			data->face->instances[0].y +=data->tilesize;
			data->y += 1;
			ft_catch_item(data);
			data->map[data->y][data->x] = 'P';
			data->steps++;
			ft_printf("%d\n", data->steps);
			close_exit(data);
		}
	}
}

void ft_move_a(mlx_key_data_t keydata, t_data *data)
{
		if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
	{
		if (data->map[data->y][data->x - 1] == '0' 
			|| data->map[data->y][data->x - 1] == 'C' 
				|| data->map[data->y][data->x - 1] == 'E')
		{

			data->map[data->y][data->x] = '0';
			data->face->instances[0].x -=data->tilesize;
			data->x -= 1;
			ft_catch_item(data);
			data->map[data->y][data->x] = 'P';
			data->steps++;
			ft_printf("%d\n", data->steps);
			close_exit(data);
		}
	}
}

void ft_move_d(mlx_key_data_t keydata, t_data *data)
{
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
	{
		if (data->map[data->y][data->x + 1] == '0' 
			|| data->map[data->y][data->x + 1] == 'C' 
				|| data->map[data->y][data->x + 1] == 'E')
		{
			data->map[data->y][data->x] = '0';
			data->face->instances[0].x +=data->tilesize;
			data->x += 1;
			ft_catch_item(data);
			data->map[data->y][data->x] = 'P';
			data->steps++;
			ft_printf("%d\n", data->steps);
			close_exit(data);
		}
	}
}