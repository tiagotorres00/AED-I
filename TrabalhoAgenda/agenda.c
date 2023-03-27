#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void novoContato(void *pBuffer);
void removerContato(void *pBuffer);
void listar(void *pBuffer);
void excluirLista(void *primeiro);

int main(int argc, char const *argv[])
{
    void *pBuffer = (void *)malloc(2 * sizeof(void *) + 3 * sizeof(char));

    if (!pBuffer)
    {
        printf("Erro ao alocar memoria.\n");
        exit(1);
    }

    *((void **)pBuffer) = NULL; // Primeiro NODO
    *((void **)pBuffer + 1) = NULL;
    //*((void **)pBuffer + sizeof(void *)) = NULL; // Ultimo NODO

    while (1)
    {
        printf("\n");
        printf("1 - Novo contato\n");
        printf("2 - Excluir contato\n");
        printf("3 - Listar\n");
        printf("4 - Sair\n");
        scanf("%3s", (char *)pBuffer + 2 * sizeof(void *));

        switch (((char *)pBuffer + 2 * sizeof(void *))[0])
        {
            case '1':
                novoContato(pBuffer);
                break;
            
            case '2':
                removerContato(pBuffer);
                break;
            
            case '3':
                listar(pBuffer);
                break;
            
            case '4':
                excluirLista(*((void **)pBuffer));
                free(pBuffer);
                exit(1);
                break;
        }
    }

    return 0;
}


void novoContato(void *pBuffer)
{
    void *nodo = (void *)malloc(2 * sizeof(void *) + 10 * sizeof(char) + 4 * sizeof(char) + 10 * sizeof(char));
    // nodo = ponteiro para anterior, ponteiro para proximo, nome, idade, telefone

    if (!nodo)
    {
        printf("Erro ao alocar memoria.\n");
        exit(1);
    }

    *((void **)nodo) = NULL; // anterior = null
    *((void **)nodo + 1) = NULL; // proximo = null
    
    printf("Digite o nome: ");
    scanf("%9s", (char *)nodo + 2 * sizeof(void *)); // salva o nome apos os dois ponteiros

    printf("Digite a idade: ");
    scanf("%3s", (char *)nodo + 2 * sizeof(void *) + 10 * sizeof(char)); // salva a idade apos o nome

    printf("Digite o telefone: ");
    scanf("%9s", (char *)nodo + 2 * sizeof(void *) + 10 * sizeof(char) + 4 * sizeof(char)); // salva o telefone apos a idade

    if (*((void **)pBuffer) == NULL) // se FIRST->NULL
    {
        *((void **)pBuffer) = nodo;                   // *head = nodo
        *((void **)pBuffer + sizeof(void *)) = nodo;  // *tail = nodo
        return;
    }

    if (strcmp(nodo + 2 * sizeof(void *), *((void **)pBuffer) + 2 * sizeof(void *)) < 0) // name, (*head)->name
    {
        *((void **)nodo + sizeof(void *)) = *((void **)pBuffer); // nodo->prox = primeiro
        *((void **)*((void **)pBuffer)) = nodo;                  // primeiro->ant = nodo
        *((void **)pBuffer) = nodo;                   // primeiro = nodo
        return;
    }

    if (strcmp(nodo + 2 * sizeof(void *), *((void **)pBuffer + sizeof(void *)) + 2 * sizeof(void *)) >= 0)
    {
        *((void **)nodo) = *((void **)pBuffer + sizeof(void *));                     // nodo->ant = ultimo
        *((void **)*((void **)pBuffer + sizeof(void *)) + sizeof(void *)) = nodo;    // ultimo->prox = nodo
        *((void **)pBuffer + sizeof(void *)) = nodo;                                // ultimo = nodo
        return;
    }

    void *atual = *((void **)pBuffer); // atual = primeiro da lista
    void *proximo = *((void **)atual + sizeof(void *));

    while (*((void **)atual + sizeof(void *)) != NULL && strcmp(nodo + 2 * sizeof(void *), proximo + 2 * sizeof(void *)) > 0)
    {
        atual = proximo;
        proximo = *((void **)proximo + sizeof(void *));
    }
    
    *((void **)nodo) = atual;                                                           // nodo->ant = atual
    *((void **)nodo + sizeof(void *)) = *((void **)atual + sizeof(void *));             // nodo->prox = atual->prox
    *((void **)*((void **)atual + sizeof(void *))) = nodo;                              // atual->prox->ant = nodo;
    *((void **)atual + sizeof(void *)) = nodo;                                          // atual->prox = nodo;
}

