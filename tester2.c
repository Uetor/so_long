/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrogon <pedrogon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:51:54 by pedrogon          #+#    #+#             */
/*   Updated: 2023/11/16 20:12:44 by pedrogon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
// Convierte los símbolos que se le especifica en 2 si puede.
void	ft_flood_map(int y, int x, t_data *data)
{
	if (data->map[y][x] == '0' || data->map[y][x] == 'C'
		|| data->map[y][x] == 'P' || data->map[y][x] == 'E')
		data->map[y][x] = '2';
	if ((data->map[y - 1][x] == '0' || data->map[y -1][x] == 'C'
		|| data->map[y - 1][x] == 'E') && y -1 >= 0)
		ft_flood_map(y - 1, x, data);
	if ((data->map[y + 1][x] == '0' || data->map[y +1][x] == 'C'
		|| data->map[y + 1][x] == 'E') && y + 1 < data->height)
		ft_flood_map(y + 1, x, data);
	if ((data->map[y][x - 1] == '0' || data->map[y][x - 1] == 'C'
		|| data->map[y][x - 1] == 'E') && x - 1 >= 0)
		ft_flood_map(y, x - 1, data);
	if ((data->map[y][x + 1] == '0' || data->map[y][x + 1] == 'C'
	|| data->map[y][x + 1] == 'E') && x + 1 < data->width)
		ft_flood_map(y, x + 1, data);
}
//Comprueba que hay alguna manera de llegar con el personaje hasta la salida.
int ft_check_exit(t_data *data)
{
	ft_flood_map(data->player_y, data->player_x, data);
	if (data->map[data->door_y][data->door_x] != '2')
	{
		write(2, "closed exit\n", 12);
		return (0);
	}
	return (1);
}
//Comprueba que el archivo que le pasamos sea un .ber
int ft_check_ber(t_data *data)
{
	size_t	j;

	j = ft_strlen(data->file);
	if (j >= 4)
	{
		if (data->file[j - 1] != 'r')
			return (0);
		if (data->file[j - 2] != 'e')
			return (0);
		if (data->file[j - 3] != 'b')
			return (0);
		if (data->file[j - 4] != '.')
			return (0);
		return (1);
	}
	return (0);
}

int	ft_tester(t_data *data)
{
	if (ft_check_ber(data) == 0)
		return (write(2, "Incorrect file\n", 16), 0);
	else if (ft_rectangle(data) == 0)
		return (write(2, "Incorrect map\n", 15), 0);
	else if (ft_check_line(data) == 0)
		return (write(2, "Incorrect numbers\n", 19), 0);
	else if (ft_check_player(data) == 0)
		return (write(2, "Error Player\n", 14), 0);
	else if (ft_check_coin(data) == 0)
		return (write(2, "Fault item\n", 12), 0);
	else if (ft_check_door(data) == 0)
		return (write(1, "Fault door", 11), 0);
	else if (ft_check_exit(data) == 0)
		return (0);
	return (1);
}
