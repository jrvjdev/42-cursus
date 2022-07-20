#include "../../includes/list.h"

int _list_size(void **list)
{
    if ((t_node **)list && *(t_node **)list)
        return (1 + _list_size((void **)(&(*(t_node **)list)->next)));
    else
        return (0);
}
