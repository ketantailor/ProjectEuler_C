/*
 * Project Euler - Problem 12: Highly divisible triangular number
 *
 * Linux: c99 euler-012.c -o euler-012.bin -Wall -Wextra -pedantic -lm
 * Windows: cl /W4 /nologo euler-012.c
 */

#include <inttypes.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define uint64 uint64_t

void euler012();
uint64 calculate_first_triangle_number(uint64 num);
uint64 calculate_triangle_number(uint64 index);
uint64 calculate_triangle_number_2(uint64 num);
uint64 calculate_divisor_count(uint64 num);
uint64 calculate_divisor_count_2(uint64 num);
uint64 calculate_divisor_count_3(uint64 num);

int main(void)
{
    puts("Project Euler - Problem 12: Highly divisible triangular number");

    euler012();

    return EXIT_SUCCESS;
}

void euler012()
{
    float start = (float)clock() / CLOCKS_PER_SEC;

    uint64 ans = calculate_first_triangle_number(500);

    float elapsed = (float)clock() / CLOCKS_PER_SEC - start;
    printf("Answer: %" PRIu64 " (elapsed: %fs)\n", ans, elapsed);
}

// Find first triangle number with more than min_divisors divisors
uint64 calculate_first_triangle_number(uint64 min_divisors)
{
    uint64 i = 76576499;
    uint64 ans = 0;
    while (true)
    {
        // uint64 tri = calculate_triangle_number(num);
        // uint64 divisors = calculate_divisor_count_2(tri);
        // if (divisors > 500) break;
        // num++;

        if (i % 2 == 0)
        {
            ans = calculate_divisor_count_3(i / 2) * calculate_divisor_count_3(i + 1);
        }
        else
        {
            ans = calculate_divisor_count_3(i) * calculate_divisor_count_3((i + 1) / 2);
        }

        if (ans > min_divisors)
            return i;

        i++;
    }
    return i;
}

uint64 calculate_triangle_number(uint64 num)
{
    uint64 sum = 0;
    for (uint64 i = 1; i <= num; i++)
    {
        sum += i;
    }
    return sum;
}

uint64 calculate_triangle_number_2(uint64 num)
{
    return (num + 1) * (num) / 2;
}

uint64 calculate_divisor_count(uint64 num)
{
    uint64 count = 0;
    for (uint64 i = num; i >= 1; i--)
    {
        if (num % i == 0)
            count++;
    }
    return count;
}

uint64 calculate_divisor_count_2(uint64 num)
{
    uint64 count = 0;
    uint64 limit = (uint64)sqrt((double)num);
    for (uint64 i = 1; i <= limit; i++)
    {
        if (num % i == 0)
            count++;
    }
    return count;
}

uint64 calculate_divisor_count_3(uint64 num)
{
    uint64 count = 0;
    for (uint64 i = 1; i * i <= num; i++)
    {
        if (i % 2 == 0)
        {
            count += 2;
            if (num / i == i)
                count--;
        }
    }
    return count;
}
