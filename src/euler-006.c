/*
 * Project Euler - Problem 06: Sum square difference
 *
 * Linux: c99 euler-006.c -o euler-006.bin -Wall -Wextra -pedantic
 * Windows: cl /W4 /nologo euler-006.c
 */

#include <inttypes.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define uint64 uint64_t

void euler006();
uint64 sum_square_difference(int num);
uint64 sum_of_squares(int n);
uint64 square_of_sums(int n);
uint64 square_of_sums_2(int n);

int main(void)
{
    puts("Project Euler - Problem 06: Sum square difference");

    euler006();

    return EXIT_SUCCESS;
}

void euler006()
{
    uint64 ans = sum_square_difference(100);
    printf("Answer: %" PRIu64 "\n", ans);
}

uint64 sum_square_difference(int num)
{
    uint64 s1 = sum_of_squares(num);
    uint64 s2 = square_of_sums_2(num);
    return s2 - s1;
}

uint64 sum_of_squares(int n)
{
    uint64 ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans += i*i;
    }
    return ans;
}

uint64 square_of_sums(int n)
{
    uint64 sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += i;
    }
    uint64 ans = sum * sum;
    return ans;
}

uint64 square_of_sums_2(int n)
{
    // (1+2+...+99+100)^2 = (101*50)^2
    uint64 sum = (n+1) * (n/2);
    uint64 ans = sum * sum;
    return ans;
}
