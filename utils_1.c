#include "push_swap.h"
#include <limits.h>

t_node  *new_node(int value)
{
    t_node *node = malloc(sizeof(t_node));
    if (!node)
        return (NULL);
    node->value = value;
    node->next = NULL;
    return (node);
}

void    free_stack(t_stack *stack)
{
    t_node *tmp;
    while (stack->top)
    {
        tmp = stack->top;
        stack->top = tmp->next;
        free(tmp);
    }
}

int     is_sorted(t_stack *a)
{
    t_node *current = a->top;
    
    if (!current)
        return (1);
        
    while (current->next)
    {
        if (current->value > current->next->value)
            return (0);
        current = current->next;
    }
    return (1);
}

static int  is_duplicate(t_stack *a, int value)
{
    t_node *current = a->top;
    while (current)
    {
        if (current->value == value)
            return (1);
        current = current->next;
    }
    return (0);
}

static int	ft_atoi_check(const char *str, int *error)
{
    long	result;
    int		sign;
    int		i;

    result = 0;
    sign = 1;
    i = 0;
    
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            sign = -1;
        i++;
    }
    
    if (!str[i])
    {
        *error = 1;
        return (0);
    }
    
    while (str[i])
    {
        if (str[i] < '0' || str[i] > '9')
        {
            *error = 1;
            return (0);
        }
        result = result * 10 + (str[i++] - '0');
        if ((sign == 1 && result > INT_MAX) || 
            (sign == -1 && result * sign < INT_MIN))
        {
            *error = 1;
            return (0);
        }
    }
    
    *error = 0;
    return ((int)(result * sign));
}

int     parse_input(t_stack *a, int argc, char **argv)
{
    int error;
    int value;

    for (int i = 1; i < argc; i++)
    {
        if (argv[i][0] == '\0')
            return (0);
            
        value = ft_atoi_check(argv[i], &error);
        if (error)
            return (0);
            
        if (is_duplicate(a, value))
            return (0);
            
        t_node *new = new_node(value);
        if (!new)
            return (0);
            
        // Inserting at the end to maintain original order
        if (!a->top)
        {
            a->top = new;
        }
        else
        {
            t_node *last = a->top;
            while (last->next)
                last = last->next;
            last->next = new;
        }
        a->size++;
    }
    return (1);
}