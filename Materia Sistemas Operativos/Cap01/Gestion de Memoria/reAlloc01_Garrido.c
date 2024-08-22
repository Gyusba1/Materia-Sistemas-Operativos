/********************************************************************************
* Fecha: 23 agosto 2024
* Autor: Felipe Andres Garrido
* Materia: Sistemas Operativos
* Tema: Gestión de memoria
* Tópico: Función realloc(), primero debemos crear ya sea un cemalloc() o un memalloc() ya que realloc() lo que hace es como actualizar el espacio de memoria reservado, si realloc() actualiza a un tamaño mayor se añade memoria al final, pero si es menor, los datos se perderán.
******************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>


int main(){

  int *arr;

  arr = (int *) malloc(5 * sizeof(int)); //Asignamos la memoria para 5 enteros

  if (arr == NULL) {
    printf("Error al asignar memoria\n");
    return 1;
  }

  //Asignamos valores a la memoria reservada
  for (int i = 0; i < 5; i++){
    arr[i] = i * 2;   //para variar los enteros dentro de la memoria los multiplico
    printf("Memoria asignada en la posición [%d] su valor es de = %d\n", i,  arr[i]);
  }

  //Asignamos la memoria para 10 enteros
  arr = realloc(arr, 10 * sizeof(int)); 

  if (arr == NULL) {
    printf("Error al asignar la nueva memoria\n");
    return 1;
  }

  //Asignamos los nuevos valores al nuevo espacio de memoria
  for (int i = 5; i < 10; i++){
    arr[i] = i * 20;
    printf("Memoria asignada en la posición [%d] su valor es de = %d\n", i, arr[i]);
  }

  

  //liberamos la memoria reservada
  free(arr);
  return 0;
}
