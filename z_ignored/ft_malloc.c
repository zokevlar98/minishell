#include <stdio.h>
#include <stdlib.h>

#define MAX_ALLOCATIONS 1000

// Global array to store allocated memory addresses
void *allocated_memory[MAX_ALLOCATIONS];
int allocation_count = 0;

// ft_malloc function to allocate memory and store the address
void* ft_malloc(size_t size) {
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
    for (int i = 0; i < allocation_count; i++) {
        free(allocated_memory[i]);
        allocated_memory[i] = NULL; // Clear the pointer
    }
    allocation_count = 0;
}

int main() {
    // Example usage
    char *str = (char *)ft_malloc(100 * sizeof(char));
    if (str) {
        snprintf(str, 100, "Hello, World!");
        printf("%s\n", str);
    }

    int *arr = (int *)ft_malloc(50 * sizeof(int));
    if (arr) {
        for (int i = 0; i < 50; i++) {
            arr[i] = i;
            printf("%d ", arr[i]);
        }
        printf("\n");
    }

    // Free all allocated memory
    ft_free_all();

    return 0;
}
