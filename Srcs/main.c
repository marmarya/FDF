#include "../Includes/fdf.h"

int main(int argc, char **argv)
{
    int     fd;
    int     **matrix;
    char    *str;
    int     count;

    count = 0;
    // str = (char **)malloc(sizeof(char **));
    matrix = (int **)malloc(sizeof(int **));
    if (!matrix)
        return (0);
    if (argc == 2)
    {
        fd = open(argv[1], O_RDONLY);
        printf("fd---%d\n", fd);
        printf("argv---%s\n", argv[1]);
        count = get_next_line(fd, &str);
        printf("count---%d\n", count);
        printf("str---%s\n", str);
        close(fd);
    }
}