/**************************************************************************************************
* Fecha: 13 agosto 2024
* Autor: Felipe Andres Garrido
* Materia: Sistemas Operativos
* Tema: Gestión de memoria
* Tópico: Reserva de memoria con la función malloc()
* La función malloc reserva un espacio de memoria de tamaño requerido.
* Los espacios son de igual tamaño y ed memoria contiggua
* La asignación es dinámica y útil para complejas destructuras de datos
* inicializados en 0
* devuelve un puntero señalando el inicio del espacio de memoria reservado.
*************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main(){
  // Declarar variables y pnteros
  int *p1 = calloc(4, sizeof(int)); //Asignacioón de vector de 4 tamaño
  int *p2 = calloc(10, sizeof(int[4])); 
  int *p3 = calloc(5, sizeof *p3); //bloque de memoria de 5

  // Llenar espacios primero bloque reservado (puntero)

  printf("Construcción y calculo de la secuencia de loa primeros 10 términos\n");
  for(int i=0; i<10; i++){
    
    *(p2+i) = i; 
    printf("El valor 9na posicion de puntero es %d \n\n", *(p2 + 8));
    
  }

  // LIBERACION DE MEMORIA
  free(p1);
  free(p2);
  free(p3);

  return 0;
}
