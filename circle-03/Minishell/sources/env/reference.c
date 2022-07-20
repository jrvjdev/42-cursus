#include "../../includes/env.h"

t_env _env(void)
{
    static t_env _env = {
        _env_create,
        _env_get,
        _env_list
    };

    return (_env);
}

t_hashmap **_env_list(void)
{
    static t_hashmap *node;

    return (&node);
}
