#include "./push_swap.h"

t_node *create_new_node(int n)
{
	t_node *new;
	new = (t_node *)malloc(sizeof(t_node));
	new->data = n;
	new->next = 0;
	return (new);
}

int main(int argc, char **argv)
{
	t_node *cur;
	t_stack *a;
	t_stack *b;

	int arr[10] = {9, 8, 7, 10, 2, 1, 5, 6, 3, 4};
	a = (t_stack *)malloc(sizeof(t_stack));
	b = (t_stack *)malloc(sizeof(t_stack));
	int i = 0;
	a->top = create_new_node(arr[i++]);
	cur = a->top;
	while (i < 10)
	{
		cur->next = create_new_node(arr[i++]);
		cur = cur->next;
	}
	a->bottom = cur;
	b->top = 0;
	b->bottom = 0;
	a_to_b(a, b, 10);
	printf("a: ");
	cur = a->top;
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