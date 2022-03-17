#include "../Includes/fdf.h"

int     ft_maximum(int  a, int b)
{
    if (b > a)
        return (b);
    return (a);
}

void	my_mlx_pixel_put(t_data data, int x, int y, int color)
{
	char	*dst;
	dst = data.addr + (y * data.line_length + x * (data.bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void    ft_draw_line(t_helps *helps, t_coord coord)
{
    int     dx;
    int     dy;
    int     max;
   
    dx = coord.x2 - coord.x1;
    dy = coord.y2 - coord.y1;
    max = ft_maximum(dx, dy);
    dx /= max;
    dy /= max;
    while ((int)(coord.x2 - coord.x1) || (int)(coord.y2 - coord.y1))
    {
        my_mlx_pixel_put(helps->img, coord.x1, coord.y1, 0xffbbcc);
        coord.x1 += dx;
        coord.y1 += dy;
    }
}