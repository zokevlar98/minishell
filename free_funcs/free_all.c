/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohmazou <mohmazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 05:39:39 by mohmazou          #+#    #+#             */
/*   Updated: 2024/08/04 06:25:51 by mohmazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

#define MAX_ALLOCATIONS 10240

// Global array to store allocated memory addresses
void *allocated_memory[MAX_ALLOCATIONS];
// int allocation_count = 0;

// ft_malloc function to allocate memory and store the address
void* ft_malloc(size_t size)
{
	static int	allocation_count;
		
    if (allocation_count >= MAX_ALLOCATIONS) {
        fprintf(stderr, "Maximum number of allocations reached.\n");
        return NULL;
    }

    void *ptr = malloc(size);
    if (ptr) {
        allocated_memory[allocation_count++] = ptr;
    } else {
        fprintf(stderr, "Memory allocation failed.\n");
    }
    return ptr;
}

// ft_free_all function to free all allocated memory
void ft_free_all() {
	int	i;
	
	i = 0;
	while (allocated_memory[i])
	{
		free(allocated_memory[i]);
		allocated_memory[i] = NULL; // Clear the pointer
		i++;
	}
	printf("free_all\n");
	// allocation_count = 0;
}