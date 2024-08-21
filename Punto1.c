#include <stdio.h>

// Definición de la estructura
typedef struct {
    float porcentajes[6];
    const char *preguntas[6];
    float respuestas[6];
} Grades;

// Declaración de las funciones
void hacerPreguntas(const char *preguntas[], float porcentajes[], float respuestas[], int numPreguntas);
float CalculoNotaFinal(float respuestas[], float porcentajes[]);

int main() {
    // Inicialización de datos
    Grades grades = {
        {0.05, 0.25, 0.15, 0.20, 0.15, 0.20},
        {
            "¿Cuál es tu nota del Lab I: Retomando C?",
            "¿Cuál es tu nota del Parcial I: Procesos?",
            "¿Cuál es tu nota del Lab II: Hilos & Sincronización?",
            "¿Cuál es tu nota del Parcial II: Memoria?",
            "¿Cuál es tu nota del Lab III: Planificación?",
            "¿Cuál es tu nota del Parcial III: Entrada y Salida?"
        },
        {0}
    };

    // Llamada a la función para hacer preguntas
    hacerPreguntas(grades.preguntas, grades.porcentajes, grades.respuestas, 6);
    
    // Calcular la nota final y mostrar el resultado
    float i = CalculoNotaFinal(grades.respuestas, grades.porcentajes);
    printf("Nota final: %f\n", i);

    return 0;
}

// Implementación de la función para hacer preguntas
void hacerPreguntas(const char *preguntas[], float porcentajes[], float respuestas[], int numPreguntas) {
    for (int i = 0; i < numPreguntas; i++) {
        printf("%s\n", preguntas[i]);
        printf("Introduce tu respuesta: ");
        scanf("%f", &respuestas[i]);
    }
}

// Implementación de la función para calcular la nota final
float CalculoNotaFinal(float respuestas[], float porcentajes[]) {
    float final = 0.0;
    for (int i = 0; i < 6; i++) {
        final += respuestas[i] * porcentajes[i];
    }
    return final;
}
