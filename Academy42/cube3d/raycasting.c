/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlozano <rlozano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 10:31:59 by rlozano           #+#    #+#             */
/*   Updated: 2020/11/03 13:16:47 by rlozano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"
#include <math.h>
#define mapWidth 24 
#define mapHeight 24 
#define screenWidth 640 
#define screenHeight 480 

int worldMap [mapWidth] [mapHeight] = 
{ 
  {1,1,1,1,1,1,1,1,1,1,1,1 , 1,1,1,1,1,1,1,1,1,1,1,1}, 
  {1,0,0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0,0,1}, 
  {1,0,0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0,0,1}, 
  {1,0,0,0,0,0,0,0,0,0,0,0 , 0,0,0,0,0,0,0,0,0,0,0,1}, 
  {1,0,0,0,0,0,2,2,2,2,2,0 , 0,0,0,3,0,3,0,3,0,0,0,1}, 
  {1,0,0,0,0,0,2,0,0,0,2,0 , 0,0,0,0,0,0,0,0,0,0,0,1}, 
  {1,0,0,0,0,0,2,0,0,0,2,0 , 0,0,0,3,0,0,0,3,0,0,0,1}, 
  {1,0,0,0,0,0,2,0,0,0,2,0 , 0,0,0,0,0,0,0,0,0,0,0,1}, 
  {1,0,0,0,0,0,2,2,0,2,2,0 , 0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, 
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, 
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, 
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, 
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, 
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, 
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, 
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, 
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, 
  {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, 
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, 
  {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, 
  {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, 
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1} 
} ;

void    ft_initiate(t_cam *param)
{
    param->izq = 0;
    param->drch = 0;
    param->up = 0;
    param->down = 0;
    param->j = 0;
    param->i = 0;
}

int main (int argc, char **argv) 
{
  t_cam param;
  ft_initiate(&param);
  double posX = 22, posY = 12;  //x and y start position
  double dirX = -1, dirY = 0; //initial direction vector
  double planeX = 0, planeY = 0.66; //the 2d raycaster version of camera plane

  double time = 0; //time of current frame
  double oldTime = 0; //time of previous frame 
  int w = 640;
  int h = 480;
  int  side = 0;
  unsigned int color = 0xffff00;
  param.mlx_ptr = mlx_init();
  param.win_ptr = mlx_new_window(param.mlx_ptr, 800, 800, "mlx 42");
  param.img = mlx_new_image(param.mlx_ptr, 800, 800);
  param.addr = (int *)mlx_get_data_addr(param.img, &param.bits_per_pixel, &param.line_length,&param.endian);

  while(1)
  {
    int x = 0;
    while(x < w)
    {
      //calculate ray position and direction
      double cameraX = 2 * x / (double)w - 1; //x-coordinate in camera space
      double rayDirX = dirX + planeX * cameraX;
      double rayDirY = dirY + planeY * cameraX;
      
      //which box of the map we're in
      int mapX = (int)posX;
      int mapY = (int)posY;

      //length of ray from current position to next x or y-side
      double sideDistX;
      double sideDistY;

       //length of ray from one x or y-side to next x or y-side
      double deltaDistX = fabs(1 / rayDirX);
      double deltaDistY = fabs(1 / rayDirY);
      double perpWallDist;

      //what direction to step in x or y-direction (either +1 or -1)
      int stepX;
      int stepY;

      int hit = 0; //was there a wall hit?
      int side; //was a NS or a EW wall hit?
      
      //calculate step and initial sideDist
      if (rayDirX < 0)
      {
        stepX = -1;
        sideDistX = (posX - mapX) * deltaDistX;
      }
      else
      {
        stepX = 1;
        sideDistX = (mapX + 1.0 - posX) * deltaDistX;
      }
      if (rayDirY < 0)
      {
        stepY = -1;
        sideDistY = (posY - mapY) * deltaDistY;
      }
      else
      {
        stepY = 1;
        sideDistY = (mapY + 1.0 - posY) * deltaDistY;
      }
      
      //perform DDA
      while (hit == 0)
      {
        //jump to next map square, OR in x-direction, OR in y-direction
        if (sideDistX < sideDistY)
        {
          sideDistX += deltaDistX;
          mapX += stepX;
          side = 0;
        }
        else
        {
          sideDistY += deltaDistY;
          mapY += stepY;
          side = 1;
        }
        //Check if ray has hit a wall
        if (worldMap[mapX][mapY] > 0) hit = 1;
      }
        //Calculate distance projected on camera direction (Euclidean distance will give fisheye effect!)
      if (side == 0)
      {
        perpWallDist = (mapX - posX + (1 - stepX) / 2) / rayDirX;
      }
      else
      {
        perpWallDist = (mapY - posY + (1 - stepY) / 2) / rayDirY;
      }
      
      //Calculate height of line to draw on screen
      int lineHeight = (int)h / perpWallDist;

      //calculate lowest and highest pixel to fill in current stripe
      int drawStart = -lineHeight / 2 + h / 2;
      if
        (drawStart < 0)drawStart = 0;
      int drawEnd = lineHeight / 2 + h / 2;
      if
        (drawEnd >= h)drawEnd = h - 1;
           //choose wall color

      if (worldMap[mapX][mapY] == 1)
      {
        (color = 0xff0000);
        break;
      }
      else if (worldMap[mapX][mapY] == 2)
      {
        (color = 0x08000);
        break;
      }
      else if (worldMap[mapX][mapY] == 3)
      {
        (color = 0x000ff);
        break;
      }
      else if (worldMap[mapX][mapY] == 4 )
      {
        (color = 0xffffff);
        break;
      }
      //give x and y sides different brightness
      if (side == 1) {color  = color / 2;}

      //draw the pixels of the stripe as a vertical line
      mlx_put_image_to_window(param.mlx_ptr, param.win_ptr, param.img, 0, 0);
      x++;
    }
  }
  mlx_loop(param.mlx_ptr);
}