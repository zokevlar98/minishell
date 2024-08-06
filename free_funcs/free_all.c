/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohmazou <mohmazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 05:39:39 by mohmazou          #+#    #+#             */
/*   Updated: 2024/08/06 06:30:19 by mohmazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	*free_all(t_alloc *alloc)
{
	t_alloc	*tmp;

	while (alloc)
	{
		tmp = alloc;
		alloc = alloc->next;
		free(tmp->ptr);
		free(tmp);
	}
	return (NULL);
}

t_alloc	*ft_new_alloc(void *ptr)
{
	t_alloc	*new;

	new = malloc(sizeof(t_alloc));
	if (!new)
	{
		printf("Malloc failed\n");
		exit(1);
	}
	new->ptr = ptr;
	new->next = NULL;
	return (new);
}

void	ft_alloc_add_back(t_alloc **alst, t_alloc *new)
{
	t_alloc	*tmp;

	if (!*alst)
	{
		*alst = new;
		return ;
	}
	tmp = *alst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

void	*ft_malloc(size_t size, int free)
{
	static t_alloc	*alloc;
	void	*ptr;
	t_alloc	*new_ptr;

	if (free)
		return (free_all(alloc));
	ptr = malloc(size);
	if (!ptr)
	{
		printf("Malloc failed\n");
		exit(1);
	}
	new_ptr = ft_new_alloc(ptr);
	ft_alloc_add_back(&alloc, new_ptr);
	return (ptr);
}