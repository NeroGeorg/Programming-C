#include "train.h"

void generateTrains(train *trains) {
    const char *dest[] = {"Москва", "Самара", "Новосибирск", "Иркутск", "Владивосток", 
                        "Екатеринбург", "Казань", "Краснодар", "Тюмень", "Челябинск"};
    const char *number[] = {"193", "425", "632", "919", "633", "555", "777", "120", "903", "439"};

    for (int i = 0; i < N; i++) {
        int rnd_idx = rand() % 10;
        strcpy(trains[i].dest, dest[rnd_idx]);
        strcpy(trains[i].number, number[rnd_idx]);
        trains[i].time_outgo[0] = (rand() % 23) + 1;
        trains[i].time_outgo[1] = (rand() % 60) + 1;
    }
}

void writeTrainsToFile(const train *trains, const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    fwrite(trains, sizeof(train), N, file);
    fclose(file);
}

void readTrainsFromFile(train *trains, const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    fread(trains, sizeof(train), N, file);
    fclose(file);
}

void printSchedule(const train *trains) {
    printf("| %-15s | %-6s | %-14s |\n", "Направление", "Номер", "Время отправления");
    for (int i = 0; i < N; i++) {
        printf("| %-15s | %-6s |     %02d:%02d       |\n", 
              trains[i].dest, 
              trains[i].number, 
              trains[i].time_outgo[0], 
              trains[i].time_outgo[1]);
    }
}

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