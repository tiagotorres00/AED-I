/*
Faca uma funcao recursiva que calcule e retorne o fatorial de um numero inteiro N
*/

#include <stdio.h>

int fatorial(int n);

int main(int argc, char const *argv[])
{
    int n;
    printf("n: ");
    scanf("%i", &n);

    int resposta = fatorial(n);
    printf("Resposta: %i\n", resposta);

    return 0;
}

int fatorial(int n)
{
    if (n == 1)
    {
        return 1;
    }
    else
    {
        return n * fatorial(n - 1);
    }
}