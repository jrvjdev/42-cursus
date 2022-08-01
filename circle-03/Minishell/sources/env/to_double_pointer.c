#include "../../includes/env.h"

void _env_add(t_node_env *malloc);

char **_env_to_double_pointer(char *string)
{
	t_node_env *env;
	char **double_pointer;

	
	env = *_env().list();
	while (env)
	{
		printf("declare -x %s=\"%s\"\n", env->key, env->value);
		env = env->next;
	}
	return (double_pointer);
}
