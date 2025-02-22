/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otanovic <otanovic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:28:20 by otanovic          #+#    #+#             */
/*   Updated: 2025/02/05 19:54:24 by otanovic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct t_node
{
	struct t_node	*next;
	struct t_node	*prev;
	int				value;
}	t_node;

int	signs_and_spaces(const char *s, int i)
{
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n' || s[i] == '\v'
		|| s[i] == '\f' || s[i] == '\r')
	{
		i++;
	}
	return (i);
}

void	handle_sign(const char *s, int *i, int *sign)
{
	if (s[*i] == '+' || s[*i] == '-')
	{
		if (s[*i] == '-')
			*sign = -1;
		(*i)++;
	}
}

int	ft_atoi(const char *s)
{
	int	i;
	int	num;
	int	sign;

	i = 0;
	num = 0;
	sign = 1;
	i = signs_and_spaces(s, i);
	handle_sign(s, &i, &sign);
	while (s[i] >= '0' && s[i] <= '9')
	{
		if (num > (INT_MAX - (s[i] - '0')) / 10)
		{
			if (sign == 1)
				return (INT_MAX);
			else
				return (INT_MIN);
		}
		num = num * 10 + (s[i] - '0');
		i++;
	}
	return (num * sign);
}

t_node	*ft_initnode(char *num)
{
	t_node	*s;

	s = (t_node *) malloc(sizeof(t_node));
	if (s)
	{
		s->value = ft_atoi(num);
		s->next = NULL;
		s->prev = NULL;
	}
	return (s);
}

void	sa(t_node **head)
{
	t_node	*first;
	t_node	*second;

	if (*head && (*head)->next)
	{
		first = *head;
		second = first->next;
		first->next = second->next;
		if (second->next)
			second->next->prev = first;
		second->prev = NULL;
		second->next = first;
		*head = second;
	}
}

void	sb(t_node **head)
{
	t_node	*first;
	t_node	*second;

	if (*head && (*head)->next)
	{
		first = *head;
		second = first->next;
		first->next = second->next;
		if (second->next)
			second->next->prev = first;
		second->prev = NULL;
		second->next = first;
		*head = second;
	}
}

void	ss(t_node **a, t_node **b)
{
	t_node	*first;
	t_node	*second;

	if (*a && (*a)->next)
	{
		first = *a;
		second = first->next;
		first->next = second->next;
		if (second->next)
			second->next->prev = first;
		second->prev = NULL;
		second->next = first;
		*a = second;
	}
	if (*b && (*b)->next)
	{
		first = *b;
		second = first->next;
		first->next = second->next;
		if (second->next)
			second->next->prev = first;
		second->prev = NULL;
		second->next = first;
		*b = second;
	}
}

void	pa(t_node **a, t_node **b)
{
	t_node	*temp;

	if (*b == NULL)
		return ;
	if (*a == NULL) // might not need this
		return ;
	if ((*b)->next)
		temp = (*b)->next;
	(*b)->next = *a;
	(*a)->prev = *b;
	*a = *b;
	*b = temp;
}

void	pb(t_node **a, t_node **b)
{
	t_node	*temp;

	if (*a == NULL)// might not need this
		return ;
	if (*b == NULL)
		return ;
	if ((*a)->next)
		temp = (*a)->next;
	(*a)->next = *b;
	(*b)->prev = *a;
	*b = *a;
	*a = temp;
}

void	rra(t_node **a)
{
	t_node	*temp;

	if (*a == NULL || (*a)->next == NULL)
		return ; 
	temp = (*a);
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = (*a);
	(*a) = temp;
	temp->prev->next = NULL;
	(*a)->prev = NULL;
}

void	rrb(t_node **a)
{
	t_node	*temp;

	if (*a == NULL || (*a)->next == NULL)
		return ; 
	temp = (*a);
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = (*a);
	(*a) = temp;
	temp->prev->next = NULL;
	(*a)->prev = NULL;
}

void	rrr(t_node **a, t_node **b)
{
	t_node	*temp;

	if (*a == NULL || (*a)->next == NULL)
		return ; 
	temp = (*a);
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = (*a);
	(*a) = temp;
	temp->prev->next = NULL;
	(*a)->prev = NULL;

	if (*b == NULL || (*b)->next == NULL)
		return ; 
	temp = (*b);
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = (*b);
	(*b) = temp;
	temp->prev->next = NULL;
	(*b)->prev = NULL;
}

void	ra(t_node **a)
{
	t_node	*first;
	t_node	*last;

    if (!a || !(*a) || !((*a)->next))
        return ;
	first = *a;
	last = *a;
	while (last->next != NULL)
		last = last->next;
	*a = first->next;
	(*a)->prev = NULL;
	last->next = first;
	first->next = NULL;
}

void	rb(t_node **b)
{
	t_node	*first;
	t_node	*last;

    if (!b || !(*b) || !((*b)->next))
        return ;
	first = *b;
	last = *b;
	while (last->next != NULL)
		last = last->next;
	*b = first->next;
	(*b)->prev = NULL;
	last->next = first;
	first->next = NULL;
}

void	rr(t_node **a, t_node **b)
{
	t_node	*first;
	t_node	*last;

    if (!b || !(*b) || !((*b)->next))
        return ;
	first = *b;
	last = *b;
	while (last->next != NULL)
		last = last->next;
	*b = first->next;
	(*b)->prev = NULL;
	last->next = first;
	first->next = NULL;
	if (!a || !(*a) || !((*a)->next))
        return ;
	first = *a;
	last = *a;
	while (last->next != NULL)
		last = last->next;
	*a = first->next;
	(*a)->prev = NULL;
	last->next = first;
	first->next = NULL;
}

int	main(int argc, char** argv)
{
	t_node	*head;
	t_node	*tail;
	t_node	*new_node;
	int		i;

	head = NULL;
	i = 1;
	while (i <= (argc - 1) && argc >= 1)
	{
		new_node = ft_initnode(argv[i]);
		if (!new_node)
			return (1);
		if (!head)
		{
			head = new_node;
			tail = new_node;
		}
		else
		{
			tail->next = new_node;
			new_node->prev = tail;
			tail = new_node;
		}
		i++;
	}

	t_node	b;
	t_node	c;
	b.prev = NULL;
	b.next = &c;
	c.prev = &b;
	c.next = NULL;
	b.value = 10;
	c.value = 4;
	t_node	*t = &b;

	rr(&head, &t);
	i = 0;
	t_node *current = head;
	while (current)
	{
		printf("%d ", current->value);
		current = current->next;
	}
}
