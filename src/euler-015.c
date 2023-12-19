/*
 * Project Euler - Problem 15: Lattice Paths
 *
 * Linux: c99 euler-015.c -o euler-015.bin -Wall -Wextra -pedantic
 * Windows: cl /W4 /nologo euler-015.c
 */

#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define uint64 uint64_t

// MS C compiler doesn't support variable length arrays
#define M 20
#define N 20

uint64 calculate_lattice_paths_iterative();

int main(void)
{
    puts("Project Euler - Problem 15: Lattice Paths");
    float start = (float)clock() / CLOCKS_PER_SEC;

    uint64 ans = calculate_lattice_paths_iterative();
    printf("Answer: %" PRIu64 "\n", ans);

    float elapsed = (float)clock() / CLOCKS_PER_SEC - start;
    printf("Completed in %fs\n", elapsed);

    return EXIT_SUCCESS;
}

uint64 calculate_lattice_paths_iterative()
{
    uint64 grid[M+1][N+1];

    for (int i = 0; i <= M; i++)
    {
        grid[i][0] = 1;
    }

    for (int j = 0; j <= N; j++)
    {
        grid[0][j] = 1;
    }

    for (int i = 1; i <= M; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            grid[i][j] = grid[i-1][j] + grid[i][j-1];
        }
    }

    return grid[M][N];
}
