
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

void	*ft_malloc(size_t size, int free)
{
	static void	**ptrs_list;
	static int	i;
	void		*ptr;


	if (free)
	{
		ft_free_all(ptrs_list);
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
	
	return (ptr);
}
