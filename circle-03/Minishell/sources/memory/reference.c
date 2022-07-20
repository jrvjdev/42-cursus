#include "../../includes/memory.h"

t_memory _memory(void)
{
    static t_memory _memory = {
        _memory_free_all,
        _memory_list,
        _memory_free,
        _memory_malloc,
        _memory_realloc,
        _memory_calloc,
        _memory_set,
        _memory_copy};

    return (_memory);
}

t_malloc **_memory_list(void)
{
    static t_malloc *command;

    return (&command);
}
