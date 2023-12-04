#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int convert(string input);

int main(void)
{
    string input = get_string("Enter a positive integer: ");

    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if (!isdigit(input[i]))
        {
            printf("Invalid Input!\n");
            return 1;
        }
    }

    printf("%i\n", convert(input));
}

int convert(string input)
{
    int length = strlen(input);
    if (length == 0)
    {
        return 0;
    }

    int lastDigit = input[length - 1] - '0';  // Convert char to int
    input[length - 1] = '\0';  // Remove the last character

    return convert(input) * 10 + lastDigit;
}
