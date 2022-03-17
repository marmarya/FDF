#ifndef FDF_H
#define FDF_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <math.h>
#include "../Libft/libft.h"
#include <mlx.h>

// #include "../GNL/get_next_line.h"
#define BUFFER_SIZE 100
#define WIN_LENGHT 1920
#define WIN_WIDTH 1080

typedef struct	s_data {
	void	*image;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct  s_helps
{
    t_data  img;  
    int     width;
    int     height;
    int     *matrix;

    void    *mlx_ptr;
    void    *win_ptr;
}   t_helps;

typedef struct s_coord
{
    int x1;
    int y1;
    int x2;
    int y2;
    int value;
}   t_coord;


int         ft_deal_key(int key, void   *data);
int         ft_get_height(char  *file_name);
int         ft_get_width(char   *file_name);
void        ft_fill_matrix(int  *line_z, char *line);
char		*ft_strnew(size_t size);
int			ft_str_endline(char *str);
char		*ft_remline(char *rem_line);
char		*ft_clearrem(char *rem_line);
int			get_next_line(int fd, char **line);
int	        ft_strlen_gnl(char *str);
char	    *ft_strjoin_gnl(char *rem_line, char *buffer);
int	        ft_str_endline_gnl(char *str);
char	    *ft_remline_gnl(char *rem_line);
char	    *ft_clearrem_gnl(char *rem_line);
int         *ft_read_file(char *argv, t_helps *helps);
void        ft_draw_line(t_helps *helps, t_coord coord);
void    	my_mlx_pixel_put(t_data data, int x, int y, int color);
int         ft_maximum(int  a, int b);
void        ft_connecting(int   *matirx);


#endif //fdf_h