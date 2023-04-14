#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *convertToBinary(char *s);
char *convertToBinary(char *s)
{
    int i;
    int j;
    int _strlen = strlen(s);
    int _binarylen = _strlen * (9 + 1);
    char *binary_str = (char *)malloc(sizeof(char)*_binarylen); 


    for (int i = 0; s[i] != '\0'; i++)
    {
        char c = s[i];

        for (j = 0; j < 8; j++)
        {
            int bit = (c >> (7 - j)) & 1;
            binary_str[i * 9 + j] = bit + '0';
            binary_str[i * 9 + j + 1] = '\n';

        }  
    }
    
    binary_str[_strlen * 8] = '\0';
    return binary_str;
}

int main()
{
    char *input_str = "Mohammad is genius"; // the input string to convert to binary
    char *s = convertToBinary(input_str);
    printf("%s\n", s);
    free(s); // free the dynamically allocated memory for the binary string
    return 0;
}
