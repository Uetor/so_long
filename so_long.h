/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 19:58:04 by pedrogon          #+#    #+#             */
/*   Updated: 2023/10/29 05:02:34 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG
# define SO_LONG
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
    char    *file;
    char    *line;
    int     fd;

    //Longitud de cadena
    int     height;   //alto
    int     width;  //ancho
    int     tilesize;

    //Memoria de filas y columnas.
    char    **map;

    //Ventana gráfica
    mlx_t *mlx;

    //Imagenes
    mlx_texture_t *texture;
    mlx_image_t *enemy;
    mlx_image_t *enemy2;
    mlx_image_t *box;
    mlx_image_t *face;
    mlx_image_t *face2;
    mlx_image_t *doorclose;
    mlx_image_t *dooropen;
    mlx_image_t *floor;
    mlx_image_t *item;
    mlx_image_t *wall;

    //Posición del jugador
    int y;
    int x;

    //Posición de la puerta
    int d;
    int r;

    // Cantidad de imágenes
    int image;
    int tmp;
}t_data;

int     ft_rectangle(t_data *data);
void    ft_reserve_memory(t_data *data);
int     ft_check_line(t_data *data);
void    ft_image(t_data *data);
void    ft_scan_map(t_data *data);
void	ft_scan_object(t_data *data);
int     ft_check_player(t_data *data);
int		ft_check_elements(t_data *data);
void    ft_hook(mlx_key_data_t keydata, void* param);
void    ft_flood_map(char **map, int height, int width, int y, int x);
int     ft_check_exit(t_data *data);
void    ft_catch_item(t_data *data);
int     ft_check_ber(t_data *data);

#endif
