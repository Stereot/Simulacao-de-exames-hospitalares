#include <stdlib.h> // Inclui funções da biblioteca padrão para alocação de memória (malloc, free, etc.)
#include <string.h> // Inclui funções da biblioteca padrão para manipulação de strings (strcpy, strcmp, etc.)
#include "hospital.h" // Inclui a estrutura do hospital (hospital.h)
#include "exam_priority_queue.h" // Inclui a estrutura da fila de prioridade de exames (exam_priority_queue.h)
#include "diagnostico.h" // Inclui as funções relacionadas ao diagnóstico (diagnostico.h)
#include "unistd.h" // Inclui funções relacionadas ao tempo de espera (sleep)

void processarDiagnosticoIA(Hospital *hospital, Exam *exame, int tempo) {
    // Gera um número aleatório entre 0 e 99
    int randValue = rand() % 100; 

    // Define a condição inicial do exame com base no número aleatório
    if (randValue < 30) {
        exame->conditionIA = 1;  // Saúde Normal (30%)
        strcpy(exame->conditionName, "Saúde Normal"); // Copia a string "Saúde Normal" para conditionName
    } else if (randValue < 50) {
        exame->conditionIA = 2;  // Bronquite (20%)
        strcpy(exame->conditionName, "Bronquite"); // Copia a string "Bronquite" para conditionName
    } else if (randValue < 60) {
        exame->conditionIA = 3;  // Pneumonia (10%)
        strcpy(exame->conditionName, "Pneumonia"); // Copia a string "Pneumonia" para conditionName
    } else if (randValue < 70) {
        exame->conditionIA = 4;  // COVID (10%)
        strcpy(exame->conditionName, "COVID"); // Copia a string "COVID" para conditionName
    } else if (randValue < 75) {
        exame->conditionIA = 4;  // Embolia pulmonar (5%)
        strcpy(exame->conditionName, "Embolia Pulmonar"); // Copia a string "Embolia Pulmonar" para conditionName
    } else if (randValue < 80) {
        exame->conditionIA = 4;  // Derrame pleural (5%)
        strcpy(exame->conditionName, "Derrame Pleural"); // Copia a string "Derrame Pleural" para conditionName
    } else if (randValue < 85) {
        exame->conditionIA = 5;  // Fibrose pulmonar (5%)
        strcpy(exame->conditionName, "Fibrose Pulmonar"); // Copia a string "Fibrose Pulmonar" para conditionName
    } else if (randValue < 90) {
        exame->conditionIA = 5;  // Tuberculose (5%)
        strcpy(exame->conditionName, "Tuberculose"); // Copia a string "Tuberculose" para conditionName
    } else {
        exame->conditionIA = 6;  // Câncer de pulmão (10%)
        strcpy(exame->conditionName, "Câncer de Pulmão"); // Copia a string "Câncer de Pulmão" para conditionName
    }


    gravarExameNoBancoDeDados(exame); // Salva o exame no banco de dados
}

void processarLaudo(Hospital *hospital, Exam *exame, int tempo) {
    sleep(20);  // Simula o tempo necessário para processar o laudo

    exame->conditionFinal = exame->conditionIA; // Define a condição final como a condição inicial

    gravarLaudoNoBancoDeDados(exame, tempo); // Salva o laudo no banco de dados
}
