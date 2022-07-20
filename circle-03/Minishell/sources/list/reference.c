#include "../../includes/memory.h"

t_list _list(void)
{
    static t_list _list = {
        _list_size,
        _list_add_node,
        _list_remove_node,
    };

    return (_list);
}
