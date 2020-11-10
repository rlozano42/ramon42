/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlozano <rlozano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 18:46:22 by rlozano           #+#    #+#             */
/*   Updated: 2020/11/10 11:33:41 by rlozano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
#define CUBE3D_H

#include "includes/minilibx/mlx.h"
#include "includes/GNL/get_next_line.h"
#include "includes/libft/libft.h"
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
# include "./includes/key_macos.h"
# include <time.h>
#include <math.h>

#define MAX_RESOLUTIONX 1920
#define MAX_RESOLUTIONY 1080
#define MIN_RESOLUTIONX 400
#define MIN_RESOLUTIONY 400

# define moveSpeed	0.08
# define rotSpeed	0.05


typedef struct	s_cam{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img;
	int			i;
	int			j;
	int			*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_cam;

typedef struct s_ray
{
  	double 			time; 
  	double 			oldTime; 
  	unsigned int 	color;
	double 			cameraX;
	double 			rayDirX;
	double 			rayDirY;
	int 			mapX;
	int 			mapY;
	double 			sideDistX;
	double 			sideDistY; //length of ray from current position to next x or y-side
	double 			deltaDistX; 
	double 			deltaDistY; 
	double 			perpWallDist;
	int 			stepX;       //what direction to step in x or y-direction (either +1 or -1)
    int 			stepY;
	int 			side; //was a NS or a EW wall hit?
	int 			lineHeight;
	int 			drawStart;
	int 			drawEnd;
	double 			frameTime;
	int				keycode;
	double 			oldPlaneX;
	double			oldDirX;
	int				up;
	int				down;
	int				left;
	int				right;
	int				esc;
	int				rot_right;
	int				rot_left;
	char			txt_hit;
	double			wallx;
	double			txtstep;
	double			txtpos;
}				t_ray;

typedef struct s_map
{
	int			fd;
	char		*line;
	int			Screenwidth;
	int			Screenheight;
	char		*north;
	char		*south;
	char		*west;
	char		*east;
	char		*sprite;
	char		**aux;
	int 		floor[3];
	int			ceiling[3];
	double			position_x;
	double			position_y;
	int			len;
	int			column;
	int			flag;
	int			row;
	char		*map;
	char		**finalmap;
	char		whois;
	double 		dirX;
	double		dirY; 
  	double 		planeX;
	double		planeY;
}				t_map;

typedef	struct		s_texture
{
	void			*txtn;
	int				*txtn_data;
	int				txtn_h;
	int				txtn_w;
	int				txtn_sl;
	int				txtn_sb;
	int				txtn_ed;
	void			*txts;
	int				*txts_data;
	int				txts_h;
	int				txts_w;
	int				txts_sl;
	int				txts_sb;
	int				txts_ed;
	void			*txtw;
	int				*txtw_data;
	int				txtw_h;
	int				txtw_w;
	int				txtw_sl;
	int				txtw_sb;
	int				txtw_ed;
	void			*txte;
	int				*txte_data;
	int				txte_h;
	int				txte_w;
	int				txte_sl;
	int				txte_sb;
	int				txte_ed;
	void			*txtp;
	int				*txtp_data;
	int				txtp_h;
	int				txtp_w;
	int				txtp_sl;
	int				txtp_sb;
	int				txtp_ed;
	int				*txt_data;
	int				txt_sl;
	int				txt_h;
	int				txt_x;
}					t_texture;

typedef	struct		s_sprites
{
	float			*sprx;
	float			*spry;
	float			*sortpprx;
	float			*sortppry;
	int				cspr;
	double			zbuffer[4320];
	double			spritex;
	double			spritey;
	double			invdet;
	double			transformx;
	double			transformy;
	int				spritescreenx;
	int				spriteheight;
	int				drawstarty;
	int				drawendy;
	int				spritewidth;
	int				drawstartx;
	int				drawendx;
	int				texx;
	int				texy;
	int				stripe;
	int				y;
	int				d;
}					t_sprites;

typedef struct s_gen
{
	t_cam 		mlx;
  	t_ray 		f;
	t_map		param;
	t_texture	txt;
	t_sprites	spr;
}				t_gen;

void			final_checkmap(t_gen *g);
void			ft_readmap(char *mapa, t_gen *g);
void 			init_raycasting(t_gen *g);
int  			ft_key_release(int keycode, t_gen *g);
int 			ft_key_press(int keycode, t_gen *g);
int  			ft_exit_game(t_cam *mlx);
void			ft_handleceiling(t_gen *g);
void			ft_handlefloor(t_gen *g);
void			ft_handlesprite(t_gen *g);
void			ft_handleeast(t_gen *g);
void			ft_handlewest(t_gen *g);
void			ft_handlesouth(t_gen *g);
void			ft_handlenorth(t_gen *g);
void			ft_handleresolution(t_gen *g);
void			ft_throw_error(const char  *str);
void			check_updown(t_gen *g, char str);
void			ft_check(t_gen *g);
void		    ft_checkrouth(t_gen *g);
void			ft_checkcolumn(t_gen *g);
void			ft_orientation(t_gen *g);
void			ft_handleresolution(t_gen *g);
void			new_window(t_gen *g);
void  			ft_movement(t_gen *g);
int 			ft_key_press(int keycode, t_gen *g);
int 			ft_key_release(int keycode, t_gen *g);
int   			ft_game(t_gen *g);
void			ft_init_textures(t_gen *g);
void			ft_put_texture(t_gen *g);
void			ft_draw_sprites(t_gen *g);
int				is_space(char c);
int				check_map(char **map, int row, int col,int Maxrow,int Maxcol);

#endif
