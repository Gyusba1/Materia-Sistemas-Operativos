/**************************************************************
* Pontificia Universidad Javeriana
* Autor: Felipe Garrido
* Fecha: Noviembre 11
* Materia: Sistemas Operativos
* Tema: Taller de Evaluación de Rendimiento
* Fichero: fuente de multiplicación de matrices NxN por hilos.
* Objetivo: Evaluar el tiempo de ejecución del 
		    algoritmo clásico de multiplicación de matrices.
			Se implementa con la Biblioteca POSIX Pthreads
****************************************************************/

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

#define DATA_SIZE (1024*1024*64*3) 

pthread_mutex_t MM_mutex;
static double MEM_CHUNK[DATA_SIZE];
double *mA, *mB, *mC;

struct parametros{
	int nH;	//numero de hilos 
	int idH; //id del hilo
	int N; //dimension de la matriz
};

struct timeval start, stop;

//funcion para llenar matriz A y B con valores
void llenar_matriz(int SZ){ 
	srand48(time(NULL));
	for(int i = 0; i < SZ*SZ; i++){
			mA[i] = 1.1*i; //drand48(); 
			mB[i] = 2.2*i; //drand48();
			mC[i] = 0; 
		}	
}

//imprimir matriz
void print_matrix(int sz, double *matriz){
	if(sz < 12){
    		for(int i = 0; i < sz*sz; i++){
     				if(i%sz==0) printf("\n");
            		printf(" %.3f ", matriz[i]);
			}	
    	printf("\n>-------------------->\n");
	}
}

//cronometro 
void inicial_tiempo(){
	gettimeofday(&start, NULL);
}

//finalizar el cronometro
void final_tiempo(){
	gettimeofday(&stop, NULL);
	stop.tv_sec -= start.tv_sec;
	printf("%9.0f \n", (double) (stop.tv_sec*1000000 + stop.tv_usec));
}

//Multiplicacion de matrices
void *mult_thread(void *variables){
	struct parametros *data = (struct parametros *)variables;
	
	//hilos y limites de multiplicacion
	int idH = data->idH;
	int nH  = data->nH;
	int N   = data->N;
	int ini = (N/nH)*idH;
	int fin = (N/nH)*(idH+1);

	//multiplicacion de la matriz
    for (int i = ini; i < fin; i++){
        for (int j = 0; j < N; j++){
			double *pA, *pB, sumaTemp = 0.0;
			pA = mA + (i*N); 
			pB = mB + j;
            for (int k = 0; k < N; k++, pA++, pB+=N){
				sumaTemp += (*pA * *pB);
			}
			mC[i*N+j] = sumaTemp;
		}
	}

	//bloqueo  y desbloqueo de los hilos
	pthread_mutex_lock (&MM_mutex);
	pthread_mutex_unlock (&MM_mutex);
	pthread_exit(NULL);
}

int main(int argc, char *argv[]){
	//verificacion de que los argumentos
	if (argc < 2){
		printf("Ingreso de argumentos \n $./ejecutable tamMatriz numHilos\n");
		return -1;	
	}
    int SZ = atoi(argv[1]); //tamaño de la matriz
    int n_threads = atoi(argv[2]); // numero dde hilos

	//declaración de hilos
    pthread_t p[n_threads];
    pthread_attr_t atrMM;

	//asignacion de punters
	mA = MEM_CHUNK;
	mB = mA + SZ*SZ;
	mC = mB + SZ*SZ;

	//llena matriz por funcion
	llenar_matriz(SZ);
	print_matrix(SZ, mA);
	print_matrix(SZ, mB);

	//cronometro
	inicial_tiempo();
	pthread_mutex_init(&MM_mutex, NULL);
	pthread_attr_init(&atrMM);
	pthread_attr_setdetachstate(&atrMM, PTHREAD_CREATE_JOINABLE);

	// crea los hilos para poder multiplicar
    for (int j=0; j<n_threads; j++){
		struct parametros *datos = (struct parametros *) malloc(sizeof(struct parametros)); 
		datos->idH = j;
		datos->nH  = n_threads;
		datos->N   = SZ;
        pthread_create(&p[j],&atrMM,mult_thread,(void *)datos);
	}

	//Espera a q los hilos terminen
    for (int j=0; j<n_threads; j++)
        pthread_join(p[j],NULL);
	final_tiempo(); //finaliza el cronometro
	
	print_matrix(SZ, mC);

	//limpia los atributos y mutex
	pthread_attr_destroy(&atrMM);
	pthread_mutex_destroy(&MM_mutex);
	pthread_exit (NULL);
}
