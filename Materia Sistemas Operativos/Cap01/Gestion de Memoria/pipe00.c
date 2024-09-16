/**************************************************************************
* Autor: Felipe Andrés Garrido Flores
* Fecha: 03/09/2024
* Tema: Introduccion a Procesos con Fork
* Fork: Al ser invocado crea 2 procesos. Proceso padre y proceso hijo.
* Cada uno de estos 2 procesos al ser invocados tienen diferente espacio
* de memoria (2 proceso diferentes), son identicos hasta que el programador 
* determine lo contrario
* "El proceso hio Siempre tendra un id = 0". Con lo cual, siempre podremos
* identificare el proceso hijo, y a su vez enviarle un "proceso" diferente.
* Se puede comunicar entre procesos con la funcion PIPE(). Crea una tuberia,
* que envia datos de forma unidireccional entre el proceso Padre y el 
* proceso Hijo.
**********************************/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

int main(){

  int id, auxiliar;
  printf("\n\n \t-->PROGRAMA PRINCIPAL<-- \n");
  printf("\n\n \t-->Creacion de PIPES entre Procesos<-- \n\n");

  //se crea el mensaje a enviar
  char sms[] = "Hola, te envio este mensaje";
  //Se crea un bus de memoria para el envio
  char lectorMsg[80];

  //Se crea un arreglo para identificar el INICIO Y EL FIN DEL PIPE
  int tuberia[2];

  // Se crea el PIPE y se verifica si fue exitoso
  if (pipe(tuberia) == -1) {
    perror("Error al crear la tubería");
    exit(1);
  }

  // Se crean los procesos diferentes
  id = fork();

  if (id > 0) {
    // mayor q 0 padre
    close(tuberia[1]); //cerrar tuberia 
    // Se lee el mensaje enviado
    auxiliar = read(tuberia[0], lectorMsg, sizeof(lectorMsg));
    if (auxiliar == -1) {
      perror("Error al leer de la tubería");
      exit(1);
    }
    printf("\n\n Seccion del PADRE\n");
    printf("\n\n -->Mensaje Recibido: \n\t %s \n", lectorMsg);

  } else if (id == 0) {
    printf("\n\n Seccion del HIJO \n");
    // El hijo envía el mensaje
    close(tuberia[0]); //cierra tuberia
    if (write(tuberia[1], sms, (strlen(sms) + 1)) == -1) {
      perror("Error al escribir en la tubería");
      exit(1);
    }
    // Finalizar ek oriceso
    exit(0);

  } else {
    printf("\n\n Hubo error en la creacion FORK \n\n");
  }

  printf("\n Fin del programa.!!!\n");

  return 0;
}
