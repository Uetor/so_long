/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 19:42:39 by pedrogon          #+#    #+#             */
/*   Updated: 2023/10/29 05:03:33 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
//Esta función comprueba que el fichero que nos dan tiene forma de rectangulo.
int	ft_rectangle(t_data *data)
{
	int	tmp;

	data->fd = open(data->file, O_RDONLY);
	if (data->fd == -1)
		return (0);
	data->line = get_next_line(data->fd);
	data->width = ft_strlen(data->line);
	data->height = 0;
	while (data->line)
	{
		data->line = get_next_line(data->fd);
		tmp = 0;
		if (data->line != 0)
		{
			while (data->line[tmp])
				tmp++;
			if (data->width != tmp)
				return (0);
		}
		data->height++;
	}
	close(data->fd);
	return (1);
}

//Reserva la memoria necesaria de todo el mapa;
void	ft_reserve_memory(t_data *data)
{
	int		i;
	char	*aux;

	data->map = malloc(sizeof(char *) * data->height);
	i = 0;
	while (data->map[i])
	{  //El -1 es para que nos nos cuente el salto de línea.  Está quitado para dejar un espacio más para el carácter nulo
		data->map[i] = malloc(sizeof(char) * data->width);
		i++;
	}
	data->fd = open(data->file, O_RDONLY);
	aux = get_next_line(data->fd);
	i = 0;
	while (aux)
	{
		data->map[i] = aux;
		aux = get_next_line(data->fd);
		i++;
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
	while (data->map[i][0] == '1' && data->map[i][data->width - 2] == '1' &&
			i < data->height - 1)
		i++;
	if (i != data->height - 1)
		return (0);
	return (1);
}
//Comprueba que sólo exita un player en el juego.
int	ft_check_player(t_data *data)
{
	int	i;
	int	j;
	int	p;

	i = 0;
	p = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			if (data->map[i][j] == 'P')
			{
				p++;
				if (p > 1)
					write(2, "More 1 player", 14);
				data->y = i;
				data->x = j;
			}
			j++;
		}
		i++;
	}
	if (p == 0)
		return (0);
	return (1);
}
//Comprueba que haya al menos una salida y un item.
int	ft_check_elements(t_data *data)
{
	int	i;
	int	j;
	int	door;

	i = 0;
	data->image = 0;
	door = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			if (data->map[i][j] == 'C')
			{
				data->image++;
				data->tmp++;
			}
			if (data->map[i][j] == 'E')
			{
				data->d = i;
				data->r = j;
				door++;
			}
			j++;
		}
		i++;
	}
	if (door < 1 || data->image < 1)
		return (0);
	return (1);
}
