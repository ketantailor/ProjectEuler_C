/*
 * Project Euler - Problem 04: Largest palindrome product
 *
 * Linux: c99 euler-004.c -o euler-004.bin -Wall -Wextra -pedantic
 * Windows: cl /W4 /nologo euler-004.c
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void euler004();
int largest_palindrome_product();
bool is_palindromic(int num);

int main(void)
{
    puts("Project Euler - Problem 04: Largest palindrome product");

    euler004();

    return EXIT_SUCCESS;
}

void euler004()
{
    int ans = largest_palindrome_product();
    printf("Answer: %i\n", ans);
}

int largest_palindrome_product()
{
    // int max_a = 0, max_b = 0;
    int max_product = 0;
    for (int a = 10; a < 1000; a++)
    {
        for (int b = 10; b < 1000; b++)
        {
            int n = a * b;

            if (n > max_product && is_palindromic(n))
            {
                // max_a = a;
                // max_b = b;
                max_product = a * b;
            }
        }
    }
    return max_product;
}

// Returns true if num reads the same both ways, e.g. 12321.
bool is_palindromic(int num)
{
    int n = num, r = 0;
    while (n > 0)
    {
        while (n % 10 != 0)
        {
            n--;
            r++;
        }
        n /= 10;
        r *= 10;
    }

    r /= 10;

    return num == r;
}
