/*
 * Project Euler - Problem 09: Special Pythagorean triplet
 *
 * Linux: c99 euler-009.c -o euler-009.bin -Wall -Wextra -pedantic
 * Windows: cl /W4 /nologo euler-009.c
 */

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LIMIT 1000

void euler009();
int calculate_triplet();

int main(void)
{
    puts("Project Euler - Problem 09: Special Pythagorean triplet");

    euler009();

    return EXIT_SUCCESS;
}

void euler009()
{
    float start = (float)clock() / CLOCKS_PER_SEC;

    int ans = calculate_triplet();

    float elapsed = (float)clock() / CLOCKS_PER_SEC - start;
    printf("Answer: %d (elapsed: %fs)\n", ans, elapsed);
}

int calculate_triplet()
{
    for (int a = 2; a <= LIMIT; a++)
    {
        for (int b = a + 1; b <= LIMIT; b++)
        {
            int c = 1000 - a - b;
            if (a * a + b * b == c * c)
            {
                return a * b * c;
            }
        }
    }
    return 0;
}
