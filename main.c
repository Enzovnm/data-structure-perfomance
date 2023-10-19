#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ANSI_GREEN "\x1b[32m"
#define ANSI_YELLOW "\x1b[33m"
#define ANSI_RED "\x1b[31m"
#define ANSI_RESET "\x1b[0m"
#define ANSI_BLUE "\x1b[34m"


void header(){
    printf("========================================================================\n");
    printf(ANSI_GREEN "SISTEMA PARA ANÁLISE DE PERFORMANCE DE ALGORITMOS DE ORDENAÇÃO DE DADOS\n" ANSI_RESET);
    printf("========================================================================\n\n");
}

void printArray(const int *array, int length) {

    for (int i = 0; i < length; i++) {
        printf("%d ", array[i]);
    }

    printf("\n\n");
}

void invalidOption(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    printf(ANSI_RED "Opção inválida. Tente novamente!\n\n" ANSI_RESET);
}


int sortingTypeChoise(){

    printf(ANSI_BLUE "1- BubbleSort\n" ANSI_RESET);
    printf(ANSI_YELLOW "2- QuickSort\n" ANSI_RESET);
    printf(ANSI_RED "3- SelectionSort\n\n" ANSI_RESET);
    printf("Qual tipo de ordenação você deseja analisar?\n");

    int choice;

    while (1) {
        if (scanf("%d", &choice) != 1 || choice < 1 || choice > 3) {
            invalidOption();
        } else {
            break;
        }
    }

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

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void bubbleSort(int *array, int length) {
    int swapped;

    for (int i = 0; i < length - 1; i++) {
        swapped = 0;
        for (int j = 0; j < length - 1 - i; j++) {
            if (array[j] > array[j + 1]) {
                swap(&array[j], &array[j + 1]);
                swapped = 1;
            }
        }

        if (swapped == 0) {
            break;
        }
    }
}

int partition(int *array, int low, int high){

    int pivot = array[high];
    int i = (low - 1);

    for(int j = low; j < high; j++){
        if(array[j] <=  pivot){
            i++;
            swap(&array[i], &array[j]);
        }
    }

    swap(&array[i + 1], &array[high]);

    return (i + 1);
}


void quickSort(int *array, int low, int high){
    if(low < high){
        int pi = partition(array,low,high);
        quickSort(array, low, pi - 1);
        quickSort(array, pi + 1, high);
    }
}


int *createRandomArray(int length){
    int *array;
    srand(time(NULL));
    array = (int *)malloc(length * sizeof(int));

    for (int i = 0; i < length; i++){
        array[i] = rand();
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
                int *array = createRandomArray(length);

                system("clear");
                
                printf(ANSI_GREEN "Dados iniciais:\n" ANSI_RESET);
                printArray(array,length);

                if(sorting == 1){
                    bubbleSort(array, length);
                    printf(ANSI_BLUE "Dados ordenados com BubbleSort:\n" ANSI_RESET);
                    printArray(array,length);
                    free(array);
                    array = NULL;
                }
                else if(sorting == 2){
                    quickSort(array,0,length - 1);
                    printf(ANSI_BLUE "Dados ordenados com QuickSort:\n" ANSI_RESET);
                    printArray(array,length);
                    free(array);
                    array = NULL;
                }
                else if(sorting == 3){

                }
                else{
                    
                }

                break;
            case 2:
                break;
            case 3:
                exit(0);
            
            default:
                invalidOption();
                break;
        }
    }
    return 0;
}