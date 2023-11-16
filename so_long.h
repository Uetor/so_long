/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrogon <pedrogon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 19:58:04 by pedrogon          #+#    #+#             */
/*   Updated: 2023/11/16 20:09:52 by pedrogon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "./libft/libft.h"
# include "./MLX42/include/MLX42/MLX42.h"

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdbool.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>

typedef struct s_data
{
//Dirección del fichero
	char	*dir;
	char	*file;
	char	*line;
	int		fd;

//Longitud de cadena
	int		height;  //alto
	int		width;  //ancho
	int		tilesize;

//Memoria de filas y columnas.
	char	**map;

//Ventana gráfica
	mlx_t	*mlx;

//Imagenes
	mlx_texture_t	*texture;
	mlx_image_t	*enemy;
	mlx_image_t	*enemy2;
	mlx_image_t	*box;
	mlx_image_t	*face;
	mlx_image_t *face2;
    mlx_image_t *doorclose;
    mlx_image_t *dooropen;
    mlx_image_t *floor;
    mlx_image_t *item;
    mlx_image_t *wall;

//Posición del jugador
	int		player_y;
	int		player_x;

//Posición de la puerta
	int		door_y;
	int		door_x;

	// Cantidad de imágenes
	int		image;
	int		coin;

//Contador de pasos
	int		steps;

//Contadores
	int		tmp;
}t_data;
//Las comprobaciones de errores
int		ft_check_ber(t_data *data);
int		ft_rectangle(t_data *data);
int		ft_check_line(t_data *data);
int		ft_check_player(t_data *data);
int		ft_check_coin(t_data *data);
int		ft_check_door(t_data *data);
int		ft_check_exit(t_data *data);
int		ft_tester(t_data *data);
//Reserva la memoria
void	ft_reserve_memory(t_data *data);
//Crea y pinta los objetos y el mapa
void	ft_image(t_data *data);
void	ft_paint_map(t_data *data);
void	ft_paint_object(t_data *data);
//Funciones para los movimientos del personaje
void	ft_hook(mlx_key_data_t keydata, void *param);
void	ft_move_w(mlx_key_data_t keydata, t_data *data);
void	ft_move_s(mlx_key_data_t keydata, t_data *data);
void	ft_move_a(mlx_key_data_t keydata, t_data *data);
void	ft_move_d(mlx_key_data_t keydata, t_data *data);

void	ft_flood_map(int y, int x, t_data *data);
void	ft_catch_item(t_data *data);
void	close_exit(t_data *data);

//Liberar memoria
void	ft_free_split(char **str, int len);

#endif
