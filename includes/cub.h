/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawadh <hawadh@student.42Abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:38:18 by hawadh            #+#    #+#             */
/*   Updated: 2022/11/10 09:21:56 by hawadh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# ifdef OSX
#  include "../minilibx_opengl/mlx.h"
#  define W 13
#  define D 2
#  define A 0
#  define S 1
#  define P 35
#  define ARROW_L 123
#  define ARROW_R 124
#  define SHIFT_KEY 257
#  define ESC 53
# endif

# ifdef LINUX
#  include "../minilibx_linux/mlx.h"
#  define ESC 65307
#  define W 119
#  define D 100
#  define E 101
#  define S 115
#  define A 97
#  define P 112
#  define ARROW_R 65363
#  define ARROW_L 65361
# endif

# define PI 3.14159265358979323846
# define RADIAN 0.017453292519943
# define BLOCK_SIZE 8
# define RAYS 1920
# define WIDTH 1920
# define HEIGHT 1080
# define MINI_DIM 180
# define MINI_SCALE 30

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <sys/stat.h>
# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"
# include <math.h>

/**
**	ENUM for Compass perspective of Player
*	NO	0	NORTH
*	SO	1	SOUTH
*	WE	2	WEST
*	EA	3	EAST
**/
typedef enum e_compass
{
	NO,
	SO,
	WE,
	EA,
}	t_pers;

/**
**	ENUM for Parsing of the type
*	NO	0	NORTH
*	SO	1	SOUTH
*	WE	2	WEST
*	EA	3	EAST
*	F	4	FLOOR
*	C	5	CEILING
**/
typedef enum e_type
{
	NORTH,
	SOUTH,
	WEST,
	EAST,
	FLOOR,
	CEILING,
}	t_type;

/**
**	Wall Structure
*	Wall front trigger
*	Wall back trigger
*	Wall left trigger
*	Wall right trigger
*	7 Angles of all four quadrants
*	Row and Column to check for collision
*	Count for iteration
**/
typedef struct s_wall
{
	double	angle;
	double	x;
	double	y;
	int		count;
	int		row;
	int		col;
	int		wall_front;
	int		wall_back;
	int		wall_left;
	int		wall_right;	
}	t_wall;

/**
 ** Sprite Structure
 **	x_pos in double an x-coordinate
 **	y_pos in double a y-coordinate
 **	x_grid in int an x-coordinate
 **	y_grid in int a y-coordinate
 **	ang = angle of the sprite
 ** dist = distance of the sprite.
 ** height of the sprite.
 **/
typedef struct s_sprite
{
	double	x_pos;
	double	y_pos;
	int		x_grid;
	int		y_grid;
	double	ang;
	double	dist;
	double	height;
}	t_sprite;

/**
**	Rays Structure
*	Distance variable
*	Angle of ray
*	X Position of the ray
*	Y Position of the ray
*	Width of the ray
*	Height of the ray
**/
typedef struct s_rays
{
	double	dist;
	double	ang;
	double	x;
	double	y;
	double	width;
	double	height;
	int		dir_wall;
	int		side;
}	t_rays;

typedef struct s_ray
{
	double	angle;
	double	x;
	double	y;
	double	x1;
	int		wall;
	int		count;
	int		grid_x;
	int		grid_y;
	double	cx;
	double	cy;
	double	dx;
	double	dy;
	int		m_x;
	int		m_y;
	double	x_step;
	double	y_step;
	double	side_dist_x;
	double	side_dist_y;
	int		side;
}	t_ray;

/**
**	Player Structure
*	view	Orientation, N,S,W,E
*	y_pos	Position on Y
*	x_pos	Position on X
**/
typedef struct s_player
{
	char		view;
	double		y_pos;
	double		x_pos;
	double		angle;
	double		dx;
	double		dy;
	double		speed;
	t_wall		wall;
	t_rays		rays[RAYS];
}	t_player;

typedef struct s_xpm
{
	void	*img;
	char	*addr;
	int		bitspix;
	int		len;
	int		end;
	int		wi;
	int		hi;
}	t_xpm;

/**
**	Minimap image address
**/
typedef struct s_minimap
{
	char	*addr;
	int		bitspix;
	int		len;
	int		end;
	int		x_pos;
	int		y_pos;
}	t_mini;

/**
**	Main window image address
**/
typedef struct s_image
{
	char	*addr;
	int		bitspix;
	int		len;
	int		end;
}	t_img;

/**
**	Mouse Data
**/
typedef struct s_mouse
{
	int		flag;
	int		y;
	int		x;
}	t_mouse;

/**
**	Floor RGB
**/
typedef struct s_floor
{
	unsigned int	red;
	unsigned int	green;
	unsigned int	blue;
}	t_floor;

/**
**	Ceiling RGB
**/
typedef struct s_ceil
{
	unsigned int	red;
	unsigned int	green;
	unsigned int	blue;
}	t_ceil;

