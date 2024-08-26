#include <stdlib.h>
#include <string.h>  // Para usar strcpy
#include "hospital.h"
#include "exam_priority_queue.h"
#include "diagnostico.h"
#include "unistd.h"

void processarDiagnosticoIA(Hospital *hospital, Exam *exame, int tempo) {
    int randValue = rand() % 100; // Gera um valor aleatório entre 0 e 99

    if (randValue < 30) {
        exame->conditionIA = 1;  // Saúde Normal (30%)
        strcpy(exame->conditionName, "Saúde Normal");
    } else if (randValue < 50) {
        exame->conditionIA = 2;  // Bronquite (20%)
        strcpy(exame->conditionName, "Bronquite");
    } else if (randValue < 60) {
        exame->conditionIA = 3;  // Pneumonia (10%)
        strcpy(exame->conditionName, "Pneumonia");
    } else if (randValue < 70) {
        exame->conditionIA = 4;  // COVID (10%)
        strcpy(exame->conditionName, "COVID");
    } else if (randValue < 75) {
        exame->conditionIA = 4;  // Embolia pulmonar (5%)
        strcpy(exame->conditionName, "Embolia Pulmonar");
    } else if (randValue < 80) {
        exame->conditionIA = 4;  // Derrame pleural (5%)
        strcpy(exame->conditionName, "Derrame Pleural");
    } else if (randValue < 85) {
        exame->conditionIA = 5;  // Fibrose pulmonar (5%)
        strcpy(exame->conditionName, "Fibrose Pulmonar");
    } else if (randValue < 90) {
        exame->conditionIA = 5;  // Tuberculose (5%)
        strcpy(exame->conditionName, "Tuberculose");
    } else {
        exame->conditionIA = 6;  // Câncer de pulmão (10%)
        strcpy(exame->conditionName, "Câncer de Pulmão");
    }

    // Grava o exame no banco de dados
    gravarExameNoBancoDeDados(exame);
}

void processarLaudo(Hospital *hospital, Exam *exame, int tempo) {
    sleep(20);  // Simula o tempo necessário para processar o laudo

    exame->conditionFinal = exame->conditionIA;

    // Grava o laudo no banco de dados
    gravarLaudoNoBancoDeDados(exame, tempo);
}

