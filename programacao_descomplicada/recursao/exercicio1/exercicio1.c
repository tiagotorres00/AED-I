/*
Crie uma funcao recursiva que receba um numero inteiro positivo N 
e calcule o somatorio dos numeros de 1 a N
*/

#include <stdio.h>

int somatorio(int n);

int main(int argc, char const *argv[])
{
    int n;
    printf("n: ");
    scanf("%i", &n);

    int resposta = somatorio(n);

    printf("Somatorio = %i\n", resposta);

    return 0;
}

int somatorio(int n)
{
    if (n == 1)
    {
        return 1;
    }
    else
    {
        return n + somatorio(n - 1);
    }
}
