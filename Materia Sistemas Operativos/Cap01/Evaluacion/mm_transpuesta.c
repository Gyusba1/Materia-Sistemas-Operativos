
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
double *mA, *mB, *mC; //punteros matriz 

struct parametros{
	int nH; //numero de hilos
	int idH; //identificacion del hilp
	int N; //dimensión matriz
};

struct timeval start, stop;

//llena matriz a y b
void llenar_matriz(int SZ){ 
	srand48(time(NULL)); //valores aleatorios
	for(int i = 0; i < SZ*SZ; i++){
			mA[i] = 1.1*i; //drand48(); 
			mB[i] = 2.2*i; //drand48();
			mC[i] = 0; 
		}	
}

//imprime la matriz 
void print_matrix(int sz, double *matriz){
	if(sz < 12){
    		for(int i = 0; i < sz*sz; i++){
     				if(i%sz==0) printf("\n");
            		printf(" %.3f ", matriz[i]);
			}	
    	printf("\n>-------------------->\n");
	}
}

//medicion de tiempo (inicio)
void inicial_tiempo(){
	gettimeofday(&start, NULL);
}

//medicion de tiempo (final)
void final_tiempo(){
	gettimeofday(&stop, NULL);
	stop.tv_sec -= start.tv_sec;
	printf("%9.0f\n", (double) (stop.tv_sec*1000000 + stop.tv_usec));
}


//ejecutadda por cada hilo para multiplicar las matrices
void *mult_thread(void *variables){
	struct parametros *data = (struct parametros *)variables;
	
	//obtener datos del hilo
	int idH = data->idH;
	int nH  = data->nH;
	int N   = data->N;
	//rango de filas de hilo q va a procesar
	int ini = (N/nH)*idH;
	int fin = (N/nH)*(idH+1);

	//multiplicacion de matrices
    for (int i = ini; i < fin; i++){
        for (int j = 0; j < N; j++){
			double *pA, *pB, sumaTemp = 0.0;
			pA = mA + (i*N); 
			pB = mB + (j*N);
            for (int k = 0; k < N; k++, pA++, pB++){
				sumaTemp += (*pA * *pB);
			}
			mC[i*N+j] = sumaTemp;
		}
	}

	pthread_mutex_lock (&MM_mutex);
	pthread_mutex_unlock (&MM_mutex);
	pthread_exit(NULL);
}

int main(int argc, char *argv[]){
	//verificacion de argumentos
	if (argc < 2){
		printf("Ingreso de argumentos \n $./ejecutable tamMatriz numHilos\n");
		return -1;	
	}
    int SZ = atoi(argv[1]); //tamaño matriz
    int n_threads = atoi(argv[2]);  //numero de hilos

	
    pthread_t p[n_threads]; //arreglo de hilos
    pthread_attr_t atrMM;

	//asignación de las matrices
	mA = MEM_CHUNK;
	mB = mA + SZ*SZ;
	mC = mB + SZ*SZ;

	//llena la matriz por la función 
	llenar_matriz(SZ);
	print_matrix(SZ, mA);
	print_matrix(SZ, mB);

	//inicia el tiempo
	inicial_tiempo();
	pthread_mutex_init(&MM_mutex, NULL);
	pthread_attr_init(&atrMM);
	pthread_attr_setdetachstate(&atrMM, PTHREAD_CREATE_JOINABLE);

	//crear hilos para la multiplicación 
    for (int j=0; j<n_threads; j++){
		struct parametros *datos = (struct parametros *) malloc(sizeof(struct parametros)); 
		datos->idH = j;
		datos->nH  = n_threads;
		datos->N   = SZ;
        pthread_create(&p[j],&atrMM,mult_thread,(void *)datos);
	}

	//espera la finalizacióon de los hilos
    for (int j=0; j<n_threads; j++)
        pthread_join(p[j],NULL);
	final_tiempo();
	
	print_matrix(SZ, mC);

	//limpia los atributos y mutex
	pthread_attr_destroy(&atrMM);
	pthread_mutex_destroy(&MM_mutex);
	pthread_exit (NULL);
}
