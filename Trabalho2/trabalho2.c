#include <stdio.h>
#include <string.h>

int minOperations(char ** logs, int logsSize);

int main(int argc, char const *argv[])
{
    char *logs[] = {"d1/","../","../","../"};
    
    int logsSize = sizeof(logs) / sizeof(logs[0]);

    int resposta = minOperations(logs, logsSize);   
    printf("%i\n", resposta);

    return 0;
}

int minOperations(char ** logs, int logsSize)
{
    int x = 0;

    for (int i = 0; i < logsSize; i++)
    {
        if (strcmp(logs[i], "../") == 0)
        {
            x--;
            if (x < 0)
            {
                x = 0;
            }
        }
        else if (strcmp(logs[i], "./") == 0)
        {
            continue;
        }
        else
        {
            x++;
        }
    }

    return x;
}