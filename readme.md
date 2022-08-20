```
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42Abudhabi.ae>    +#+  +:+       +#+        */
/*   By: hawadh <hawadh@student.42Abudhabi.ae>    +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 17:31:03 by makhtar           #+#    #+#             */
/*   Created: 2022/06/21 17:31:31 by hawadh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
```

```
***NOTES:***

42Docs guide on raycasting:
https://lodev.org/cgtutor/raycasting.html

```

`#BUGS: #15`

1.	~~***HA:***	Segfaul in `get_next_line();` due to `ft_strchr();` in `libft`~~
2.	~~***HA:***	Function parses whole file, should stop at first line of map~~
3.	~~***HA:***	Leak in `extract_file();` line `#26`~~
4.	~~***HA:***	Segfault when moving mouse in window in function `mlx_mouse_get_pos();` in function `draw_cursor();`~~
5.	~~***HA:***	Crosshair was not drawing~~
6.	~~***HA:***	Map printed with extra spaces~~
7.	~~***HA:***	Memory leak in `parse_layout();` in my function `store_confg_map();` line `#47`~~
8.	~~***MAK:***	Parser returning invalid map on checking walls if any `0` is present, `line #13` in file.cub~~
9.	~~***HA:***	xpm file opening failing~~
10.	~~***HA:***	On full screen, pause causes window to turn red if window resized to full screen~~
11.	~~***HA:***	Parser function `check_tabs();` had issue with iteration (Did I write this late night?) where `i = -1` and `while (++i > 0)`~~
12.	~~***HA:***	in `add_xpm();` image not placing in only Blue~~
13.	~~***HA:***	Map not redrawing on clearing window when hitting pause button a second time~~
14.	~~***HA:***	Minimap skipping areas and not drawing in walls~~
15. ***HA:***	Minimap not drawing walls when player is closer to left side of array

`#TODO:`

1.	~~***HA:***	Incorprate `get_next_line();` in `ft_reading();`~~
2.	~~***HA:***	Refactor `isdir();` and double check project for forbidden functions~~
3.	~~***HA:***	Parse and store map and config in separate 2D array for each~~
4.	~~***HA:***	Figure out how to separate map from configurations~~
5.	~~***HA:***	Add `make vg` rule in Makefile for debugging~~
6.	~~***HA:***	Debug segfault in `get_size();` due to~~
7.	~~***HA:***	Double check space stripping in squash~~
8.	~~***MAK:***	Declare a new structure to fetch the info and place it in the main root of the structure which will work on every aspect of the program.~~
9.	~~***HA:***	Study Raycasting~~
10.	~~***HA:***	Discuss images to be used with **`MA`**~~
11.	~~***HA:***	Figure out correct drawing and following of mouse cursor~~
12.	~~***MAK:***	Take xpm files and read it to check if the file reading is working perfectly or not.~~
13.	~~***MAK:***	Time for raycasting math to solve.~~
14.	~~***HA:***	Draw interior of minimap~~
15.	~~***HA:***	Figure out hook management for hook_num 46, see comments in `utils_hooks.c`~~
16.	***HA:***	Figure out what is the event that detects clicking on window edges
17.	~~***HA:***	Figure out XPM image for pause in center of screen and implement removal~~
18.	~~***HA:***	Correctly implement # 14~~
19.	***HA:***	Fix minimap drawing to draw when player is closer to left side of array coords, possibly due coords calculation making coords negative and invalid read

`#CURRENT STATUS`

`HA:	18 Jul 2022`

