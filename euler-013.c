/*
 * Project Euler - Problem 13: Large sum
 *
 * Linux: c99 euler-013.c -o euler-013.bin -Wall -Wextra -pedantic
 * Windows: cl /W4 /nologo /wd6053 euler-013.c
 */

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define uint64 uint64_t

uint64 large_sum();

int main(void)
{
    puts("Project Euler - Problem 13: Large sum");
    float start = (float)clock() / CLOCKS_PER_SEC;

    uint64 ans = large_sum();
    printf("Answer: %" PRIu64 "\n", ans);

    float elapsed = (float)clock() / CLOCKS_PER_SEC - start;
    printf("Completed in %fs\n", elapsed);

    return EXIT_SUCCESS;
}

uint64 large_sum()
{
    FILE *file = fopen("euler-013.txt", "r");
    if (file == NULL)
    {
        fprintf(stderr, "Failed to open file 'euler-013.txt'.\n");
        return 0;
    }

    uint64 sum = 0, line_num = 0;
    char line[256], trimmed_line[13];
    trimmed_line[12] = '\0';

    while (fgets(line, sizeof(line), file))
    {
        strncpy(trimmed_line, line, sizeof(trimmed_line) - 1);

        char *end;
        line_num = strtoull(trimmed_line, &end, 10);

        sum += line_num;
    }

    while (sum >= 10000000000)
        sum /= 10;

    fclose(file);

    return sum;
}
