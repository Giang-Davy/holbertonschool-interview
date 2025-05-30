#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * is_digit_string - Checks if a string contains only digits
 * @s: The string to check
 *
 * Return: 1 if the string contains only digits, 0 otherwise
 */
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

/**
 * check_args - Checks the number of arguments and validates if they are digits
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Exits with status 98 and prints "Error" if validation fails
 */
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

/**
 * multiply - Multiplies two positive number strings
 * @num1: First number string
 * @num2: Second number string
 * @result_len: Pointer to store the length of the result array
 *
 * Return: Pointer to the array holding the multiplication result or NULL on failure
 */
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

/**
 * print_result - Prints the multiplication result skipping leading zeros
 * @result: Pointer to the result array
 * @len: Length of the result array
 */
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

/**
 * main - Entry point, validates arguments, multiplies numbers and prints result
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Return: 0 on success, 1 on memory allocation failure
 */
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
