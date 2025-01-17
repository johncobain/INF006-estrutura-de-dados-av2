#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
    char *items[MAX];
    int top;
} Pilha;

void inicializaPilha(Pilha *p) {
    p->top = -1;
}

int estaVazia(Pilha *p) {
    return p->top == -1;
}

int estaCheia(Pilha *p) {
    return p->top == MAX - 1;
}

void push(Pilha *p, char *valor) {
    if (estaCheia(p)) {
        printf("Pilha cheia!\n");
        return;
    }
    
    // Criar pilha temporária para reorganização
    Pilha temp;
    inicializaPilha(&temp);
    
    // Remover elementos maiores que o novo valor
    while (!estaVazia(p) && strcmp(p->items[p->top], valor) < 0) {
        temp.items[++temp.top] = p->items[p->top--];
    }
    
    // Inserir novo valor
    p->items[++p->top] = valor;
    
    // Recolocar elementos removidos
    while (!estaVazia(&temp)) {
        p->items[++p->top] = temp.items[temp.top--];
    }
}

char* pop(Pilha *p) {
    if (estaVazia(p)) {
        printf("Pilha vazia!\n");
        return NULL;
    }
    return p->items[p->top--];
}

void imprimePilha(Pilha *p) {
    printf("\nPilha atual:\n");
    for (int i = p->top; i >= 0; i--) {
        printf("%s\n", p->items[i]);
    }
    printf("\n");
}

int main() {
    Pilha p;
    inicializaPilha(&p);
    
    // Inserindo os nomes da primeira linha
    push(&p, "bruno");
    push(&p, "dani");
    push(&p, "carla");
    push(&p, "antonia");
    push(&p, "walter");
    
    // Inserindo os nomes da segunda linha
    push(&p, "maria");
    push(&p, "joao");
    
    // Inserindo os nomes das linhas seguintes
    push(&p, "maria");
    push(&p, "joao");
    push(&p, "opa");
    push(&p, "bula");
    push(&p, "chica");
    push(&p, "suca");
    push(&p, "mara");
    push(&p, "nara");
    push(&p, "cabanca");
    
    imprimePilha(&p);
    
    return 0;
}
