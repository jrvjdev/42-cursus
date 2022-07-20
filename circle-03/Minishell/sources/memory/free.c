#include "../../includes/memory.h"

t_malloc *_memory_check(t_malloc **list, void *ptr)
{
    if (list && *list && ptr)
    {
        if (ptr == (*list)->ptr)
            return (*list);
        return (_memory_check(&(*(t_malloc **)list)->next, ptr));
    }
    return (NULL);
}

int _memory_free(void *ptr)
{
    t_malloc *node;

    node = _memory_check(_memory().mallocs(), ptr);
    if (ptr && node)
    {
        _list().remove_node((void **)_memory().mallocs(), node);
        free(node->ptr);
        free(node);
        return (1);
    }
    return (0);
}

int _memory_free_all(void)
{
    if (*_memory().mallocs())
        return (_memory().free(*_memory().mallocs()) + _memory().free_all());
    return (0);
}