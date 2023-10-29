#include "so_long.h"

void ft_flood_map(char **map, int height, int width, int y, int x)
{

    if (map[y][x] == '0' || map[y][x] == 'C' || map[y][x] == 'P' || map[y][x] == 'E')
        map[y][x] = '2';
    if ((map[y -1][x] == '0' || map[y -1][x] == 'C' || map[y - 1][x] == 'E') && y -1 >= 0)
        ft_flood_map(map, height, width, y -1, x);
    if ((map[y +1][x] == '0' || map[y +1][x] == 'C' || map[y + 1][x] == 'E') && y + 1 < height)
        ft_flood_map(map, height, width, y + 1, x);
    if ((map[y][x - 1] == '0'|| map[y][x - 1] == 'C' || map[y][x -1] == 'E') && x - 1 >= 0)
        ft_flood_map(map, height, width, y, x - 1);
    if ((map[y][x + 1] == '0' || map[y][x + 1] == 'C' || map[y][x + 1] == 'E') && x + 1 < width)
        ft_flood_map(map, height, width, y , x + 1);
}

int ft_check_exit(t_data *data)
{
    ft_flood_map(data->map, data->height, data->width, data->y, data->x);
    if (data->map[data->d][data->r] == '2')
        return (1);
    return (0);
}

int ft_check_ber(t_data *data)
{
    size_t j;
    
    j = ft_strlen(data->file);
    if (j >= 4)
    {
        if (data->file[j - 1] != 'r')
            return(0);
        if (data->file[j - 2] != 'e')
            return(0);
        if (data->file[j - 3] != 'b')
            return(0);
        if (data->file[j - 4] != '.')
            return(0);
        return(1);
    }
    return (0);
}
