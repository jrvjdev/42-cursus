#include "../includes/minishell.h"
/* FOR DEBUGGING */
void	print_arrays(char **a)
{
  int i;

  i = 0;
	while(a[i])
  {
    // if (a[i])
    //  if (ft_strlen(a[i]) == 0)
    //   break;
	  printf("%s\n", a[i++]);
  }
}

