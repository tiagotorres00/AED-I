/*
Faça uma agenda capaz de incluir, apagar, buscar e listar quantas pessoas o usuário desejar, 
porém, toda a informação incluída na agenda deve ficar num único lugar chamado: “void *pBuffer”.

Não pergunte para o usuário quantas pessoas ele vai incluir.
Não pode alocar espaço para mais pessoas do que o necessário.
Cada pessoa tem nome[10], idade e telefone.
*/
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
                exit(1);
        }
    }


    return 0;
}

void adicionarPessoa(void *pBuffer, int *pTamanhoBuffer)
{
    int p = *pTamanhoBuffer;
    pBuffer = realloc(pBuffer, *pTamanhoBuffer + (10 * sizeof(char)) + sizeof(int) + (10 * sizeof(char)));
    if (!pBuffer)
    {
        printf("Erro ao realocar memoria.\n");
        exit(1);
    }

    *((int *)pBuffer) += 1;

    char nome[10];

    printf("Digite o nome da pessoa: ");
    scanf("%s", nome);

    strcpy(((char *)pBuffer + p), nome);

    p += (10 * sizeof(char));
    
    printf("Digite a idade: ");
    scanf("%i", &(*((int *)pBuffer + p)));

    p += sizeof(int);

    char telefone[10];
    printf("Digite o telefone: ");
    scanf("%s", telefone);
    strcpy(((char *)pBuffer + p), telefone);


    *pTamanhoBuffer += 10 * sizeof(char) + sizeof(int) + 10 * sizeof(char);
}

void removerPessoa(void *pBuffer, int *pTamanhoBuffer)
{   
    int p = sizeof(int);

    char nome[10];

    printf("Digite o nome da pessoa: ");
    scanf("%s", nome);

    int n = strlen(nome);
    for (int i = p; i < *pTamanhoBuffer; i++) // possivel otimizar fazendo i pular de 18 em 18 bytes (tamanho da pessoa)!!
    {
        int counter = 0;
        if (*((char *)pBuffer + i) == nome[0])
        {
            for (int j = i; j < n; j++)
            {
                if (*((char *) pBuffer + j) == nome[j])
                {
                    counter++;
                }
            }

            if (counter == n)
            {
                for (int j = i; j < (*pTamanhoBuffer - ((10 * sizeof(char)) + sizeof(int) + 10 * sizeof(char))); j++)
                {
                    *((char *)pBuffer + j) = *((char *)pBuffer + j + ((10 * sizeof(char)) + sizeof(int) + 10 * sizeof(char))); // como tirar o char *
                }
                break;
            }
        }
    }

    *((int *)pBuffer) -= 1; // Atualiza o numero de pessoas no buffer
    pBuffer = realloc(pBuffer, *pTamanhoBuffer - (10 * sizeof(char) + sizeof(int) + 10 * sizeof(char)));
    *pTamanhoBuffer -= (10 * sizeof(char) + sizeof(int) + 10 * sizeof(char)); 
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
        printf("Idade: %i\n", *((int *)pBuffer + p));
        p += sizeof(int);
        printf("Telefone: %s\n\n", (pBuffer + p));
        p += 10 * sizeof(char);
    }
}