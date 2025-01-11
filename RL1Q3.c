//Dupla: Gabriel Nascimento Miranda Dos Santos (20241160019), Andrey Gomes Da Silva Nascimento (20241160024);
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){
    FILE *fp_in = fopen("L1Q3.in", "r");
    FILE *fp_out = fopen("L1Q3.out", "w");
    char line[1000];
    if (fp_in == NULL || fp_out == NULL){
        printf("Arquivos nao podem ser abertos.");
        return EXIT_FAILURE;
    }

    printf("TEST");

    // while (fgets(line, sizeof(line), fp_in) != NULL){
    //     char space[] = " ";
    // }

    fclose(fp_in);
    fclose(fp_out);
    return 0;
}