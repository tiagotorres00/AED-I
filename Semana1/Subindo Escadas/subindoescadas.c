#include <stdio.h>

int climbStairs(int n);

int main(int argc, char const *argv[])
{
    int n;
    
    printf("n: ");
    scanf("%i", &n);

    int resposta = climbStairs(n);
    printf("Resposta: %i\n", resposta);
    
    return 0;
}

int climbStairs(int n)
{
    int resposta = 1;
    int anterior = 1;

    for (int i = 0; i < n - 1; i++)
    {
        int tmp = resposta;
        resposta = resposta + anterior;
        anterior = tmp;
    }

    return resposta;
}
