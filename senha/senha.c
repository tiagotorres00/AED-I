// Verificar se uma senha tem pelo menos uma letra minúsculo, uma maiúscula, um número e um símbolo

#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

bool validar(char *senha);

int main(void)
{
    char *senha[50];
    printf("Digite sua senha:");
    scanf("%s", senha);

    if (validar(senha))
    {
        printf("Senha valida!\n");
    }
    else
    {
        printf("Sua senha precisa de pelo menos: uma letra minuscula, uma maiuscula, um numero e um simbolo\n");
    }
}

bool validar(char *senha)
{
    bool minuscula = false;
    bool maiuscula = false;
    bool numero = false;
    bool simbolo = false;

    // Verifica se todos requisitos são cumpridos
    for (int i = 0, n = strlen(senha); i < n; i++)
    {
        if (islower(senha[i]))
        {
            minuscula = true;
        }
        else if (isupper(senha[i]))
        {
            maiuscula = true;
        }
        else if (senha[i] >= 48 && senha[i] <= 57)
        {
            numero = true;
        }
        else if (senha[i] >= 33 && senha[i] <= 47)
        {
            simbolo = true;
        }
    }

    if (minuscula && maiuscula && numero && simbolo)
    {
        return true;
    }

    return false;
}
