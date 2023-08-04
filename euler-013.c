// Project Euler - Problem 13: Large sum
// Compile with: c99 problem12.c -o problem12.bin -Wall -Wextra -pedantic -lm
// Windows: cl /W4 /nologo problem12.c

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

#define uint64 uint64_t

int brute_force();

int main(void)
{
    puts("Project Euler - Problem 13: Large sum");
    float start = (float)clock() / CLOCKS_PER_SEC;

    uint64 ans = brute_force();

    float elapsed = (float)clock() / CLOCKS_PER_SEC - start;
    printf("Answer: %ld (elapsed: %fs)\n", ans, elapsed);

    return EXIT_SUCCESS;
}

int brute_force()
{
    return 0;
}
