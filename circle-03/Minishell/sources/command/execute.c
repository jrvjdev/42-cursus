#include "../../includes/command.h"

void _command_execute(void)
{
	while ((*_command().list()))
		(*_command().list())->function(*_command().list());
}