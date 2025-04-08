#ifndef TRAIN_H
#define TRAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define N 5

typedef struct {
    char dest[30];
    char number[20];
    int time_outgo[2];
} train;

// Прототипы функций
void generateTrains(train *trains);
void writeTrainsToFile(const train *trains, const char *filename);
void readTrainsFromFile(train *trains, const char *filename);
void printSchedule(const train *trains);
void searchTrain(const train *trains, int size, const char *search_str);

#endif