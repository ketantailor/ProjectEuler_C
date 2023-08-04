// Project Euler - Problem 05: Smallest multiple
// Compile with: c99 euler-005.c -o euler-005.bin -Wall -Wextra -pedantic
// Windows: cl /W4 /nologo euler-005.c

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define u64 uint64_t

void euler005();
u64 smallest_multiple();

int main(void)
{
    puts("Project Euler - Problem 05: Smallest multiple");

    euler005();

    return EXIT_SUCCESS;
}

void euler005()
{
    u64 ans = smallest_multiple();
    printf("Answer: %ld\n", ans);
}

u64 smallest_multiple()
{
    // get the max number it could be
    u64 max = 1;
    for (int m = 1; m <= 20; m++)
    {
        max *= m;
    }

    // find and return the lowest number
    for (u64 i = 20; i <= max; i += 20)
    {
        bool found = true;
        for (int m = 1; m <= 20; m++)
        {
            if (i % m != 0)
            {
                found = false;
                break;
            }
        }

        if (found)
        {
            return i;
        }
    }

    return (u64)-1;
}
