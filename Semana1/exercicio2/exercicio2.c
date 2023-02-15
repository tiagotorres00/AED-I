#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int menu(void);
void adicionarNome(void);
void removerNome(void);
void listar(void);

char *string;
int tamanhoString = 0;
int numeroNomes = 0;

int main(void)
{
    int opcao = menu();

    if (opcao == 4)
    {
        free(string);
        return 0;
    }
}

int menu(void)
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
            adicionarNome();
            break;
        
        case 2:
            removerNome();
            break;
        
        case 3:
            listar();
            break;
        
        case 4:
            return 4;
    }

    menu();
}


void adicionarNome(void)
{
    char nome[30];

    printf("Digite o nome a ser adicionado: ");
    scanf("%s", &nome);

    int tamanhoNome = strlen(nome) + 1;
    string = realloc(string, tamanhoString + (sizeof(char) * tamanhoNome)); 

    if (!string)
    {
        printf("Erro ao realocar memoria.");
        exit(1);
    }

    // Copia o nome digitado pelo usuario para a string unica
    for (int i = tamanhoString, j = 0; i < (tamanhoString + tamanhoNome); i++)
    {
        string[i] = nome[j];
        j++;
    }

    tamanhoString += tamanhoNome;
    numeroNomes++;
}


void removerNome(void)
{
    char nome[30];

    printf("Digite o nome a ser removido: ");
    scanf("%s", &nome);

    int tamanhoNome = strlen(nome) + 1;

    // Passa por todas as letras da string ate encontrar a letra inicial do nome a ser removido
    for (int i = 0; i < tamanhoString; i++)
    {
        // Quando encontra:
        if (nome[0] == string[i])
        {
            // Compara as proximas n letras. Contador usado para verificar se todas as letras coincidem 
            int contador = 0;
            for (int j = 0; j < tamanhoNome; j++)
            {
                if (nome[j] == string[i + j])
                {
                    contador++;
                }
            }

            // Se todas as letras coincidem, "apaga" o nome e reorganiza os proximos caracteres para nao ficar um espaco vazio no meio da string
            if (contador == tamanhoNome)
            {
                for (int j = i; j < (tamanhoString - tamanhoNome); j++)
                {
                    string[j] = string[j + tamanhoNome];
                }
            }
        }
    }

    if (tamanhoString - tamanhoNome < 1)
    {
        string = realloc(string, 1);
    }
    else
    {
        string = realloc(string, (tamanhoString - tamanhoNome));
    }

    if (!string)
    {
        printf("Erro ao realocar memoria.");
        exit(1);
    }


    tamanhoString -= tamanhoNome;
    numeroNomes--;
}

void listar(void)
{
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
