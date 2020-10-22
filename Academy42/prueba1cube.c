#include "mlx.h"

typedef struct  s_ram{
    int         izq;
    int         drch;
    int         up;
    int         down;
    void        *mlx_ptr;
    void        *win_ptr;
    int         i;
    int         j;

}               t_ram;

int     down(int keycode, t_ram *param)
{
    if (keycode == 126)
        param->up = 1;
    printf("Down: %d\n", keycode);
}

int     release(int keycode, t_ram *param)
{
    if (keycode == 126)
        param->up = 0;
    printf("Release: %d\n", keycode);
}

void    ft_init(t_ram *param)
{
    param->izq = 0;
    param->drch = 0;
    param->up = 0;
    param->down = 0;
    param->j = param->i = 0;
}

int test2(t_ram *param)
{
    if (param->up == 1)
    {
        param->j = 0;
        while (param->j <= 799)
        {
            param->i = 0;
            while (param->i <= 799)
                mlx_pixel_put(param->mlx_ptr, param->win_ptr, param->i++, param->j, 0xFFFFFF);
            mlx_pixel_put(param->mlx_ptr, param->win_ptr, 0, param->j++, 0xFFFFFF);
        }
            
    }
    else
    {
        param->j = 0;
        while (param->j <= 799)
        {
            param->i = 0;
            while (param->i <= 799)
                mlx_pixel_put(param->mlx_ptr, param->win_ptr, param->i++, param->j, 0xFF0000);
            mlx_pixel_put(param->mlx_ptr, param->win_ptr, 0, param->j++, 0xFF0000);
        }
    }
}

int main()
{
    t_ram param;

    ft_init(&param);
    param.mlx_ptr = mlx_init();
    param.win_ptr = mlx_new_window(param.mlx_ptr, 800, 800, "mlx 42");
    
    mlx_hook(param.win_ptr, 2, 0, down, &param);
    mlx_hook(param.win_ptr, 3, 0, release, &param);
    mlx_loop_hook(param.mlx_ptr, test2, &param);
    mlx_loop(param.mlx_ptr);
}