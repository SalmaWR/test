#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


char *binaryToStr(char *binary_str)
{
	char char_counter;
	int len = strlen(binary_str);
	int str_len = (len / 8) + 1;

	if (len % 8 != 0)
	{
		printf("go and kill yourself");
		return NULL;
	}

	char *char_str = malloc(sizeof(char) * str_len);
	if (char_str == NULL)
	{
		printf("Failed to allocate memory\n");
		return NULL;
	}

	for (int i = 0; i < str_len; i++)
	{
		char_counter = 0;
		for (int power_of_n = 7; power_of_n >= 0; power_of_n--)
		{
			if (binary_str[i * 8 + power_of_n] == '1')
			{
				char_counter += 1 << (7 - power_of_n);
			}
		}
		char_str[i] = char_counter;
	}

	char_str[str_len] = '\0';
	return char_str;
}

int main()
{
	char *binary_str = "10110010101011100001011010000110101101101011011010000110001001100000010010010110110011100000010011001110101101101000011001001110001011100000010000010110100001100001011010000110000101101000011000010110000101101000011000010110000101101000011000010110";
	char *char_str = binaryToStr(binary_str);
	printf("%s\n", char_str);
	free(char_str);
	return 0;
}
