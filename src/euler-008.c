/*
 * Project Euler - Problem 08: Largest product in a series
 *
 * Linux: c99 euler-008.c -o euler-008.bin -Wall -Wextra -pedantic
 * Windows: cl /W4 /nologo euler-008.c
 */

#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define uint64 uint64_t

void euler008();
uint64 brute_force();
int char_to_int(char c);

char *input = "73167176531330624919225119674426574742355349194934969835203127745063262395783180169848018694788518438586"
              "15607891129494954595017379583319528532088055111254069874715852386305071569329096329522744304355766896648"
              "95044524452316173185640309871112172238311362229893423380308135336276614282806444486645238749303589072962"
              "90491560440772390713810515859307960866701724271218839987979087922749219016997208880937766572733300105336"
              "78812202354218097512545405947522435258490771167055601360483958644670632441572215539753697817977846174064"
              "95514929086256932197846862248283972241375657056057490261407972968652414535100474821663704844031998900088"
              "95243450658541227588666881164271714799244429282308634656748139191231628245861786645835912456652947654568"
              "28489128831426076900422421902267105562632111110937054421750694165896040807198403850962455444362981230987"
              "87992724428490918884580156166097919133875499200524063689912560717606058861164671094050775410022569831552"
              "0005593572972571636269561882670428252483600823257530420752963450";

int main(void)
{
    puts("Project Euler - Problem 08: Largest product in a series");

    euler008();

    return EXIT_SUCCESS;
}

void euler008()
{
    float start = (float)clock() / CLOCKS_PER_SEC;

    uint64 ans = brute_force();

    float elapsed = (float)clock() / CLOCKS_PER_SEC - start;
    printf("Answer: %" PRIu64 " (elapsed: %fs)\n", ans, elapsed);
}

uint64 brute_force()
{
    int digits = 13;
    uint64 max_product = 0;

    for (int i = digits; input[i] != '\0'; i++)
    {
        uint64 current_product = 1;
        for (int d = 0; d < digits; d++)
        {
            current_product *= char_to_int(input[i - d]);
        }
        if (current_product > max_product)
        {
            max_product = current_product;
        }
    }
    return max_product;
}

int char_to_int(char c)
{
    if (c < 48 || c > 59)
        return -1;
    return c - 48;
}
