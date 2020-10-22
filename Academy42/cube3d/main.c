#include "mlx.h"
#include "cube3d.h"

int     down(int keycode, t_cam *param)
{
    if (keycode == 126)
        param->up = 1;
    printf("Down: %d\n", keycode);
}

int     release(int keycode, t_cam *param)
{
    if (keycode == 126)
        param->up = 0;
    printf("Release: %d\n", keycode);
}

void    ft_initiate(t_cam *param)
{
    param->izq = 0;
    param->drch = 0;
    param->up = 0;
    param->down = 0;
    param->j = 0;
    param->i = 0;
}

int test2(t_cam *param)
{
    if (param->up == 1)
    {
        param->j = 0;
        while (param->j <= 799)
        {
            param->i = 0;
            while (param->i <= 799)
                param->addr[param->j * 800 + param->i++] = 0xFF0000; // (x, y) ---> y * ancho + x
            param->j++;
        }
        mlx_put_image_to_window(param->mlx_ptr, param->win_ptr, param->img, 0, 0);
    }
    else
    {
        param->j = 0;
        while (param->j <= 799)
        {
            param->i = 0;
            while (param->i <= 799)
                param->addr[param->j * 800 + param->i++] = 0xFFFFFF; // (x, y) ---> y * ancho + x
            param->j++;
        }
        mlx_put_image_to_window(param->mlx_ptr, param->win_ptr, param->img, 0, 0);
    }
}

int main()
{
    t_cam param;

    ft_initiate(&param);
    param.mlx_ptr = mlx_init();
    param.win_ptr = mlx_new_window(param.mlx_ptr, 800, 800, "mlx 42");

    param.img = mlx_new_image(param.mlx_ptr, 800, 800);

    param.addr = (int *)mlx_get_data_addr(param.img, &param.bits_per_pixel, &param.line_length,&param.endian);

 /*   while (param.i < 800)
        param.addr[400 * 800 + param.i++] = 0xFF0000; // (x, y) ---> y * ancho + x*/

    mlx_hook(param.win_ptr, 2, 0, down, &param);
    mlx_hook(param.win_ptr, 3, 0, release, &param);
    mlx_loop_hook(param.mlx_ptr, test2, &param);
    mlx_loop(param.mlx_ptr);
}