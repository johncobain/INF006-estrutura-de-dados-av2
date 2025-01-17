//Dupla: Gabriel Nascimento Miranda Dos Santos (20241160019), Andrey Gomes Da Silva Nascimento (20241160024);
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct LI
{
    int num;
    struct LI *prox;
}LI;

typedef struct LE
{
    int num;
    struct LI *elementos;
    struct LE *anterior;
    struct LE *prox;
}LE;


void OrdenarVetor(LE arr[], int qtdLE) {
    int i, j, temp;

    for (i = 0; i < qtdLE - 1; i++) {
        for (j = 0; j < qtdLE - i - 1 && arr[j].prox != NULL; j++) {
            if (arr[j].num > arr[j + 1].num) {
                temp = arr[j].num;
                arr[j].num = arr[j + 1].num;
                arr[j + 1].num = temp;
            }
        }
    }
}

int main(){
    FILE *fp_in = fopen("L1Q3.in", "r");
    FILE *fp_out = fopen("L1Q3.out", "w");
    char line[1000];
    char space[] = " ";
    
    if (fp_in == NULL || fp_out == NULL){
        printf("Arquivos nao podem ser abertos.");
        return EXIT_FAILURE;
    }

    printf("TEST");

    while (fgets(line, sizeof(line), fp_in) != NULL){
        int qtdLE = 0;
        LE Ancora[1000];
        Ancora[0].anterior = NULL;

        LI Elementos[1000];

        char *slice = strtok(line, space);

        //Adquirir todos os elementos da ancora após LE e antes de LI
        if(strcmp(slice, "LE") == 0){
            slice = strtok(NULL, space);
            for(int i = 0;slice != NULL && strcmp(slice, "LI") != 0; i++){
                if(i > 0){
                    Ancora[i-1].prox = &Ancora[i];
                    Ancora[i].anterior = &Ancora[i-1];
                } 
                Ancora[i].prox = NULL;
                Ancora[i].num = atoi(slice);
                qtdLE++;
                slice = strtok(NULL, &space);
            }
        }

        for(int i = 0; i < qtdLE;i++){
            fprintf(fp_out,"%d ",Ancora[i].num);
        }
        fprintf(fp_out," | ");
        //ordenar lista LE
        OrdenarVetor(Ancora, qtdLE);
        printf("\n");

        for(int i = 0; i < qtdLE;i++){
            fprintf(fp_out,"%d ",Ancora[i].num);
        }
        fprintf(fp_out,"\n");

        //Adquirir todos os elementos da lista circular após o LI
        // if(strcmp(slice, "LI")){

        // }
    }

    fclose(fp_in);
    fclose(fp_out);
    return 0;
}
