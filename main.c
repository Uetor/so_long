#include "so_long.h"

int main(int argc, char **argv)
{
    t_data data;

    data.tilesize = 64; //Tamaño de las imagenes
    data.steps = 0; // Pasos del personaje
    if (argc == 2)
    {
        data.dir = ft_strdup("./maps/");
        data.file = ft_strjoin(data.dir, argv[1]);
        free(data.map);
        if (ft_tester(&data) == 1)
        {
            ft_reserve_memory(&data);
            //Esto es para iniciar la ventna con el ancho y el alto.
            data.mlx = mlx_init((data.width - 1) * data.tilesize, 
                data.height * data.tilesize, "so_long", true);
            ft_image(&data);
            ft_paint_map(&data);
            ft_paint_object(&data);
            mlx_key_hook(data.mlx, &ft_hook, &data);
            mlx_loop(data.mlx);
            mlx_terminate(data.mlx);
        }    
    }
    return (0);
}