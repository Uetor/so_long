/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrogon <pedrogon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 19:42:39 by pedrogon          #+#    #+#             */
/*   Updated: 2023/11/16 20:09:10 by pedrogon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
//Esta función comprueba que el fichero que nos dan tiene forma de rectangulo.
int	ft_rectangle(t_data *data)
{
	data->fd = open(data->file, O_RDONLY);
	if (data->fd == -1)
		return (0);
	data->line = get_next_line(data->fd);
	data->width = ft_strlen(data->line);
	data->height = 0;
	while (data->line)
	{
		free(data->line);
		data->line = get_next_line(data->fd);
		data->tmp = 0;
		if (data->line != 0)
		{
			while (data->line[data->tmp])
				data->tmp++;
			if (data->width != data->tmp)
				return (0);
		}
		data->height++;
	}
	close(data->fd);
	ft_reserve_memory(data);
	puts("Check rectangulo");
	return (1);
}

//Reserva la memoria necesaria de todo el mapa;
void	ft_reserve_memory(t_data *data)
{
	int		i;
	char	*aux;

	aux = NULL;
	data->map = malloc(sizeof(char *) * data->height);
	i = 0;
	data->fd = open(data->file, O_RDONLY);
	data->map[0] = get_next_line(data->fd);
	i = 0;
	while (data->map[i])
	{
		i++;
		data->map[i] = get_next_line(data->fd);
	}
	close(data->fd);
}

//Comprueba que los números que hay en cada línea son los correctos.
int	ft_check_line(t_data *data)
{
	int	i;
	int	j;

	j = 0;
	while (data->map[0][j] == '1')
		j++;
	if (j != data->width - 1)
		return (0);
	j = 0;
	while (data->map[data->height - 1][j] == '1')
		j++;
	if (j != data->width - 1)
		return (0);
	i = 0;
	while (data->map[i][0] == '1' && data->map[i][data->width - 2] == '1' 
		&& i < data->height - 1)
		i++;
	if (i != data->height - 1)
		return (0);
	puts("Check line");
	return (1);
}
//Comprueba que sólo exita un player en el juego.
int	ft_check_player(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	data->tmp = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			if (data->map[i][j] == 'P')
			{
				data->tmp++;
				data->player_y = i;
				data->player_x = j;
			}
			j++;
		}
		i++;
	}
	if (data->tmp == 0 || data->tmp > 1)
		return (0);
	puts("Check player");
	return (1);
}
//Comprueba que haya al menos un item.
int	ft_check_coin(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	data->image = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			if (data->map[i][j] == 'C')
			{
				data->image++;
				data->coin++;
			}
			j++;
		}
		i++;
	}
	if (data->image < 1)
		return (0);
	return (1);
}
