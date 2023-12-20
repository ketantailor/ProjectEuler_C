/*
 * Project Euler - Problem 07: 10001st prime
 *
 * Linux: c99 euler-007.c -o euler-007.bin -Wall -Wextra -pedantic
 * Windows: cl /W4 /nologo euler-007.c
 */

#include <inttypes.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define u64 uint64_t

void euler007();
u64 nth_prime(int n);
bool is_prime(u64 num);
bool is_prime_2(u64 num);

int main(void)
{
    puts("Project Euler - Problem 07: 10001st prime");

    euler007();

    return EXIT_SUCCESS;
}

void euler007()
{
    float start = (float)clock() / CLOCKS_PER_SEC;

    u64 ans = nth_prime(10001);

    float elapsed = (float)clock() / CLOCKS_PER_SEC - start;

    printf("Answer: %" PRIu64 " (elapsed: %fs)\n", ans, elapsed);
}

u64 nth_prime(int n)
{
    int prime_count = 0;
    for (u64 i = 2; i < 1000000000; i++)
    {
        if (is_prime_2(i) == true)
        {
            prime_count++;
            if (prime_count == n)
            {
                return i;
            }
        }
    }
    return 0;
}

bool is_prime(u64 num)
{
    for (u64 x = 2; x < num; x++)
    {
        if (num % x == 0)
            return false;
    }
    return true;
}

bool is_prime_2(u64 num)
{
    if (num == 2)
        return true;
    if (num % 2 == 0)
        return false;

    u64 i = 3;
    u64 range = (u64)sqrt((double)num);
    while (i <= range)
    {
        if (num % i == 0)
            return false;
        i += 1;
    }
    return true;
}
