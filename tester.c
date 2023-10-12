#include "so_long.h"
//Esta función comprueba que el fichero que nos dan tiene forma de rectangulo.
int   ft_rectangle(t_data *data)
{
    int tmp;

    data->fd = open(data->file, O_RDONLY);
    if (data->fd == -1)
        return (0);
    data->line = get_next_line(data->fd);
    data->width = ft_strlen(data->line);
    data->high = 0;
    while (data->line)
    {
        data->line = get_next_line(data->fd);
        tmp = 0;
        if (data->line != 0)
        {    
            while(data->line[tmp])
                tmp++;           
            if (data->width != tmp)
                return (0);
        }
        data->high++;
    }
    close(data->fd);
    return (1);
}

//Reserva la memoria necesaria de todo el mapa;
void    ft_reserve_memory(t_data *data)
{
    int i;
    char *aux;

    data->map = malloc(sizeof(char *) * data->high);
    i = 0;
    while(data->map[i])
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
int ft_check_line(t_data *data)
{
    int i;
    int j;

    i = 0;
    while (data->map)
    {
        if (data->map[0])
        {
            j = 0;
            while (data->map[0][j])
            {
                if (data->map[0][j] != 1)
                    return (0);
                printf("%d", data->map[0][j]);
                j++;
            }
        }
        i++;
    }
    return (1);
}
