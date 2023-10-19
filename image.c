#include "so_long.h"

void ft_image(t_data *data)
{
        //Esto es para iniciar la ventana con el ancho y el alto.
        //data->mlx = mlx_init(data->width * data->tilesize, data->high * data->tilesize, "so_long", true);
        data->texture = mlx_load_png("./Texturas/enemy.png");
        //Con esto creamos una imagen que sólo tenemos en la memoria.
        data->enemy = mlx_texture_to_image(data->mlx, data->texture);
        //Es para cuando ya hemos creado la imagen, liberamos la memoria de texture y así evitamos leaks de memoria
        mlx_delete_texture(data->texture);
        data->texture = mlx_load_png("./Texturas/box.png");
        data->box = mlx_texture_to_image(data->mlx, data->texture);
        mlx_delete_texture(data->texture);
        data->texture = mlx_load_png("./Texturas/char.png");
        data->face = mlx_texture_to_image(data->mlx, data->texture);
        mlx_delete_texture(data->texture);
        data->texture = mlx_load_png("./Texturas/char2.png");
        data->face2 = mlx_texture_to_image(data->mlx, data->texture);
        mlx_delete_texture(data->texture);
        data->texture = mlx_load_png("./Texturas/enemy2.png");
        data->enemy2 = mlx_texture_to_image(data->mlx, data->texture);
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

void    ft_scan_map(t_data *data)
{
        int     i;
        int     j;

        i = 0;
        while (i < data->high)
        {
                j = 0;
                while (j < data->width - 1)
                {
                        //printf("%d", data->map[i][j]);
                        if (data->map[i][j] == '1')       
                                mlx_image_to_window(data->mlx, data->wall, j * data->tilesize, i * data->tilesize);
                        else if (data->map[i][j] == '0')
                                mlx_image_to_window(data->mlx, data->floor, j * data->tilesize, i * data->tilesize);
                        else if (data->map[i][j] == 'P')
                                mlx_image_to_window(data->mlx, data->face, j * data->tilesize, i * data->tilesize);
                        else if (data->map[i][j] == 'C')
                                mlx_image_to_window(data->mlx, data->item, j * data->tilesize, i * data->tilesize);
                        else if (data->map[i][j] == 'E')
                                mlx_image_to_window(data->mlx, data->doorclose, j * data->tilesize, i * data->tilesize);        
                        j++;
                }
                //printf("\n");
                i++;
        }
}