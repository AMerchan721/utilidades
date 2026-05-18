////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//
// ZONA DE IMPORTACIÓN: FICHEROS NECESARIOS A INCLUIR
//
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

#include "utilidades.h"   // Mi propia colección de subprogramas útiles.



////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//
// ZONA DE MACROS, CONSTANTES Y VARIABLES GLOBALES: PARA USO GLOBAL.
//
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

char MSJxERROR[] = "¡VALOR NO VÁLIDO!";
char MSJxPAUSA[] = "Pulse INTRO para continuar... ";

int codigoError; // VARIABLE GLOBAL: Visible por todos los subprogramas.



////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//
// ZONA DE CÓDIGO: CUERPOS DE LOS SUBPROGRAMAS DECLARADOS ANTES.
//
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void esperarINTRO (void);
//
//  USO:
//
//    Programa que produce una espera hasta que se pulse INTRO.
//
//  DETALLES:
//
//    Es un envoltorio de la función vaciarBuffer(), a la cual delega todo el
//    trabajo. Es una manera de crear "sinónimos" de acciones, es decir, de
//    tener disponibles varios nombres para hacer lo mismo.
//
//  PARÁMETROS DE ENTRADA:
//
//    Ninguno
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    vaciarBuffer()
//
//      Se delega toda la carga de trabajo a esta función.
//
////////////////////////////////////////////////////////////////////////////////

