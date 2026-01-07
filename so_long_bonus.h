/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael-hou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 02:10:00 by antigravity       #+#    #+#             */
/*   Updated: 2025/12/20 12:25:00 by mael-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "so_long.h"

// Bonus Functions
void	init_enemies(t_game *game);
void	reset_enemies(t_game *game);
void	move_enemies(t_game *game);
void	animate_enemies(t_game *game, int old_frame);
void	update_move_display(t_game *game);
void	render_entities(t_game *game, int y, int x);
void	render_frames(t_game *game, mlx_image_t **frames, int x, int y);

// Menu
void	init_menus(t_game *game);
void	toggle_menus(t_game *game);
void	handle_menu_input(mlx_key_data_t keydata, t_game *game);
void	update_fade(t_game *game);
void	handle_exit(t_game *game);
void	reset_coins(t_game *game);
void	reset_key(t_game *game);
int		check_rect(t_game *game);
int		check_walls(t_game *game);
void	init_music(t_game *game);

void	set_image_alpha(mlx_image_t *img, int alpha);
void	setup_menu_image(t_game *game, mlx_image_t *img);
void	reset_game(t_game *game);

// init_utils_bonus functions
void	check_and_clear_pixel(mlx_image_t *img, uint32_t x, uint32_t y,
			uint8_t bg[3]);
void	remove_background(mlx_image_t *img);

#endif
