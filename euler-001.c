// Project Euler - Problem 01: Multiples of 3 or 5
// Compile with: c99 euler-001.c -o euler-001.bin -Wall -Wextra -pedantic
// Windows: cl /W4 /nologo euler-001.c

#include <stdio.h>
#include <stdlib.h>

void euler01();
int sum_multiples_of_three_and_five(int num);

int main(void)
{
    puts("Project Euler - Problem 01: Multiples of 3 or 5");

    euler01();

    return EXIT_SUCCESS;
}

void euler01()
{
    int ans = sum_multiples_of_three_and_five(1000);
    printf("Answer: %i\n", ans);
}

int sum_multiples_of_three_and_five(int num)
{
    int sum = 0;
    for (int i = 0; i < num; i++)
    {
        if (i % 3 == 0 || i % 5 == 0)
            sum += i;
    }
    return sum;
}