void removerContato(void *pBuffer)
{
    if (*((void **)pBuffer) == NULL)
    {
        printf("Agenda vazia!\n");
        return;
    }

    void *atual = *((void **)pBuffer); // atual = primeiro da lista
    char *nome = (char *)malloc(10 * sizeof(char));

    printf("Digite o nome: ");
    scanf("%9s", nome);

    while (1)
    {
        if (strcmp(atual + 2 * sizeof(void *), nome) == 0) // se encontrou o nome
        {
            if ((*((void **)atual) != NULL) && (*((void **)atual + sizeof(void *)) != NULL)) // se atual estiver no meio da lista
            {
                void *anterior = *((void **)atual); 
                void *proximo = *((void **)atual + sizeof(void *));

                *((void **)anterior + sizeof(void *)) = proximo; // anterior aponta para o proximo
                *((void **)proximo) = anterior; // proximo aponta para o anterior
                free(atual);
                free(nome);
                printf("Contato removido.\n");
                return;
            }
            else if (*((void **)atual) == NULL) // se o elemento anterior do atual for NULL (se atual for o priemiro da lista)
            {
                void *proximo = *((void **)atual + sizeof(void *));

                if (proximo == NULL)
                {
                    *((void **)pBuffer) = NULL;
                    *((void **)pBuffer + sizeof(void *)) = NULL;
                    free(atual);
                    free(nome);
                    printf("Contato removido.\n");
                    return;
                }
                
                *((void **)proximo) = NULL;       // proximo->anterior = NULL
                *((void **)pBuffer) = proximo;    // pBuffer->First = proximo;
                free(atual);
                free(nome);
                printf("Contato removido.\n");
                return;
            }
            else // se for o ultimo da lista
            {
                void *anterior = *((void **)atual);
                *((void **)anterior + sizeof(void *)) = NULL; // anterior aponta para null
                *((void **)pBuffer + sizeof(void *)) = anterior;
                free(atual);
                free(nome);
                printf("Contato removido.\n");
                return;
            }
        }
        else if (*((void **)atual + sizeof(void *)) == NULL) // se nao encontrou o nome e chegou no fim da lista
        {
            printf("Contato nao encontrado.\n");
            return;
        }

        atual = *((void **)atual + sizeof(void *)); // atual = atual->proximo
    }
}

void listar(void *pBuffer)
{
    if (*((void **)pBuffer) == NULL)
    {
        printf("Lista vazia!\n");
        return;
    }
    else
    {
        void *atual = *((void **)pBuffer); // atual = primeiro da lista
        
        while (1)
        {
            printf("Nome: %s\n", (char *)atual + 2 * sizeof(void *));
            printf("Idade: %s\n", (char *)atual + 2 * sizeof(void *) + 10 * sizeof(char));
            printf("Telefone: %s\n\n", (char *)atual + 2 * sizeof(void *) + 10 * sizeof(char) + 4 * sizeof(char));
            if (*((void **)atual + sizeof(void *)) == NULL)
            {
                break;
            }
            else
            {
                atual = *((void **)atual + sizeof(void *));
            }
        }
    }
}

void excluirLista(void *primeiro)
{
    if (primeiro != NULL)
    {
        excluirLista(*((void **)primeiro + sizeof(void *)));
        free(primeiro);
    }
}