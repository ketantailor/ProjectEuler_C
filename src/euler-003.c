/*
 * Project Euler - Problem 03: Largest prime factor
 *
 * Linux: c99 euler-003.c -o euler-003.bin -Wall -Wextra -pedantic -lm
 * Windows: cl /W4 /nologo euler-003.c
 */

#include <inttypes.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define u64 uint64_t

void euler003(void);
u64 largest_prime_factor(u64 n);
bool is_prime(u64 num);

int main(void)
{
    puts("Project Euler - Problem 03: Largest prime factor");

    euler003();

    return EXIT_SUCCESS;
}

void euler003(void)
{
    u64 ans = largest_prime_factor(600851475143);
    printf("Answer: %" PRIu64 "\n", ans);
}

// Return the largest prime factor
u64 largest_prime_factor(u64 n)
{
    u64 start = llroundl(sqrtl((long double)n));
    for (u64 i = start; i >= 2; i--)
    {
        if (n % i == 0)
        {
            if (is_prime(i))
            {
                return i;
            }
        }
    }
    return 0;
}

// Returns true if num is prime
bool is_prime(u64 num)
{
    u64 limit = llroundl(sqrtl((long double)num));
    for (u64 i = 2; i <= limit; i++)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}
