// Faca um programa que receba uma palavra e a imprima de tras-para-frente

#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char palavra[50];

    printf("Digite a palavra: ");
    scanf("%s", palavra);

    int tamanhoPalavra = strlen(palavra);

    for (int i = tamanhoPalavra; i >= 0; i--)
    {
        printf("%c", palavra[i]);
    }
    printf("\n");

    return 0;
}
