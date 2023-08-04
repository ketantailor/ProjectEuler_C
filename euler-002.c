// Project Euler - Problem 02: Even Fibonacci numbers
// Compile with: c99 euler-002.c -o euler-002.bin -Wall -Wextra -pedantic
// Windows: cl /W4 /nologo euler-002.c

#include <stdio.h>
#include <stdlib.h>

void euler02();
int even_fibonacci_numbers(int num);

int main(void)
{
    puts("Project Euler - Problem 02: Even Fibonacci numbers");

    euler02();

    return EXIT_SUCCESS;
}

void euler02()
{
    int ans = even_fibonacci_numbers(4000000);
    printf("Answer: %i\n", ans);
}

int even_fibonacci_numbers(int num)
{
    int fibA = 1;
    int fibB = 1;
    int sum = 0;

    while (fibA < num)
    {
        int tmp = fibA + fibB;
        fibA = fibB;
        fibB = tmp;

        if (fibA % 2 == 0)
            sum += fibA;
    }

    return sum;
}
