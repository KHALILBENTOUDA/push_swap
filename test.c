#include <libc.h>

typedef struct s_new
{
    int value;
    struct s_new *next;
    struct s_new *prev;
} t_new;

t_new *add_new_node(int content, t_new *last)
{
    t_new *node;

    node = malloc(sizeof(t_new));
    if (!node)
        return (NULL);
    node -> value = content;
    node -> next = NULL;
    if (last == NULL)
        printf("%d", last->value);
    else
    {
        while (last)
        {
            last = last->next;
        }
    }
    return (node);
}

// void fill_stack(t_new **a, char **content)
// {
//     int i;
//     t_new *last_node;
//     t_new *new_node;

//     i = 1;
//     last_node = NULL;
//     while(content[i])
//     {
//         new_node = add_new_node(ft_atoi(content[i]));
//         if (*a)
//         {
//             last_node = *a;
//             while(last_node->next)
//                 last_node = last_node->next;
//             last_node->next = new_node;
//         }
//         else
//             *a = new_node;
//         i++;
//     }
// }

int main()
{
    t_new *array;
    t_new *list;

    array = add_new_node(11,array);
    array -> next = add_new_node(13,array);
    array -> next -> next = add_new_node(21,array);
    array -> next -> next -> next = add_new_node(3,array);

    while (array)
    {
        list = array;
        while (list)
        {
            if (array->value < list->value)
            {
                printf("%d   ->  %d\n",array->value, list->value);
                break;
            }
            else if(list->value && list->next == NULL)
                printf("%d   ->  %d\n",array->value, -1);
            list = list ->next;
        }
        array = array->next;
    }
    return (0);
}