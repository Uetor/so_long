#include "so_long.h"

int main(int argc, char **argv)
{
    t_data data;

    if (argc == 2)
    {
        data.tilesize = 64; //Tamaño de las imagenes
        data.dir = ft_strdup("./maps/");
        data.file = ft_strjoin(data.dir, argv[1]);
        ft_rectangle(&data);
        ft_reserve_memory(&data);
        ft_check_line(&data);
        ft_check_player(&data);
        ft_check_elements(&data);
        ft_check_exit(&data);
        free(data.map);
        ft_reserve_memory(&data);
        //Esto es para iniciar la ventna con el ancho y el alto.
        data.mlx = mlx_init((data.width - 1) * data.tilesize, data.height * data.tilesize, "so_long", true);
        ft_image(&data);
        ft_scan_map(&data);
        ft_scan_object(&data);
        mlx_key_hook(data.mlx, &ft_hook, &data);
        mlx_loop(data.mlx);
        mlx_terminate(data.mlx);
    }
    return (0);
}