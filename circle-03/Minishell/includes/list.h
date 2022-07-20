#ifndef DOBLY_LINKED_LIST_H
#define DOBLY_LINKED_LIST_H

typedef struct s_node t_node;
typedef struct s_list t_list;

struct s_node
{
	t_node *prev;
	t_node *next;
};

struct s_list
{
	int (*size)(void **list);
	int (*add_node)(void **list, void *node);
	void (*remove_node)(void **list, void *node);
};

t_list _list(void);

int _list_size(void **list);
int _list_add_node(void **list, void *node);
void _list_remove_node(void **list, void *node);

#endif // DOBLY_LINKED_LIST_H