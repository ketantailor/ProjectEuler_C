/*
 * Project Euler - Problem 16: Power Digit Sum
 *
 * Linux: c99 euler-016.c -o euler-016.bin -Wall -Wextra -pedantic
 * Windows: cl /W4 /nologo euler-016.c
 */

#include <inttypes.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define uint64 uint64_t
#define MAX_DIGITS 300

uint64 power_digit_sum(uint64 num);
void double_digit_array(int* digits);

int main(void)
{
    puts("Project Euler - Problem 16: Power Digit Sum");
    float start = (float)clock() / CLOCKS_PER_SEC;

    uint64 ans = power_digit_sum(1000);
    printf("Answer: %" PRIu64 "\n", ans);

    float elapsed = (float)clock() / CLOCKS_PER_SEC - start;
    printf("Completed in %fs\n", elapsed);

    return EXIT_SUCCESS;
}

uint64 power_digit_sum(uint64 num)
{
    int digits[MAX_DIGITS];
    for (int i = 0; i < MAX_DIGITS; i++)
    {
        digits[i] = 0;
    }
    digits[MAX_DIGITS - 1] = 1;

    for (unsigned int n = 0; n < num; n++)
    {
        double_digit_array(digits);
    }

    uint64 sum = 0;
    for (int i = 0; i < MAX_DIGITS; i++)
    {
        sum += digits[i];
    }
    return sum;
}

// Takes an array of digits and doubles the whole number in place
void double_digit_array(int* digits)
{
    int carry[MAX_DIGITS];
    for (unsigned int c = 0; c < MAX_DIGITS; c++)
    {
        carry[c] = 0;
    }

    unsigned int d = MAX_DIGITS - 1;
    while (true)
    {
        int v2 = 2 * digits[d] + carry[d];
        digits[d] = v2 % 10;
        if (d != 0)
        {
            carry[d -1] = v2 / 10;
        }

        if (d == 0) break;
        d--;
    }
}
