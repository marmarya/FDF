#include "../Includes/fdf.h"

int     *ft_read_file(char *argv, t_helps *helps)
{
    int     fd;
    int     i;
    int     **matrix;
    char    *line;
    char    **string;

    i = 0;
    int j;
    j = 0;
    matrix = (int **)malloc(sizeof(int **));
    fd = open(argv, O_RDONLY);
    while ((get_next_line(fd, &line)))
    {
        string = ft_split(line, ' ');
        while (string[i] != '\0')
        {
            matrix[j][i] = ft_atoi(string[i]);
            i++;
        }
        j++;
        free(line);
    }
    helps->height = j;
    printf("height---%d\n", j);
    close(fd);
    return (*matrix);
}

int     ft_check_map(char *argv)
{
    int     i;
    int     cmp;
    int     fd;
    int     ret;
    char    *line;

    i = 0;
    ret = 1;
    cmp = 0;
    fd = open(argv, O_RDONLY);
    while (get_next_line(fd, &line))
    {
        while (line[i] != '\0')
            i++;
        if (line[i] == '\n')
            cmp = i;
        if (cmp != i)
            ret = 0;
        i = 0;
        free(line);
    }
    return (ret);
}

int main(int argc, char **argv)
{
    t_helps *helps;
    int     length;

    helps = (t_helps *)malloc(sizeof(t_helps));
    helps->mlx_ptr = mlx_init();
    helps->win_ptr = mlx_new_window(helps->mlx_ptr, WIN_WIDTH, WIN_LENGHT, "FDF");
    helps->img.image = mlx_new_image(helps->mlx_ptr, WIN_WIDTH, WIN_LENGHT);
    helps->img.addr = mlx_get_data_addr(helps->img.image, &helps->img.bits_per_pixel, &helps->img.line_length, &helps->img.endian);
    if (argc == 2)
    {
        ft_read_file(argv[1], helps);
        length = ft_find_length(argv[1]);      
        printf("leght---%d\n", length); 
    }
        helps->matrix = ft_read_file(argv[1]);
    int i = 0;
    while(helps->matrix[i])
    {
        printf("%d\n", helps->matrix[i]);
        i++;
    }
    ft_connecting(helps->matrix);
    ft_draw_line(helps, 15, 15, 500, 500);
    mlx_put_image_to_window(helps->mlx_ptr, helps->win_ptr, helps->img.image, 0, 0);
    mlx_loop(helps->mlx_ptr);
}