/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlozano <rlozano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 10:31:59 by rlozano           #+#    #+#             */
/*   Updated: 2020/11/05 11:30:40 by rlozano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"
#include <math.h>

void init_raycasting(t_map *param)
{
  t_cam mlx;
  t_ray f;
  ft_bzero(&mlx, sizeof(t_cam));
  ft_bzero(&f, sizeof(t_ray));
  
//  f.posX = 22;
//  f.posY= 12;  //x and y start position
//  f.w = 640;
//  f.h = 480;
// f.dirX= -1;
//  f.dirY = 0; //initial direction vector
//  f.planeX = 0;
//  f.laneY = 0.66; //the 2d raycaster version of camera plane
  f.time = 0; //time of current frame
  f.oldTime = 0; //time of previous frame 
  f.side = 0;
  
  mlx.mlx_ptr = mlx_init();
  mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, param->resolution_x, param->resolution_y, "mlx 42");
  mlx.img = mlx_new_image(mlx.mlx_ptr, param->resolution_x, param->resolution_y);
  mlx.addr = (int *)mlx_get_data_addr(mlx.img, &mlx.bits_per_pixel, &mlx.line_length,&mlx.endian);


  while(1)
  {
    int x = 0;
    while(x < param->resolution_x)
    {
      int j = 0;
      
      //calculate ray position and direction
      f.cameraX = 2 * x / (double)param->resolution_x - 1; //x-coordinate in camera space
      f.rayDirX = param->dirX + param->planeX * f.cameraX;
      f.rayDirY = param->dirY + param->planeY * f.cameraX;
      
      //which box of the map we're in
      f.mapX = (int)param->position_x;
      f.mapY = (int)param->position_y;

       //length of ray from one x or y-side to next x or y-side
      f.deltaDistX = fabs(1 / f.rayDirX);
      f.deltaDistY = fabs(1 / f.rayDirY);

      int hit = 0; //was there a wall hit?
      
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
      
      //perform DDA
      while (hit == 0)
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
        if (param->finalmap[f.mapX][f.mapY] > 0)
            hit = 1;
      }
        //Calculate distance projected on camera direction (Euclidean distance will give fisheye effect!)
      if (f.side == 0)
        f.perpWallDist = (f.mapX - param->position_x + (1 - f.stepX) / 2) / f.rayDirX;
      else
        f.perpWallDist = (f.mapY - param->position_y + (1 - f.stepY) / 2) / f.rayDirY;
      
      //Calculate height of line to draw on screen
      f.lineHeight = (int)param->resolution_y / f.perpWallDist;

      //calculate lowest and highest pixel to fill in current stripe
      f.drawStart = -f.lineHeight / 2 + param->resolution_y / 2;
      if(f.drawStart < 0)
        f.drawStart = 0;
      f.drawEnd = f.lineHeight / 2 + param->resolution_y / 2;
      if(f.drawEnd >= param->resolution_y)
        f.drawEnd = param->resolution_y - 1;
      //choose wall color

      if (param->finalmap[f.mapX][f.mapY] == 1)
        (f.color = 0xfffffff);
      //give x and y sides different brightness
      if (f.side == 1)
        f.color  = f.color / 2;
      
      //draw the pixels of the stripe as a vertical line
      while (j <= f.drawStart)
        mlx.addr[j++ * param->resolution_x + x]  =  0x000000;
      while (j < f.drawEnd)
        mlx.addr[j++ * param->resolution_x + x]  =  f.color;
      while (j < param->resolution_y)
        mlx.addr[j++ * param->resolution_x + x]  =  0x763c28;

      mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, mlx.img, 0, 0);
      x++;
    }
    mlx_loop(mlx.mlx_ptr);
  }
}