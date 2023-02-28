/*
Escreva uma funcao recursiva que calcule a soma dos primeiros n cubos: 
S(n) = 1^3 + 2^3 + ... + n^3
*/

#include <stdio.h>

int somaCubos(int n);

int main(int argc, char const *argv[])
{
    int n;
    printf("n: ");
    scanf("%i", &n);

    int resposta = somaCubos(n);
    printf("Resposta: %i\n", resposta);
    return 0;
}

int somaCubos(int n)
{
    if (n == 1)
    {
        return 1;
    }
    else
    {
        return n * n * n + somaCubos(n - 1);
    }
}