// #include <pthread.h>
// #include <stdio.h>
// #include <unistd.h>

// pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// void cleaner(void *arg) {
//     pthread_mutex_unlock(&mutex); 
//     printf("Завершение потока: %s\n", (char*)arg);
// }

// void* some_work(void* arg) {
//     pthread_cleanup_push(cleaner, arg);

//     pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);
//     pthread_setcanceltype(PTHREAD_CANCEL_DEFERRED, NULL);

//     for(int i = 0; i < 5; ++i) {
//         pthread_mutex_lock(&mutex);
//         printf("Работает: ");
//         puts(arg);
//         pthread_mutex_unlock(&mutex);
//         sleep(2);
//     }

//     pthread_cleanup_pop(0);
//     return NULL;
// }

// int main(void) { 
//     pthread_t thread1, thread2, thread3, thread4;

//     pthread_create(&thread1, NULL, some_work, "1. Hello World");
//     pthread_create(&thread2, NULL, some_work, "2. Hello LAB7");
//     pthread_create(&thread3, NULL, some_work, "3. Thread 3");
//     pthread_create(&thread4, NULL, some_work, "4. Thread 4");

//     sleep(2);

//     pthread_cancel(thread1);
//     pthread_cancel(thread2);
//     pthread_cancel(thread3);
//     pthread_cancel(thread4);

//     pthread_join(thread1, NULL);
//     pthread_join(thread2, NULL);
//     pthread_join(thread3, NULL);
//     pthread_join(thread4, NULL);

//     return 0;
// }

// #include <pthread.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <unistd.h>
// #include <time.h>

// pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// void* sleep_and_print(void* arg){
//     int n = *(int*)arg;
//     sleep(n);
//     pthread_mutex_lock(&mutex);
//     printf(" %d", n);
//     pthread_mutex_unlock(&mutex);
//     return NULL;
// }

// void sleepSort(int arr[], int n){
//     pthread_t threads[n];

//     for(int i = 0; i < n; i++){
//         int* num = malloc(sizeof(int));
//         *num = arr[i];
//         pthread_create(&threads[i], NULL, sleep_and_print, num);
//     }

//     for(int i = 0; i < n; i++){
//         pthread_join(threads[i], NULL);
//     }
// }

// int main(void) { 

//     int A[50];
//     srand(time(0));
//     printf("Исходный массив: \n");
//     for(int i = 0; i < 50; i++){
//         A[i] = rand() % 100 + 1;
//         printf(" %d", A[i]);
//     }
//     printf("\n"); 

//     printf("Отсортированный массив: \n");
//     sleepSort(A, 50);

//     return 0;
// }

// #include <pthread.h>
// #include <stdio.h>
// #include <unistd.h>

// pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// void cleaner(void *arg) {
//     pthread_mutex_unlock(&mutex); 
//     printf("Завершение потока: %s\n", (char*)arg);
// }

// void* some_work(void* arg) {
//     pthread_cleanup_push(cleaner, arg);

//     pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);
//     pthread_setcanceltype(PTHREAD_CANCEL_DEFERRED, NULL);

//     for(int i = 0; i < 5; ++i) {
//         pthread_mutex_lock(&mutex);
//         printf("Работает: ");
//         puts(arg);
//         pthread_mutex_unlock(&mutex);
//         sleep(2);
//     }

//     pthread_cleanup_pop(0);
//     return NULL;
// }

// int main(void) { 
//     pthread_t thread1, thread2, thread3, thread4;

//     pthread_create(&thread1, NULL, some_work, "1. Thread 1");
//     pthread_create(&thread2, NULL, some_work, "2. Thread 2");
//     pthread_create(&thread3, NULL, some_work, "3. Thread 3");
//     pthread_create(&thread4, NULL, some_work, "4. Thread 4");

//     sleep(2);

//     pthread_join(thread1, NULL);
//     pthread_join(thread2, NULL);
//     pthread_join(thread3, NULL);
//     pthread_join(thread4, NULL);

//     return 0;
// }

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define N 10

int A[N][N];
int B[N][N];
int C[N][N];

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

typedef struct{

    int start_row;
    int end_row;

}ThreadData;

