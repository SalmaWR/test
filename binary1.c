#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

char *convertToBinary(char *s)
{
	int i;
	int j;
	int _strlen = strlen(s);
	int _binarylen = _strlen * 8;
	char *binary_str = (char *)malloc(sizeof(char) * _binarylen + 1);

	for (i = 0; s[i] != '\0'; i++)
	{
		char c = s[i];

		for (j = 7; j >= 0; j--)
		{

			if (c % 2 == 0)
			{
				binary_str[i * 8 + j] = '0';
			}
			else
			{
				binary_str[i * 8 + j] = '1';
			}

			c = c / 2;
			
		}

	}
	
	binary_str[_strlen * 8] = '\0';
	return binary_str;
}

int main()
{
	int fd;
	int fwrite;
	fd = open("plan.txt",O_RDONLY);
	char buffer[1024];
	read (fd,buffer,1024);
	char *input_str = NULL;
	char *s = convertToBinary(buffer);
	printf("%s\n", s);
	printf("%s", buffer);
	free(s);
	
	return 0;
}
