/******************************************************
Autor: Felipe Andrés Garrido Flores
Fecha: 23/07/2024
Profesor: J.Corredor
Materias: Sistemas Operativos
Tmea: Programación en C
Requerimientos:
          -Función que sume 2 enteros
          -Función que calcule el área de una circunferencia
          -Función de bienvenida
************************************************************/

#include <stdio.h>

//Función bienvenida

void bienvenida(){
  printf("Hola Mundo...\n");
  printf("\t\t Bienvenidos a mi clase de SISTEMAS OPERATIVOS \n");
}

//Función que sume 2 enteros

int suma2enteros(){
  printf("Primer entero: 2");
  printf("Segundo entero: 4");
  int suma = 2 + 4;
  printf("Suma es: %d\n", suma);
     
}

//Area de circunferencia

void areacircunferencia(){
  int radio = 2;
  float pi = 3,14
  printf("El radio es: %d\n", radio);
  float area = radio*radio*pi;
  printf("El radio es: %d\n", radio);
}

int main(int argc, char *argv[]){
  

  
}
