#include "so_long.h"

int main(int argc, char **argv)
{
    t_data data;

    if (argc == 2)
    {
        data.dir = ft_strdup("./maps/");
        data.file = ft_strjoin(data.dir, argv[1]);
        ft_rectangle(&data);
        ft_reserve_memory(&data);
        ft_check_line(&data);
    }
    return (0);
}