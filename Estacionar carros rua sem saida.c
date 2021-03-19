#include <stdio.h>
#include <stdlib.h>

typedef struct _Stack
{
    int top;
    int size;
    int *vector;
} Stack;

int empty (Stack *p)
{
    return (p->top == 0);
}

int full (Stack *p)
{
    return (p->top == p->size);
}

Stack* create_stack (int size)
{
    Stack *p = (Stack *)malloc(sizeof(Stack));
    p->top = 0;
    p->size = size;
    p->vector = (int *)malloc(size * sizeof(int));
    return p;
}

void push (Stack *p, int elem)
{
    if (full(p))
    {
        printf("pilha cheia: capacidade esgotada\n");
    }
    p->vector[p->top] = elem;
    p->top++;
}

int pop (Stack *p)
{
    if (empty(p))
    {
        printf("pilha vazia!\n");
        exit(1);
    }
    p->top--;
    return p->vector[p->top];
}
void estaciona_carro (Stack *p, int elem)
{
    if(full(p))
        {
            printf("Nao eh possivel:Rua cheia\n\n");
        }
        else
        {
            push(p, elem);
        }

}

void retira_carro (Stack *p, int elem)
{
    int movimentos = -1;
    if(empty(p))
    {
        printf("Nao é possivel : Rua ja está vazia");
    }
    else
    {
        while(p->vector[p->top] != elem)
        {
            p->top--;
            movimentos++;
        }

        printf("Foram necessarios tirar %d Carros da fila\n\n", movimentos);

    }

}




void free_stack (Stack *p)
{
    free(p->vector);
    free(p);
}
int main()
{
    Stack *pilha = create_stack(5);
    int placa, a, j=1;
    while(j>0)
    {
        printf("1-ESTACIONAR CARRO\n2-RETIRAR CARRO\n");
        scanf("%d", &a);
        if(a == 1)
        {
            printf("DIGITE A PLACA DO CARRO:\n");
            scanf("%d", &placa);
            estaciona_carro(pilha, placa);
        }
        else if(a == 2)
        {
            printf("DIGITE A PLACA DO CARRO PARA RETIRAR:\n");
            scanf("%d", &placa);
            retira_carro(pilha, placa);

        }
        placa = 0;
        a = 0;
    }
    free_stack(pilha);
    return 0;

}
