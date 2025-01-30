


#include <limits.h>

typedef struct stack
{
	int	*value;
	int	size;
};

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

char *ft_initstack(int argc, char **argv)
{
	int *stack;
	int	i;

	i = 0;
	stack = malloc(sizeof(int) * argc);
	while (i <= argc)
	{
		stack[i] = ft_atoi(argv[i]);
		i++;
	}
}

int	main(int argc, char** argv)
{
	char	*args;
	if (argc <= 1)
		return (0);
	args = ft_initistack(argc, argv);

}
