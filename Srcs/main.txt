#include "fdf.h"


int     ft_deal_key(int key, void   *data)
{
    printf("%d", key);
    return (0);
}

int     main(int    argc, char **argv)
{
    helps   *data;
    int     i;
    int     j;

    i = 0;
    data = (helps *)malloc(sizeof(helps *));
    if (!data)
        return (0);
    ft_read_file(argv[1], data);
    while (i < data->height)
    {
        j = 0;
        while (j < data->width)
        {
            printf("%d ", data->matrix[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
}