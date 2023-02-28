/*
Faca uma funcao recursiva que calcule e retorne o N-esimo termo da sequencia Fibonacci
Alguns numeros desta sequencia sao: 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89...
*/

#include <stdio.h>

int fibonacci(int n);

int main(int argc, char const *argv[])
{
    int n;
    printf("n: ");
    scanf("%i", &n);

    int resposta = fibonacci(n);
    printf("Resposta: %i\n", resposta);

    return 0;
}

int fibonacci(int n)
{
    if (n == 1)
    {
        return 1;
    }
    else if (n == 2)
    {
        return 1;
    }
    else
    {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}
