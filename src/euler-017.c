/*
 * Project Euler - Problem 17: Number Letter Counts
 *
 * Linux: c99 euler-017.c -o euler-017.bin -Wall -Wextra -pedantic
 * Windows: cl /W4 /nologo euler-017.c
 */

#include <inttypes.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


#define uint64 uint64_t


char *numbers_small[] =
{
    "", "one", "two", "three", "four", "five",
    "six", "seven", "eight", "nine", "ten",
    "eleven", "twelve", "thirteen", "fourteen", "fifteen", 
    "sixteen", "seventeen", "eighteen", "nineteen"
};

char *numbers_tens[] =
{
    "", "", "twenty", "thirty", "forty", "fifty",
    "sixty", "seventy", "eighty", "ninety"
};

uint64 sum_number_letter_count(int num);
uint64 number_letter_count(int num);


int main(void)
{
    puts("Project Euler - Problem 17: Number Letter Counts");
    float start = (float)clock() / CLOCKS_PER_SEC;

    uint64 ans = sum_number_letter_count(1000);
    printf("Answer: %" PRIu64 "\n", ans);

    float elapsed = (float)clock() / CLOCKS_PER_SEC - start;
    printf("Completed in %fs\n", elapsed);

    return EXIT_SUCCESS;
}


uint64 sum_number_letter_count(int num)
{
    uint64 sum = 0;
    for (int i = 0; i <= num; i++)
    {
        sum += number_letter_count(i);
    }
    return sum;
}


uint64 number_letter_count(int num)
{
    int single = num % 10;
    int ten = num % 100 - single;
    int hundred = num % 1000 - ten - single;
    int thousand = num % 10000 - hundred - ten - single;

    uint64 count = 0;

    if (thousand > 0)
    {
        count += number_letter_count(thousand / 1000) + strlen("thousand");
    }
    
    if ((thousand != 0 || hundred != 0) && (ten != 0 || single != 0))
    {
        count += strlen("and");
    }

    if (hundred != 0)
    {
        count += number_letter_count(hundred / 100) + strlen("hundred");
    }

    if (ten == 10)
    {
        count += strlen(numbers_small[10 + single]);
    }
    else
    {
        count += strlen(numbers_tens[ten / 10]);
        count += strlen(numbers_small[single]);
    }

    return count;
}
