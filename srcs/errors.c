/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawadh <hawadh@student.42Abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:27:11 by hawadh            #+#    #+#             */
/*   Updated: 2022/07/08 21:18:17 by hawadh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

/**
**	Prints errors with colour codes
**/
void	error_print(char *str)
{
	write(2, "\033[1;91m", strlen("\033[1;91m"));
	write(2, str, strlen(str));
	write(2, "\n\033[0m", strlen("\n\033[0m"));
}

/**
**	Print error message
*	status == 0		File Descriptor 
*	status == 1		Empty File
*	status == 2		Invalid Arguments
*	status == 3		Invalid Map
*	status == 4		Mlx Failed
*	status == 5		XPM Load failed
*	status == 6		Layout failed XPM and C and F
*	status == 7		Malloc Failure
**/
void	err_return(int status, t_info *info)
{
	if (status == 0)
		error_print("[0]:	ERROR: File Descriptor");
	else if (status == 1)
		error_print("[1]:	ERROR: Empty File");
	else if (status == 2)
		error_print("[2]:	ERROR: Arguments");
	else if (status == 3)
		error_print("[3]:	ERROR: Map not valid");
	else if (status == 4)
		error_print("[4]:	ERROR: Minilibx Failure");
	else if (status == 5)
		error_print("[5]:	ERROR: XPM Load Image Failure");
	else if (status == 6)
		error_print("[6]:	ERROR: Invalid Layout");
	else if (status == 7)
		error_print("[7]:	ERROR: Malloc Failure");
	free_data(info);
	exit (1);
}
