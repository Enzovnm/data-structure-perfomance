#include <stdio.h>

#define ANSI_GREEN "\x1b[32m"
#define ANSI_YELLOW "\x1b[33m"
#define ANSI_RED "\x1b[31m"
#define ANSI_RESET "\x1b[0m"
#define ANSI_BLUE "\x1b[34m"


int main() {
    
    printf(ANSI_GREEN "SISTEMA PARA ANÁLISE DE PERFORMANCE DE ALGORITMOS DE ORDENAÇÃO DE DADOS\n\n" ANSI_RESET);
    

    printf(ANSI_BLUE "1- BubbleSort\n" ANSI_RESET);
    printf(ANSI_YELLOW "2- QuickSort\n" ANSI_RESET);
    printf(ANSI_RED "3- SelectionSort\n\n" ANSI_RESET);

    int sortingType;
    
    printf("Qual tipo de ordenação você deseja analisar?\n");
    scanf("%d", &sortingType);

    switch (sortingType)
    {
    case 1:

    
        break;
    
    default:
        break;
    }
    return 0;
}