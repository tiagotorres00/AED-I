#include <stdio.h>
#include <string.h>

int minOperations(char ** logs, int logsSize);

int main(void)
{
    char *logs[] = {"d1/","../","../","../"};
    
    int logsSize = sizeof(logs) / sizeof(logs[0]);

    int resposta = minOperations(logs, logsSize);   
    printf("%i\n", resposta);

    return 0;
}

int minOperations(char ** logs, int logsSize)
{
    int distancia = 0;

    for (int i = 0; i < logsSize; i++)
    {
        if (strcmp(logs[i], "../") == 0)
        {
            distancia--;
            if (distancia < 0)
            {
                distancia = 0;
            }
        }
        else if (strcmp(logs[i], "./") == 0)
        {
            continue;
        }
        else
        {
            distancia++;
        }
    }

    return distancia;
}