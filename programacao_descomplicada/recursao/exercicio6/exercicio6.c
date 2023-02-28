/*
A multiplicacao de dois numeros inteiros pode ser feita atraves de somas sucessivas. 
Proponha um algoritmo recursivo Multip_Rec(n1,n2) que calcule a multiplicacao de dois inteiros.
*/

#include <stdio.h>

int multiplicacao(int n1, int n2);

int main(int argc, char const *argv[])
{
    int n1, n2;

    printf("n1: ");
    scanf("%i", &n1);

    printf("n2: ");
    scanf("%i", &n2);

    printf("Resposta: %i\n", multiplicacao(n1, n2));

    return 0;
}

int multiplicacao(int n1, int n2)
{
    if (n2 == 1)
    {
        return n1;
    }
    else
    {
        return n1 + multiplicacao(n1, n2 - 1);
    }
}
