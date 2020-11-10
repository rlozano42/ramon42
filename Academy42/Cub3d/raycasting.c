/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlozano <rlozano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 10:31:59 by rlozano           #+#    #+#             */
/*   Updated: 2020/11/10 12:06:48 by rlozano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int  ft_exit_game(t_cam *mlx)
{
  mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	exit(EXIT_SUCCESS);
  return(0);
}

int   ft_game(t_gen *g)
{
    ft_movement(g);
    init_raycasting(g);
    ft_draw_sprites(g);
    mlx_put_image_to_window(g->mlx.mlx_ptr, g->mlx.win_ptr, g->mlx.img, 0, 0);
    return(0);
}

void init_raycasting(t_gen *g)
{
    int j;
    int x = 0;
    
    while(x < g->param.Screenwidth)
    {
      g->f.cameraX = 2 * x / (double)g->param.Screenwidth - 1;
      g->f.rayDirX = g->param.dirX + g->param.planeX * g->f.cameraX;
      g->f.rayDirY = g->param.dirY + g->param.planeY * g->f.cameraX;
      g->f.mapX = g->param.position_x;
      g->f.mapY = g->param.position_y;
      g->f.deltaDistX = fabs(1 / g->f.rayDirX);
      g->f.deltaDistY = fabs(1 / g->f.rayDirY);
    
      
      //calculate step and initial sideDist
      if (g->f.rayDirX < 0)
      {
        g->f.stepX = -1;
        g->f.sideDistX = (g->param.position_x - g->f.mapX) * g->f.deltaDistX;
      }
      else
      {
        g->f.stepX = 1;
        g->f.sideDistX = (g->f.mapX + 1.0 - g->param.position_x) * g->f.deltaDistX;
      }
      
      if (g->f.rayDirY < 0)
      {
        g->f.stepY = -1;
        g->f.sideDistY = (g->param.position_y - g->f.mapY) * g->f.deltaDistY;
      }
      else
      {
        g->f.stepY = 1;
        g->f.sideDistY = (g->f.mapY + 1.0 - g->param.position_y) * g->f.deltaDistY;
      }
      
      int hit;

      hit = 0;
      //perform DDA igual que el miguel hasta otro 10
      while (hit == 0)
      {
        if (g->f.sideDistX < g->f.sideDistY)
        {
          g->f.sideDistX += g->f.deltaDistX;
          g->f.mapX += g->f.stepX;
          g->f.side = 0;
        }
        else
        {
          g->f.sideDistY += g->f.deltaDistY;
          g->f.mapY += g->f.stepY;
          g->f.side = 1;
        }
        if (g->param.finalmap[g->f.mapX][g->f.mapY] == '1')
          hit = 1;
      }


      if (g->f.side == 0)
      {
        g->f.txt_hit = (g->f.mapX < g->param.position_x ? 'N' : 'S');
        g->f.perpWallDist = (g->f.mapX - g->param.position_x + (1 - g->f.stepX) / 2) / g->f.rayDirX;
        g->f.wallx = g->param.position_y + g->f.perpWallDist * g->f.rayDirY;
        
      }
      else
      {
        g->f.txt_hit  = (g->f.mapY < g->param.position_y ? 'W' : 'E');
        g->f.perpWallDist = (g->f.mapY - g->param.position_y + (1 - g->f.stepY) / 2) / g->f.rayDirY;
        g->f.wallx = g->param.position_x + g->f.perpWallDist * g->f.rayDirX;
      }
      g->spr.zbuffer[x] = g->f.perpWallDist; 
      ft_put_texture(g);
      
      g->f.lineHeight = (int)(g->param.Screenheight / g->f.perpWallDist);
      g->f.drawStart = (-g->f.lineHeight / 2) + g->param.Screenheight / 2;
      if(g->f.drawStart < 0)
        g->f.drawStart = 0;
      g->f.drawEnd = (g->f.lineHeight / 2) + g->param.Screenheight / 2;
      if(g->f.drawEnd >= g->param.Screenheight)
        g->f.drawEnd = g->param.Screenheight - 1;
      g->f.wallx -= floor(g->f.wallx);
      g->txt.txt_x = g->f.wallx * (g->txt.txt_sl / 4);
		  if ((g->f.side == 0 && g->f.rayDirX > 0) || (g->f.side == 1 && g->f.rayDirY < 0))
			  g->txt.txt_x = (g->txt.txt_sl / 4) - g->txt.txt_x - 1;     
      j = 0;
      //draw the pixels of the stripe as a vertical line
      
      g->f.txtstep = 1.0 * g->txt.txt_h / g->f.lineHeight;
	    g->f.txtpos = (g->f.drawStart - g->param.Screenheight  / 2 + g->f.lineHeight / 2) * g->f.txtstep;
      while (j < g->f.drawStart)
      {
        *(g->mlx.addr + j++ * g->param.Screenwidth + x)  =  255;
      }
      while (j < g->f.drawEnd)
      {
        *(g->mlx.addr + x + j++ * g->mlx.line_length / 4) = *(g->txt.txt_data + g->txt.txt_x + (int)g->f.txtpos * g->txt.txt_sl / 4);
        g->f.txtpos += g->f.txtstep;
      }
      while (j < g->param.Screenheight)
      {
        *(g->mlx.addr + j++ * g->param.Screenwidth + x)   =  60000;
      }
       
      x++;
    }
}