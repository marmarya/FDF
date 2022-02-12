#ifndef FDF_H
#define FDF_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "Libft/libft.h"
#include "mlx/mlx.h"

typedef struct  s_helps
{
    int     width;
    int     height;
    int     **matrix;

    void    *mlx_ptr;
    void    *win_ptr;
}   helps;

int     ft_deal_key(int key, void   *data);
int     ft_get_height(char  *file_name);
int     ft_get_width(char   *file_name);
void    ft_fill_matrix(int  *line_z, char *line);
void    ft_read_file(char   *file_name, helps *data);

#endif //fdf_h