/*
1. O programa deve armazenar no máximo 10 pessoas

2.Todas as variáveis que forem usadas no programa deve ser ponteiros. 
A única exceção é o item 1 que deve ser uma variável global Pessoa pessoas[10].

    1.Os ponteiros devem apontar para um buffer chamado pBuffer onde os dados devem ser armazenados. 
    Por exemplo, um contador para um for deve ser um ponteiro para int e o int vai ficar armazenado dentro de pBuffer.

    2.Não pode usar struct dentro do pBuffer
*/

#include <stdio.h>
#include <stdlib.h>

struct Pessoa
{
    char nome[10];
    int idade;
    int telefone;
};

struct Pessoa pessoas[10];

int main(int argc, char const *argv[])
{
    
    return 0;
}
