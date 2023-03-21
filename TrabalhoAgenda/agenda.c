#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void adicionarPessoa(void *pBuffer);
void listar(void *pBuffer);

int main(int argc, char const *argv[])
{
    void *pBuffer = malloc(sizeof(int) + sizeof(int) + sizeof(int) + sizeof(int *) + sizeof(int *)); 
    // Numero de contatos + Opcao + Ponteiro para o primeiro + ponteiro para o ultimo

    if (!pBuffer)
    {
        printf("Erro ao alocar memoria.\n");
        return 1;
    }

    *((int *)pBuffer) = -1; // opcao = -1
    *((int *)pBuffer + sizeof(int)) = 0; // numero de contatos = 0
    *((int *)pBuffer + 2 * sizeof(int)) = 0; // tamanho da LISTA, precisa ser em bytes e nao em elementos, pois o void anda de 1 em 1 byte
    *((int **)pBuffer + 3 * sizeof(int)) = NULL;                   // primeiro elemento da lista
    *((int **)pBuffer + 3 * sizeof(int) + sizeof(int *)) = NULL;   // ultimo elemento da lista

    /*
    while (1)
    {
        printf("\n");
        printf("1- Adicionar Nova Pessoa\n");
        printf("2- Apagar Pessoa\n");
        printf("3- Listar\n");
        printf("4- Sair\n");

        switch (opcao) // switch OPCAO
        {
            case 1:
                adicionarPessoa(pBuffer);
                break;
            
            case 2:
                exit(1);
            
            case 3:
                listar(pBuffer);
                break;
            
            case 4:
                free(pBuffer);
                exit(1);
        }
    }
    */

    adicionarPessoa(pBuffer);
    adicionarPessoa(pBuffer);
    adicionarPessoa(pBuffer);
    listar(pBuffer);


    return 0;
}

void adicionarPessoa(void *pBuffer)
{
    void *nodo = malloc(1 * sizeof(int *) + 10 * sizeof(char) + 4 * sizeof(char) + 10 * sizeof(char) + 1 * sizeof(int *));
    // NODO ANTERIOR + NOME[10] + IDADE[4] + TELEFONE[10] + PROXIMO NODO
    if (!nodo)
    {
        printf("Erro ao alocar memoria.\n");
        exit(1);
    }

    if (*((int **)pBuffer + 3 * sizeof(int)) == NULL) // se for o primeiro elemento da lista
    {
        *((int **)nodo) = NULL; // anterior = NULL

        printf("Digite o nome: ");
        scanf("%s", ((char *)nodo + 1 * sizeof(int *))); // nodo + anterior

        printf("Digite a idade: ");
        scanf("%s", ((char *)nodo + 1 * sizeof(int *) + 10 * sizeof(char))); // nodo + anterior + nome

        printf("Digite o telefone: ");
        scanf("%s", ((char *)nodo + 1 * sizeof(int *) + 10 * sizeof(char) + 4 * sizeof(char))); // nodo + anterior + nome + idade

        *((int **)nodo + 1 * sizeof(int *) + 10 * sizeof(char) + 4 * sizeof(char) + 10 * sizeof(char)) = NULL; // proximo = NULL

        *((int **)pBuffer + 3 * sizeof(int)) = nodo; // primeiro elemento da lista = nodo
        *((int **)pBuffer + 3 * sizeof(int) + sizeof(int *)) = nodo; // ultimo elemento da lista = nodo
    }
    else
    {
        *((int **)nodo) = (pBuffer + 3 * sizeof(int) + sizeof(int *)); // anterior do novo NODO = ultimo NODO da lista
        *(*((int **)pBuffer + 3 * sizeof(int) + sizeof(int *)) + 1 * sizeof(int *) + 10 * sizeof(char) + 4 * sizeof(char) + 10 * sizeof(char)) = nodo; // proximo do ultimo NODO da lista = novo NODO
        *((int **)pBuffer + 3 * sizeof(int) + sizeof(int *)) = nodo; // ultimo NODO da lista = novo NODO

        printf("Digite o nome: ");
        scanf("%s", ((char *)nodo + 1 * sizeof(int *))); // nodo + anterior

        printf("Digite a idade: ");
        scanf("%s", ((char *)nodo + 1 * sizeof(int *) + 10 * sizeof(char))); // nodo + anterior + nome

        printf("Digite o telefone: ");
        scanf("%s", ((char *)nodo + 1 * sizeof(int *) + 10 * sizeof(char) + 4 * sizeof(char))); // nodo + anterior + nome + idade

        *((int **)nodo + 1 * sizeof(int *) + 10 * sizeof(char) + 4 * sizeof(char) + 10 * sizeof(char)) = NULL; // proximo = NULL
    }
}

void listar(void *pBuffer)
{
    void *atual = *((int **)pBuffer + 3 * sizeof(int)); // atual = primeiro da lista
    
    if (*((int **)pBuffer + 3 * sizeof(int)) == NULL)
    {
        printf("Agenda vazia.\n");
        return;
    }
    else
    {
        while (*((int **)atual + 1 * sizeof(int **) + 10 * sizeof(char) + 4 * sizeof(char) + 10 * sizeof(char)) != NULL) // while atual->prox != NULL
        {
            printf("\n");
            printf("Nome: %s\n", (atual + 1 * sizeof(int **)));
            printf("Idade: %s\n", (atual + 1 * sizeof(int **) + 10 * sizeof(char)));
            printf("Telefone: %s\n", (atual + 1 * sizeof(int **) + 10 * sizeof(char) + 4 * sizeof(char)));
            atual += 1 * sizeof(int **) + 10 * sizeof(char) + 4 * sizeof(char) + 10 * sizeof(char) + 1 * sizeof(int **);
        }
    }
}