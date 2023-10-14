#include <stdio.h>
#include <stdlib.h>

#define ANSI_GREEN "\x1b[32m"
#define ANSI_YELLOW "\x1b[33m"
#define ANSI_RED "\x1b[31m"
#define ANSI_RESET "\x1b[0m"
#define ANSI_BLUE "\x1b[34m"


void header(){

    system("clear");
    printf("==================================================================================================\n");
    printf(ANSI_GREEN "SISTEMA PARA ANÁLISE DE PERFORMANCE DE ALGORITMOS DE ORDENAÇÃO DE DADOS\n" ANSI_RESET);
    printf("==================================================================================================\n\n");
}

int sortingTypeChoise(){
    printf(ANSI_BLUE "1- BubbleSort\n" ANSI_RESET);
    printf(ANSI_YELLOW "2- QuickSort\n" ANSI_RESET);
    printf(ANSI_RED "3- SelectionSort\n\n" ANSI_RESET);
    printf("Qual tipo de ordenação você deseja analisar?\n");
    int choice;
    scanf("%d", &choice);
    return choice;
    
}

int arrayDefinitionChoise(){

    system("clear");

    printf(ANSI_BLUE "1- Arquivo de texto\n" ANSI_RESET);
    printf(ANSI_YELLOW "2- Valores aleatórios\n\n" ANSI_RESET);
    printf("Como deseja obter dados?\n");
    int arrayDefinition;
    scanf("%d",&arrayDefinition);

    return arrayDefinition;

}

void bubbleSort(int *array, int length) {
    int temp, swapped;

    for (int i = 0; i < length - 1; i++) {
        swapped = 0;
        for (int j = 0; j < length - 1 - i; j++) {
            if (array[j] > array[j + 1]) {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                swapped = 1;
            }
        }

        if (swapped == 0) {
            break;
        }
    }
}


int main() {
    header();

    int sorting = sortingTypeChoise();
    int arrayDefinition = arrayDefinitionChoise();

    
}