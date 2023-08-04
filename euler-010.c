// Project Euler - Problem 10: Summation of primes
// Compile with: c99 euler-010.c -o euler-010 -Wall -Wextra -pedantic -lm
// Windows: cl /W4 /nologo euler-010.c

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

#define uint64 uint64_t

void euler010();
uint64 brute_force();
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

    uint64 ans = brute_force();

    float elapsed = (float)clock() / CLOCKS_PER_SEC - start;
    printf("Answer: %ld (elapsed: %fs)\n", ans, elapsed);
}

uint64 brute_force()
{
    uint64 sum = 0;
    for (uint64 i = 2; i < 2000000; i++)
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
    register uint64 range = sqrt(num);
    while (i <= range)
    {
        if (num % i == 0) return false;
        i += 1;
    }
    return true;
}

