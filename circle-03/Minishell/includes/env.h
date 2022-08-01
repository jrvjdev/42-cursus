#ifndef ENV_H
# define ENV_H

# include "string.h"

typedef struct s_env t_env;
typedef struct s_node_env t_node_env;

struct s_node_env
{
	char *key;
	char *value;
	t_node_env *prev;
	t_node_env *next;
};

struct s_env
{
	void *(*create)(char *hashmap);
	t_node_env **(*list)(void);
	t_node_env *(*get)(char *key);
};

t_env		_env(void);

t_node_env **_env_list(void);
t_node_env 	*_env_get(char *key);
void 		*_env_create(char *hashmap);

#endif
