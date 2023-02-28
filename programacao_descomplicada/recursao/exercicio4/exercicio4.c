/*
Crie uma funcao recursiva que receba dois inteiros positivos k e n e calcule k^n
*/

#include <stdio.h>

int funcao(int k, int n);

int main(int argc, char const *argv[])
{
    int k, n;

    printf("k: ");
    scanf("%i", &k);

    printf("n: ");
    scanf("%i", &n);

    int resposta = funcao(k, n);
    printf("Resposta: %i\n", resposta);

    return 0;
}

int funcao(int k, int n)
{
    if (n == 1)
    {
        return k;
    }
    else
    {
        return k * funcao(k, n-1);
    }
}
