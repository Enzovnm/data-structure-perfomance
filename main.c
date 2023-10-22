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

void invalidOption(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    printf(ANSI_RED "Opção inválida. Tente novamente!\n" ANSI_RESET);
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

int readingArrayLength(){
    int length;
    printf("Digite o tamanho do array:\n");
    scanf("%d", &length);
    return length;
}


void printArray(const int *array, int length) {
    for (int i = 0; i < length; i++) {
        printf("%d ", array[i]);
    }

    printf("\n\n");
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

void selectionSort(int *array, int length){
    int min_indx;
    for (int i = 0; i < length - 1; i++) {
        min_indx = i;
        for (int j = i + 1; j < length; j++) {
            if (array[j] < array[min_indx])
                min_indx = j;
        }
        if (min_indx != i) {
            swap(&array[min_indx], &array[i]);
        }
    }
}

void executeSort(int sorting, int isFile, int *array, int length) {
    if (isFile == 0) {
        printf(ANSI_GREEN "Dados iniciais:\n" ANSI_RESET);
        printArray(array, length);
    }

    switch (sorting) {
        case 1:
            bubbleSort(array, length);
            if (isFile == 0) {
                printf(ANSI_BLUE "Dados ordenados com BubbleSort:\n" ANSI_RESET);
                printArray(array, length);
            }
            break;
        case 2:
            quickSort(array, 0, length - 1);
            if (isFile == 0) {
                printf(ANSI_BLUE "Dados ordenados com QuickSort:\n" ANSI_RESET);
                printArray(array, length);
            }
            break;
        default:
            selectionSort(array, length);
            if (isFile == 0) {
                printf(ANSI_BLUE "Dados ordenados com SelectionSort:\n" ANSI_RESET);
                printArray(array, length);
            }
    }
    
    if(isFile == 0){
        free(array);
        array = NULL;
    }
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
                executeSort(sorting,0,array,length);
                break;

            case 2:
                int maxNumbers = 500000;
                int num;
                int count = 0;
                int *arrayFile = (int *)malloc(maxNumbers * sizeof(int));
                char filename[256];

                
                printf("Digite o nome do arquivo: ");
                scanf("%s",filename);

                FILE *file = fopen(filename,"r");

                while (file == NULL)
                {
                    printf(ANSI_RED "Não foi possível abrir o arquivo %s, Digite o nome do arquivo novamente\n" ANSI_RESET, filename);
                    scanf("%s", filename);
                    file = fopen(filename, "r");
                }
                

                for(count; count < maxNumbers && fscanf(file,"%d", &num) != EOF; count ++ ){
                    arrayFile[count] = num;
                }

                fclose(file);
                system("clear");
                int sortingForFile = sortingTypeChoise();
                executeSort(sortingForFile, 1, arrayFile, count);
                
                FILE *outputFile = fopen("output.txt", "w");

                if(outputFile == NULL){
                    printf(ANSI_RED "Não foi possível escrever o arquivo %s\n" ANSI_RESET, filename);
                    exit(EXIT_FAILURE);
                }

                for (int i = 0; i < count; i++) {
                    fprintf(outputFile, "%d\n", arrayFile[i]);
                }

                fclose(outputFile);

                free(arrayFile);
                arrayFile = NULL;

                printf(ANSI_BLUE "Foi gerado um novo arquivo output.txt com seus dados ordenados!\n" ANSI_RESET);


                break;

            case 3:
                exit(EXIT_SUCCESS);
            
            default:
                invalidOption();
                break;
        }
    }
    return 0;
}