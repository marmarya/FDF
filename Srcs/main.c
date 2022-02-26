#include "../Includes/fdf.h"

int main(int argc, char **argv)
{
    int     fd;
    int     **matrix;
    char    **str;
    int     count;

    matrix = (int **)malloc(sizeof(int **));
    if (!matrix)
        return (0);
    if (argc == 2)
    {
        fd = open(argv[1], O_RDONLY);
        printf("fd---%d\n", fd);
        count = get_next_line(fd, str);
        printf("count---%d\n", count);
    }
}