/**
**	File Map layout and data
*	file		file contents
*	map			map contents
*	confg		Below config during mlx_xpm_file_to_image();
*	pause		Pause image
*	floor		RGB of floor
*	ceiling		RGB of ceiling
**/
typedef struct s_data
{
	char	**file;
	char	**map;
	char	**confg;
	char	*pause;
	char	*gun;
	char	*gun_anim;
	t_xpm	*xpm;
	t_floor	floor;
	t_ceil	ceil;
}	t_data;

/**
**	Parsing for 2d map
*	i			iterator;
*	map			2d string
*	str			index of the map
**/
typedef struct s_str
{
	int		i;
	char	**map;
	char	*str;
}	t_str;

/**
**	Main Struct with all info including struct Pointers
*	minilibx	*mlx
*	window		*window
*	image		*img		
*	data		struct
*	mouse		struct
*	minimap		struct
**/
typedef struct s_info
{
	void		*mlx;
	void		*win;
	void		*img;
	void		*mini_map;
	int			fire;
	t_data		*data;
	t_mouse		*mouse;
	t_img		*image;
	t_mini		*mini;
	t_sprite	*sprite;
	t_player	*player;
	t_sprite	**spr;
}	t_info;

/**
**	Memory Management
**/
void		free_split(char **str);
void		free_data(t_info *info);

/**
**	Math Functions
**/
double		sq(double num);
double		get_dist(double x_one, double y_one, double x_two, double y_two);
double		get_height(double dist, double r_ang, double p_ang);
double		dda_x(double new_x, double old_x, double old_y, double ang);
double		dda_y(double new_y, double old_y, double old_x, double ang);

/**
**	Sprites Management
**/
int			key_sprite(int c);
void		dup_values(t_sprite *new_spr, t_sprite *old_spr, t_ray *ray);
t_sprite	**new_alloc_sprite(t_sprite **old_spr);
void		check_sprite(t_ray *ray, t_info *inf);

/**
**	Parsing Functions
**/
size_t		get_act_size(char **input);
size_t		confg_count(char **file);
void		error_print(char *str);
void		err_return(int status, t_info *info);
void		check_map(t_info *info, char *str);
void		fetch_rgb(char *str, t_info *info, const char *layout);
char		**clean_whitespace(char **input);
char		**squash_lines(char **file, char **input);
char		*squash(char *input);
int			store_data(t_data *d, char **input);
int			check_if_map(char *input);
int			isdir(char *str);
int			get_size(t_info *info, char *str);
int			compare_ext(char *str);
int			check_line(char *input);
int			check_rgb(char *str, const char *layout, t_info *info);
int			parse_config(char *str, const char *layout, t_info *info);
int			parse_config_rgb(char *str, const char *layout, t_info *info);
int			data_init(t_info *info, int *i, int *ret);
char		*get_layouts(char *str);
int			get_raw_layout(char *line);
char		*get_type_str(int type);
int			get_2d_len(char **str);
int			ft_strlen_int(char *str);
int			parse_spaces(char **str);
int			parse_map(char **str, int index);
int			parse_arg(char **maps, t_info *info);

/**
**	Window Functions
**/
int			init_window(t_info *info);
int			key_hook_manage(int hook_num, t_info *info);
int			esc_win(t_info *info);

/**
**	Drawing Functions
**/
void		my_pixel_put(t_info *inf, int x, int y, int rgb);
void		draw_cursor(t_info *info);
void		draw_map(t_info *info);
void		ceiling_floor(t_info *info);
void		draw_minimap(t_info *info, t_mini *mini);
void		place_walls(t_info *inf, t_rays *ray, int x);

/**
**	player struct functions
**/
void		init_player(t_info *info);
void		find_player(t_data *data, t_player *player);

/**
**	Mini-map functions
**/
void		init_minimap(t_info *info);
void		mini_interior(t_info *info, t_mini *mini);
void		mini_pixel_put(t_mini *mini, int x, int y, int rgb);
double		extract_decimal(t_player *player, char status);

/**
**	XPM Functions 
**/
int			init_xpm(t_info *info, t_data *data);

/**
**	RGB Functions
**/
size_t		rgb(t_data *data, int status);

/**
**	Hook Functions
**/
void		handle_wall_collision(t_info *inf);
void		move_frwrd(t_info *inf);
void		move_back(t_info *inf);
void		move_left(t_info *inf);
void		move_right(t_info *inf);
void		rotation(int hook_num, t_info *inf);
void		moves(int hook_num, t_info *inf);
void		hook_management(t_info *info);

/**
**	Mouse Functions
**/
void		linux_osx_mouse(t_info *info, int x, int y, int status);
void		init_cursor(t_info *inf);
void		rotation(int hook_num, t_info *inf);
int			init_mouse(t_info *info);
int			mouse_move(int x, int y, t_info *info);

/**
**	RayCasting functions
**/
void		raycasting(t_info *inf, t_ray *ray);
int			edge_case(double x, double y, t_info *vars);
int			wall_hit_direction(t_ray *ray);
void		init_rays(t_info *inf);
double		euclidean(t_ray *ray, double dist, double p_ang);

#endif
