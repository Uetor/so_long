/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 18:11:43 by pedrogon          #+#    #+#             */
/*   Updated: 2023/10/30 05:45:56 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_image(t_data *data)
{
	data->texture = mlx_load_png("./Texturas/char.png");
	//Con esto creamos una imagen que sólo tenemos en la memoria.
	data->face = mlx_texture_to_image(data->mlx, data->texture);
	//Es para cuando ya hemos creado la imagen,
	//liberamos la memoria de texture y así evitamos leaks de memoria
	mlx_delete_texture(data->texture);
	data->texture = mlx_load_png("./Texturas/exitclose.png");
	data->doorclose = mlx_texture_to_image(data->mlx, data->texture);
	mlx_delete_texture(data->texture);
	data->texture = mlx_load_png("./Texturas/exitopen.png");
	data->dooropen = mlx_texture_to_image(data->mlx, data->texture);
	mlx_delete_texture(data->texture);
	data->texture = mlx_load_png("./Texturas/floor.png");
	data->floor = mlx_texture_to_image(data->mlx, data->texture);
	mlx_delete_texture(data->texture);
	data->texture = mlx_load_png("./Texturas/item.png");
	data->item = mlx_texture_to_image(data->mlx, data->texture);
	mlx_delete_texture(data->texture);
	data->texture = mlx_load_png("./Texturas/wall.png");
	data->wall = mlx_texture_to_image(data->mlx, data->texture);
	mlx_delete_texture(data->texture);
}

void	ft_paint_map(t_data *data)
{
	int	i;
	int	j;
	int	tmp;

	tmp = data->tilesize;
	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width - 1)
		{
			if (data->map[i][j] == '1')
				mlx_image_to_window(data->mlx, data->wall, j * tmp, i * tmp);
			else
				mlx_image_to_window(data->mlx, data->floor, j * tmp, i * tmp);
			j++;
		}
		i++;
	}
}

void	ft_paint_object(t_data *data)
{
	int	i;
	int	j;
	int	tmp;

	tmp = data->tilesize;
	i = 0;
	mlx_image_to_window(data->mlx, data->doorclose, data->r * tmp, data->d * tmp);
	mlx_image_to_window(data->mlx, data->dooropen, data->r * tmp, data->d * tmp);
	data->dooropen->instances[0].enabled = false;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width - 1)
		{
			if (data->map[i][j] == 'P')
				mlx_image_to_window(data->mlx, data->face, j * tmp, i * tmp);
			else if (data->map[i][j] == 'C')
				mlx_image_to_window(data->mlx, data->item, j * tmp, i * tmp);
			j++; 
		}
		i++;
	}
}

void ft_catch_item(t_data *data)
{
	int	i;
	
	i = 0;
	if (data->map[data->y][data->x] == 'C')
	{
		while ( i < data->image)
		{ //tenemos un array con las imagenes de item.  Esto lo hacemos para comprobar que cuando el jugador este en la misma casilla que el item.
			if (data->x * 64 == data->item->instances[i].x 
				&& data->y * 64 == data->item->instances[i].y)
			{//con la característica enabled como esta puesta la imagen item desaparezca.
				data->item->instances[i].enabled = false;
				data->coin--;
			}
			if (data->coin == 0)
			{
				data->doorclose->instances[0].enabled = false;
				data->dooropen->instances[0].enabled = true;
			}
			i++;

		}
	}
} 

void	close_exit(t_data *data)
{
	if (data->y == data->d && data->x == data->r && data->coin == 0)
		mlx_terminate(data->mlx);
}
