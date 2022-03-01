#include "../Includes/fdf.h"

int     *ft_read_file(char *argv, int   fd, char    *line)
{
    int     fd;
    int     i;
    int     *matrix;
    char    *line;
    char    **string;

    i = 0;
    matrix = (int *)malloc(sizeof(int *));
    fd = open(argv[1], O_RDONLY);
    get_next_line(fd, &line);
    string = ft_split(str, ' ');
    while (string[i] != '\0')
    {
        matrix[i] = ft_atoi(string[i]);
        printf("%d ", matrix[i]);
        i++;
    }
    close(fd);
    return (matrix);
}

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        ft_read_file(&argv[1]);
    }
}