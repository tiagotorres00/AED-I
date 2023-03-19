/*
Faça um programa que armazene a informação de várias
pessoas numa pilha.
O programa deve possuir um menu:
0: Insere pessoa
1: Deleta pessoa do topo
2: Deleta pessoa por nome
3: Limpa a pilha
4: Lista na tela as pessoas
5: Sair do programa
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct
{
    char nome[50];
    int idade;
} 
Pessoa;

typedef struct
{
    Pessoa *pessoas;
    Pessoa *topo;
    Pessoa *base;
    int limite;
}
Pilha;

int main(int argc, char const *argv[])
{
    int opcao;
    Pilha *pilha;

    reset(pilha);

    while (1)
    {
        printf("\n");
        printf("0- Insere pessoa\n");
        printf("1- Deleta pessoa do topo\n");
        printf("2- Deleta pessoa por nome\n");
        printf("3- Limpar\n");
        printf("4- Listar\n");
        printf("5- Sair");
        scanf("%i", &opcao);

        switch (opcao)
        {
            case 0: // inserir pessoa
                Pessoa novapessoa;
                printf("Qual o nome?/n");
                scanf("%s", novapessoa.nome);

                printf("Qual a idade?\n");
                scanf("%i", novapessoa.idade);

                push(pilha, &novapessoa);
                break;

            case 1: // deleta do topo
                
                break;
            
            case 2: // deleta por nome
                
                break;
            
            case 3: // limpa
                
                break;
            
            case 4: // lista
                break;

            case 5:
                return;
        }
    }

    return 0;
}

void reset(Pilha *pilha)
{
    pilha->pessoas = NULL;
    pilha->topo = NULL;
    pilha->base = NULL;
    pilha->limite = 0;
}

bool empty(Pilha *pilha)
{
    return pilha->topo == pilha->pessoas;
}


bool push(Pilha *pilha, Pessoa *novapessoa)
{
    

    return true;
}