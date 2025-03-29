#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define N 5

typedef struct{
    char dest[30];
    char number[20];
    int time_outgo[2];
} train;

void searchTrain(const train *trains, int size, const char *search_str) {
    printf("\nРезультаты поиска \"%s\":\n", search_str);
    int found = 0;
    
    for (int i = 0; i < size; i++) {
        if (strstr(trains[i].dest, search_str) ||
            strstr(trains[i].number, search_str) ||
            (atoi(search_str) == trains[i].time_outgo[0]) || 
            (atoi(search_str) == trains[i].time_outgo[1])) {
            
            printf("| %-15s | %-6s | %02d:%02d |\n",
                   trains[i].dest,
                   trains[i].number,
                   trains[i].time_outgo[0],
                   trains[i].time_outgo[1]);
            found = 1;
        }
    }
    if (!found) {
        printf("Ничего не найдено!\n");
    }
}

int main(){
    srand(time(NULL));

    const char *dest[] = {"Москва", "Самара", "Новосибирск", "Иркутск", "Владивосток", "Екатеринбург", "Казань", "Краснодар", "Тюмень", "Челябинск"};
    const char *number[] = {"193", "425", "632", "919", "633", "555", "777", "120", "903", "439"};

    train tablo[N];

    for (int i = 0; i < N; i++) {
        int rnd_idx = rand() % 10;
        strcpy(tablo[i].dest, dest[rnd_idx]);
        strcpy(tablo[i].number, number[rnd_idx]);
        tablo[i].time_outgo[0] = (rand() % 23) + 1;
        tablo[i].time_outgo[1] = (rand() % 60) + 1;
    }

    FILE *file;
    file = fopen("train.dat", "wb");
    if (file == NULL) {
        perror("Error opening file");
        exit(1);
    }

    fwrite(tablo, sizeof(train), N, file);
    fclose(file);

    file = fopen("train.dat", "rb");
    if (file == NULL) {
        perror("Error opening file");
        exit(1);
    }
    
    train read_data[N];
    fread(read_data, sizeof(train), N, file);

    printf("| %-15s | %-6s | %-14s |\n", "Направление", "Номер", "Время отправления");
    for (int i = 0; i < N; i++) {
        printf("| %-15s | %-6s |     %02d:%02d       |\n", read_data[i].dest, read_data[i].number, read_data[i].time_outgo[0], read_data[i].time_outgo[1]);
    }

    char str[30];
    printf("Поиск: ");
    scanf("%29s", str);
    searchTrain(read_data, N, str);

    fclose(file);
    return 0;
}
