#include "push_swap.h"

void print_ab(t_stack *a, t_stack *b)
{
	printf("a: ");
	t_node *cur = a->top;
	while (cur)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("\nb: ");
	cur = b->top;
	while (cur)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("\n");
}