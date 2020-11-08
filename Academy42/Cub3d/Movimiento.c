/*      //timing for input and FPS counter
      f.oldTime = time;
      time = getTicks();
      f.frameTime = (time - f.oldTime) / 1000.0; //frameTime is the time this frame has taken, in seconds
 */
     
/*    //move forward if no wall in front of you
	    if (f.up)
	    {
            if(param->finalmap[(int)(param->position_x + f.dirX * moveSpeed)][(int)param->position_y ] == '0') param->position_x += f.dirX * moveSpeed;
            if(param->finalmap[(int)(param->position_x)][(int)(param->position_y  + f.dirY * moveSpeed)] == '0') param->position_y += f.dirY * moveSpeed;
	    }
	    if (f.down)
	    {
            if(param->finalmap[(int)(param->position_x - f.dirX * moveSpeed)][(int)param->position_y] == '0') param->position_x -= f.dirX * moveSpeed;
            if(param->finalmap[(int)(param->position_x)][(int)(param->position_y - f.dirY * moveSpeed)] == '0') param->position_y  -= f.dirY * moveSpeed;
	    }
	    if (f.left)
	    {
          if (param->finalmap[(int)param->position_x][(int)(param->position_y + f.dirX * moveSpeed)] == '0') param->position_y += f.dirX * moveSpeed;
	        if (param->finalmap[(int)(param->position_x - f.dirY * moveSpeed)][(int)param->position_y] == '0') param->position_x -= f.dirY * moveSpeed;
	    }
	    if (f.right)
	    {
          if(param->finalmap[(int)param->position_x][(int)(param->position_y - f.dirX * moveSpeed)] == '0') param->position_y -= f.dirX * moveSpeed;
	        if (param->finalmap[(int)(param->position_x + f.dirY * moveSpeed)][(int)param->position_y] == '0') param->position_x += f.dirY * moveSpeed;
	    }
      if (f.rot_left)
      {
        double old_dir_x;
		    double old_plane_x;
    
		    old_dir_x = f.dirX;
		    f.dirX = f.dirX * cos(rotSpeed) - f.dirY * sin(rotSpeed);
		    f.dirY = old_dir_x * sin(rotSpeed) + f.dirY * cos(rotSpeed);
		    old_plane_x = f.planeX;
		    f.planeX = f.planeX * cos(rotSpeed) - f.planeY * sin(rotSpeed);
		    f.planeY = old_plane_x * sin(rotSpeed) + f.planeY * cos(rotSpeed);
      }
      if (f.rot_right)
      {
        double old_dir_x;
		    double old_plane_x;
    
		    old_dir_x = f.dirX;
		    f.dirX = f.dirX * cos(-rotSpeed) - f.dirY * sin(-rotSpeed);
		    f.dirY = old_dir_x * sin(-rotSpeed) + f.dirY * cos(-rotSpeed);
		    old_plane_x = f.planeX;
		    f.planeX = f.planeX * cos(-rotSpeed) - f.planeY * sin(-rotSpeed);
		    f.planeY = old_plane_x * sin(-rotSpeed) + f.planeY * cos(-rotSpeed);
      }
      if (f.esc)
        ft_exit_game(&mlx);*/