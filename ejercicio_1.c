#include <stdio.h>
#include <string.h>

// Prototipos de funciones
void crearMensaje();
void descifrarMensaje();

int main() {
    int opcion = 0;
    
    while (1) {
        printf("\n\t*** ESCÍTALA ESPARTANA ***\n");
        printf("1) Crear mensaje cifrado (Cifrar).\n");
        printf("2) Descifrar mensaje.\n");
        printf("3) Salir.\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                crearMensaje();
                break;
            case 2:
                descifrarMensaje();
                break;
            case 3:
                printf("Saliendo del programa...\n");
                return 0;
            default:
                printf("Opción no válida. Intente de nuevo.\n");
        }
    }
    return 0;
}

void crearMensaje() {
    int ren, col, i = 0, j = 0, k = 0;

    printf("\n--- CIFRADO ---\n");
    printf("Ingresar el tamaño de la escítala (Renglones): ");
    scanf("%d", &ren);
    printf("Ingresar el tamaño de la escítala (Columnas/Caras): ");
    scanf("%d", &col);

    char escitala[ren][col];
    char texto[ren * col]; // Arreglo lineal para el texto original

    printf("Escriba el texto a cifrar (sin espacios): ");
    scanf("%s", texto);

    // PASO 1: Llenar la matriz con el texto original
    // La escítala se escribe a lo largo de la vara (fila por fila en la matriz lógica)
    
    /* TODO: Escribe aquí los bucles anidados para llenar 'escitala[i][j]' 
       usando los caracteres de 'texto'.
       Tip: Necesitas recorrer renglones y luego columnas. */

    size_t size = sizeof(texto)/sizeof(texto[0]);   // Variable que contiene el tamaño de texto[]

    printf("\n\n");
    // Bucle matriz

    for (i = 0; i < ren; i++){                      // Se coloca en el renglon i

        for (j = 0; j < col; j++){                  // Avanza hacia la derecha en las columnas

           escitala[i][j] = texto[k];               // Coloca el carácter contenido en texto[k] en la posicion [i][j] de la matriz.
           k++;

        }

    }

    /*Bucle print //Descomentar esta parte para imprimir la matriz auxiliar.

    for (i = 0; i < ren; i++){


        for (j = 0; j < col; j++){

            printf("%c ", escitala[i][j]);

        }

        printf("\n");

    }*/

    printf("\n\n");

    printf("El texto cifrado (leído de la tira) es:\n");

    // PASO 2: Leer la matriz para obtener el cifrado
    // Al desenrollar la tira, leemos verticalmente (columna por columna)
    
    /* TODO: Escribe aquí los bucles para imprimir el mensaje cifrado.
       Tip: Ahora el bucle externo debe controlar las columnas y el interno los renglones. */
    k = 0;                                          // Reiniciamos k
    char texto2[size+1];                              // Creamos un nuevo arreglo con el tamaño texto[] para guardar el texto cifrado. 
    for (i = 0; i < col; i++){                      // Se coloca en la columna j

        for (j = 0; j < ren; j++){                  // Baja por los renglones

           texto2[k] = escitala[j][i];              // Cambiamos el valor en la posicion [j][i], i controla las columnas y j los renglones, por eso no usamos [i][j].
           k++;

        }

    }
    texto2[size] = '\0';
    printf("%s", texto2);
    printf("\n");

}

void descifrarMensaje() {
    int ren, col, i=0, j=0, k = 0;

    printf("\n--- DESCIFRADO ---\n");
    printf("Ingresar el tamaño de la escítala (Renglones original): ");
    scanf("%d", &ren);
    printf("Ingresar el tamaño de la escítala (Columnas original): ");
    scanf("%d", &col);

    char escitala[ren][col];
    char texto[ren * col];

    printf("Escriba el texto cifrado: ");
    scanf("%s", texto);

    // PASO 1: Reconstruir la matriz desde la tira cifrada
    // Recuerda: El texto cifrado viene en orden de columnas (vertical),
    // por lo tanto, debemos llenarlo en ese mismo orden.

    /* TODO: Escribe aquí los bucles para llenar la matriz 'escitala'.
       Tip: El orden de los bucles 'for' es inverso al llenado del cifrado normal. 
       Debes llenar columna por columna usando el 'texto' cifrado. */

    // Bucle matriz.

    for (i = 0; i < col; i++){                      // Nuevamente necesitamos leer la matriz hacia abajo (en lugar de hacia la derecha), asi que i controlara las columnas y j los renglones.

        for (j = 0; j < ren; j++){

           escitala[j][i] = texto[k];               //  Volvemos a acceder a la posicion [j][i] (en lugar de [i][j]), para que los valores de la matriz pasen de manera correcta al arreglo texto[]
           k++;

        }

    }

    /*Bucle print //Descomentar esta parte para imprimir la matriz auxiliar.

    for (i = 0; i < ren; i++){


        for (j = 0; j < col; j++){

            printf("%c ", escitala[i][j]);

        }

        printf("\n");

    }*/

    printf("El texto descifrado es:\n");

    // PASO 2: Leer el mensaje original
    // Una vez reconstruida la matriz, leemos fila por fila normalmente.

    /* TODO: Escribe aquí los bucles para imprimir el mensaje original. */

    size_t size = sizeof(texto)/sizeof(texto[0]);   // Variable que contiene el tamaño de texto[]
    k = 0;                                          // Reiniciamos k
    char texto2[size];                              // Creamos un nuevo arreglo con el tamaño de texto[] para guardar el texto descifrado.
    for (i = 0; i < ren; i++){                      // Se coloca en el renglon i

        for (j = 0; j < col; j++){                  // Lee las columnas (lee hacia la derecha)

           texto2[k] = escitala[i][j];              // Cambiamos el valor de texto2[k] por el almacenado en la posicion [i][j]
           k++;

        }

    }
    texto2[size] = '\0';
    printf("%s", texto2);
    printf("\n");

    printf("\n");
}

// PREGUNTA: En la implementación se una matriz auxiliar de dimensiones ren × col para realizar la transposición. 
// Si tuvieras una restricción de memoria severa y no pudieras crear esa matriz bidimensional, 
// ¿qué fórmula matemática utilizarías para imprimir el carácter correcto directamente desde el arreglo original texto[] ?
