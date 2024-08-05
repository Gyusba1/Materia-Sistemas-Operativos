/******************************************************
Autor: Felipe Andrés Garrido Flores
Fecha: 30/07/2024
Profesor: J.Corredor
Materias: Sistemas Operativos
Tmea: Argumentos de entrada en C
************************************************************/

#include <stdio.h>

int main() {
  
  //Diferentes Tipos de Datos
    int edad;
    float altura;
    char inicial;
    char nombre[50];
    int anio_nacimiento;
    float peso;
    char genero;
    char pais[50];

    // Pedir un entero
    printf("Ingrese su edad: ");
    scanf("%d", &edad);

    // Pedir un número decimal
    printf("Ingrese su altura en metros: ");
    scanf("%f", &altura);

    // Pedir un carácter
    printf("Ingrese la inicial de su nombre: ");
    scanf(" %c", &inicial);

    // Pedir una cadena de caracteres
    printf("Ingrese su nombre completo: ");
    scanf(" %s", nombre);

    // Pedir otro entero
    printf("Ingrese su año de nacimiento: ");
    scanf("%d", &anio_nacimiento);

    // Pedir otro numero decimal
    printf("Ingrese su peso: ");
    scanf("%f", &peso);

    // Pedir un caracter
    printf("Ingrese su género con un solo caracter: ");
    scanf(" %c", &genero);

    // Pedir una cadena de caracteres
    printf("Ingrese su país: ");
    scanf(" %s", pais);

    // Mostrar dats
    printf("\nDatos ingresados:\n");
    printf("Edad: %d\n", edad);
    printf("Altura: %.2f metros\n", altura);
    printf("Inicial: %c\n", inicial);
    printf("Nombre completo: %s\n", nombre);
    printf("Año de nacimiento: %d\n", anio_nacimiento);
    printf("Peso: %.2f kilogramos\n", peso);
    printf("Género: %c\n", genero);
    printf("País de residencia: %s\n", pais);

    return 0;
}
