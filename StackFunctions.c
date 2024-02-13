#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

typedef struct elemento
{
    int numero;
    struct elemento *prox;
}elemento;

typedef struct pilha{
    elemento *topo;
}pilha;

void inicializaPilha(pilha *p){
    p->topo = NULL;
}

void empilha(pilha *p, int n){
    elemento *novo = (elemento*)malloc(sizeof(elemento));
    novo->numero = n;
    novo->prox = p->topo;
    p->topo = novo;
}

int desempilha(pilha *p){
    if(p->topo == NULL){
        printf("Pilha vazia\n");
        return -1;
    }
    int n = p->topo->numero;
    elemento *lixo = p->topo;
    p->topo = p->topo->prox;
    free(lixo);
    return n;
}

void imprimePilha(pilha *p){
    elemento *aux = p->topo;
    while(aux != NULL){
        printf("%d\n", aux->numero);
        aux = aux->prox;
    }
}
void CompararPilhas(pilha *p1, pilha *p2){
    elemento *aux = p1->topo;
    elemento *aux2 = p2->topo;
    int cont1 = 0;
    int cont2 = 0;
    while(aux != NULL){
        cont1++;
        aux = aux->prox;
}
    while(aux2 != NULL){
        cont2++;
        aux2 = aux2->prox;
    }
    if(cont1 == cont2){
        printf("As pilhas tem o mesmo tamanho\n");
    }
    else{
        printf("As pilhas tem tamanhos diferentes\n");
        printf("Pilha 1: %d\n", cont1);
        printf("Pilha 2: %d\n", cont2);
        printf("A maior pilha eh a \'%d\' \n", (cont1 > cont2) ? 1 : 2);
    }
}

void MaiorMenorMedia(pilha *p){
    if (p->topo == NULL){
        printf("Pilha vazia\n");
        return;
    }

    elemento *aux = p->topo;
    int maior = aux->numero;
    int menor = aux->numero;
    int media = 0;
    int cont = 0;
    while(aux != NULL){
        if(aux->numero > maior){
            maior = aux->numero;
        }
        if(aux->numero < menor){
            menor = aux->numero;
        }
        media += aux->numero;
        cont++;
        aux = aux->prox;
    }
    media = media/cont;
    printf("Maior: %d\n", maior);
    printf("Menor: %d\n", menor);
    printf("Media: %d\n", media);
}

void VerificaImpares(pilha *p){
    if (p->topo == NULL){
        printf("Pilha vazia\n");
        return;
    }
    elemento *aux = p->topo;
    int cont = 0;
    while(aux != NULL){
        if(aux->numero % 2 != 0){
            cont++;
        }
        aux = aux->prox;
    }
    printf("Numero de impares: %d\n", cont);
}

void VerificaPares(pilha *p){
    if (p->topo == NULL){
        printf("Pilha vazia\n");
        return;
    }
    elemento *aux = p->topo;
    int cont = 0;
    while (aux != NULL){
        if (aux->numero % 2 ==0)
            cont++;
        aux = aux->prox;
    }
    printf("Numero de pares: %d\n", cont);
}

int main(){
    srand(time(NULL));

    pilha p1, p2;
    int opcao;

    inicializaPilha(&p1);
    inicializaPilha(&p2);

    for (int i = 0; i < rand()%20; i++)
        empilha(&p1, rand()%100);

    for (int i = 0; i < rand()%20; i++)
        empilha(&p2, rand()%100);

    printf("Pilha 1\n");
    imprimePilha(&p1);
    printf("Pilha 2\n");
    imprimePilha(&p2);

    while (opcao != 0){

    
    printf("\n\nDigite a opcao desejada\n");
    printf("1 - Transferir elementos da pilha 1 para a pilha 2\n");
    printf("2 - Comparar pilhas\n");
    printf("3 - Maior/Menor/Media da pilha\n");
    printf("4 - Numero de impares na pilha\n");
    printf("5 - Numero de pares na pilha\n");
    printf("0 - Sair\n");

    scanf("%d", &opcao);

    switch (opcao)
    {

    case 1:
        while(p1.topo != NULL){
            empilha(&p2, desempilha(&p1));
        }
        printf("Pilha 1\n");
        imprimePilha(&p1);
        printf("Pilha 2\n");
        imprimePilha(&p2);
        break;

    case 2:
        CompararPilhas(&p1, &p2);
        break;
    case 3:
        printf("\nPilha 1\n");
        MaiorMenorMedia(&p1);
        printf("\nPilha 2\n");
        MaiorMenorMedia(&p2);
        break;
    case 4:
        printf("\nPilha 1\n");
        VerificaImpares(&p1);
        printf("\nPilha 2\n");
        VerificaImpares(&p2);
        break;
    case 5:
        printf("\nPilha 1\n");
        VerificaPares(&p1);
        printf("\nPilha 2\n");
        VerificaPares(&p2);
        break;

    default:
        break;
    }
    }

    return 0;
}
