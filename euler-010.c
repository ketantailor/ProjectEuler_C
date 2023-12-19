/*
 * Project Euler - Problem 10: Summation of primes
 *
 * Linux: c99 euler-010.c -o euler-010.bin -Wall -Wextra -pedantic -lm
 * Windows: cl /W4 /nologo euler-010.c
 */

#include <inttypes.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define uint64 uint64_t

void euler010();
uint64 sum_all_primes(int max);
bool is_prime(uint64 num);

int main(void)
{
    puts("Project Euler - Problem 10: Summation of primes");

    euler010();

    return EXIT_SUCCESS;
}

void euler010()
{
    float start = (float)clock() / CLOCKS_PER_SEC;

    uint64 ans = sum_all_primes(2000000);

    float elapsed = (float)clock() / CLOCKS_PER_SEC - start;
    printf("Answer: %" PRIu64 " (elapsed: %fs)\n", ans, elapsed);
}

uint64 sum_all_primes(int max)
{
    uint64 sum = 0;
    for (int i = 2; i < max; i++)
    {
        if (is_prime(i))
        {
            sum += i;
        }
    }
    return sum;
}

bool is_prime(uint64 num)
{
    if (num == 2) return true;
    if (num % 2 == 0) return false;

    register uint64 i = 3;
    register uint64 range = (uint64)sqrt((double)num);
    while (i <= range)
    {
        if (num % i == 0) return false;
        i += 1;
    }
    return true;
}