void print_matix(int n, int A[n][n]){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf(" %3d ", A[i][j]);
        }
        printf("\n");
    }
}

void* solve_matrix(void* data) {
    ThreadData *data2 = (ThreadData *)data;
    for(int i = data2->start_row; i < data2->end_row; i++){
        for(int j = 0; j < N; j++){
            C[i][j] = 0;
            for(int k = 0; k < N; k++){
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    free(data2);
    return NULL;
}

int main(int argc, char *argv[]) {

    if (argc != 2){
        fprintf(stderr, "Using: %s <number_threads>\n", argv[0]);
        exit(1);
    }
    int n_thr = atoi(argv[1]);   

    srand(time(NULL));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            // A[i][j] = rand() % 10;
            // B[i][j] = rand() % 10;
            A[i][j] = 1;
            B[i][j] = 1;
        }
    }
    
    pthread_t threads[n_thr];
    int num_rows = N / n_thr; 
    ThreadData* thread_data[n_thr];
    
    for(int i = 0; i < n_thr; i++){
        ThreadData* data = malloc(sizeof(ThreadData));
        data->start_row = i * num_rows;
        data->end_row = ( i == n_thr - 1) ? N : data->start_row + num_rows; 
        pthread_create(&threads[i], NULL, solve_matrix, data);
    }

    for(int i = 0; i < n_thr; i++){
        pthread_join(threads[i], NULL);
    }

    printf("Matrix C:\n");
    print_matix(N, C);
    return 0;
}

// #include <stdio.h>
// #include <pthread.h>
// #include <stdint.h> // uint8_t
// #include <stdlib.h>
// #include <string.h>
// #include <stdbool.h>
// #include <unistd.h>
// #include <time.h>

// typedef struct elem {
//     char *msg;
// } elem_t;

// typedef struct fifo {

//     pthread_mutex_t lock;
//     pthread_cond_t cond;
//     int length;
//     int start;

//     int fifo_max_queue_size;
//     elem_t *elems; // ring buffer

//     bool is_running;

// } fifo_t;

// fifo_t *fifo_init(int max_fifo_size) {

//     fifo_t *fifo = malloc(sizeof(fifo_t));
//     if (fifo == NULL) {
//         return NULL;
//     }

//     if (pthread_mutex_init(&fifo->lock, NULL) != 0) {
//         free(fifo);
//         return NULL;
//     }
//     if (pthread_cond_init(&fifo->cond, NULL) != 0) {
//         free(fifo);
//         return NULL;
//     }

//     fifo->elems = malloc(max_fifo_size * sizeof(elem_t));
//     if (fifo->elems == NULL) {
//        free(fifo);
//        return NULL;
//     }
//     fifo->fifo_max_queue_size = max_fifo_size;

//     fifo->length = 0;
//     fifo->start = 0;

//     return fifo;
// }

// void fifo_deinit(fifo_t *fifo) {
//     if (fifo) {
//         for (int i = 0; i < fifo->fifo_max_queue_size; ++i) {
//             if (fifo->elems[i].msg != NULL) {
//                 free(fifo->elems[i].msg);
//             }
//         }
//         free(fifo->elems);
//         pthread_mutex_destroy(&fifo->lock);
//         pthread_cond_destroy(&fifo->cond);
//         free(fifo);
//     }
// }

// typedef struct client_info {
//     fifo_t *fifo;
//     char name[16];
// } client_info_t;

// void *msgSend(void *arg) {
//     client_info_t *client_data = (client_info_t *)arg;
//     fifo_t *fifo = client_data->fifo;
//     const char *client_name = client_data->name;
//     char messages[5][64] = {
//         "Hello server!",
//         "How are you doing?",
//         "Another message from me.",
//         "Is everything alright?",
//         "Goodbye for now!"
//     };
//     int message_index = 0;

//     if (fifo == NULL) {
//         fprintf(stderr, "msgSend: Invalid FIFO pointer\n");
//         pthread_exit(NULL);
//     }

//     printf("%s запущен...\n", client_name);

//     while (fifo->is_running) {
//         char message[192];
//         snprintf(message, sizeof(message), "[%s] %s", client_name, messages[message_index % 5]);
//         message_index++;

//         usleep(rand() % 3000000 + 1000000);

//         if (pthread_mutex_lock(&fifo->lock) != 0) abort();
//         while (fifo->length == fifo->fifo_max_queue_size && fifo->is_running) {
//             printf("%s: очередь заполнена, ждем...\n", client_name);
//             if (pthread_cond_wait(&fifo->cond, &fifo->lock) != 0) abort();
//         }
//         if (!fifo->is_running) {
//             if (pthread_mutex_unlock(&fifo->lock) != 0) break;
//         }

//         char *msg_to_queue = malloc(strlen(message) + 1);
//         if (msg_to_queue == NULL) {
//             perror("malloc failed in msgSend");
//             abort();
//         }
//         strcpy(msg_to_queue, message);

//         int idx = (fifo->start + fifo->length) % fifo->fifo_max_queue_size;
//         fifo->elems[idx].msg = msg_to_queue;
//         fifo->length++;

//         if (pthread_cond_signal(&fifo->cond) != 0) abort();
//         if (pthread_mutex_unlock(&fifo->lock) != 0) abort();
//     }

//     printf("%s завершает работу...\n", client_name);
//     pthread_exit(NULL);
// }

// void *msgRecv(void *arg) {
//     fifo_t *fifo = (fifo_t *)arg;
//     char buffer[256];
//     char client_name[64];
//     char message_content[192 - 64];

//     if (fifo == NULL) {
//         fprintf(stderr, "msgRecv: Invalid FIFO pointer\n");
//         pthread_exit(NULL);
//     }

//     printf("Сервер запущен...\n");

//     while (fifo->is_running) {
//         if (pthread_mutex_lock(&fifo->lock) != 0) abort();
//         while (fifo->length == 0 && fifo->is_running) {
//             printf("Сервер: очередь пуста, ждем...\n");
//             if (pthread_cond_wait(&fifo->cond, &fifo->lock) != 0) abort();
//         }
//         if (!fifo->is_running) {
//             if (pthread_mutex_unlock(&fifo->lock) != 0) break;
//             return NULL;
//         }
//         char *msg = fifo->elems[fifo->start].msg;
//         fifo->elems[fifo->start].msg = NULL;
//         fifo->start = (fifo->start + 1) % fifo->fifo_max_queue_size;
//         fifo->length--;
//         if (pthread_cond_signal(&fifo->cond) != 0) abort();
//         if (pthread_mutex_unlock(&fifo->lock) != 0) abort();

//         if (msg) {
//             if (sscanf(msg, "[%[^]] ] %[^\n]", client_name, message_content) == 2) {
//                 printf("[%s] %s\n", client_name, message_content);
//             } else {
//                 printf("[Неизвестный отправитель] %s\n", msg);
//             }
//             free(msg);
//             usleep(rand() % 2000000 + 500000);
//         }
//     }

//     printf("Поток сервера завершен.\n");
//     pthread_exit(NULL);
// }

// bool isEmpty(fifo_t *fifo) {
//     return fifo->length == 0;
// }

// int main(void) {
//     srand(time(NULL));

//     const int fifo_max_queue_size = 10;
//     fifo_t *fifo = fifo_init(fifo_max_queue_size);

//     if (fifo == NULL) {
//         return 1;
//     }

//     fifo->is_running = true;
//     pthread_t server1, server2, client1, client2;
//     client_info_t client1_data = {fifo, "User-1"};
//     client_info_t client2_data = {fifo, "User-2"};

//     pthread_create(&server1, NULL, msgRecv, (void *)fifo);
//     pthread_create(&server2, NULL, msgRecv, (void *)fifo);
//     pthread_create(&client1, NULL, msgSend, (void *)&client1_data);
//     pthread_create(&client2, NULL, msgSend, (void *)&client2_data);

//     sleep(10);

//     fifo->is_running = false;
//     pthread_cond_broadcast(&fifo->cond);

//     pthread_join(server1, NULL);
//     pthread_join(server2, NULL);
//     pthread_join(client1, NULL);
//     pthread_join(client2, NULL);

//     fifo_deinit(fifo);

//     return 0;
// }