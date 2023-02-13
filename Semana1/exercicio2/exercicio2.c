/*
Faça um programa que armazena nomes.
O programa deve armazenar todos os nomes na mesma string.
O tamanho da string deve crescer e diminuir conforme nomes forem colocados ou removidos. 
Não pode ter desperdício de memória.

Faça o seguinte menu:
1) Adicionar nome
2) Remover nome
3) Listar
4) Sair
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int Menu(void);
void AdicionarNome(void);
void RemoverNome(void);
void Listar(void);


char *string;
int tamanhoString = 0;
int numeroNomes = 0;

int main(void)
{
    int opcao = Menu();

    if (opcao == 4)
    {
        free(string);
        return 0;
    }
}

int Menu(void)
{
    int opcao;

    do
    {
        printf("\n");
        printf("1- Adicionar nome\n");
        printf("2- Remover nome\n");
        printf("3- Listar\n");
        printf("4- Sair\n");
        scanf("%i", &opcao);
    } 
    while (opcao < 1 || opcao > 4);

    switch (opcao)
    {
        case 1:
            AdicionarNome();
            break;
        
        case 2:
            RemoverNome();
            break;
        
        case 3:
            Listar();
            break;
        
        case 4:
            return 4;
    }

    Menu();
}

void AdicionarNome(void)
{
    char nome[30];

    printf("Digite o nome a ser adicionado: ");
    scanf("%s", &nome);

    int tamanhoNome = strlen(nome) + 1;
    string = realloc(string, tamanhoString + (sizeof(char) * tamanhoNome));

    for (int i = tamanhoString, j = 0; i < (tamanhoString + tamanhoNome); i++)
    {
        string[i] = nome[j];
        j++;
    }

    tamanhoString += tamanhoNome;
    numeroNomes++;
}

void RemoverNome(void)
{
    char nome[30];

    printf("Digite o nome a ser removido: ");
    scanf("%s", &nome);

    int tamanhoNome = strlen(nome) + 1;

    for (int i = 0; i < tamanhoString; i++)
    {
        if (nome[0] == string[i])
        {
            int counter = 0;
            for (int j = 0; j < tamanhoNome; j++)
            {
                if (nome[j] == string[i + j])
                {
                    counter++;
                }
            }

            if (counter == tamanhoNome)
            {
                for (int j = i; j < (tamanhoString - tamanhoNome); j++)
                {
                    string[j] = string[j + tamanhoNome];
                }
            }
        }
    }

    string = realloc(string, (tamanhoString - tamanhoNome));
    tamanhoString -= tamanhoNome;
    numeroNomes--;
}

void Listar(void)
{
    int indexPrimeiraLetra[numeroNomes];
    indexPrimeiraLetra[0] = 0;

    int counter = 1;

    for (int i = 1, j = 1; i < tamanhoString; i++)
    {
        if (counter == numeroNomes)
        {
            break;
        }
        else if (string[i - 1] == '\0')
        {
            indexPrimeiraLetra[j] = i;
            j++;
            counter++;
        }
    }

    for (int i = 0, j = 0; i < tamanhoString; i++)
    {
        if (string[i] == '\0')
        {
            printf("\n");
        }
        else
        {
            printf("%c", string[i]);
        }
    }

    printf("\n");
}
