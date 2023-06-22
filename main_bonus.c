#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "colors.h"

typedef struct s_list
{
	char *data;
	struct s_list *next;
} t_list;

void ft_list_push_front(t_list **, void *);
int ft_list_size(t_list *begin_list);

void printf_list(t_list *list)
{
	int i = 0;
	while (list)
	{
		printf(YEL "%d:" GRN " %s\n" CRESET,
			   i, list->data);
		list = list->next;
		i++;
	}
}

#define COLOR_VALUE(S) "`" GRN S CRESET "`"
#define PRINT_ADD_LIST(ELEM) printf("added: " COLOR_VALUE("%s") " (current=" COLOR_VALUE("%p") " : next=" COLOR_VALUE("%p") ")\n", \
									ELEM->data, ELEM, ELEM->next)

int main()
{
	t_list list;
	t_list list_next;
	t_list list_last;
	list.data = strdup("toto");
	list.next = &list_next;
	list_next.data = strdup("bar");
	list_next.next = &list_last;
	list_last.data = strdup("monkaS");
	list_last.next = NULL;

	printf(BLU "\n# ft_list_push_front\n" CRESET);
	printf(BLK "## default list\n" CRESET);
	t_list *push_test = &list;
	ft_list_push_front(&push_test, strdup("Bouuuh"));
	PRINT_ADD_LIST(push_test);
	printf("new list size: " COLOR_VALUE("%d") "\n", ft_list_size(push_test));
	printf_list(push_test);
	// Clean old list
	free(list.data);
	free(push_test->data);
	free(push_test);
	push_test = NULL;

	printf(BLK "\n## to empty list\n" CRESET);
	ft_list_push_front(&push_test, strdup("barbar"));
	PRINT_ADD_LIST(push_test);
	printf(BLK "### Push null\n" CRESET);
	ft_list_push_front(&push_test, NULL);
	PRINT_ADD_LIST(push_test);
	printf_list(push_test);
	printf("new list size: " COLOR_VALUE("%d") "\n", ft_list_size(push_test));
}