/*
Faca um programa que preencha uma matriz de string com os modelos de cinco carros (exemplos de modelos: Fusca, Gol, Vectra, etc.). 
Em seguida, preencha um vetor com o consumo desses carros, isto e, quantos quilometros cada um deles faz com um litro de combustivel. 
Calcule e mostre:
(a) O modelo de carro mais economico; 
(b) Quantos litros de combustivel cada um dos carros cadastrados consome para percorrer uma distancia de 1.000 quilometros
*/

#include <stdio.h>

int main(int argc, char const *argv[])
{
    char carros[5][15];
    int consumo[5];

    for (int i = 0; i < 5; i++)
    {
        printf("Digite o nome do carro: ");
        scanf("%s", carros[i]);

        printf("Digite o consumo desse carro: ");
        scanf("%i", &consumo[i]);
    }

    int maisEconomico;
    int menorConsumo = consumo[0];

    for (int i = 0; i < 5; i++)
    {
        if (consumo[i] > menorConsumo)
        {
            menorConsumo = consumo[i];
            maisEconomico = i;
        } 
    }

    printf("\nModelo mais economico: %s\n", carros[maisEconomico]);

    for (int i = 0; i < 5; i++)
    {
        printf("\nCarro: %s\n", carros[i]);
        printf("Combustivel consumido em 1000 km: %i\n", 1000 / consumo[i]);
    }

    return 0;
}
