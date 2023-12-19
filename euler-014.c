/*
 * Project Euler - Problem 14: Longest Collatz Sequence
 *
 * Linux: c99 euler-014.c -o euler-014.bin -Wall -Wextra -pedantic
 * Windows: cl /W4 /nologo euler-014.c
 */

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int get_longest_collatz_sequence_count(int max);
int get_collatz_sequence_count(int num);

int main(void)
{
    puts("Project Euler - Problem 14: Longest Collatz Sequence");
    float start = (float)clock() / CLOCKS_PER_SEC;

    int ans = get_longest_collatz_sequence_count(1000000);
    printf("Answer: %i\n", ans);

    float elapsed = (float)clock() / CLOCKS_PER_SEC - start;
    printf("Completed in %fs\n", elapsed);

    return EXIT_SUCCESS;
}

// Returns the max length of all Collatz sequences for all numbers below num
int get_longest_collatz_sequence_count(int max)
{
    int max_num = INT_MAX;
    int max_seq = INT_MIN;

    for (int i = max; i > 0; i--)
    {
        int count = get_collatz_sequence_count(i);
        if (count > max_seq)
        {
            max_num = i;
            max_seq = count;
        }
    }

    return max_num;
}

// Returns the length of the Collatz sequence for num
int get_collatz_sequence_count(int num)
{
    long n = num;
    int count = 0;
    while (n != 1)
    {
        if (n % 2 == 0)
            n /= 2;
        else
            n = 3 * n + 1;
        count++;
    }
    return count;
}
