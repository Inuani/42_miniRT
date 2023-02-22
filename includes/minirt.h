/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egauthey <egauthey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 11:13:13 by egauthey          #+#    #+#             */
/*   Updated: 2023/02/22 16:07:25 by egauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "../libs/libft/libft.h"
# include "../libs/mlx/mlx.h"


# include <fcntl.h> // functions for working with file descriptors, opening and manipulating files
# include <math.h>

# define HEIGHT 1080
# define WIDTH 1920

typedef struct s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	t_img		img;
}				t_data;

//handle window && image
void	init_window(t_data *data);
int		close_win(void);

//handle keys
int	event_handler(int key, t_data *data);


#endif