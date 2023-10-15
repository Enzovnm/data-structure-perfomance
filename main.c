#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>

#define ANSI_GREEN "\x1b[32m"
#define ANSI_YELLOW "\x1b[33m"
#define ANSI_RED "\x1b[31m"
#define ANSI_RESET "\x1b[0m"
#define ANSI_BLUE "\x1b[34m"

void printArray(int *array, int length) {

    for (int i = 0; i < length; i++) {
        printf("%d ", array[i]);
    }

    printf("\n\n");
}

void header(){
    printf("========================================================================\n");
    printf(ANSI_GREEN "SISTEMA PARA ANÁLISE DE PERFORMANCE DE ALGORITMOS DE ORDENAÇÃO DE DADOS\n" ANSI_RESET);
    printf("========================================================================\n\n");
}

int sortingTypeChoise(){

    printf(ANSI_BLUE "1- BubbleSort\n" ANSI_RESET);
    printf(ANSI_YELLOW "2- QuickSort\n" ANSI_RESET);
    printf(ANSI_RED "3- SelectionSort\n\n" ANSI_RESET);
    printf("Qual tipo de ordenação você deseja analisar?\n");

    int choice;
    scanf("%d", &choice);
    system("clear");
    return choice;
    
}

int arrayDefinitionChoise(){

    printf("Digite uma das opções abaixo:\n\n");
    printf(ANSI_BLUE "1- Valores aleatórios\n" ANSI_RESET);
    printf(ANSI_YELLOW "2- Arquivo de texto\n" ANSI_RESET);
    printf(ANSI_RED "3 - Sair \n\n" ANSI_RESET);

    int arrayDefinition;
    scanf("%d",&arrayDefinition);

    system("clear");

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


int *creatingArrayRandValues(length){
    int *array;

    array = (int *)malloc(length * sizeof(int));

    for (int i = 0; i < length; i++){
        array[i] = (rand() % 100) + 1;
    }

    return array;
    
}

int readingArrayLength(){
    int length;
    printf("Digite o tamanho do array:\n");
    scanf("%d", &length);
    return length;
}


int main() {
    while(1){

        header();
        int arrayDefinition = arrayDefinitionChoise();

        switch(arrayDefinition){
            case 1:

                int sorting = sortingTypeChoise();
                int length = readingArrayLength();
                int *array = creatingArrayRandValues(length);

                system("clear");

                printf(ANSI_GREEN "Dados iniciais:\n" ANSI_RESET);
                printArray(array,length);

                if(sorting == 1){
                    bubbleSort(array, length);
                    printf(ANSI_BLUE "Dados ordenados com BubbleSort:\n" ANSI_RESET);
                    printArray(array,length);
                    free(array);
                }

                break;
            case 2:
                break;
            case 3:
                exit(0);
            
            default:
                printf("Opção inválida. Tente novamente.\n");
                break;
        }

    }
}