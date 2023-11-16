/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrogon <pedrogon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:41:01 by pedrogon          #+#    #+#             */
/*   Updated: 2023/11/16 20:10:23 by pedrogon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_leaks(void)
{
	system("leaks -q 'so_long'");
}

void	ft_free_split(char **str, int len)
{
	int		i;

	i = len;
	while (i >= 0)
	{
		free(str[i]);
		i--;
	}
	free(str);
}

//Comprueba que haya una salida
int	ft_check_door(t_data *data)
{
	int	i;
	int	j;
	int	door;

	i = 0;
	door = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			if (data->map[i][j] == 'E')
			{
				data->door_y = i;
				data->door_x = j;
				door++;
			}
			j++;
		}
		i++;
	}
	if (door != 1)
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	atexit(ft_leaks);
	t_data	data;

	data.tilesize = 64; //Tamaño de las imagenes
	data.steps = 0; // Pasos del personaje
	if (argc == 2)
	{
		data.dir = ft_strdup("./maps/");
		data.file = ft_strjoin(data.dir, argv[1]);
		if (ft_tester(&data) == 1)
		{
			ft_free_split(data.map, data.height -1);
			ft_reserve_memory(&data);
			//Esto es para iniciar la ventana con el ancho y el alto.
			data.mlx = mlx_init((data.width - 1) * data.tilesize, data.height * data.tilesize, "so_long", true);
			ft_image(&data);
			ft_paint_map(&data);
			ft_paint_object(&data);
			mlx_key_hook(data.mlx, &ft_hook, &data);
			mlx_loop(data.mlx);
			mlx_terminate(data.mlx);
		}
		ft_free_split(data.map, data.height -1);
		free(data.dir);
		free(data.file);
	}
	return (0);
}
