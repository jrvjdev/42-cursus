#include "../../includes/list.h"

void _list_remove_node(void **list, void *node)
{
	// _command_free((t_node **)list, (t_node *)node);
	if (!(t_node **)list || !*((t_node **)list) || !((t_node *)node))
		return;
	if (*((t_node **)list) == ((t_node *)node))
		*((t_node **)list) = ((t_node *)node)->next;
	if (((t_node *)node)->next)
		((t_node *)node)->next->prev = ((t_node *)node)->prev;
	if (((t_node *)node)->prev)
		((t_node *)node)->prev->next = ((t_node *)node)->next;
	return;
}