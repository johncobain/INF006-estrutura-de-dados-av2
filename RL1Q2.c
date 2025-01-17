//Dupla: Gabriel Nascimento Miranda Dos Santos (20241160019), Andrey Gomes Da Silva Nascimento (20241160024);
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stack {
    int top;
    char names[512][512];
} Stack;

void pop(Stack *s);
void push(Stack *s, char name[]);
void initializeStack(Stack *s);

int main() {
    FILE *fp_in = fopen("L1Q2.in", "r");
    FILE *fp_out = fopen("L1Q2.out", "w");
    char line[1000];

    if (fp_in == NULL || fp_out == NULL) {
        printf("Arquivos não podem ser abertos.\n");
        return EXIT_FAILURE;
    }

    while (fgets(line, sizeof(line), fp_in) != NULL) {
        printf("Linha lida: '%s'\n", line); // Log da linha lida
        line[strcspn(line, "\n")] = '\0'; // Remove o \n da linha lida /*ERROR*/
        printf("Linha lida: '%s'\n", line); // Log da linha lida

        Stack stack, secondary;
        initializeStack(&stack);
        initializeStack(&secondary);

        char *slice = strtok(line, " "); // Quebra a linha em tokens
        printf("Tokens:\n");

        while (slice != NULL) {
            printf("  Token: '%s'\n", slice); // Log do token
            if (stack.top == 0 || strcmp(slice, stack.names[stack.top - 1]) >= 0) {
                push(&stack, slice);
            } else {
                while (stack.top > 0 && strcmp(slice, stack.names[stack.top - 1]) < 0) {
                    push(&secondary, stack.names[stack.top - 1]);
                    pop(&stack);
                }
                push(&stack, slice);
                while (secondary.top > 0) {
                    push(&stack, secondary.names[secondary.top - 1]);
                    pop(&secondary);
                }
            }
            slice = strtok(NULL, " ");
        }

        printf("\nPilha final:\n");
        while (stack.top > 0) {
            printf("%s ", stack.names[stack.top - 1]);
            pop(&stack);
        }
        printf("\n==========================\n");
    }

    fclose(fp_in);
    fclose(fp_out);
    return 0;
}

void initializeStack(Stack *s) {
    s->top = 0;
    memset(s->names, 0, sizeof(s->names));
}

void pop(Stack *s) {
    if (s->top > 0) {
        s->top--;
    }
}

void push(Stack *s, char name[]) {
    if (s->top < 512) { // Limite da pilha
        strcpy(s->names[s->top], name);
        s->top++;
    }
}
