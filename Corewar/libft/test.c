#include "includes/libft.h"
#include <stdio.h>

void	delete_process(void *process, size_t size)
{
	free(process);
	size = 0;
}

int main()
{
	t_doubly *head;
	//t_doubly *new;
	char	str[2] = "0";
	//int i = 0;
	
	head = ft_doublynew(str, 2);
	ft_doublydelone(&head, delete_process);
	/*while (i < 50)
	{
		str[0] = i + 1 + '0';
		new = ft_doublynew(str, 2);
		ft_doublyadd(&head, new);
		i++;
	}
	while (head != NULL)
	{
		printf("%s\n",(char*)head->content);
		head = head->next;
	}*/
}
