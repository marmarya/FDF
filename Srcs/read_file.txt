#include "fdf.h"

int     ft_get_height(char  *file_name)
{
    char    *line;
    int     fd;
    int     height;

    fd = open(file_name, O_RDONLY, 0);
    height = 0;
    while (get_next_line(fd, &line))
    {
        height++;
        free(line);
    }
    close(fd);
    return (height);
}

int     ft_get_width(char   *file_name)
{
    int     width;
    int     fd;
    char    *line;

    fd = open(file_name, O_RDONLY, 0);
    get_next_line(fd, &line);
    width = ft_wdcounter(line, ' ');
    free(line);
    close(fd);
    return (width);
}

void    ft_fill_matrix(int  *line_z, char *line)
{
    char    **numbers;
    int     i;

    numbers = ft_split(line, ' ');
    i = 0;
    while (numbers[i])
    {
        line_z[i] = ft_atoi(numbers[i]);
        free(numbers[i]);
        i++;
    }
    free(numbers);
}

void    ft_read_file(char   *file_name, helps *data)
{
    int     fd;
    char    *line;
    int     i;

    data->height = ft_get_height(file_name);
    data->width = ft_get_width(file_name);

    data->matrix = (int **)malloc(sizeof(int *) * (data->height + 1));
    //check
    i = 0;
    while (i <= data->height)
        data->matrix[i++] = (int *)malloc(sizeof(int) * (data->width + 1));
    fd = open(file_name, O_RDONLY, 0);
    i = 0;
    while (get_next_line(fd, &line))
    {
        ft_fill_matrix(data, line);
        free(line);
        i++;
    }
    close(fd);
    data->matrix[i] = NULL;
}