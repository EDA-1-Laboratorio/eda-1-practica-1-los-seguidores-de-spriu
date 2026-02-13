#include <stdio.h>

// Definimos un tamaño máximo para facilitar la gestión de memoria en esta práctica
#define MAX 20

void generarEspiral(int n, int matriz[MAX][MAX]) {
    int valor = 1;
    int top = 0, bottom = n - 1;
    int left = 0, right = n - 1;

    while (valor <= n * n) {
        // 1. Recorrer de izquierda a derecha (fila superior)
        // TODO: Escribir el bucle for que llena desde 'left' hasta 'right'
        // Tip: Al terminar, incrementar 'top'
        for (int i= left; i<= right; i=i+1) {   //Empieza en la columna (i) mientras i sea menor o igual que right y la columna (i) avanza de a 1
            matriz[top][i]= valor;              //De esta forma se irán llenando los espacios de las columnas de la fila superior (top)
            valor= valor + 1;                   //Aumenta el valor en 1 porque es el valor que se le asignará a cada espacio 
        }
        top=top+1;                              //Aumento top en 1 para que la siguiente fila "superior" sea la que esta abajo de top
        
        // 2. Recorrer de arriba a abajo (columna derecha)
        // TODO: Escribir el bucle for que llena desde 'top' hasta 'bottom'
        // Tip: Al terminar, decrementar 'right'
        for (int i=top; i<= bottom; i=i+1) {    //Empieza en la fila (i) mientras i sea menor o igual que bottom y la fila (i) avanza de a 1
            matriz[i][right]=valor;             //De esta forma se van llenando los espacios de la columna derecha 
            valor=valor+1;                      //Aumenta el valor en 1 porque es el valor que se le asignará a cada espacio 
        }
        right=right-1;                          //Le resto 1 a la columna derecha para que se mueva a la izquierda

        // 3. Recorrer de derecha a izquierda (fila inferior)
        if (top <= bottom) {                    //Si top(fila superior) es menor o igual que bottom(fila inferior) 
            // TODO: Escribir el bucle for
            // Tip: Al terminar, decrementar 'bottom'
            for(int i=right; i>=left; i=i-1) {  //Empieza en la columna (i) mientras i sea mayor o igual que left y la columna (i) retrocede de a 1
               matriz[bottom][i]=valor;         //De esta forma se van llenando los espacios de las columnas de la fila inferior que es bottom
                valor=valor+1;                  //Aumenta el valor en 1 porque es el valor que se le asignará a cada espacio 
            }
            bottom=bottom-1;                    //Le resto 1 a la fila inferior para que empiece desde más arriba
        }
        // 4. Recorrer de abajo a arriba (columna izquierda)
        if (left <= right) {                    //Si la columna izquierda es menor o igual que la derecha
            // TODO: Escribir el bucle for
            // Tip: Al terminar, incrementar 'left'
            for(int i=bottom; i>=top; i=i-1) {  //Empieza en la fila (i) mientras i sea mayor o igual que top y la fila (i) retrocede de a 1
                matriz[i][left]=valor;          //De esta forma se van llenando los espacios de la columna izquierda
                valor=valor+1;                  //Aumenta el valor en 1 porque es el valor que se le asignará a cada espacio
            }
            left=left+1;                        //Aumento la columna en 1 para que se mueva ahora hacia la derecha
        }
    }
}

void imprimirMatriz(int n, int matriz[MAX][MAX]) {
    printf("\n--- Matriz Espiral de %dx%d ---\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%4d ", matriz[i][j]); // %4d para alinear columnas
        }
        printf("\n");
    }
}

int main() {
    int n;
    int matriz[MAX][MAX];

    printf("Ingrese el tamaño N de la matriz (max %d): ", MAX);
    scanf("%d", &n);

    if (n > MAX) {
        printf("Error: El tamaño excede el máximo permitido.\n");
        return 1;
    }

    generarEspiral(n, matriz);
    imprimirMatriz(n, matriz);

    return 0;
}

// PREGUNTA: ¿Qué sucede si se omite la verificación if (top <= bottom) -linea 21- dentro del bucle?
// RESPUESTA: 
