#ifndef FDF_H
#define FDF_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "../Libft/libft.h"
#include "../mlx/mlx.h"
// #include "../GNL/get_next_line.h"
#define BUFFER_SIZE 100

typedef struct  s_helps
{
    int     width;
    int     height;
    int     **matrix;

    void    *mlx_ptr;
    void    *win_ptr;
}   helps;

int         ft_deal_key(int key, void   *data);
int         ft_get_height(char  *file_name);
int         ft_get_width(char   *file_name);
void        ft_fill_matrix(int  *line_z, char *line);
void        ft_read_file(char   *file_name, helps *data);
char		*ft_strnew(size_t size);
int			ft_str_endline(char *str);
char		*ft_remline(char *rem_line);
char		*ft_clearrem(char *rem_line);
int			get_next_line(int fd, char **line);
int	ft_strlen_gnl(char *str);
char	*ft_strjoin_gnl(char *rem_line, char *buffer);
int	ft_str_endline_gnl(char *str);
char	*ft_remline_gnl(char *rem_line);
char	*ft_clearrem_gnl(char *rem_line);

#endif //fdf_h