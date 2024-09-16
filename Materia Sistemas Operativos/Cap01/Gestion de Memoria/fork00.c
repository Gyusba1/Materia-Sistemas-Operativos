/***************************************************************************
* Autor: Felipe Andrés Garrido Flores
* Fecha: 03/09/2024
* Materia: Sistemas Operativos
* Tema: Introduccion a Procesos con Fork
* Fork: Al ser invocado crea 2 procesos. Proceso padre y proceso hijo.
* Cada uno de estos 2 procesos al ser invocados tienen diferente espacio
* de memoria (2 proceso diferentes), son identicos hasta que el programador 
* determine lo contrario
* El proceso hio Siempre tendra un id = 0 con lo cual, siempre podremos
* identificare el proceso hijo, y a su vez enviarle un "proceso" diferente.
************************************/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
int main(){

  int id;
  printf("\n\nHola profesionales en formacion \n\n");
  printf("\n\n \t-->PROGRAMA PRINCIPAL<-- \n\n");

  //Se crea los procesos diferentes
  id = fork();
  if(id > 0){
    printf("\n\nSoy el proceso PADRE ID = %d\n\n", getpid());
  } else if(id == 0){
    printf("\n\nSoy el proceso HIJO ID = %d\n\n", getpid());
  } else{
    printf("\n\n Hubo error en la creacion FORK \n\n");
  }

  //Se imprimen numero de 10 a 0
  for(int i = 10; i >= 0; i--){
    printf("-->: %d\n", i);
  }

  printf("\n Fin del programa.!!!\n");

  return 0;
}
