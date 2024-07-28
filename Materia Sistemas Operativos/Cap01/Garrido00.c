
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
};

//Función que sume 2 enteros

void suma2enteros(){
  
  int n1, n2;
  printf("Ingrese el primer numero a sumar:");
  scanf("%d", &n1);
  printf("Ingrese el segundo numero a integrar:");
  scanf("%d", &n2);
  int suma = n1+n2;
  printf("Suma es: %d\n", suma);
     
}

//Area de circunferencia

void areacircunferencia(){
  int radio;
  float pi = 3.14;
  printf("Ingrese Radio: %d\n", radio);
  scanf("%d", &radio);
  float area = radio*radio*pi;
  printf("Resultado es: %f\n", area);
}

int main(int argc, char *argv[]){
  
  void bienvenida();
  void suma2enteros();
  void areacircunferencia();

  return 0;
}
