#include "push_swap.h"

static int *find_the_lis(int *lis, int *temp_array, int stack_len)
{
    int i;
    int j;

    i = 0;
    while (i < stack_len)
    {
        j = 0;
        while (j < i)
        {
            if (temp_array[i] > temp_array[j] && lis[j] + 1 > lis[i])
                lis[i] = lis[j] + 1;
            j++;
        }
        i++;
    }
    return (lis);
}

static void find_max_lis(int *lis, int *max, int stack_len, int *index)
{
    int i;

    i = 0;
    while (i < stack_len)
    {
        if (lis[i] > *max)
        {
            *max = lis[i];
            *index = i;
        }
        i++;
    }
}

static int *fill_and_compare_lis(int *final_lis, int *lis, int *temp_array, int max_index, int max_lis, int stack_len)
{
    int i = max_index;

    while (max_lis > 0)
    {
        if (lis[i] == max_lis)
        {
            final_lis[max_lis - 1] = temp_array[i];
            max_lis--;
        }
        i--;
        if (i < 0) // Loop back to the end of the array
            i = stack_len - 1;
    }
    return (final_lis);
}

static int *extend_lis_circular(int *final_lis, int *temp_array, int max_index, int stack_len, int lis_size)
{
    int i = (max_index + 1) % stack_len;
    int k = lis_size;

    while (i != max_index)
    {
        if (temp_array[i] > final_lis[lis_size - 1])
        {
            final_lis = realloc(final_lis, sizeof(int) * (k + 1));
            final_lis[k++] = temp_array[i];
        }
        i = (i + 1) % stack_len;
    }
    return final_lis;
}

void init_array(int stack_len, t_stack *iter, int *temp_array, int *lis)
{
    int i;

    i = 0;
    while (i < stack_len && iter)
    {
        temp_array[i] = iter->value;
        lis[i] = 1;
        i++;
        iter = iter->next;
    }
}

int *get_lis(t_stack **stack, int stack_len, int *lis_size)
{
    t_stack *iter;
    int *lis;
    int *temp_array;
    int *final_lis;
    int max_lis;
    int max_index;

    max_lis = 0;
    max_index = 0;
    iter = *stack;
    lis = malloc(sizeof(int) * stack_len);
    temp_array = malloc(sizeof(int) * stack_len);
    if (!lis || !temp_array)
        return (NULL);
    init_array(stack_len, iter, temp_array, lis);
    lis = find_the_lis(lis, temp_array, stack_len);
    find_max_lis(lis, &max_lis, stack_len, &max_index);
    final_lis = malloc(sizeof(int) * max_lis);
    if (!final_lis)
        return (NULL);
    final_lis = fill_and_compare_lis(final_lis, lis, temp_array, max_index, max_lis, stack_len);
    *lis_size = max_lis;
    final_lis = extend_lis_circular(final_lis, temp_array, max_index, stack_len, *lis_size);
    *lis_size = 0;
    while (final_lis[*lis_size])
        (*lis_size)++;
    return (free(temp_array), free(lis), final_lis);
}
