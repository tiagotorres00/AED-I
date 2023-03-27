#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
void novoContato(void *pBuffer);
void removerContato(void *pBuffer);
void listar(void *pBuffer);
void excluirLista(void *primeiro);
 
int main(void)
{
    void *pBuffer = (void *)malloc(2 * sizeof(void *) + 2 * sizeof(char));
    // Aloca memoria para: o ponteiro para o primeiro elemento da lista, o ponteiro para o ultimo elemento da lista, string de 2 caracters
 
    if (!pBuffer)
    {
        printf("Erro ao alocar memoria.\n");
        exit(1);
    }
 
    *((void **)pBuffer) = NULL;     // pBuffer->First = NULL
    *((void **)pBuffer + 1) = NULL; // pBuffer->Last = NULL
 
    while (1)
    {
        printf("\n");
        printf("1 - Novo contato\n");
        printf("2 - Excluir contato\n");
        printf("3 - Listar\n");
        printf("4 - Sair\n");
        scanf("%1s", (char *)pBuffer + 2 * sizeof(void *));
 
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
 
    *((void **)nodo) = NULL;         // nodo->anterior = NULL
    *((void **)nodo + 1) = NULL;     // nodo->proximo = NULL
 
    printf("Digite o nome: ");
    scanf("%9s", (char *)nodo + 2 * sizeof(void *)); // salva o nome apos os dois ponteiros
 
    printf("Digite a idade: ");
    scanf("%3s", (char *)nodo + 2 * sizeof(void *) + 10 * sizeof(char)); // salva a idade apos o nome
 
    printf("Digite o telefone: ");
    scanf("%9s", (char *)nodo + 2 * sizeof(void *) + 10 * sizeof(char) + 4 * sizeof(char)); // salva o telefone apos a idade
 
    // Primeiro elemento da lista
    if (*((void **)pBuffer) == NULL) // se pBuffer->First = NULL (Se a lista estiver vazia)
    {
        *((void **)pBuffer) = nodo;           // pBuffer->First = NULL
        *((void **)pBuffer + 1) = nodo;       // pBuffer->Last = NULL
        return;
    }
 
    // Caso o novo contato deva se tornar o primeiro da lista
    if (strcmp(nodo + 2 * sizeof(void *), *((void **)pBuffer) + 2 * sizeof(void *)) < 0) // compara nodo->nome com pBuffer->First->nome
    {
        *((void **)nodo + 1) = *((void **)pBuffer);  // nodo->proximo = pBuffer->First
        *((void **)*((void **)pBuffer)) = nodo;      // pBuffer->First->anterior = nodo
        *((void **)pBuffer) = nodo;                  // pBuffer->First = nodo
        return;
    }
 
    // Caso o novo contato deva se tornar o ultimo da lista
    if (strcmp(nodo + 2 * sizeof(void *), *((void **)pBuffer + 1) + 2 * sizeof(void *)) >= 0) // compara nodo->nome com pBuffer->Last->nome
    {
        *((void **)nodo) = *((void **)pBuffer + 1);        // nodo->anterior = pBuffer->Last
        *((void **)*((void **)pBuffer + 1) + 1) = nodo;    // pBuffer->Last->proximo = nodo
        *((void **)pBuffer + 1) = nodo;                    // pBuffer->Last = nodo
        return;
    }
 
    // Caso o novo contato deva entrar no meio da lista
    void *atual = *((void **)pBuffer);     // atual = primeiro da lista
    void *proximo = *((void **)atual + 1); // proximo = segundo da lista
 
    // enquanto ATUAL NAO FOR O ULTIMO DA LISTA && nodo->nome deve ficar depois do proximo->nome
    while (*((void **)atual + 1) != NULL && strcmp(nodo + 2 * sizeof(void *), proximo + 2 * sizeof(void *)) > 0)
    {
        atual = proximo;    // "anda" um elemento para o lado
        proximo = *((void **)proximo + 1);
    }
 
    *((void **)nodo) = atual;                            // nodo->anterior = atual
    *((void **)nodo + 1) = *((void **)atual + 1);        // nodo->proximo = atual->prox
    *((void **)*((void **)atual + 1)) = nodo;            // atual->proximo->anterior = nodo
    *((void **)atual + 1) = nodo;                        // atual->proximo = nodo
}
 
void removerContato(void *pBuffer)
{
    if (*((void **)pBuffer) == NULL)
    {
        printf("Agenda vazia!\n");
        return;
    }
 
    void *atual = *((void **)pBuffer);  // atual = primeiro da lista
    char *nome = (char *)malloc(10 * sizeof(char));
 
    printf("Digite o nome: ");
    scanf("%9s", nome);
 
    while (1)
    {
        if (strcmp(atual + 2 * sizeof(void *), nome) == 0) // busca o nome na lista
        {
            if ((*((void **)atual) != NULL) && (*((void **)atual + 1) != NULL)) // se atual estiver no MEIO DA LISTA
            {
                void *anterior = *((void **)atual);
                void *proximo = *((void **)atual + 1);
 
                *((void **)anterior + 1) = proximo; // anterior->proximo = proximo
                *((void **)proximo) = anterior;     // proximo->anterior = anterior
                free(atual);
                free(nome);
                printf("Contato removido.\n");
                return;
            }
            else if (*((void **)atual) == NULL) // se atual for o PRIMEIRO DA LISTA
            {
                void *proximo = *((void **)atual + 1);
 
                if (proximo == NULL) // se a lista so tiver UM CONTATO
                {
                    *((void **)pBuffer) = NULL;         // pBuffer->First = NULL
                    *((void **)pBuffer + 1) = NULL;     // pBuffer->Last = NULL
                    free(atual);
                    free(nome);
                    printf("Contato removido.\n");
                    return;
                }
 
                // se a lista tiver PELO MENOS DOIS CONTATOS
                *((void **)proximo) = NULL;       // proximo->anterior = NULL
                *((void **)pBuffer) = proximo;    // pBuffer->First = proximo;
                free(atual);
                free(nome);
                printf("Contato removido.\n");
                return;
            }
            else // se for o ULTIMO DA LISTA
            {
                void *anterior = *((void **)atual);
                *((void **)anterior + 1) = NULL;     // anterior->proximo = NULL
                *((void **)pBuffer + 1) = anterior;  // pBuffer->Last = anterior
                free(atual);
                free(nome);
                printf("Contato removido.\n");
                return;
            }
        }
        else if (*((void **)atual + 1) == NULL) // se NAO ENCONTROU O NOME
        {
            printf("Contato nao encontrado.\n");
            free(nome);
            return;
        }
 
        atual = *((void **)atual + 1); // atual = atual->proximo
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
            if (*((void **)atual + 1) == NULL) // se atual->proximo = NULL
            {
                break;
            }
            else
            {
                atual = *((void **)atual + 1); // atual = atual->proximo
            }
        }
    }
}
 
void excluirLista(void *primeiro)
{
    if (primeiro != NULL) // se nao chegou no fim da lista
    {
        excluirLista(*((void **)primeiro + 1)); // exclui o proximo nodo
        free(primeiro);
    }
}