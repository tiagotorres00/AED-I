/*
Faca uma funcao recursiva que receba um numero inteiro positivo N e imprima todos os 
numeros naturais de 0 ate N em ordem crescente. 
*/

#include <stdio.h>

void funcao(int n);

int main(int argc, char const *argv[])
{
    int n;
    printf("n: ");
    scanf("%i", &n);

    funcao(n);
    
    return 0;
}

void funcao(int n)
{
    if (n == -1)
    {
        return;
    }

    funcao(n - 1);
    printf("%i\n", n);

    return;
}