#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int is_digit_string(char *s)
{
	while (*s)
	{
		if (!isdigit(*s))
			return (0);
		s++;
	}
	return (1);
}

void check_args(int argc, char **argv)
{
	if (argc != 3)
	{
		printf("Error\n");
		exit(98);
	}
	if (!is_digit_string(argv[1]) || !is_digit_string(argv[2]))
	{
		printf("Error\n");
		exit(98);
	}
}

int *multiply(char *num1, char *num2, int *result_len)
{
	int len1 = strlen(num1);
	int len2 = strlen(num2);
	int *result = calloc(len1 + len2, sizeof(int));

	if (!result)
		return (NULL);

	for (int i = len1 - 1; i >= 0; i--)
	{
		for (int j = len2 - 1; j >= 0; j--)
		{
			int mul = (num1[i] - '0') * (num2[j] - '0');
			int p1 = i + j;
			int p2 = i + j + 1;
			int sum = mul + result[p2];

			result[p2] = sum % 10;
			result[p1] += sum / 10;
		}
	}

	*result_len = len1 + len2;
	return (result);
}

void print_result(int *result, int len)
{
	int i = 0;

	while (i < len && result[i] == 0)
		i++;
	if (i == len)
		printf("0");
	else
	{
		for (; i < len; i++)
			printf("%d", result[i]);
	}
	printf("\n");
}

int main(int argc, char *argv[])
{
	int result_len;
	int *result;

	check_args(argc, argv);
	result = multiply(argv[1], argv[2], &result_len);
	if (!result)
		return (1);
	print_result(result, result_len);
	free(result);
	return (0);
}
