#include "train.h"
#include <stdio.h>

int main() {
    srand(time(NULL));
    
    train tablo[N];
    train read_data[N];
    char str[30];
    
    generateTrains(tablo);
    writeTrainsToFile(tablo, "train.dat");
    readTrainsFromFile(read_data, "train.dat");
    
    printSchedule(read_data);
    
    printf("Поиск: ");
    scanf("%29s", str);
    searchTrain(read_data, N, str);
    
    return 0;
}