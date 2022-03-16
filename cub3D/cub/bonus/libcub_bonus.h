/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libcub_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apecci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 14:22:15 by apecci            #+#    #+#             */
/*   Updated: 2021/09/07 14:22:19 by apecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBCUB_BONUS_H
# define LIBCUB_BONUS_H
# include "../libcub.h"

/*
**Minimap
*/

void			minimap_img(t_data *img, t_window *window, t_player *player,
					int min_fract);
void			mouse_rot(t_window *window);
void			player_movement_b(t_keys *keys, t_player *player, char **map);

#endif
