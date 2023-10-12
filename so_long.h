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
    char    *dir;
    char    *file;
    char    *line;
    int     fd;

    //Longitud de cadena
    int     high;   //alto
    int     width;  //ancho

    //Medida de filas y columnas.
    char    **map;
}t_data;

int     ft_rectangle(t_data *data);
void    ft_reserve_memory(t_data *data);
int     ft_check_line(t_data *data);

#endif