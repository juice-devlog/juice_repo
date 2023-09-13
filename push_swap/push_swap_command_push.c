#include "./push_swap.h"

void	pa(t_stack *a, t_stack *b)
{
	t_node *top_b;

	top_b = b->top;
	b->top = top_b->next;
	top_b->next = a->top;
	a->top = top_b;
}

void pb(t_stack *a, t_stack *b)
{
	t_node *top_a;

	// t_node *a_check;
	// t_node *b_check;

	// a_check = a->top;
	// b_check = b->top;

	if (a->top)
	{
		top_a = a->top;
		a->top = top_a->next;
		top_a->next = b->top;
		b->top = top_a;
		if (!b->bottom)
			b->bottom = top_a;
	}

	printf("pb a->top %d\n", a->top->data);
	//printf("a->top %d\n", a->top->next->data);
	//printf("a->top %d\n", a->top->next->next->data);

	//printf("a->top %d\n" , a->top->next->next->next->data);
	printf("pb b->top %d\n", b->top->data);
	write(1, "pb\n", 3);
	// while (a_check->next)
	// {
	// 	printf("a->top pb: %d\n", a_check->data);
	// 	a_check = a_check->next;
	// }
	// while (b_check->next)
	// {
	// 	printf("b->top pb: %d\n", b_check->data);
	// 	b_check = b_check->next;
	// }
	// }
}