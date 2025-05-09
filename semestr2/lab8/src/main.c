#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdarg.h>
#include <setjmp.h>
#include <cmocka.h>

typedef struct {
    long comparisons;
    long swaps;
} Stats;

void swap(int *a, int *b, Stats *stats) {
    int temp = *a;
    *a = *b;
    *b = temp;
    stats->swaps++;
}

void swapTest(int *a, int *b, Stats *stats){

    stats->swaps = 0;
    printf("Data: \n a = %d, b = %d, swaps = %d", *a, *b, stats->swaps);
    printf("\na <--> b\n");
    swap(a, b, stats);
    printf("Result: \n a = %d, b = %d, swaps = %d", *a, *b, stats->swaps);
    
}

void quick_sort(int arr[], int left, int right, Stats *stats) {
    if (left >= right) return;

    int pivot = arr[left];
    int i = left + 1;
    int j = right;

    while (1) {
        while (i <= j && arr[i] <= pivot) {
            i++;
            stats->comparisons++;
        }
        if (i <= j) stats->comparisons++;

        while (i <= j && arr[j] >= pivot) {
            j--;
            stats->comparisons++;
        }
        if (i <= j) stats->comparisons++;

        if (i <= j) {
            swap(&arr[i], &arr[j], stats);
        } else {
            break;
        }
    }

    if (left != j) {
        swap(&arr[left], &arr[j], stats);
    }

    quick_sort(arr, left, j - 1, stats);
    quick_sort(arr, j + 1, right, stats);
}

void generate_array(int arr[], int n, int type) {
    switch(type) {
        case 0: // Убывающий
            for (int i = 0; i < n; i++) arr[i] = n - i;
            break;
        case 1: // Возрастающий
            for (int i = 0; i < n; i++) arr[i] = i + 1;
            break;
        case 2: // Случайный
            for (int i = 0; i < n; i++) arr[i] = rand() % (n * 10);
            break;
    }
}

void print_mas(int arr[], int n){
    printf("массив:\n");
    for(int i = 0; i < n; i++){
        printf(" %4d", arr[i]);
        if((i + 1) % 40 == 0) printf("\n");
    }
    printf("\n");
}

void test_generate_array(int arr[], int n){
    int A[n];
    Stats stats[3] = {0};

    for (int type = 0; type < 3; type++) {
        generate_array(arr, n, type);
        if( type == 0) printf("\nУбывающий ");
        else if( type == 1) printf("\nВозрастающий ");
        else printf("\nСлучайный ");
        print_mas(arr, n);
    }
}

void analyze_for_n(int n) { //это просто вывод таблицы 
    int arr[n];
    Stats stats[3] = {0}; // 0 - убыв, 1 - возр, 2 - случ

    for (int type = 0; type < 3; type++) {
        generate_array(arr, n, type);
        quick_sort(arr, 0, n - 1, &stats[type]);
    }
    
    printf("| %4d | %12ld | %12ld | %12ld |\n", 
           n, 
           stats[0].swaps + stats[0].comparisons,
           stats[1].swaps + stats[1].comparisons,
           stats[2].swaps + stats[2].comparisons);
}

void test_sort(int n) {  
    int arr[n];
    Stats stats[3] = {0}; // 0 - убыв, 1 - возр, 2 - случ

    for (int type = 0; type < 3; type++) {
        generate_array(arr, n, type);
        quick_sort(arr, 0, n - 1, &stats[type]);
        print_mas(arr, n);
        printf("\n");
    }
}

void test_sort_empty() {  
    int arr[] = {};
    int n = sizeof(arr) / sizeof(arr[0]);
    Stats stats[3] = {0};
    for (int type = 0; type < 1; type++) {
        quick_sort(arr, 0, n - 1, &stats[type]);
        print_mas(arr, n);
        printf("\n");
    }
}

void test_sort_single() {  
    int arr[] = {10};
    int n = sizeof(arr) / sizeof(arr[0]);
    Stats stats[3] = {0};
    for (int type = 0; type < 1; type++) {
        quick_sort(arr, 0, n - 1, &stats[type]);
        print_mas(arr, n);
        printf("\n");
    }
}

void test_sort_duplicates() {  
    int arr[] = {5, 3, 7, 3, 6, 8, 3, 1, 3, 3, 3, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    Stats stats[3] = {0};
    for (int type = 0; type < 1; type++) {
        quick_sort(arr, 0, n - 1, &stats[type]);
        print_mas(arr, n);
        printf("\n");
    }
}


int main() {
    srand(time(NULL));
    
    printf("Трудоемкость метода Хоара (QuickSort)\n");
    printf("|  N   |             QuickSort (Mф + Cф)            |\n");
    printf("|      | Убыв.        | Возр.        | Случ.        |\n");
    
    int sizes[] = {100, 200, 300, 400, 500};
    for (int i = 0; i < 5; i++) {
        analyze_for_n(sizes[i]);
    }
    
    int a = 450, b = 125;
    Stats test_stats = {0, 0};
    swapTest(&a, &b, &test_stats);

    for (int i = 0; i < 5; i++) {
        int array[sizes[i]];
        test_generate_array(array, sizes[i]);
    }

    printf("\nПосле сортировки ");

    for (int i = 0; i < 5; i++) {
        test_sort(sizes[i]);
    }

    test_sort_empty();
    test_sort_single();
    test_sort_duplicates();

    return 0;
}