1.	New files to split functions `parse_file.c`, `errors.c`, `parse_file.c`
2.	Added .gitignore
3.	Created new Function `err_return();` to exit status 1 with correct error message
4.	Added get_next_line(); and minilibx_opengl
5.	Added debugger files to run debugger
6.	Refactored function `ft_reading();` and, now static `init();`
7.	New functions `get_size();` to get number of lines in file in `utils_parse.c`
8.	New struct pointer in `t_info` called `t_data`
9.	New function static `extract_data();` to extract data from file and store in a 2D array
10.	Added my `libft` function `ft_strchr();` to cub3d libft
11.	Added new function `ft_ptrptrlen();` to our libft returns 2D array size
12.	Added new function `ft_isspace();` to our libft, if ascii whitespace return `TRUE`
13.	New function `clean_file();` in new file `utils_file.c` to clean file input
14.	Helper functions for above `squash();` and `count_str_size();`. Squash removes all excess whitespaces in line and `count_str_size();` returns correct str size without excess white spaces
15.	New function called `free_split();` to free 2D arrays in new file `memory_mngmnt.c`
16.	Parsing Configurations almost complete, see `TODO #4`
17.	Moved function `get_act_size();` to file `utils_parse.c`
18.	New file `utils_file_ext.c` with functions `**squash_lines();` and, new function, `check_line(); to only clean file up to last line not including map to be left for parsing.
19.	Cleaning file complete.
20.	`make vg` rule added, see Makefile
21.	Leak found and fixed in `clean_whitespaces();` was missing a pointer
22.	Added new function to libft: `ft_strrmc();` removes `char c` from array
23.	Uncomment of MLX related lines in Makefile, MLX now functional in Program
24.	`mlx_loop();` now called in function `init();`
25.	Window now initialised and opening, by adding function calls `mlx_new_window();` in `main.c` function `init();`
26.	Two new files, `window.c` for window functions and `utils_hooks.c` for key hook utilities
27.	Calling `mlx_key_hook();` int `init();` that calls new function `key_hook_manage();` which currently only handles **ESC**
28. New function `esc_win();` which calls `free_data();` and `exit(0);`, this function handles both `(x) and esc`
29.	Calling `mlx_hook();` in `init();` to handle above `(x)`
30.	Two new functions in `window.c` to initialise and store window + image address, `init_window();` and `get_img_addr();`
31.	New file `draw.c` contains 2 new functions `draw_cursor();` and `my_pixel_put();`
32.	Function draw cursor calls `MLX` function `mlx_mouse_get_pos();` to get mouse position for cursor drawing ***WIP***
33.	Updated `memory_mngmnt.c` with 3 new `free_struct_???();` functions one for each struct and struct members
34.	Added error message `ERROR: Minilibx Failure` for any failure from minilibx functions
35.	Added print loop in `check_map();` to print file contents after cleaning and parsing
36.	Refactored `draw_cursor();` and new function `init_mouse();` in new file `mouse.c`
37.	New file `hooks.c` to contain new function `hook_management();` to hold all `mlx_hook();` calls
38.	Refactored `draw_cursor();` and new function `mouse_move();` calls `init_cursor();` from within `hook_management();`
39.	Moved `mlx_loop();` to `window.c` called in function `init_window();`
40.	Refactored `init_cursor();` now draws half cursor in centre of screen
41.	New file `rgb.c` with new function `rgb();` to calculate colours for roof and ceiling.
42. Three new functions in new file `utils_draw.c` to draw roof and ceiling colours `draw_ceiling();` and `draw_floor();` called from function `ceiling_floor();`
43.	New function `draw_map();` called in `init_window();` in `draw.c` to draw currently contains `ceiling_floor();`  -> to draw ceiling and floor, and `init_cursor();` -> to redraw cursor
44.	New file `mini_map.c` contains 3 functions to draw minimap border and interior see TODO #14, functions named `draw_minimap(); mini_bottom_top(); mini_interior();`
45.	Minimap drawn in top left corner, Missing interior
46.	Downloaded some xpm images and added window control flags to MLX library
47.	Removed fullscreen flag from `mlx_new_window.m` flag is `NSWindowStyleMaskFullScreen;`
48.	Buttom `m` on keyboard stops mouse capture and releases mouse
49.	Added `mlx_string_put();` function from old `MLX` to current `MLX` library, and updated `mlx.h`
50.	New function `check_tabs();` called in `squash_lines();` replaces all tabs to 4 spaces within the `map` only in file `utils_file_ext.c`
51.	New function to mimic `ft_strlen();` but adds +4 to the count for each tab found
52.	Bug #6 Fixed, was due invalid write due to incorrect calculation in `get_tab_size();`
53.	Added `xpm_images/` file with sample xpm images to discuss
54.	New Function `init_xpm();` to init and store all xpm images placed in `window.c`
55.	New function in `parse_layout.c` called `store_map();` & `**map` of `data->file`
56.	New function `confg_count();` to count number of lines for `data->confg` & `data->map` in `parse_layout();`
57.	Added Loading and implementation fo Pause Message on hitting `'m' hook number 64` in `key_hook_manage();`, yet to implement removal of Pause Message
58.	Fixed leak in `store_map();` line 47, due starting iteration at `i = -1;` solution was to increment `i` before check `data->file[i]` in `while (++i < len && data->file[i])`
59.	Deleted unnecessary file `utils_parse_ext.c`
60.	Moved function call `parse_arg();` to function `check_map();` as clean-up of `main.c`
61.	Added error message `status == 5` in `errors.c` for XPM Image loading failure
62.	Added parameter `t_info *info` to function prototype `void err_return(int status, t_info *info);` and sending in `t_info *info` to all occuring function calls to free any allocated data within the structure in case of any error returns before exit
63.	New function `store_confg_map();` which stores the map and the confg in their respective 2D Arrays
64.	New File `utils_xpm.c` to hold all xpm related functions
65.	Renamed `xpm_images/` to `imgs/`
66.	New Function `init_minimap();` called in `init_window();` inits memory for `t_mini` structure to be used for initialising a new image for minimap and calling `mlx_get_data_addr();` to place image in main window for faster redrawing of minimap
67.	Due to above, `draw_minimap();` completely refactored now only 1 function called within `mini_interior();` to draw interior
68.	New Custom `pixel_put();` function for mini map called `mini_pixel_put();` uses `t_mini *mini` as struct pointer
69.	Added new error message and status to `err_return();`, and removed print of `d->confg` from `check_map();`
70.	New function prints layout content in `parse_layout();` called `print_xpm();`
71.	Refactored `check_tabs();` and `squash_lines();` to reduce number of lines and fix extra removal of character from `check_tabs();`, `squash_lines();` now has 2 additional `else if` statements
72.	Changed position of `PAUSE` image in window within function `key_hook_manage();` line `#44`
73.	New file `utils_xpm.c` with function `opem_xpm();` uses `mlx_xpm_file_to_image();` to open all xpm images and store in `data->confg` called in `init_xpm();`
74.	Added `&& i < len` line `#39` in `open_xpm();` to fix `bug #9`
75.	Added new function  `free_struct_mini();` in `memory_mngmnt.c` to free struct `t_mini` and it's contents
76.	New File `utils_mini_map.c`
77.	New Struct `s_player` to save all player related data, also new function, `draw_player_walls();` to extract player position and future drawing of minimap in `mini_interior();` with 2 functions `find_player_array();` for Y and `find_player_index();` for X while also extracting Perspective
78.	Bug fix `#11`
79.	New function added to `libft` `ft_ismapicon();` to detect if character in string is a valid map character, now called in `check_if_map();`
80.	New Approved map walls xpm images
81.	Implemented Colour bit Masking, and renamed file `utils_mini_map.c` into `player.c` and renamed function `draw_walls_player();` to `init_player`
82.	New function in `window.c` called `init_all();`, calls all `init?????();` functions before drawing and pushing to window`
83.	Refactored `open_xpm();` and new function `get_xpm_addr();` to extract addresses of each xpm file for later use in merging with main image
84.	Added `# define WIDTH 1920` and `# define HEIGHT 1080` in `cub.h`
85.	New Struct `s_xpm` in array to contain all image data, with new Enum to contain `NO`, `SO`, `WE`, `EA`
86.	Added free for `data->xpm` struct in `memory_mngmnt.c` and moved `free_split();` to new `utils_memory_mngmnt.c`
87.	Two new Functions in `draw.c` called `place_xpm();` and `add_xpm();`; Function `place_xpm();` to determine initial player orientation, and `add_xpm();` draws the image to main image address
88.	New Pause button `'p' == hook_num 35`
89.	Implemented correct method of adding xpm address to img
90.	Added `mlx_clear_window();` for pause removal. See bug #13
91.	New Variable `xpm->divisible` to determine size of walls
92.	New function to hold Pause code `handle_pause();` located in `utils_hooks.c`
93.	Refactored `add_xpm();` with correct iteration of image `char *`, still not drawing correctly
94.	Started mini map drawing, see `mini_map.c` and file `utils_mini_math.c` renamed to `utils_minimap.c`
95.	New XPM image implemented `Ak47.xpm` for weapon, and new images for `NO SO WE EA`
96.	Buf #12 FIXED, now correctly implementing copying of image pixels with colours to main image window via `char *`, also added `wi - 4` && `hi - 4` to avoid invalid read within images
97.	Currently working on and implementing of drawing interior contents of minimap, with 2 new functions, `draw_mini_player();` which draws player in centre of minimap (Currently white square also drawn around to figure out scaling) and `draw_mini_walls();` to attempt to draw walls in respective positions in the minimap.
98.	Changed size of minimap image from `260x185` to `185x185` and moved function `mini_interior();` to `utils_minimap.c`
99.	Added new `# define MINI_SCALE 29` for minimap scaling and new variable `data->gun`
100. New Wall images Implemented
101. Attempting new algorithm in `mini_interior();` WIP
102. Removed `TRUE FALSE` from `cub.h` since it already exists in `libft.h`
103. Minimap fully functional, refactored `mini_intrior();` and 2 new functions `draw_mini_enemy();` and temporary function `draw_square();` for scaling testing confirmation
104. Moved function `draw_mini_player();` and `draw_square();`
105. Added acceptable character in `valid_key();` in `parse_map.c` character `'m'` for enemies, `line #32 -> #33`
106. Refactored scaling and sizes of mini-map drawing to fit player and map exact centre in minimap
107. Swapped `EA` and `NO` walls images
108. New function `find_player();` in `player.c` to find player position in map array, Function is `NOT STATIC` so it can be recalled with each iteration to redraw mini-map, added function call in `draw.c draw_map();`
109. WIP free xpm struct array in `memory_mngmnt.c` and new test map `zmap.cub`

`MAK:	4 July 2022`

1.	Parsing for different types of layout is finished. Memory leaks, and norms are done.
2.	For better reference please read the comments to know what is the structure for parser.
3.	Changed char to const char in ft_strcmp.
4.	Updated crosshair with green line and minimal size of the crosshair.
5.	Updated parsing function to fetch the values based on the requirements like path to different xpm files, colours given based on RGB combination for floor and ceilings.
6.	Updated Crosshair


