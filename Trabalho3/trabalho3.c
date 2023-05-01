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
    struct TreeNode raizA1;
    struct TreeNode folha1A1;
    struct TreeNode folha2A1;
 
    struct TreeNode raizA2;
    struct TreeNode folha1A2;
    struct TreeNode folha2A2;
 
    // --------------------------
    raizA1.val = 1;
    raizA1.left = &folha1A1;
    raizA1.right = &folha2A1;
 
    folha1A1.val = 2;
    folha1A1.left = NULL;
    folha1A1.right = NULL;
 
    folha2A1.val = 3;
    folha2A1.left = NULL; 
    folha2A1.right = NULL;
 
    // ---------------------------
    raizA2.val = 1;
    raizA2.left = &folha1A2;
    raizA2.right = &folha2A2;
 
    folha1A2.val = 3;
    folha1A2.left = NULL;
    folha1A2.right = NULL;
 
    folha2A2.val = 2;
    folha2A2.left = NULL;
    folha2A2.right = NULL;
 
    int resultado = leafSimilar(&raizA1, &raizA2);
    if (resultado == 1)
    {
        printf("Sao similares.\n");
    }
    else
    {
        printf("Nao sao similares");
    }
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
 
    if (tam1 != tam2)
    {
        return false;
    }
 
    for (int i = 0; i < tam1; i++)
    {
        if (*((int *)folhas1 + (1 * i)) != *((int *)folhas2 + (1 * i)))
        {
            free(folhas1);
            free(folhas2);
            return false;
        }
    }
 
    free(folhas1);
    free(folhas2);
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
        *((int *)folhas + (1 * *tam)) = (*raiz).val;
        *tam = *tam + 1;
        return;
    }
 
    buscarFolhas((*raiz).left, folhas, tam);
    buscarFolhas((*raiz).right, folhas, tam);
}