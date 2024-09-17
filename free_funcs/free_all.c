/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 03:48:13 by mohmazou          #+#    #+#             */
/*   Updated: 2024/09/17 01:18:55 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free_all(void **ptrs_list)
{
	int	i;

	i = 0;
	if (!ptrs_list)
		return ;
	
	while (ptrs_list[i])
	{
		free(ptrs_list[i]);
		i++;
	}
	free(ptrs_list);
	ptrs_list = NULL;
}
//ft_malloc fiha chi mouchkil raha tat5eli minishell segv
void	*ft_malloc(size_t size, int free)
{
	static void	**ptrs_list;
	static int	i;
	void		*ptr;
	FILE		*file;


	if (free)//had condetion fach tikon dak fichier diyal log supprime 
	{//ki tadir exit f minishell SEGV 
		file = fopen("malloc_log", "w");
		ft_free_all(ptrs_list);
		fprintf(file, "malloc freed\n");
		fclose(file);
		return (NULL);
	}
	if (!ptrs_list)
	{
		ptrs_list = malloc(sizeof(void *) * 10240);
		if (!ptrs_list)
		{
			printf("xmalloc: cannot allocate memory\n");
			exit(1);
		}
	}
	ptr = malloc(size);
	if (!ptr)
	{
		printf("xmalloc: cannot allocate memory\n");
		exit(1);
	}
		
	ptrs_list[i++] = ptr;
	ptrs_list[i] = NULL;
	
	file = fopen("malloc_log", "a");
	fprintf(file, "malloc[%d]: %p\n", i, ptr);
	fclose(file);
	return (ptr);
}
