#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void adicionarPessoa(void *pBuffer, int *pTamanhoBuffer);
void removerPessoa(void *pBuffer, int *pTamanhoBuffer);
void listar(void *pBuffer);

int main(int argc, char const *argv[])
{
    int tamanhoBuffer = 0;
    int *pTamanhoBuffer = &tamanhoBuffer;

    void *pBuffer = malloc(sizeof(int));

    if (!pBuffer)
    {
        printf("Erro ao alocar memoria.\n");
        return 1;
    }

    *((int *)pBuffer) = 0;
    tamanhoBuffer += sizeof(int); // precisa ser em bytes e nao em elementos, pois o void anda de 1 em 1 byte

    while (1)
    {
        int opcao;
        printf("\n");
        printf("1- Adicionar Nova Pessoa\n");
        printf("2- Apagar Pessoa\n");
        printf("3- Listar\n");
        printf("4- Sair\n");
        scanf("%i", &opcao);

        switch (opcao)
        {
            case 1:
                adicionarPessoa(pBuffer, pTamanhoBuffer);
                break;
            
            case 2:
                removerPessoa(pBuffer, pTamanhoBuffer);
                break;
            
            case 3:
                listar(pBuffer);
                break;
            
            case 4:
                free(pBuffer);
                exit(1);
        }
    }


    return 0;
}

void adicionarPessoa(void *pBuffer, int *pTamanhoBuffer)
{
    int p = *pTamanhoBuffer;
    pBuffer = realloc(pBuffer, *pTamanhoBuffer + (10 * sizeof(char)) + 4 * sizeof(char) + (10 * sizeof(char)));
    if (!pBuffer)
    {
        printf("Erro ao realocar memoria.\n");
        exit(1);
    }

    char nome[10];

    printf("Digite o nome da pessoa: ");
    scanf("%s", nome);

    strcpy(((char *)pBuffer + p), nome);

    p += (10 * sizeof(char));
    
    printf("Digite a idade: ");
    scanf("%s", &(*((char *)pBuffer + p)));

    p += 4 * sizeof(char);

    char telefone[10];
    printf("Digite o telefone: ");
    scanf("%s", telefone);
    strcpy(((char *)pBuffer + p), telefone);

    // Atualiza as variaveis
    *((int *)pBuffer) += 1;
    *pTamanhoBuffer += 10 * sizeof(char) + 4 * sizeof(char) + 10 * sizeof(char);
}

void removerPessoa(void *pBuffer, int *pTamanhoBuffer)
{   
    int nPessoas = *((int *)pBuffer);
    int p = sizeof(int);
    char nome[10];

    printf("Digite o nome da pessoa: ");
    scanf("%s", nome);

    int n = strlen(nome);
    
    for (int i = 0; i < nPessoas; i++)
    {
        // Se encontrar o nome da pessoa
        if (strcmp((pBuffer + p), nome) == 0)
        {
            // Se o nome da pessoa estiver no inicio ou meio do buffer, eh necessario "puxar" e reorganizar a memoria do buffer
            if (!(p == *pTamanhoBuffer - 24))
            {   
                memcpy(((char *)pBuffer + p), ((char *)pBuffer + p + 24), *pTamanhoBuffer - p);
            }

            // Caso o nome esteja no final, ou os dados ja foram reorganizados, excluir a parte final do buffer e atualizar as variaveis
            pBuffer = realloc(pBuffer, *pTamanhoBuffer - (10 * sizeof(char) + 4 * sizeof(char) + 10 * sizeof(char)));
            if (!pBuffer)
            {
                printf("Erro ao realocar memoria.\n");
                exit(1);
            }

            *((int *)pBuffer) -= 1;
            *pTamanhoBuffer -= (10 * sizeof(char) + 4 * sizeof(char) + 10 * sizeof(char)); 
            return;
        }
        else
        {
            // Pula direto para o proximo nome
            p += (10 * sizeof(char) + 4 * sizeof(char) + 10 * sizeof(char));
        }
    }

    printf("Nome nao encontrado. Tente novamente.\n");
}

void listar(void *pBuffer)
{
    int nPessoas = *((int *)pBuffer);
    int p = sizeof(int);

    for (int i = 0; i < nPessoas; i++)
    {
        printf("\n");
        printf("Contato %i: \n", i);
        printf("Nome: %s\n", (pBuffer + p));
        p += 10 * sizeof(char);
        printf("Idade: %s\n", (pBuffer + p));
        p += 4 * sizeof(char);
        printf("Telefone: %s\n\n", (pBuffer + p));
        p += 10 * sizeof(char);
    }
}