#include "../../includes/list.h"

int _list_add_node(void **list, void *node)
{
	// _command_add((t_node **)list, (t_node *)node);
	if (!(t_node **)list)
		return (0);
	if (*((t_node **)list))
	{
		if (_list_add_node((void **)(&((*((t_node **)list))->next)), node))
			((t_node *)node)->prev = (*(t_node **)list);
		return (0);
	}
	else
	{
		*((t_node **)list) = (t_node *)node;
		return (1);
	}
	// return (1);
}
