#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

char ** removeAnagrams(char ** words, int wordsSize, int* returnSize);
void swap(char *x, char *y);
void quick_sort(char *word, int left, int right);

int main(int argc, char const *argv[])
{
    int wordsSize = 5;
    int *returnSize = malloc(sizeof(int));
    *returnSize = wordsSize;
    char **words = (char **)malloc(wordsSize * sizeof(char *));

    if (!words)
    {
        printf("Erro ao alocar memoria.");
        exit(1);
    }

    words[0] = "ab";
    words[1] = "bc";
    words[2] = "cb";
    words[3] = "ab";
    words[4] = "bc";

    char **novaLista = removeAnagrams(words, wordsSize, returnSize);

    for (int i = 0; i < *returnSize; i++)
    {
        printf("%s ", novaLista[i]);
    }

    for (int i = 0; i < *returnSize; i++)
    {
        free(novaLista[i]);
    }
    
    free(words);
    free(novaLista);
    return 0;
}

char ** removeAnagrams(char ** words, int wordsSize, int* returnSize){
    int numeroDeAnagramas = 0;

    for (int i = wordsSize-1; i > 0; i--)
    {
        bool anagrama = true;
        int tamanhoPalavra1 = strlen(words[i]), tamanhoPalavra2 = strlen(words[i-1]);

        if (tamanhoPalavra1 != tamanhoPalavra2) // Se nao tiverem o mesmo tamanho, nao sao anagramas
        {
            continue;
        }

        // Cria dois vetores para armazenar o numero de aparicoes de cada letra em uma palavra
        int letrasPalavra1[26] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        int letrasPalavra2[26] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

        for (int j = 0; j < tamanhoPalavra1; j++)
        {                                           
            letrasPalavra1[words[i][j] - 97]++;
            letrasPalavra2[words[i-1][j] - 97]++;
        }

        for (int j = 0; j < 26; j++)
        {
            if (letrasPalavra1[j] != letrasPalavra2[j]) // Se houver mais aparicoes de uma letra qualquer na palavra1 que na 2, nao sao anagramas
            {
                anagrama = false;
            }
        }

        if (anagrama)
        {
            words[i] = "A";
            numeroDeAnagramas++;
        }
    }

    *returnSize = wordsSize - numeroDeAnagramas;
    char **novaLista = (char **)malloc(*returnSize * sizeof(char *));

    if (!novaLista)
    {
        printf("Erro ao alocar memoria.");
        exit(1);
    }

    // Copia as palavras "originais" para a nova lista
    int j = 0;
    for (int i = 0; i < wordsSize; i++)
    {
        if (strcmp(words[i], "A") != 0)
        {
            novaLista[j] = (char *)malloc((strlen(words[i]) + 1) * sizeof(char));
            if (!novaLista[j])
            {
                printf("Erro ao alocar memoria");
                exit(1);
            }
            strcpy(novaLista[j], words[i]);
            j++;
        }
    }

    return novaLista;
}
