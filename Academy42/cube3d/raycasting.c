/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlozano <rlozano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 10:31:59 by rlozano           #+#    #+#             */
/*   Updated: 2020/11/06 13:37:31 by rlozano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"
#include <math.h>

int ft_key_press(int keycode, t_ray *f)
{
	if (keycode == K_W)
		f->up = 1;
	if (keycode == K_S)
		f->down = 1;
	if (keycode == K_AR_R)
		f->rot_right = 1;
	if (keycode == K_AR_L)
		f->rot_left = 1;
	if (keycode == K_A)
		f->left = 1;
	if (keycode == K_D)
		f->right = 1;
	if (keycode == K_ESC)
		f->esc = 1;
	return (0);
}

int ft_key_release(int keycode, t_ray *f)
{
	if (keycode == K_W)
		f->up = 0;
	if (keycode == K_S)
		f->down = 0;
	if (keycode == K_AR_R)
		f->rot_right = 0;
	if (keycode == K_AR_L)
		f->rot_left = 0;
	if (f->keycode == K_A)
		f->left = 0;
	if (keycode == K_D)
		f->right = 0;
	if (keycode == K_ESC)
		f->esc = 0;
	return (0);
}

int  ft_exit_game(t_cam *mlx)
{
  mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	exit(EXIT_SUCCESS);
  return(0);
}


void	ft_orientation(t_map *param)
{
	if (param->whois == 'N')
	{
		param->dirX = -1;
		param->dirY = 0;
		param->planeX = 0;
		param->planeY = 0.66;
	}
	if (param->whois == 'S')
	{
		param->dirX = 1;
		param->dirY = 0;
		param->planeX = 0;
		param->planeY = -0.66;
	}
	if (param->whois == 'W')
	{
		param->dirX = 0;
		param->dirY = -1;
		param->planeX = -0.66;
		param->planeY = 0;
	}
	if (param->whois == 'E')
	{
		param->dirX = 0;
		param->dirY = 1;
		param->planeX = 0.66; 
		param->planeY =  0;
	}
	
}
void      ft_initstruct(t_map *param)
{
  param->dirX = 0;
  param->dirY = 0;
  param->planeX = 0;
  param->planeY = 0;
}

void init_raycasting(t_map *param)
{
  t_cam mlx;
  t_ray f;
  ft_bzero(&mlx, sizeof(t_cam));
  ft_bzero(&f, sizeof(t_ray));

  
  mlx.mlx_ptr = mlx_init();
  mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, param->resolution_x, param->resolution_y, "Cub3d");
  mlx.img = mlx_new_image(mlx.mlx_ptr, param->resolution_x, param->resolution_y);
  mlx.addr = (int *)mlx_get_data_addr(mlx.img, &mlx.bits_per_pixel, &mlx.line_length,&mlx.endian);

  ft_orientation(param);
  while(1)
  {
    mlx_destroy_image(mlx.mlx_ptr, mlx.img);
    mlx.img = mlx_new_image(mlx.mlx_ptr, param->resolution_x, param->resolution_y);
    mlx.addr = (int *)mlx_get_data_addr(mlx.img, &mlx.bits_per_pixel, &mlx.line_length,&mlx.endian);
    int j;
    int x = 0;
    while(x < param->resolution_x)
    {
      ft_bzero(&f, sizeof(t_ray));
      
      j = 0;
      
      //calculate ray position and direction
      f.cameraX = 2 * x / (double)param->resolution_x - 1; //x-coordinate in camera space
      f.rayDirX = param->dirX + param->planeX * f.cameraX;
      f.rayDirY = param->dirY + param->planeY * f.cameraX;
      
      //which box of the map we're in
      f.mapX = param->position_x;
      f.mapY = param->position_y;

       //length of ray from one x or y-side to next x or y-side
      f.deltaDistX = fabs(1 / f.rayDirX);
      f.deltaDistY = fabs(1 / f.rayDirY);
      
      //calculate step and initial sideDist
      if (f.rayDirX < 0)
      {
        f.stepX = -1;
        f.sideDistX = (param->position_x- f.mapX) * f.deltaDistX;
      }
      else
      {
        f.stepX = 1;
        f.sideDistX = (f.mapX + 1.0 - param->position_x) * f.deltaDistX;
      }
      if (f.rayDirY < 0)
      {
        f.stepY = -1;
        f.sideDistY = (param->position_y - f.mapY) * f.deltaDistY;
      }
      else
      {
        f.stepY = 1;
        f.sideDistY = (f.mapY + 1.0 - param->position_y) * f.deltaDistY;
      }
      
      //perform DDA igual que el miguel hasta otro 10
      while (f.hit == 0)
      {
        //jump to next map square, OR in x-direction, OR in y-direction
        if (f.sideDistX < f.sideDistY)
        {
          f.sideDistX += f.deltaDistX;
          f.mapX += f.stepX;
          f.side = 0;
        }
        else
        {
          f.sideDistY += f.deltaDistY;
          f.mapY += f.stepY;
          f.side = 1;
        }
        //Check if ray has hit a wall
        if (param->finalmap[f.mapX][f.mapY] == '1')
            f.hit = 1;
      }
        //Calculate distance projected on camera direction (Euclidean distance will give fisheye effect!)
      if (f.side == 0)
        f.perpWallDist = (f.mapX - param->position_x + (1 - f.stepX) / 2) / f.rayDirX;
      else
        f.perpWallDist = (f.mapY - param->position_y + (1 - f.stepY) / 2) / f.rayDirY;
      
      //Calculate height of line to draw on screen
      f.lineHeight = (int)param->resolution_y / f.perpWallDist;
      // 10 igual

      //calculate lowest and highest pixel to fill in current stripe
      f.drawStart = -f.lineHeight / 2 + param->resolution_y / 2;
      if(f.drawStart < 0)
        f.drawStart = 0;
      f.drawEnd = f.lineHeight / 2 + param->resolution_y / 2;
      if(f.drawEnd >= param->resolution_y)
        f.drawEnd = param->resolution_y - 1;
      //choose wall color

      if (param->finalmap[f.mapX][f.mapY] == '1')
        (f.color = 0xfffffff);
      //give x and y sides different brightness
      if (f.side == 1)
        f.color  = f.color / 2;
      
      //draw the pixels of the stripe as a vertical line
      while (j < f.drawStart)
      {
        *(mlx.addr + j * param->resolution_x + x)  =  255;
        j++;
      }
      while (j < f.drawEnd)
      {
        *(mlx.addr + j * param->resolution_x + x)   =  3;
        j++;
      }
      while (j < param->resolution_y)
      {
        *(mlx.addr + j * param->resolution_x + x)   =  60000;
        j++;
      }
      
      x++;
    }
    mlx_hook(mlx.win_ptr, 2, 1, ft_key_press, &f);
	  mlx_hook(mlx.win_ptr, 3, 2, ft_key_release, &f);
	  mlx_hook(mlx.win_ptr, 17, 1L << 17, ft_exit_game, &mlx);
    mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, mlx.img, 0, 0);
    mlx_loop(mlx.mlx_ptr);
  }
}