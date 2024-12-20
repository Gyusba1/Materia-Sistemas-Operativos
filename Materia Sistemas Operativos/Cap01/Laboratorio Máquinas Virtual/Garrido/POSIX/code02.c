#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

int counter = 0;
int max = 4;

pthread_mutex_t counter_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t condp_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t condc_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t condVarProd = PTHREAD_COND_INITIALIZER;
pthread_cond_t condVarCons = PTHREAD_COND_INITIALIZER;

void *productor() {
    while (1) {
        pthread_mutex_lock(&condp_mutex);
        while (counter >= 10) 
            pthread_cond_wait(&condVarProd, &condp_mutex);
        pthread_mutex_unlock(&condp_mutex);

        pthread_mutex_lock(&counter_mutex);
        counter++;
        pthread_cond_signal(&condVarCons);
        printf("Soy el PRODUCTOR %d || Contador = %d\n", (int)pthread_self(), counter);
        pthread_mutex_unlock(&counter_mutex);

        if (counter > 7)
            sleep(4);
    }
}

void *consumidor() {
    while (1) {
        sleep(1);

        pthread_mutex_lock(&condc_mutex);
        while (counter <= 0) {
            pthread_cond_signal(&condVarProd);
            pthread_cond_wait(&condVarCons, &condc_mutex);
        }
        pthread_mutex_unlock(&condc_mutex);

        pthread_mutex_lock(&counter_mutex);
        if (counter > 0) {
            printf("Soy el CONSUMIDOR %d || Contador = %d\n", (int)pthread_self(), counter);
            counter--;
            pthread_cond_signal(&condVarProd);
        }
        pthread_mutex_unlock(&counter_mutex);
    }
}

int main(int argc, char *argv[]) {
    pthread_t prodHilo[max];            // Vector de hilos productor
    pthread_t consHilo[max];            // Vector de hilos consumidor

    for (int i = 0; i < max; i++) {
        // Creación de hilos y envío de función Productor o Consumidor
        pthread_create(&prodHilo[i], NULL, &productor, NULL);
        pthread_create(&consHilo[i], NULL, &consumidor, NULL);
    }

    for (int i = 0; i < max; i++) {
        pthread_join(prodHilo[i], NULL);
        pthread_join(consHilo[i], NULL);
    }

    return 0;
}
