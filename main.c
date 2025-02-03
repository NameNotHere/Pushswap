/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otanovic <otanovic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:28:20 by otanovic          #+#    #+#             */
/*   Updated: 2025/02/03 15:55:17 by otanovic         ###   ########.fr       */
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

int	main(int argc, char** argv)
{
	t_node	*head;
	t_node	*tail;
	t_node	*new_node;
	int		i;

	head = NULL;
	i = 1;
	if (argc <= 1)
		return (0);
	while (i <= (argc - 1))
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
	i = 0;
    t_node *current = head;
    while (current)
    {
        printf("%d ", current->value);
        current = current->next;
    }
}
