//Dupla: Gabriel Nascimento Miranda Dos Santos (20241160019), Andrey Gomes Da Silva Nascimento (20241160024);
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct LI
{
    int num;
    LI *prox;
}LI;

typedef struct LE
{
    int num;
    LI *elementos;
    LE *anterior;
    LE *prox;
}LE;


int main(){
    FILE *fp_in = fopen("L1Q3.in", "r");
    FILE *fp_out = fopen("L1Q3.out", "w");
    char line[1000];
    char space = " ";
    if (fp_in == NULL || fp_out == NULL){
        printf("Arquivos nao podem ser abertos.");
        return EXIT_FAILURE;
    }

    printf("TEST");

    while (fgets(line, sizeof(line), fp_in) != NULL){
        LE Ancora[1000];
        Ancora[0].anterior = NULL;

        LI Elementos[1000];

        char *slice = strtok(line, space);

        if(strcmp(slice, "LE") == 0){
            slice = strtok(NULL, space);
            for(int i = 0; strcmp(slice, "LI") != 0; i++){
                if(i > 0){
                    Ancora[i-1].prox = &Ancora[i];
                    Ancora[i].anterior = &Ancora[i-1];
                } 
                Ancora[i].prox = NULL;
                Ancora[i].num = atoi(slice);
            }
        }
        if(strcmp(slice, "LI")){

        }
    }

    fclose(fp_in);
    fclose(fp_out);
    return 0;
}