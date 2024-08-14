/**************************************************************************************************
* Fecha: 13 agosto 2024
* Autor: Felipe Andres Garrido
* Materia: Sistemas Operativos
* Tema: Gestión de memoria
* Tópico: Reserva de memoria con la función malloc()
* La función malloc reserva un espacio de memoria de tamaño requerido.
* devuelve un puntero señalando el inicio del espacio de memoria reservado.
*************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main(){
  // Declarar variables y pnteros
  int *bloque00 = malloc(4*sizeof(int)); //Asignacioón de vector de 4 tamaño
  int *puntero = malloc(15*sizeof(*puntero)); //Bloque de memoria de 14

  //Llenar espacios primero bloque reservado (bloque00)
  for(int i = 0; 1 < 4; i++){
    bloque00[i] = i * 2;
    printf("El valor de memoria reservada Bloque00[%d] = %d ", i, bloque00[i]);
    
  }
  //Llenar espacios primero bloque reservado (puntero)
  if(puntero!=NULL){
    *(puntero + 8) = 9889; //se llena la posicion 9 con valor de 9889
    printf("El valor 9na posicion de puntero es %d \n\n", *(puntero + 8));
    printf("El valor 9na posicion de puntero es %d \n\n", puntero[8]);
  }

  //LIBERACION DE MEMORIA
  free(bloque00);
  free(puntero);
  
  return 0;
}
