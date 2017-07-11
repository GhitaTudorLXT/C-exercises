#include <stdio.h>
#include <stdlib.h>

typedef struct stack stack;

struct stack
{
	int *elements;
	int top;
	int size;
};

int is_digit(char c)
{
	return c >= '0' && c <= '9' ? 1 : 0;
}

int is_operator(char c)
{
	switch (c)
	{
		case ('+'):
		case ('-'):
		case ('*'):
		case ('/'):
		case ('%'):
			return 1;
			break;
		default:
			return 0;
	}
}

int get_operand(char *input)
{
	char aux;
	int i = 0;
	int operand;

	while (is_digit(input[i]))
		i++;

	aux = input[i];
	input[i] = '\0';
	operand = atoi(input);
	input[i] = aux;

	return operand;
}

int main()
{
	stack operands;
	operands.elements = (int*)malloc(100);
	operands.size = 100;
	operands.top = -1;

	char *input = (char*)malloc(128);
	size_t size = 128;

	int sign = 0;
	int divbz = 0;

	getline(&input, &size, fdopen(0, "r"));

	while (1)
	{
		if (*input == '\0' || *input == '\n') break;

		while (*input == ' ' || *input == '\t')
			input++;

		if (is_digit(*input))
		{
			operands.elements[++operands.top] = get_operand(input);

			if (sign)
			{
				operands.elements[operands.top] *= -1;
				sign = 0;
			}
		}

		if (is_operator(*input))
		{
			/*
			* Checking if the - sign is actually representing the negative of a number and not an operator
			*/
			if (*input == '-' && is_digit(*(input + 1)))
			{
				sign = 1;
				input++;
				continue;
			}

			int operand_2 = operands.elements[operands.top--];
			int operand_1 = operands.elements[operands.top--];

			int result;

			switch (*input)
			{
				case ('+'):
					result = operand_1 + operand_2;
					break;
				case ('-'):
					result = operand_1 - operand_2;
					break;
				case ('*'):
					result = operand_1 * operand_2;
					break;
				case ('/'):
					if (operand_2 == 0) 
					{
						divbz = 1;
						break;
					}
					result = operand_1 / operand_2;
					break;
				case ('%'):
					result = operand_1 % operand_2;
					break;
			}

			if (divbz) break;

			operands.elements[++operands.top] = result;
		}

		while (*input != ' ' && *input != '\t' && *input != '\0')
			input++;
	}

	if (!divbz)
		printf("Result: %d\n", operands.elements[operands.top]);
	else
		printf("Divide by zero error!\n");

	free(operands.elements);

	return 0;
}