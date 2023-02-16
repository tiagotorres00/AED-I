// Crie um programa que compara duas strings (nao use a funcao strcmp). 

#include <stdio.h>
#include <string.h>

int main(void)
{
    char str1[50];
    char str2[50];

    printf("Digite a primeira string: ");
    scanf("%s", str1);

    printf("Digite a segunda string: ");
    scanf("%s", str2);

    int n1 = strlen(str1);
    int n2 = strlen(str2);

    if (n1 != n2)
    {
        printf("As strings sao diferentes.\n");
        return 0;
    }
    else
    {   
        int x = 0;
        for (int i = 0; i < n1; i++)
        {
            if (str1[i] == str2[i])
            {
                x++;
            }
        }
        if (x == n1)
        {
            printf("As strings sao iguais!\n");
            return 0;
        }
        else
        {
            printf("As strings sao diferentes.\n");
            return 0;
        }
    }
}