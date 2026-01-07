/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael-hou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 04:45:00 by mael-hou          #+#    #+#             */
/*   Updated: 2025/12/10 04:45:00 by mael-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	check_and_clear_pixel(mlx_image_t *img, uint32_t x, uint32_t y,
		uint8_t bg[3])
{
	uint8_t	*pixel;

	pixel = &img->pixels[((y * img->width) + x) * sizeof(int32_t)];
	if (abs(pixel[0] - bg[0]) < 10 && abs(pixel[1] - bg[1]) < 10 && abs(pixel[2]
			- bg[2]) < 10)
		pixel[3] = 0;
}

void	remove_background(mlx_image_t *img)
{
	uint32_t	x;
	uint32_t	y;
	uint8_t		*pixel;
	uint8_t		bg[3];

	if (!img || img->width == 0 || img->height == 0)
		return ;
	pixel = &img->pixels[0];
	bg[0] = pixel[0];
	bg[1] = pixel[1];
	bg[2] = pixel[2];
	y = 0;
	while (y < img->height)
	{
		x = 0;
		while (x < img->width)
		{
			check_and_clear_pixel(img, x, y, bg);
			x++;
		}
		y++;
	}
}
