#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool haveConflict(char ** evento1, int evento1Tamanho, char ** evento2, int evento2Tamanho);

int main(int argc, char const *argv[])
{
    char** evento1 = (char**) malloc(10 * sizeof(char));
    evento1[0] = "14:15";
    evento1[1] = "15:00";

    char** evento2 = (char**) malloc(10 * sizeof(char));
    evento2[0] = "09:30";
    evento2[1] = "11:00";

    int evento1Tamanho = 2;
    int evento2Tamanho = 2;

    if (haveConflict(evento1, evento1Tamanho, evento2, evento2Tamanho))
    {
        printf("Verdadeiro");
    }
    else
    {
        printf("Falso");
    }

    return 0;
}

bool haveConflict(char ** evento1, int evento1Tamanho, char ** evento2, int evento2Tamanho)
{
    int inicio1 = (((int)evento1[0][0] - 48) * 600 + ((int)evento1[0][1] - 48) * 60 + ((int)evento1[0][3] - 48) * 10 + ((int)evento1[0][4] - 48) * 1);
    int fim1 = (((int)evento1[1][0] - 48) * 600 + ((int)evento1[1][1] - 48) * 60 + ((int)evento1[1][3] - 48) * 10 + ((int)evento1[1][4] - 48) * 1);
    int inicio2 = (((int)evento2[0][0] - 48) * 600 + ((int)evento2[0][1] - 48) * 60 + ((int)evento2[0][3] - 48) * 10 + ((int)evento2[0][4] - 48) * 1);
    int fim2 = (((int)evento2[1][0] - 48) * 600 + ((int)evento2[1][1] - 48) * 60 + ((int)evento2[1][3] - 48) * 10 + ((int)evento2[1][4] - 48) * 1);

    if (fim1 < inicio2)
    {
        return false;
    }
    else if (fim1 == inicio2)
    {
        return true;
    }
    else
    {
        if (fim2 < inicio1)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
}