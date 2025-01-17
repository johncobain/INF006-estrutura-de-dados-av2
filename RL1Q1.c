//Dupla: Gabriel Nascimento Miranda Dos Santos (20241160019), Andrey Gomes Da Silva Nascimento (20241160024);
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct list{
    int values[512];
    int size;
    int sum;
} List;

void bubble(int values[], int size){
    for(int i = 0; i < size; i++){    
        for(int j = 0; j < size-1-i; j++){
            int aux;
            if(values[j] > values[j+1]){
                aux = values[j];
                values[j] = values[j+1];
                values[j+1] = aux;
            }
        }
    }
}


int main(){
    FILE *fp_in = fopen("L1Q1.in", "r");
    FILE *fp_out = fopen("L1Q1.out", "w");
    char line[1000];
    if (fp_in == NULL || fp_out == NULL){
        printf("Arquivos nao podem ser abertos.");
        return EXIT_FAILURE;
    }

    char space[] = " ";
    char lineCount = 0;

    while (fgets(line, sizeof(line), fp_in) != NULL){
        List lists[512];
        int count = -1;

        char *slice = strtok(line, space); // Quebra inicial por espaços


        // Processar todas as listas na linha
        while (slice != NULL){
            // Ignorar a palavra "start"
            if(strcmp(slice, "start") == 0){
                count++;
                lists[count].size = 0;
                lists[count].sum = 0;
            }else{
                lists[count].values[lists[count].size] = atoi(slice);
                lists[count].size++;
                lists[count].sum += atoi(slice);
            }
            slice = strtok(NULL, space);
        }

        // ordenar cada lista internamente
        for(int i = 0; i<=count; i++){
            bubble(lists[i].values, lists[i].size);
        }

        // printar no console cada lista
        for(int i = 0; i<=count; i++){
            printf("line %d, list %d: ", lineCount+1, i+1);
            for(int j = 0; j < lists[i].size; j++){
                printf("%d ", lists[i].values[j]);
            }
            printf(" | sum: %d\n", lists[i].sum);
        }
        
        // liberar lista no final
        // for(int i = 0; i <= count; i++){
        //     free(lists[i].values);
        // }
        // free(lists);
        lineCount++;
    }

    fclose(fp_in);
    fclose(fp_out);
    return 0;
}