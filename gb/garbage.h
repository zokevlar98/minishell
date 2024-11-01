/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohmazou <mohmazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 09:42:43 by zqouri            #+#    #+#             */
/*   Updated: 2024/11/01 03:30:20 by mohmazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GARBAGE_H

# define GARBAGE_H

# include <stdlib.h>

typedef struct s_garb
{
	void			*addr;
	struct s_garb	*next;
}	t_garb;

void	clear_list(t_garb *list);
void	add_node(t_garb **list, t_garb *node);
void	*gb_malloc(size_t size, int type);

#endif