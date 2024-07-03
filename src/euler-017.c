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
#include <time.h>


#define uint64 uint64_t


uint64 sum_number_letter_count(int num);
uint64 number_letter_count(int num);
uint64 low_number_letter_count(int single);


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
        // n thousand
        count += number_letter_count(thousand / 1000) + 8;
    }
    
    if ((thousand != 0 || hundred != 0) && (ten != 0 || single != 0))
    {
        // and
        count += 3;
    }

    if (hundred != 0)
    {
        // n hundred
        count += number_letter_count(hundred / 100) + 7;
    }

    switch (ten)
    {
        case 10:
            count += low_number_letter_count(10 + single);
            break;
        case 20:
            count += 6; // twenty
            break;
        case 30:
            count += 6; // thirty
            break;
        case 40:
            count += 5; // forty
            break;
        case 50:
            count += 5; // fifty
            break;
        case 60:
            count += 5; // sixty
            break;
        case 70:
            count += 7; // seventy
            break;
        case 80:
            count += 6; // eighty
            break;
        case 90:
            count += 6; // ninety
            break;
    }

    if (ten != 10 && single != 0)
    {
        count += low_number_letter_count(single);
    }

    return count;
}

uint64 low_number_letter_count(int single)
{
    uint64 count = 0;

    switch (single)
    {
        case 1:
            count += 3; // one
            break;
        case 2:
            count += 3; // two
            break;
        case 3:
            count += 5; // three
            break;
        case 4:
            count += 4; // four
            break;
        case 5:
            count += 4; // five
            break;
        case 6:
            count += 3; // six
            break;
        case 7:
            count += 5; // seven
            break;
        case 8:
            count += 5; // eight
            break;
        case 9:
            count += 4; // nine
            break;
        case 10:
            count += 3; // ten
            break;
        case 11:
            count += 6; // eleven
            break;
        case 12:
            count += 6; // twelve
            break;
        case 13:
            count += 8; // thirteen
            break;
        case 14:
            count += 8; // fourteen
            break;
        case 15:
            count += 7; // fifteen
            break;
        case 16:
            count += 7; // sixteen
            break;
        case 17:
            count += 9; // seventeen
            break;
        case 18:
            count += 8; // eighteen
            break;
        case 19:
            count += 8; // nineteen
            break;
    }

    return count;
}

