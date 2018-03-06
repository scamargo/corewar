#include "libft.h"
#include <stdio.h>

void delete_node(void *content, size_t content_size)
{
	free(content);
}	

int main(void)
{
	 //char *str1 = malloc(2);
	//str1 = "1";
	// create node
	t_doubly *head = ft_doublynew("1", sizeof(2));
	t_doubly *second = ft_doublynew("2", sizeof(2));
	ft_doublyadd(&head, second);
	t_doubly *third = ft_doublynew("3", sizeof(2));
	ft_doublyadd(&head, third);
	printf("head: %s, head->next:%s, head->prev:%s\n", (char*)head->content, (char*)head->next->content, (char*)head->prev);
	ft_doublydelone(&second, delete_node);
	printf("head: %s, head->next:%s\n", (char*)head->content, (char*)head->next->content);
	// add node
	// delete node
}