void esperarINTRO (void)
{
  vaciarBuffer();
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void descartarEntrada (void);
//
//  USO:
//
//    Programa que produce una espera hasta que se pulse INTRO.
//
//  DETALLES:
//
//    Es un envoltorio de la función vaciarBuffer(), a la cual delega todo el
//    trabajo. Es una manera de crear "sinónimos" de acciones, es decir, de
//    tener disponibles varios nombres para hacer lo mismo.
//
//  PARÁMETROS DE ENTRADA:
//
//    Ninguno
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    vaciarBuffer()
//
//      Se delega toda la carga de trabajo a esta función.
//
////////////////////////////////////////////////////////////////////////////////

void descartarEntrada (void)
{
  vaciarBuffer();
}


////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void vaciarBuffer (void);
//
//  USO:
//
//    Programa que espera que el usuario pulse teclas a la espera de INTRO.
//
//  DETALLES:
//
//    Se basa en un bucle que va pidiendo letras del buffer de teclado y no
//    termina hasta que detecta que ha encontrado un "INTRO" (0x10). Cualquier
//    otro código ASCII introducido por el usuario se descarta. Se produce ECO
//    de cualquier tecla pulsada.
//
//  PARÁMETROS DE ENTRADA:
//
//    Ninguno
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    getchar()
//
//      Es el programa estándar ("prefabricado") que hace la logística de
//      comunicarse con el sistema operativo y con el hardware del teclado.
//
////////////////////////////////////////////////////////////////////////////////

void vaciarBuffer (void)
{
  // ENTER CREADO EN DEFINE = ASCII(10) = 0x0A
  
  // MEDIANTE BUCLE DO-WHILE:
  char letra;
  do
  {
    letra = getchar();
  } while (letra != ENTER);
  
  // MEDIANTE BUBLE WHILE:
  // while (getchar() != '\n')   ; // Bucle vacío
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void borrarPantalla (void);
//
//  USO:
//
//    Programa que "limpia" o borra la pantalla del terminal.
//
//  DETALLES:
//
//    Es un envoltorio de la función limpiarPantalla(), a la cual delega todo el
//    trabajo. Es una manera de crear "sinónimos" de acciones, es decir, de
//    tener disponibles varios nombres para hacer lo mismo.
//
//  PARÁMETROS DE ENTRADA:
//
//    Ninguno
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    limpiarPantalla()
//
//      Se delega toda la carga de trabajo a esta función.
//
////////////////////////////////////////////////////////////////////////////////

void borrarPantalla (void)
{
  limpiarPantalla();
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void limpiarPantalla (void);
//
//  USO:
//
//    Programa que "limpia" o borra la pantalla del terminal.
//
//  DETALLES:
//
//    El programa usa la función prefabricada system(BORRAR). Esta función
//    tiene como parámetro BORRAR, que está definida según se esté en Windows
//    o en Linux.
//
//  PARÁMETROS DE ENTRADA:
//
//    Ninguno
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    system(BORRAR)
//
//      Es el programa estándar (prefabricado) que hace la logística de 
//      borrar la pantalla tras una acción.
//
////////////////////////////////////////////////////////////////////////////////

void limpiarPantalla (void)
{
  system(BORRAR);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void bajar (int nlineas);
//
//  USO:
//
//    Permite bajar el cursor en la pantalla, tantas líneas como se le indique.
//
//  DETALLES:
//
//    Crea tantas líneas en blanco como se le suministre como dato. No ubica el
//    cursor de texto en ninguna coordenada concreta, sino que genera contenido
//    en blanco en la pantalla, desplazando el punto donde se escribirá texto en
//    acciones posteriores. Utiliza para ello un bucle en cuyo interior se llama
//    a printf() con el código ASCII de salto de línea '\n' ó 0x10.
//
//  PARÁMETROS DE ENTRADA:
//
//    nlineas
//
//      Variable entera que recibirá del exterior el número de líneas en blanco
//      que se va a desplazar el cursor hacia abajo.
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    printf()
//
//      Es el programa estándar ("prefabricado") que hace la logística de
//      emitir por pantalla.
//
////////////////////////////////////////////////////////////////////////////////

void bajar (int nlineas)
{
  while(nlineas>0)
  {
    printf("\n");   // No se puede usar "mostrar()" porque crearíamos un bucle de llamadas.
    
    nlineas--;
  }
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void abajo (int nfils);
//
//  USO:
//
//    Permite bajar el cursor en la pantalla, tantas líneas (o filas, en este caso) como se le indique.
//
//  DETALLES:
//
//    Es un envoltorio de la función limpiarPantalla(), a la cual delega todo el
//    trabajo. Es una manera de crear "sinónimos" de acciones, es decir, de
//    tener disponibles varios nombres para hacer lo mismo.
//
//  PARÁMETROS DE ENTRADA:
//
//    nfilas
//
//      Variable entera que recibirá del exterior el número de filas
//      que se va a desplazar el cursor hacia abajo.
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    bajar(nfils)
//
//      Se delega toda la carga de trabajo a esta función.
//
////////////////////////////////////////////////////////////////////////////////

void abajo (int nfils)
{
  bajar(nfils);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void saltar (int nfils);
//
//  USO:
//
//    Permite bajar el cursor en la pantalla, tantas líneas (o filas, en este caso) como se le indique.
//
//  DETALLES:
//
//    Es un envoltorio de la función limpiarPantalla(), a la cual delega todo el
//    trabajo. Es una manera de crear "sinónimos" de acciones, es decir, de
//    tener disponibles varios nombres para hacer lo mismo.
//
//  PARÁMETROS DE ENTRADA:
//
//    nfilas
//
//      Variable entera que recibirá del exterior el número de filas
//      que se va a desplazar el cursor hacia abajo.
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    bajar(nfils)
//
//      Se delega toda la carga de trabajo a esta función.
//
////////////////////////////////////////////////////////////////////////////////

void saltar (int nfils)
{
  bajar(nfils);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void desplazarFils (int nfils);
//
//  USO:
//
//    Permite bajar el cursor en la pantalla, tantas líneas (o filas, en este caso) como se le indique.
//
//  DETALLES:
//
//    Es un envoltorio de la función limpiarPantalla(), a la cual delega todo el
//    trabajo. Es una manera de crear "sinónimos" de acciones, es decir, de
//    tener disponibles varios nombres para hacer lo mismo.
//
//  PARÁMETROS DE ENTRADA:
//
//    nfilas
//
//      Variable entera que recibirá del exterior el número de filas
//      que se va a desplazar el cursor hacia abajo.
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    bajar(nfils)
//
//      Se delega toda la carga de trabajo a esta función.
//
////////////////////////////////////////////////////////////////////////////////

void desplazarFils (int nfils)
{
  bajar(nfils);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void desplazarV (int nfils);
//
//  USO:
//
//    Permite bajar el cursor en la pantalla, tantas líneas (o filas, en este caso) como se le indique.
//
//  DETALLES:
//
//    Es un envoltorio de la función limpiarPantalla(), a la cual delega todo el
//    trabajo. Es una manera de crear "sinónimos" de acciones, es decir, de
//    tener disponibles varios nombres para hacer lo mismo.
//
//  PARÁMETROS DE ENTRADA:
//
//    nfilas
//
//      Variable entera que recibirá del exterior el número de filas
//      que se va a desplazar el cursor hacia abajo.
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    bajar(nfils)
//
//      Se delega toda la carga de trabajo a esta función.
//
////////////////////////////////////////////////////////////////////////////////

void desplazarV (int nfils)
{
  bajar(nfils);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void desplazarY (int nfils);
//
//  USO:
//
//    Permite bajar el cursor en la pantalla, tantas líneas (o filas, en este caso) como se le indique.
//
//  DETALLES:
//
//    Es un envoltorio de la función limpiarPantalla(), a la cual delega todo el
//    trabajo. Es una manera de crear "sinónimos" de acciones, es decir, de
//    tener disponibles varios nombres para hacer lo mismo.
//
//  PARÁMETROS DE ENTRADA:
//
//    nfilas
//
//      Variable entera que recibirá del exterior el número de filas
//      que se va a desplazar el cursor hacia abajo.
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    bajar(nfils)
//
//      Se delega toda la carga de trabajo a esta función.
//
////////////////////////////////////////////////////////////////////////////////

void desplazarY (int nfils)
{
  bajar(nfils);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void indentar (int ncolumnas);
//
//  USO:
//
//    Permite desplazar hacia la derecha el cursor en la pantalla, tantas tabulacIones como se le indique.
//
//  DETALLES:
//
//    Crea tantas tabulaciones como se le suministre como dato. No ubica el
//    cursor de texto en ninguna coordenada concreta, sino que genera contenido
//    en blanco en la pantalla, desplazando el punto donde se escribirá texto en
//    acciones posteriores. Utiliza para ello un bucle en cuyo interior se llama
//    a printf() con el código ASCII de salto de línea '\n' ó 0x10.
//
//  PARÁMETROS DE ENTRADA:
//
//    ncolumnas
//
//      Variable entera que recibirá del exterior el número de tabulaciones
//      que se va a desplazar el cursor hacia la derecha.
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    printf()
//
//      Es el programa estándar ("prefabricado") que hace la logística de
//      emitir por pantalla.
//
////////////////////////////////////////////////////////////////////////////////

void indentar (int ncolumnas)
{
  for(int i=0; i<ncolumnas; i++)
  {
    printf(" ");   // No se puede usar "mostrar()" porque crearíamos un bucle de llamadas.
  }
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void derecha (int ncols);
//
//  USO:
//
//    Permite desplazar hacia la derecha el cursor en la pantalla, tantas tabulaciones como se le indique.
//
//  DETALLES:
//
//    Es un envoltorio de la función indentar(ncolumnas), a la cual delega todo el
//    trabajo. Es una manera de crear "sinónimos" de acciones, es decir, de
//    tener disponibles varios nombres para hacer lo mismo.
//
//  PARÁMETROS DE ENTRADA:
//
//    ncols
//
//      Variable entera que recibirá del exterior el número de columnas (tabulaciones)
//      que se va a desplazar el cursor hacia abajo.
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    indentar(ncols)
//
//      Se delega toda la carga de trabajo a esta función.
//
////////////////////////////////////////////////////////////////////////////////

void derecha (int ncols)
{
  indentar(ncols);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void tabular (int ncols);
//
//  USO:
//
//    Permite desplazar hacia la derecha el cursor en la pantalla, tantas tabulaciones como se le indique.
//
//  DETALLES:
//
//    Es un envoltorio de la función indentar(ncolumnas), a la cual delega todo el
//    trabajo. Es una manera de crear "sinónimos" de acciones, es decir, de
//    tener disponibles varios nombres para hacer lo mismo.
//
//  PARÁMETROS DE ENTRADA:
//
//    ncols
//
//      Variable entera que recibirá del exterior el número de columnas (tabulaciones)
//      que se va a desplazar el cursor hacia abajo.
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    indentar(ncols)
//
//      Se delega toda la carga de trabajo a esta función.
//
////////////////////////////////////////////////////////////////////////////////

void tabular (int ncols)
{
  indentar(ncols);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void desplazarCols (int ncols);
//
//  USO:
//
//    Permite desplazar hacia la derecha el cursor en la pantalla, tantas tabulaciones como se le indique.
//
//  DETALLES:
//
//    Es un envoltorio de la función indentar(ncolumnas), a la cual delega todo el
//    trabajo. Es una manera de crear "sinónimos" de acciones, es decir, de
//    tener disponibles varios nombres para hacer lo mismo.
//
//  PARÁMETROS DE ENTRADA:
//
//    ncols
//
//      Variable entera que recibirá del exterior el número de columnas (tabulaciones)
//      que se va a desplazar el cursor hacia abajo.
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    indentar(ncols)
//
//      Se delega toda la carga de trabajo a esta función.
//
////////////////////////////////////////////////////////////////////////////////

void desplazarCols (int ncols)
{
  indentar(ncols);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void desplazarX (int ncols);
//
//  USO:
//
//    Permite desplazar hacia la derecha el cursor en la pantalla, tantas tabulaciones como se le indique.
//
//  DETALLES:
//
//    Es un envoltorio de la función indentar(ncolumnas), a la cual delega todo el
//    trabajo. Es una manera de crear "sinónimos" de acciones, es decir, de
//    tener disponibles varios nombres para hacer lo mismo.
//
//  PARÁMETROS DE ENTRADA:
//
//    ncols
//
//      Variable entera que recibirá del exterior el número de columnas (tabulaciones)
//      que se va a desplazar el cursor hacia abajo.
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    indentar(ncols)
//
//      Se delega toda la carga de trabajo a esta función.
//
////////////////////////////////////////////////////////////////////////////////

void desplazarX (int ncols)
{
  indentar(ncols);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void desplazarH (int ncols);
//
//  USO:
//
//    Permite desplazar hacia la derecha el cursor en la pantalla, tantas tabulaciones como se le indique.
//
//  DETALLES:
//
//    Es un envoltorio de la función indentar(ncolumnas), a la cual delega todo el
//    trabajo. Es una manera de crear "sinónimos" de acciones, es decir, de
//    tener disponibles varios nombres para hacer lo mismo.
//
//  PARÁMETROS DE ENTRADA:
//
//    ncols
//
//      Variable entera que recibirá del exterior el número de columnas (tabulaciones)
//      que se va a desplazar el cursor hacia abajo.
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    indentar(ncols)
//
//      Se delega toda la carga de trabajo a esta función.
//
////////////////////////////////////////////////////////////////////////////////

void desplazarH (int ncols)
{
  indentar(ncols);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void posicionar (int nfils, int ncols)
//
//  USO:
//
//    Permite desplazar hacia la derecha y hacia abajo el cursor en la pantalla, 
//    tantas filas y columnas como se le indique.
//
//  DETALLES:
//
//    Crea tantas tabulaciones y líneas en blanco como se le suministre como dato. No ubica el
//    cursor de texto en ninguna coordenada concreta, sino que genera contenido
//    en blanco en la pantalla, desplazando el punto donde se escribirá texto en
//    acciones posteriores. Utiliza para ello dos funciones ya definidas: bajar(nfils) e tabular(ncols).
//
//  PARÁMETROS DE ENTRADA:
//
//    nfils
//
//      Variable entera que recibirá del exterior el número de líneas
//      que se va a desplazar el cursor hacia abajo.
//
//    ncols
//
//      Variable entera que recibirá del exterior el número de tabulaciones
//      que se va a desplazar el cursor hacia la derecha.
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    bajar(nfils)
//
//      Permite bajar el cursor en la pantalla, tantas líneas como se le indique.
//
//    tabular(ncols)
//
//      Permite desplazar hacia la derecha el cursor en la pantalla, tantas tabulaciones como se le indique.
////////////////////////////////////////////////////////////////////////////////

void posicionar (int nfils, int ncols)
{
  bajar(nfils);
  tabular(ncols);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void desplazar (int nfils, int ncols);
//
//  USO:
//
//    Permite desplazar hacia la derecha y hacia abajo el cursor en la pantalla, 
//    tantas filas y columnas como se le indique.
//
//  DETALLES:
//
//    Es un envoltorio de la función posicionar (int nfils, int ncols), a la cual delega todo el
//    trabajo. Es una manera de crear "sinónimos" de acciones, es decir, de
//    tener disponibles varios nombres para hacer lo mismo.
//
//  PARÁMETROS DE ENTRADA:
//
//    nfils
//
//      Variable entera que recibirá del exterior el número de líneas
//      que se va a desplazar el cursor hacia abajo.
//
//    ncols
//
//      Variable entera que recibirá del exterior el número de columnas (tabulaciones)
//      que se va a desplazar el cursor hacia abajo.
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    void posicionar (int nfils, int ncols)
//
//      Se delega toda la carga de trabajo a esta función.
//
////////////////////////////////////////////////////////////////////////////////

void desplazar (int nfils, int ncols)
{
  posicionar(nfils, ncols);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void desplazarXY (int nfils, int ncols);
//
//  USO:
//
//    Permite desplazar hacia la derecha y hacia abajo el cursor en la pantalla, 
//    tantas filas y columnas como se le indique.
//
//  DETALLES:
//
//    Es un envoltorio de la función posicionar (int nfils, int ncols), a la cual delega todo el
//    trabajo. Es una manera de crear "sinónimos" de acciones, es decir, de
//    tener disponibles varios nombres para hacer lo mismo.
//
//  PARÁMETROS DE ENTRADA:
//
//    nfils
//
//      Variable entera que recibirá del exterior el número de líneas
//      que se va a desplazar el cursor hacia abajo.
//
//    ncols
//
//      Variable entera que recibirá del exterior el número de columnas (tabulaciones)
//      que se va a desplazar el cursor hacia abajo.
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    void posicionar (int nfils, int ncols)
//
//      Se delega toda la carga de trabajo a esta función.
//
////////////////////////////////////////////////////////////////////////////////

void desplazarXY (int nfils, int ncols)
{
  posicionar(nfils, ncols);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void retardoSegundos (int segundosmax);
//
//  USO:
//
//    Permite "pausar" el programa la cantidad de segundos que se le indique.
//
//  DETALLES:
//
//    Pausa el programa tantos segundos como se le suministre como dato.
//    Utiliza para ello el bucle "for" repetidas veces.
//
//  PARÁMETROS DE ENTRADA:
//
//    segundosmax
//
//      Variable entera que recibirá del exterior el número de segundos que va a
//      durar la pausa.
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    No depende de ninguna función.
//
////////////////////////////////////////////////////////////////////////////////

void retardoSegundos (int segundosmax)
{
  // POSIBILIDAD: Poner en función de la que usa milisegundos.
  
  // AJUSTAR CEROS DE LOS BUCLES PARA APROXIMAR EL PERIODO.

  for(int nseg=0; nseg < segundosmax ; nseg++)
  {
    for(int j=0; j<100; j++)
      for(int j=0; j<1000; j++)
        for(int k=0; k<1000; k++)   ;
  }
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void retardoMilisegundos (int milisegundosmax);
//
//  USO:
//
//    Permite "pausar" el programa la cantidad de milisegundos que se le indique.
//
//  DETALLES:
//
//    Pausa el programa tantos milisegundos como se le suministre como dato.
//    Utiliza para ello el bucle "for" repetidas veces.
//
//  PARÁMETROS DE ENTRADA:
//
//    milisegundosmax
//
//      Variable entera que recibirá del exterior el número de milisegundos que va a
//      durar la pausa.
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    No depende de ninguna función.
//
////////////////////////////////////////////////////////////////////////////////

void retardoMilisegundos (int milisegundosmax)
{
  int i, j;
  
  // AJUSTAR CEROS DE LOS BUCLES PARA APROXIMAR EL PERIODO.

  for (int nmiliseg=0; nmiliseg<milisegundosmax ; nmiliseg++)
    for (i=0; i<100; i++)
      for (j=0; j<1000; j++)   ;
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void retrasoMilisegundos (int milisegundos)
//
//  USO:
//
//    Permite "pausar" el programa la cantidad de milisegundos que se le indique.
//
//  DETALLES:
//
//    Pausa el programa tantos milisegundos como se le suministre como dato.
//    Utiliza para ello las funciones estándar de la librería <time.h>.
//
//  PARÁMETROS DE ENTRADA:
//
//    milisegundos
//
//      Variable entera que recibirá del exterior el número de milisegundos que va a
//      durar la pausa.
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    clock()
//
//      Es una función estándar del lenguaje C que sirve para medir el 
//      tiempo de uso de la CPU consumido por el programa desde que se inició.
//
////////////////////////////////////////////////////////////////////////////////

void retrasoMilisegundos (int milisegundos)
{
  double e = 0;

  clock_t t0 = clock();   // clock_t es un tipo interno equivalente a UINT32.
  
  do
  {
    
    e = 1000*(double)(clock()-t0)/CLOCKS_PER_SEC;

  } while (e<milisegundos);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void esperarSegundos (int segundos)
//
//  USO:
//
//    Permite "pausar" el programa la cantidad de segundos que se le indique.
//
//  DETALLES:
//
//    Pausa el programa tantos segundos como se le suministre como dato.
//    Utiliza para ello la función sleep() o Sleep().
//
//  PARÁMETROS DE ENTRADA:
//
//    segundos
//
//      Variable entera que recibirá del exterior el número de segundos que va a
//      durar la pausa.
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    Sleep (int segundos)
//
//      Es una función estándar del lenguaje C que sirve para pausar o suspender 
//      la ejecución del programa durante un tiempo determinado sin consumir recursos de la CPU. LO HACE EN WINDOWS.
//    sleep (int segundos)
//      
//      Es una función estándar del lenguaje C que sirve para pausar o suspender 
//      la ejecución del programa durante un tiempo determinado sin consumir recursos de la CPU. LO HACE EN UN SO DISTINTO A WINDOWS.
////////////////////////////////////////////////////////////////////////////////

void esperarSegundos (int segundos)
{
  #ifdef SO_WINDOWS
    Sleep(segundos*1000);
  #else
    sleep(segundos);
  #endif
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void esperarMilisegundos (int milisegundos)
//
//  USO:
//
//    Permite "pausar" el programa la cantidad de milisegundos que se le indique.
//
//  DETALLES:
//
//    Pausa el programa tantos milisegundos como se le suministre como dato.
//    Utiliza para ello la función sleep() o Sleep().
//
//  PARÁMETROS DE ENTRADA:
//
//    milisegundos
//
//      Variable entera que recibirá del exterior el número de milisegundos que va a
//      durar la pausa.
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    Sleep (int segundos)
//
//      Es una función estándar del lenguaje C que sirve para pausar o suspender 
//      la ejecución del programa durante un tiempo determinado sin consumir recursos de la CPU. LO HACE EN WINDOWS.
//    sleep (int segundos)
//      
//      Es una función estándar del lenguaje C que sirve para pausar o suspender 
//      la ejecución del programa durante un tiempo determinado sin consumir recursos de la CPU. LO HACE EN UN SO DISTINTO A WINDOWS.
////////////////////////////////////////////////////////////////////////////////

void esperarMilisegundos (int milisegundos)
{
  #ifdef SO_WINDOWS
    Sleep(milisegundos);
  #else
    usleep(milisegundos*1000);   // Alternativa: nanosleep() de "time.h".
  #endif
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void pausa (void);
//
//  USO:
//
//    Permite establecer una pausa prefijada con una línea en blanco y dos tabulaciones
//
//  DETALLES:
//
//    Es una pausa para usar en el caso de que no se quiera poner de
//    nuevo los números 1 y 2. Es decir, es como "pausaEstandar" pero con valores de posición
//    prefijados. 
//
//  PARÁMETROS DE ENTRADA:
//
//    Ninguno
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    pausaEstandar (1, 2)
//
//      Permite colocar el cursor en la posición (1, 2) para que haga una pausa.
////////////////////////////////////////////////////////////////////////////////

void pausa (void)
{
  pausaEstandar(1, 2);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void pausaEstandar (int nfils, int ncols);
//
//  USO:
//
//    Permite establecer una pausa prefijada con un mensaje fijo y la opción de NO cambiar de línea.
//
//  DETALLES:
//
//    Es una pausa para usar en el caso de que no se quiera poner de
//    nuevo un mensaje ni una opción de cambio de línea. Es decir, es como
//    "pausaGenerica" pero con un mensaje y un NO cambio de línea. 
//
//  PARÁMETROS DE ENTRADA:
//
//    Ninguno
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    pausaGenerica(MSJxPAUSA, nfils, ncols, FALSE)
//
//      Es una pausa de tipo "genérica" que permite establecerla a través de un mensaje y una posición.
////////////////////////////////////////////////////////////////////////////////

void pausaEstandar (int nfils, int ncols)
{
  pausaGenerica(MSJxPAUSA, nfils, ncols, FALSE);
}


////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void pausaGenerica (char msjtxt[], int nfils, int ncols, boolean nuevalinea);
//
//  USO:
//
//    Permite hacer una pausa en el programa mostrando un texto y en una posición elegida.
//
//  DETALLES:
//
//    Pone en la pantalla el mensaje que se indique, baja las líneas indicadas y 
//    se mueve a la derecha los espacios pedidos. Después, se queda esperando a que 
//    el usuario pulse la tecla INTRO para poder seguir con el programa.
//
//  PARÁMETROS DE ENTRADA:
//
//    msjtxt
//
//      Texto o mensaje que se requiere que salga en la pantalla durante la pausa.
//    nfils
//
//      Número de líneas que va a bajar el texto en la pantalla.
//    ncols
//
//      Número de espacios o columnas que se va a mover el texto a la derecha.
//    nuevalinea
//
//      Opción para elegir si se desea que salte de línea al terminar el texto (TRUE o FALSE).
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    mensaje_x_y()
//
//      Se encarga de colocar y escribir el mensaje en su sitio.
//    esperarINTRO()
//
//      Hace que el programa se pare hasta que el usuario pulse INTRO.
//
////////////////////////////////////////////////////////////////////////////////

void pausaGenerica (char msjtxt[], int nfils, int ncols, boolean nuevalinea)
{
  mensaje_x_y(msjtxt, nfils, ncols, nuevalinea);

  esperarINTRO();
}


////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void texto (char msjtxt[]);
//
//  USO:
//
//    Programa que escribe una frase o texto en la pantalla del tirón.
//
//  DETALLES:
//
//    Escribe en la pantalla el mensaje que se pase y, al terminar de escribirlo, 
//    hace un salto a la línea de abajo automáticamente. Para hacer esto usa la 
//    función prefabricada puts().
//
//  PARÁMETROS DE ENTRADA:
//
//    msjtxt
//
//      Frase o cadena de texto que se va a mostrar en la pantalla.
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    puts()
//
//      Es la función estándar que se encarga de mostrar el texto y bajar de línea.
//
////////////////////////////////////////////////////////////////////////////////

void texto (char msjtxt[])
{
  puts(msjtxt);
}


////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void separar (void);
//
//  USO:
//
//    Programa que sirve para dejar un espacio o línea en blanco.
//
//  DETALLES:
//
//    Hace un salto de línea normal para separar cosas en la pantalla. Lo hace 
//    llamando a la función mostrar() pasándole el código de salto de línea '\n'.
//
//  PARÁMETROS DE ENTRADA:
//
//    Ninguno
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    mostrar()
//
//      Se usa para enviar el salto de línea a la pantalla.
//
////////////////////////////////////////////////////////////////////////////////

void separar()
{
  mostrar("\n");
}


////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void nuevaLinea (void);
//
//  USO:
//
//    Programa que hace que el cursor baje exactamente una línea hacia abajo.
//
//  DETALLES:
//
//    Es un envoltorio de la función saltar(), a la cual le pasa siempre el número 1 
//    para no tener que estar escribiéndolo. Es otra forma de llamar a la acción de 
//    bajar una sola línea.
//
//  PARÁMETROS DE ENTRADA:
//
//    Ninguno
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    saltar()
//
//      Se le delega el trabajo pasándole un 1 para que baje esa línea.
//
////////////////////////////////////////////////////////////////////////////////

void nuevaLinea (void)
{
  saltar(1);
}


////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void mostrar (char msjtxt[]);
//
//  USO:
//
//    Programa que muestra un texto en la pantalla sin moverse de donde está el cursor.
//
//  DETALLES:
//
//    Es un envoltorio de la función mostrar_x_y(), a la que le pasa un 0 en las 
//    filas y un 0 en las columnas. Sirve para escribir directamente sin dejar 
//    márgenes ni espacios extra.
//
//  PARÁMETROS DE ENTRADA:
//
//    msjtxt
//
//      El mensaje o texto que se desea que aparezca en la pantalla.
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    mostrar_x_y()
//
//      Se encarga de poner el texto usando la posición (0, 0).
//
////////////////////////////////////////////////////////////////////////////////

void mostrar (char msjtxt[])
{
  mostrar_x_y (msjtxt, 0, 0);
}


////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void mostrar_x_y (char msjtxt[], int nfils, int ncols);
//
//  USO:
//
//    Programa que muestra un texto bajando unas líneas y moviéndose a la derecha.
//
//  DETALLES:
//
//    Es un envoltorio de la función mensaje_x_y(). Le pasa las filas y columnas 
//    que se requiera mover, y le dice que FALSE (que no) a la opción de hacer 
//    un salto de línea al final del texto.
//
//  PARÁMETROS DE ENTRADA:
//
//    msjtxt
//
//      El mensaje de texto que se va a mostrar en la pantalla.
//    nfils
//
//      Número de líneas que se desea bajar antes de escribir.
//    ncols
//
//      Número de columnas o espacios que se desea mover a la derecha.
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    mensaje_x_y()
//
//      Hace todo el trabajo de colocar el texto y escribirlo sin saltar de línea.
//
////////////////////////////////////////////////////////////////////////////////

void mostrar_x_y (char msjtxt[], int nfils, int ncols)
{
  mensaje_x_y (msjtxt, nfils, ncols, FALSE);
}


////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void escribir (char msjtxt[]);
//
//  USO:
//
//    Programa que sirve para poner un texto en la pantalla de forma directa.
//
//  DETALLES:
//
//    Es un envoltorio de la función escribir_x_y() y funciona igual que "mostrar". 
//    Pone los valores de posición a cero (0, 0) para mostrar el texto justo donde 
//    esté el cursor en ese momento.
//
//  PARÁMETROS DE ENTRADA:
//
//    msjtxt
//
//      La frase o texto que se desea poner en la pantalla.
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    escribir_x_y()
//
//      Se le pasa el trabajo poniendo la posición en el origen (0, 0).
//
////////////////////////////////////////////////////////////////////////////////

void escribir (char msjtxt[])
{
  escribir_x_y (msjtxt, 0, 0);
}


////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void escribir_x_y (char msjtxt[], int nfils, int ncols);
//
//  USO:
//
//    Programa que pone un texto en pantalla en una fila y columna determinadas.
//
//  DETALLES:
//
//    Es un envoltorio de la función mensaje_x_y(). Manda el texto junto con las 
//    filas y columnas para colocarse, y pone la opción de nueva línea a FALSE 
//    para que el cursor se quede pegado al final del texto.
//
//  PARÁMETROS DE ENTRADA:
//
//    msjtxt
//
//      El texto que se va a mostrar en la pantalla.
//    nfils
//
//      Líneas que va a bajar el cursor hacia abajo.
//    ncols
//
//      Espacios que se va a mover el cursor hacia la derecha.
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    mensaje_x_y()
//
//      Llama a esta función para colocar el mensaje en su sitio exacto.
//
////////////////////////////////////////////////////////////////////////////////

void escribir_x_y (char msjtxt[], int nfils, int ncols)
{
  mensaje_x_y (msjtxt, nfils, ncols, FALSE);
}


////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void imprimir (char msjtxt[]);
//
//  USO:
//
//    Programa que sirve para imprimir un mensaje sin cambiar de fila ni columna.
//
//  DETALLES:
//
//    Es un envoltorio de la función imprimir_x_y() con los valores fijados a (0, 0). 
//    Es otro sinónimo o nombre diferente para hacer la misma acción de mostrar un 
//    texto de forma directa en pantalla.
//
//  PARÁMETROS DE ENTRADA:
//
//    msjtxt
//
//      El mensaje de texto que va a salir por la pantalla.
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    imprimir_x_y()
//
//      Le delega la carga pasándole la posición en cero.
//
////////////////////////////////////////////////////////////////////////////////

void imprimir (char msjtxt[])
{
  imprimir_x_y (msjtxt, 0, 0);
}


////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void imprimir_x_y (char msjtxt[], int nfils, int ncols);
//
//  USO:
//
//    Programa que sirve para imprimir un mensaje moviéndolo a una fila y columna.
//
//  DETALLES:
//
//    Es un envoltorio de la función mensaje_x_y(). Se usa para colocar el texto 
//    en los márgenes que se indiquen y se asegura de que la opción de bajar de 
//    línea al final esté desactivada mediante un FALSE.
//
//  PARÁMETROS DE ENTRADA:
//
//    msjtxt
//
//      El texto o frase listo para salir en pantalla.
//    nfils
//
//      Las filas que se desee que baje antes de escribir.
//    ncols
//
//      Las columnas o espacios hacia la derecha.
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    mensaje_x_y()
//
//      Llama al programa principal de mensajes para mostrar el texto.
//
////////////////////////////////////////////////////////////////////////////////

void imprimir_x_y (char msjtxt[], int nfils, int ncols)
{
  mensaje_x_y (msjtxt, nfils, ncols, FALSE);
}


////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void mensaje (char msjtxt[], int nfils, int ncols);
//
//  USO:
//
//    Programa que saca un mensaje por pantalla indicando sus filas y columnas.
//
//  DETALLES:
//
//    Es un envoltorio directo de la función mensaje_x_y(). Hace exactamente lo mismo, 
//    pero está pensado para usarse cuando no se quiera escribir a mano el último 
//    parámetro de salto de línea, poniéndolo siempre como FALSE.
//
//  PARÁMETROS DE ENTRADA:
//
//    msjtxt
//
//      El mensaje de texto que se requiere que se muestre.
//    nfils
//
//      Número de filas para bajar el texto en vertical.
//    ncols
//
//      Número de espacios para mover el texto en horizontal.
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    mensaje_x_y()
//
//      Función principal a la que se le pasa el mensaje y las posiciones.
//
////////////////////////////////////////////////////////////////////////////////

void mensaje (char msjtxt[], int nfils, int ncols)
{
  mensaje_x_y (msjtxt, nfils, ncols, FALSE);
}


////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void mensaje_x_y (char msjtxt[], int nfils, int ncols, boolean nuevalinea);
//
//  USO:
//
//    Programa principal que controla la posición y la escritura de los mensajes.
//
//  DETALLES:
//
//    Es la función que hace casi todo el trabajo de mostrar en pantalla. Primero 
//    llama a saltar() para bajar las líneas pedidas, luego a tabular() para 
//    moverse a la derecha, y después usa printf() para mostrar el texto. Al final, 
//    mira si "nuevalinea" vale TRUE para hacer un salto extra de línea o no.
//
//  PARÁMETROS DE ENTRADA:
//
//    msjtxt
//
//      La frase o cadena de texto que se va a mostrar en la pantalla.
//    nfils
//
//      La cantidad de líneas que se va a mover hacia abajo.
//    ncols
//
//      La cantidad de espacios o tabulaciones hacia la derecha.
//    nuevalinea
//
//      Opción (TRUE o FALSE) para decidir si baja una línea al terminar de escribir.
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    saltar()
//
//      Sirve para bajar el cursor las líneas que se le indiquen.
//    tabular()
//
//      Sirve para mover el cursor los espacios indicados a la derecha.
//    printf()
//
//      Es el programa estándar que se comunica con la pantalla para mostrar el texto.
//
////////////////////////////////////////////////////////////////////////////////

void mensaje_x_y (char msjtxt[], int nfils, int ncols, boolean nuevalinea)
{
  saltar(nfils);
  tabular(ncols);
  printf("%s", msjtxt);
  
  if (nuevalinea)   printf("\n");   // ALTERNATIVA: if (nuevalinea)   putchar(ENTER);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void iniciaAleatorizador (void);
//
//  USO:
//
//    Prepara el entorno del programa para generar números aleatorios.
//
//  DETALLES:
//
//    Establece la semilla inicial para el algoritmo matemático de números 
//    pseudoaleatorios. Utiliza el reloj interno del sistema operativo para 
//    obtener un valor cambiante segundo a segundo. Esto garantiza que la 
//    secuencia de números generados por el programa sea distinta en cada  
//    ejecución.
//
//  PARÁMETROS DE ENTRADA:
//
//    Ninguno.
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    time()
//
//      Obtiene el tiempo actual del sistema en segundos desde la época Unix.
//    srand()
//
//      Configura la semilla de inicio para el generador pseudoaleatorio.
//
////////////////////////////////////////////////////////////////////////////////

void iniciaAleatorizador (void)
{
  srand(time(NULL));
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    int generaAleatorioEntero (int limite);
//
//  USO:
//
//    Genera de forma matemática un número entero al azar dentro de un rango determinado.
//
//  DETALLES:
//
//    Calcula un número pseudoaleatorio que comienza en 0 y llega hasta el valor del
//    límite menos uno. Utiliza el operador de residuo (módulo) para recortar el 
//    resultado de la función estándar de C. Requiere que la semilla del generador 
//    haya sido establecida previamente para que los resultados varíen en cada ejecución.
//
//  PARÁMETROS DE ENTRADA:
//
//    limite
//
//      El número entero que define el techo del rango. El valor máximo posible 
//      que devolverá la función será este número menos uno (limite - 1).
//
//  VALOR DE SALIDA:
//
//    Devuelve un número entero (int) aleatorio comprendido entre 0 y limite - 1.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    rand()
//
//      Entrega un número entero pseudoaleatorio grande entre 0 y un máximo fijo (RAND_MAX).
//
////////////////////////////////////////////////////////////////////////////////

int generaAleatorioEntero (int limite)
{
  // Generará un número entre 0 y limite - 1, nunca llega a limite.
  return (rand() % limite);
}


////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    int obtenerEntero (void);
//
//  USO:
//
//    Sustitución mejorada de scanf() que impide que queden letras almacenadas
//    en el buffer de teclado para posteriores operaciones de entrada de datos.
//
//  DETALLES:
//
//    La función scanf() no retira el código ASCII de la letra INTRO del buffer
//    de teclado ni posibles letras después de un texto que se pueda convertir
//    en una cantidad. Nos ayudamos de otra función creada en esta librería,
//    vaciarBuffer() para ello. No muestra ningún mensaje por pantalla.
//
//  PARÁMETROS DE ENTRADA:
//
//    Ninguno
//
//  VALOR DE SALIDA:
//
//    Devuelve al exterior el valor entero que a su vez ha recibido en la
//    variable "valor" de la función scanf(), mediante paso por referencia.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    scanf()
//
//      Es el programa estándar ("prefabricado") que hace la logística de
//      leer caracteres del teclado y convertirlos en la cantidad entera.
//
////////////////////////////////////////////////////////////////////////////////

int obtenerEntero (void)
{
  int valor;
  
  scanf("%d", &valor);
  vaciarBuffer();

  return valor;
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    char obtenerCaracterASCII();
//
//  USO:
//
//    Funciona como un "intermediario" para capturar un carácter desde el teclado.
//
//  DETALLES:
//
//    Es un envoltorio de la función obtenerLetra(), a la cual delega todo el
//    trabajo. Es una manera de crear "sinónimos" de acciones, es decir, de
//    tener disponibles varios nombres para hacer lo mismo.
//
//  PARÁMETROS DE ENTRADA:
//
//    Ninguno.
//
//  VALOR DE SALIDA:
//
//    Devuelve un dato de tipo carácter (char) que representa el símbolo o letra 
//    capturado en el formato de codificación ASCII.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    obtenerLetra()
//
//      Es la función encargada de realizar la lectura real de la letra o símbolo.
//
////////////////////////////////////////////////////////////////////////////////

char obtenerCaracterASCII()
{
  return obtenerLetra();
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    char obtenerLetra (void);
//
//  USO:
//
//    Lee un carácter del teclado y valida si pertenece al estándar ASCII estándar.
//
//  DETALLES:
//
//    Captura una entrada mediante getchar() y evalúa su código numérico. Si el 
//    carácter se encuentra dentro del rango válido de ASCII (valores menores a 128), 
//    lo acepta y lo prepara para su devolución. En caso contrario, lo descarta 
//    asignando un carácter nulo. Al finalizar, si la entrada no fue la tecla ENTER, 
//    limpia el flujo de entrada para eliminar caracteres sobrantes o acumulados.
//
//  PARÁMETROS DE ENTRADA:
//
//    La función no recibe ningún parámetro de entrada (void).
//
//  VALOR DE SALIDA:
//
//    Devuelve un carácter (char). Si la entrada es válida, retorna el carácter leído; 
//    si no es un ASCII válido, retorna el carácter nulo ('\0').
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    getchar()
//
//      Función estándar que detiene el programa para leer un carácter del teclado.
//    vaciarBuffer()
//
//      Función interna que descarta los caracteres sobrantes en la entrada.
//
////////////////////////////////////////////////////////////////////////////////

char obtenerLetra (void)   // Sólo ASCII VÁLIDO.
{
  char letra, valida;
  
  letra = getchar();
  
  if (letra < 128)
    valida = letra; // Devolveremos la letra
  else
    valida = '\0';  // Devolveremos la letra nula.
  
  // VACIAMOS POSIBLES CÓDIGOS EN EL BUFFER.
  //   Se incluye el INTRO EXTRA y una posible escritura de múltiples letras.
  if (letra != ENTER)   vaciarBuffer();

  return valida;
}


////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    int pedirEntero (char msjtxt[], int ncols);
//
//  USO:
//
//    Muestra un mensaje en pantalla para pedir un dato entero al usuario. El
//    mensaje es configurable y desplazable un número de caracteres desde la
//    izquierda de la pantalla.
//
//  DETALLES:
//
//    Es como un printf() más un scanf(), mejorados. Puede desplazarse el texto
//    recibido mediante un segundo dato entero. También impide problemas del
//    buffer de teclado con scanf(). Para ello, delega el emitir el mensaje por
//    pantalla a las funciones msj() y mostrar(), y la toma del dato entero a la
//    función obtenerEntero().
//
//  PARÁMETROS DE ENTRADA:
//
//    mensaje
//
//      Variable de tipo vector de caracteres donde se recibirá el texto que se
//      debe mostrar, que debe ser una cadena terminada en '\0'.
//
//    tabs
//
//      Variable entera donde se recibirá del exterior el número de espacios en
//      blanco a añadir antes del mensaje.
//
//  VALOR DE SALIDA:
//
//    Devuelve al programa donde se invoque, un valor entero que a su vez esta
//    función ha recibido desde la función obtenerEntero().
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    msj()
//
//      Se encarga efectivamente de mostrar el mensaje.
//
//    mostrar()
//
//      Usada para añadir en pantalla un texto adicional después del mensaje.
//
//    obtenerEntero()
//
//      Es la función que se encarga en la práctica de obtener la cantidad.
//
////////////////////////////////////////////////////////////////////////////////

int pedirEntero (char msjtxt[], int ncols)
{
  mensaje(msjtxt, 0, ncols);
  mostrar(": ");
  
  return obtenerEntero();
}


////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    int pedirEnteroPositivo (char msjtxt[], int ncols, boolean mostrarerror);
//
//  USO:
//
//    Programa que pide un número entero por teclado y se asegura de que sea positivo.
//
//  DETALLES:
//
//    Muestra el texto de petición con los espacios a la derecha que se indiquen 
//    y lee el número de la pantalla. Si el número introducido es menor que cero 
//    y está activada la opción de errores, se muestra un mensaje avisando del 
//    fallo. El bucle se repite una y otra vez hasta que el número sea válido.
//
//  PARÁMETROS DE ENTRADA:
//
//    msjtxt
//
//      El texto o mensaje de petición que se va a mostrar en la pantalla.
//    ncols
//
//      Número de espacios o columnas que se va a mover el texto a la derecha.
//    mostrarerror
//
//      Opción para elegir si se desea mostrar el aviso de error (TRUE o FALSE).
//
//  VALOR DE SALIDA:
//
//    Devuelve el número entero positivo que se ha validado de forma correcta.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    mensaje()
//
//      Se usa para colocar y escribir la frase de petición del número.
//    mostrar()
//
//      Pone los dos puntos pegados al final de la frase de petición.
//    obtenerEntero()
//
//      Se encarga de leer el número que el usuario escribe en el teclado.
//    nuevaLinea()
//
//      Sirve para dejar una separación bajando una línea en blanco.
//    mensaje_x_y()
//
//      Muestra el texto de error en su fila y columna correspondientes.
//
////////////////////////////////////////////////////////////////////////////////

int pedirEnteroPositivo (char msjtxt[], int ncols, boolean mostrarerror)
{
  int num;
  
  do
  {
    mensaje(msjtxt, 0, ncols);
    mostrar(": ");
    num = obtenerEntero();
    
    if (mostrarerror)
    {
      if (num < 0)
      {
        nuevaLinea();
        mensaje_x_y(MSJxERROR, 0, ncols+2, TRUE);
        nuevaLinea();
      }
    }
    
  } while (num < 0);
  
  return num;
}



////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    int pedirEnteroIntervalo (char msjtxt[], int ncols, boolean mostrarerror, int min, int max);
//
//  USO:
//
//    Programa que pide un número entero por teclado y se asegura de que esté en un rango.
//
//  DETALLES:
//
//    Muestra el texto de petición con los espacios a la derecha que se indiquen 
//    y enseña los límites mínimo y máximo permitidos. Si el número no está dentro 
//    del rango y está activada la opción de errores, se muestra un mensaje avisando 
//    del fallo. El bucle se repite una y otra vez hasta que el dato sea válido.
//
//  PARÁMETROS DE ENTRADA:
//
//    msjtxt
//
//      El texto o mensaje de petición que se va a mostrar en la pantalla.
//    ncols
//
//      Número de espacios o columnas que se va a mover el texto a la derecha.
//    mostrarerror
//
//      Opción para elegir si se desea mostrar el aviso de error (TRUE o FALSE).
//    min
//
//      Valor mínimo que se puede introducir en el programa.
//    max
//
//      Valor máximo que se puede introducir en el programa.
//
//  VALOR DE SALIDA:
//
//    Devuelve el número entero validado dentro del intervalo correcto.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    mensaje()
//
//      Se usa para colocar y escribir la frase de petición del número.
//    printf()
//
//      Es el programa estándar que se usa para enseñar los límites del rango.
//    obtenerEntero()
//
//      Se encarga de leer el número que el usuario escribe en el teclado.
//    nuevaLinea()
//
//      Sirve para dejar una separación bajando una línea en blanco.
//    mensaje_x_y()
//
//      Muestra el texto de error en su fila y columna correspondientes.
//
////////////////////////////////////////////////////////////////////////////////

int pedirEnteroIntervalo (char msjtxt[], int ncols, boolean mostrarerror, int min, int max)
{
  int num;
  
  do
  {
    mensaje(msjtxt, 0, ncols);
    printf(" [%d,%d]: ", min, max);
    
    num = obtenerEntero();
    
    if (mostrarerror)
    {
      if (num < min || num > max)
      {
        nuevaLinea();
        mensaje_x_y(MSJxERROR, 0, ncols+2, TRUE);
        nuevaLinea();
      }
    }
    
  } while (num < min || num > max);
  
  return num;
}


////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    int pedirLetra (char msjtxt[], int ncols, boolean mostrarerror, char letra);
//
//  USO:
//
//    Programa que pide un carácter por teclado y se asegura de que sea una letra concreta.
//
//  DETALLES:
//
//    Pasa la letra buscada a mayúsculas y enseña el mensaje de petición movido a la 
//    derecha. Lee el carácter del usuario, lo pasa a mayúsculas para comparar de forma 
//    fácil y mira si coincide con el esperado. Si falla y se activa la opción de errores, 
//    se muestra el aviso por pantalla. Se repite hasta recibir la letra exacta.
//
//  PARÁMETROS DE ENTRADA:
//
//    msjtxt
//
//      El texto o mensaje de petición que se va a mostrar en la pantalla.
//    ncols
//
//      Número de espacios o columnas que se va a mover el texto a la derecha.
//    mostrarerror
//
//      Opción para elegir si se desea mostrar el aviso de error (TRUE o FALSE).
//    letra
//
//      Carácter o letra específica que se obliga a introducir al usuario.
//
//  VALOR DE SALIDA:
//
//    Devuelve la letra validada de forma correcta en formato de mayúsculas.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    toupper()
//
//      Función del sistema que convierte cualquier letra minúscula en mayúscula.
//    mensaje()
//
//      Se usa para colocar y escribir la frase de petición de la letra.
//    mostrar()
//
//      Pone los dos puntos pegados al final de la frase de petición.
//    obtenerLetra()
//
//      Se encarga de leer el carácter que el usuario escribe en el teclado.
//    nuevaLinea()
//
//      Sirve para dejar una separación bajando una línea en blanco.
//    mensaje_x_y()
//
//      Muestra el texto de error en su fila y columna correspondientes.
//
////////////////////////////////////////////////////////////////////////////////

int pedirLetra (char msjtxt[], int ncols, boolean mostrarerror, char letra)
{
  char pedida;
  
  letra = toupper(letra);
  
  do
  {
    mensaje(msjtxt, 0, ncols);
    mostrar(": ");
    
    pedida = obtenerLetra();
    pedida = toupper(pedida);   // Convertimos a mayúsculas para simplificar casos.
    
    if (mostrarerror)
    {
      if (letra != pedida)
      {
        nuevaLinea();
        mensaje_x_y(MSJxERROR, 0, ncols+2, TRUE);
        nuevaLinea();
      }
    }
    
  } while (letra != pedida);
  
  return pedida;
}


////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    int pedirConfirmacion (char msjtxt[], int ncols, boolean mostrarerror);
//
//  USO:
//
//    Programa que pide una respuesta afirmativa o negativa a través de las macros SI y NO.
//
//  DETALLES:
//
//    Muestra el texto de consulta junto con los caracteres válidos de respuesta. Lee el 
//    teclado y pasa la letra a mayúsculas para evitar fallos con los cambios de tamaño. 
//    Si la respuesta no es igual a la macro SI ni a la macro NO, enseña un mensaje de error 
//    siempre que esté activado el aviso. El proceso continúa hasta recibir una de las dos.
//
//  PARÁMETROS DE ENTRADA:
//
//    msjtxt
//
//      El texto o mensaje de confirmación que se va a mostrar en la pantalla.
//    ncols
//
//      Número de espacios o columnas que se va a mover el texto a la derecha.
//    mostrarerror
//
//      Opción para elegir si se desea mostrar el aviso de error (TRUE o FALSE).
//
//  VALOR DE SALIDA:
//
//    Devuelve el carácter de confirmación definitivo que coincide con SI o con NO.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    mensaje()
//
//      Se usa para colocar y escribir la frase de consulta en la pantalla.
//    printf()
//
//      Es el programa estándar que se usa para enseñar las opciones válidas de respuesta.
//    obtenerLetra()
//
//      Se encarga de leer el carácter que el usuario escribe en el teclado.
//    toupper()
//
//      Función del sistema que convierte cualquier letra minúscula en mayúscula.
//    nuevaLinea()
//
//      Sirve para dejar una separación bajando una línea en blanco.
//    mensaje_x_y()
//
//      Muestra el texto de error en su fila y columna correspondientes.
//
////////////////////////////////////////////////////////////////////////////////

int pedirConfirmacion (char msjtxt[], int ncols, boolean mostrarerror)
{
  char letra;
  
  do
  {
    mensaje(msjtxt, 0, ncols);
    printf(" [%c/%c]: ", SI, NO);
    
    letra = obtenerLetra();
    letra = toupper(letra);   // Convertimos a mayúsculas para simplificar casos.
    
    if (mostrarerror)
    {
      if (letra != SI && letra != NO)
      {
        nuevaLinea();
        mensaje_x_y(MSJxERROR, 0, ncols+2, TRUE);
        nuevaLinea();
      }
    }
    
  } while (letra != SI && letra != NO);
  
  return letra;
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    boolean validarLetraUnica (char original, char dada, boolean sensibleamayusculas);
//
//  USO:
//
//    Compara dos caracteres para verificar si representan la misma letra.
//
//  DETALLES:
//
//    Analiza la igualdad entre un carácter original y uno recibido por el usuario. 
//    Si el parámetro sensibleamayusculas se establece en FALSE, la función 
//    transforma temporalmente ambas letras a mayúsculas antes de compararlas, 
//    haciendo que caracteres como 'a' y 'A' se consideren iguales. Devuelve el 
//    resultado de la evaluación como un valor booleano.
//
//  PARÁMETROS DE ENTRADA:
//
//    original
//
//      El carácter de referencia o patrón guardado por el programa.
//    dada
//
//      El carácter introducido por el usuario que se desea verificar.
//    sensibleamayusculas
//
//      Opción (TRUE o FALSE) para activar o desactivar la distinción estricta 
//      entre letras mayúsculas y minúsculas.
//
//  VALOR DE SALIDA:
//
//    Devuelve un valor booleano (boolean). Retorna TRUE si los caracteres coinciden 
//    según las reglas establecidas, o FALSE en caso de que sean diferentes.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    toupper()
//
//      Función estándar que convierte un carácter en su equivalente en mayúscula.
//
////////////////////////////////////////////////////////////////////////////////

boolean validarLetraUnica (char original, char dada, boolean sensibleamayusculas)
{
  if (!sensibleamayusculas)
  {
    original = toupper(original);
      dada   = toupper(dada);
  }
  
  return (original == dada);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    boolean validarLetraConjunto (char letra, char seleccion[], boolean sensibleamayusculas);
//
//  USO:
//
//    Verifica si un carácter específico se encuentra dentro de una lista o cadena de texto.
//
//  DETALLES:
//
//    Recorre uno a uno los caracteres de un arreglo dinámico utilizando un bucle
//    for. En cada iteración, invoca a la función validarLetraUnica() para comparar
//    la letra buscada con la posición actual del arreglo. Si encuentra una coincidencia,
//    activa la bandera de resultado en TRUE e interrumpe el ciclo de inmediato mediante
//    un break para optimizar el tiempo de ejecución.
//
//  PARÁMETROS DE ENTRADA:
//
//    letra
//
//      El carácter individual que el programa desea buscar o validar.
//    seleccion[]
//
//      El arreglo o cadena de caracteres que contiene el grupo de letras permitidas.
//    sensibleamayusculas
//
//      Opción (TRUE o FALSE) para decidir si se diferencia entre mayúsculas y minúsculas.
//
//  VALOR DE SALIDA:
//
//    Devuelve un valor booleano (boolean). Devuelve TRUE si la letra existe dentro 
//    del conjunto, o FALSE si se termina el recorrido sin encontrar coincidencia.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    strlen()
//
//      Función estándar que calcula la longitud total de la cadena de texto dada.
//    validarLetraUnica()
//
//      Función que compara de forma individual dos letras bajo ciertas condiciones.
//
////////////////////////////////////////////////////////////////////////////////

boolean validarLetraConjunto (char letra, char seleccion[], boolean sensibleamayusculas)
{
  boolean resultado = FALSE;
  int largo = strlen(seleccion);
  
  for(int i = 0; i < largo ; i++)
  {
    if (validarLetraUnica(letra, seleccion[i], sensibleamayusculas))
    {
      resultado = TRUE;
      break;
    }
  }
  
  return resultado;
}


char *cadenaOpcionesDisponibles (char entrada[])
{
  if (entrada == NULL) return NULL;   // Si no dan nada, petas máximus ...
  
  char *textoinicial, *textofinal;
  
  textoinicial = entrada;
  
  int largoinicial, largofinal;
  
  largoinicial = strlen(textoinicial);

  if (largoinicial == 0)
  {
    // Nos dan cadena vacía, así que generamos vacía. Pero consideramos el '\0'.
    largofinal = 1;
    textofinal = (char *) malloc(1*sizeof(char));
    textofinal[0] = '\0';
  }
  else
  {
    // CASO 1: "A" -> "A" => largo 2 = 1 (letra) + 1 ('\0')
    // CASO 2: "ABC" -> "A/B/C" => largo 6 = 3 (letras) + 2 (sepadores) +1 ('\0'); 
    largofinal = 2 * largoinicial;
    textofinal = (char *) malloc(largofinal*sizeof(char));
    
    if (textofinal != NULL)
    {
      int j = 0;
      for (int i = 0; i < largoinicial; i++, j++)
      {
        textofinal[j] = textoinicial[i];
        j++;
        textofinal[j] = '/';
      }
      
      // Sustituimos la última '/' por un ' 0'.
      j--;
      textofinal[j] = '\0';
    }
  }

  return textofinal;
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    int pedirLetraSeleccion (char msjtxt[], int ncols, boolean mostrarerror, char seleccion[], boolean sensibleamayusculas);
//
//  USO:
//
//    Solicita repetidamente una letra al usuario hasta que introduzca una opción válida de una lista.
//
//  DETALLES:
//
//    Genera un bucle do-while que imprime un mensaje de solicitud junto 
//    con la lista de opciones formateada por cadenaOpcionesDisponibles(). Lee la 
//    entrada con obtenerLetra() y evalúa si pertenece al conjunto permitido usando 
//    validarLetraConjunto(). Si la entrada es inválida y 'mostrarerror' es TRUE, 
//    despliega un aviso visual de error. Al romper el ciclo, libera la memoria dinámica 
//    del texto de opciones y retorna la letra (en mayúscula si no es sensible al caso).
//
//  PARÁMETROS DE ENTRADA:
//
//    msjtxt
//
//      La frase o cadena de texto para pedirle el dato al usuario.
//    ncols
//
//      La cantidad de espacios o tabulaciones hacia la derecha para alinear el menú.
//    mostrarerror
//
//      Opción (TRUE o FALSE) para activar o desactivar un aviso visual si la opción es incorrecta.
//    seleccion[]
//
//      El arreglo con el grupo original de caracteres permitidos para la validación.
//    sensibleamayusculas
//
//      Opción (TRUE o FALSE) para determinar si se distingue estrictamente entre mayúsculas y minúsculas.
//
//  VALOR DE SALIDA:
//
//    Devuelve el código entero (int) correspondiente al carácter válido aceptado por el sistema.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    cadenaOpcionesDisponibles()
//
//      Genera una nueva cadena formateada con las opciones y reserva memoria dinámica para ella.
//    mensaje() / mostrar() / printf() / nuevaLinea() / mensaje_x_y()
//
//      Funciones de interfaz encargadas de dar formato, espaciado e imprimir texto en la consola.
//    obtenerLetra()
//
//      Captura y valida un carácter desde la entrada estándar del teclado.
//    validarLetraConjunto()
//
//      Comprueba si el carácter ingresado existe en el arreglo de opciones válidas.
//    free()
//
//      Función estándar que libera el bloque de memoria asignado dinámicamente a la cadena de opciones.
//    toupper()
//
//      Función estándar que convierte la letra final a mayúscula si el sistema ignora las minúsculas.
//
////////////////////////////////////////////////////////////////////////////////

int pedirLetraSeleccion (char msjtxt[], int ncols, boolean mostrarerror, char seleccion[], boolean sensibleamayusculas)
{
  // HACER: Evitar que falle con «seleccion» a valor NULL.
  
  // Usar «cadenaOpcionesDisponibles()» implica luego liberar memoria con «free()».
  char *editada = cadenaOpcionesDisponibles(seleccion);
  
  char letra;
  
  boolean validada;
  
  do
  {
    mensaje(msjtxt, 0, ncols);
    mostrar(" [");
    printf("%s", editada);
    mostrar("]: ");
    
    letra = obtenerLetra();

    validada = validarLetraConjunto(letra, seleccion, sensibleamayusculas);
    
    if (mostrarerror)
    {
      if (!validada)
      {
        nuevaLinea();
        mensaje_x_y(MSJxERROR, 0, ncols+2, TRUE);
        nuevaLinea();
      }
    }
  } while (!validada);
  
  // Liberamos la memoria para cadena modificada.
  free(editada);
  
  // Si no era sensible a mayúsculas, siempre la devolvemos mayúscula.
  if (!sensibleamayusculas)   letra = toupper(letra);
  
  return letra;
}



#ifdef SO_WINDOWS

#include <conio.h>

char obtenerTeclaInteractiva(void)
{
  int caracter = _getch();   // En Windows, getch() ya es bloqueante por defecto.

  if (caracter == 0 || caracter == 224)
  {
    // Tecla especial, depende de un segundo código. Lo leemos.
    caracter = _getch();
    
    switch(caracter)
    {
      case 72: caracter = TECLA_ARRIBA;    break;   // Flecha Arriba
      case 80: caracter = TECLA_ABAJO;     break;   // Flecha Abajo
      case 75: caracter = TECLA_IZQUIERDA; break;   // Flecha Izquierda
      case 77: caracter = TECLA_DERECHA;   break;   // Flecha Derecha
      default: caracter = TECLA_NULA;               // Tecla nula.
    }
    else
    {
      // Normalización de teclas conflictivas no estándar.
      switch(caracter)
      {
        case 13: caracter = TECLA_ENTER;
        case 8:  caracter = TECLA_RETROCESO;
      }
    }
    
    return (char)caracter;
}

#else

#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int obtenerTeclaInteractiva(void)
{
  struct termios terminaloriginal, terminalnueva;
  int caracter;

  // 1. Obtenemos la configuración actual de la terminal.
  tcgetattr(STDIN_FILENO, &terminaloriginal);
  terminalnueva = terminaloriginal;

  // 2. Desactivamos el modo canónico (espera de INTRO) y el ECO (ver la tecla al pulsar).
  terminalnueva.c_lflag &= ~(ICANON | ECHO); // Quitamos espera de INTRO y eco
  tcsetattr(STDIN_FILENO, TCSANOW, &terminalnueva);
  
  // 3. El programa se detiene aquí hasta recibir un carácter.
  // Las flechas envían una secuencia de escape: 27 (ESC), 91 ('['), y una letra.
  caracter = getchar();
  
  if (caracter == ESCAPE)
  {
    // Cambiamos a NO BLOQUEANTE un instante para ver si hay bytes extra
    int flags = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, flags | O_NONBLOCK);
    
    // Pedimos a ver si hay otro caracter.
    int siguiente = getchar();
    
    // ¿Es '[' (91)?
    if (siguiente == '[')
    {
      // Lo desechamos simplemente no usando "siguiente".

      // Pedimos el tercer código de caracter generado.
      caracter = getchar();
      
      while ((siguiente = getchar()) != EOF && siguiente != -1);

      switch(caracter)
      {
        case 'A': caracter = TECLA_ARRIBA;    break;   // Flecha Arriba
        case 'B': caracter = TECLA_ABAJO;     break;   // Flecha Abajo
        case 'D': caracter = TECLA_IZQUIERDA; break;   // Flecha Izquierda
        case 'C': caracter = TECLA_DERECHA;   break;   // Flecha Derecha
        default:  caracter = TECLA_NULA;      break;
      }
    }
    else
    {
      if (siguiente == EOF || siguiente == -1)
      {
        // Era sólo la tecla ESCAPE.
        caracter = TECLA_ESCAPE;
      }
      else
      {
        // Era una secuencia no contemplada.
        caracter = TECLA_NULA;
      }
    }

    // Restauramos el modo BLOQUEANTE de la terminal.
    fcntl(STDIN_FILENO, F_SETFL, flags);
  }

  // 4. Restauramos la configuración original antes de salir.
  tcsetattr(STDIN_FILENO, TCSANOW, &terminaloriginal);
  
  return caracter;
}

#endif
