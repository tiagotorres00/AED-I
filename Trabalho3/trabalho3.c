#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool leafSimilar(struct TreeNode* root1, struct TreeNode* root2);
void buscarFolhas(struct TreeNode* raiz, int *folhas, int *tam);

int main(void)
{
    // funcionou com a arvore pequena do exemplo 2, mas nao funcionou com a arvore do exemplo 1
    struct TreeNode raizA1;
    struct TreeNode no1A1;
    struct TreeNode no2A1;
    struct TreeNode no3A1;
    struct TreeNode folha1A1;
    struct TreeNode folha2A1;
    struct TreeNode folha3A1;
    struct TreeNode folha4A1;
    struct TreeNode folha5A1;

    struct TreeNode raizA2;
    struct TreeNode no1A2;
    struct TreeNode no2A2;
    struct TreeNode no3A2;
    struct TreeNode folha1A2;
    struct TreeNode folha2A2;
    struct TreeNode folha3A2;
    struct TreeNode folha4A2;
    struct TreeNode folha5A2;

    // ---------------------------
    raizA1.val = 3;
    raizA1.left = &no1A1;
    raizA1.right = &no2A1;

    no1A1.val = 5;
    no1A1.left = &folha1A1;
    no1A1.right = &no3A1;

    no2A1.val = 1;
    no2A1.left = &folha4A1;
    no2A1.right = &folha5A1;

    no3A1.val = 2;
    no3A1.left = &folha2A1;
    no3A1.right = &folha3A1;

    folha1A1.val = 6;
    folha1A1.left = NULL;
    folha1A1.right = NULL;

    folha2A1.val = 7;
    folha2A1.left = NULL;
    folha2A1.right = NULL;

    folha3A1.val = 4;
    folha3A1.left = NULL;
    folha3A1.right = NULL;

    folha4A1.val = 9;
    folha4A1.left = NULL;
    folha4A1.right = NULL;

    folha5A1.val = 8;
    folha5A1.left = NULL;
    folha5A1.right = NULL;

    // ---------------------------
    raizA2.val = 3;
    raizA2.left = &no1A2;
    raizA2.right = &no2A2;

    no1A2.val = 5;
    no1A2.left = &folha1A2;
    no1A2.right = &folha2A2;

    no2A2.val = 1;
    no2A2.left = &folha3A2;
    no2A2.right = &no3A2;

    no3A2.val = 2;
    no3A2.left = &folha4A2;
    no3A2.right = &folha5A2;

    folha1A2.val = 6;
    folha1A2.left = NULL;
    folha1A2.right = NULL;

    folha2A2.val = 7;
    folha2A2.left = NULL;
    folha2A2.right = NULL;

    folha3A2.val = 4;
    folha3A2.left = NULL;
    folha3A2.right = NULL;

    folha4A2.val = 9;
    folha4A2.left = NULL;
    folha4A2.right = NULL;

    folha5A2.val = 8;
    folha5A2.left = NULL;
    folha5A2.right = NULL;

    printf("Resultado: %i\n", leafSimilar(&raizA1, &raizA2));
    return 0;
}

bool leafSimilar(struct TreeNode* root1, struct TreeNode* root2)
{
    int *folhas1 = (int *)malloc(200 * sizeof(int));
    int tam1 = 0;

    int *folhas2 = (int *)malloc(200 * sizeof(int));
    int tam2 = 0;

    buscarFolhas(root1, folhas1, &tam1);
    buscarFolhas(root2, folhas2, &tam2);

    printf("TAM1: %i\n", tam1);
    printf("TAM2: %i\n", tam2);

    if (tam1 != tam2)
    {
        return false;
    }

    for (int i = 0; i < tam1; i++)
    {
        printf("Folha1: %i\n", *((int *)folhas1 + (1 * i)));
        printf("Folha2: %i\n\n", *((int *)folhas2 + (1 * i)));

        if (*((int *)folhas1 + (1 * i)) != *((int *)folhas2 + (1 * i)))
        {
            return false;
        }
    }

    return true;
}

void buscarFolhas(struct TreeNode *raiz, int *folhas, int *tam)
{
    if (raiz == NULL)
    {
        return;
    }

    if ((*raiz).left == NULL && (*raiz).right == NULL)
    {
        printf("VALOR FOLHA: %i\n", (*raiz).val);
        *((int *)folhas + (1 * *tam)) = (*raiz).val;
        printf("VALOR ARMAZENADO: %i\n", *((int *)folhas + (1 * *tam)));
        *tam = *tam + 1;
        return;
    }

    buscarFolhas((*raiz).left, folhas, tam);
    buscarFolhas((*raiz).right, folhas, tam);
}