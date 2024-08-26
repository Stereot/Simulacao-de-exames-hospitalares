#include "exam_priority_queue.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h> 
#include "patient_queue.h"

Exam *criarExam(Paciente *paciente, int timestamp) {
    Exam *exame = (Exam *)malloc(sizeof(Exam));
    exame->id = paciente->id;
    exame->conditionIA = -1;
    exame->conditionFinal = -1;
    exame->timestamp = timestamp;
    strcpy(exame->conditionName, "Desconhecido");  // Nome inicializado como "Desconhecido"
    return exame;
}

ExamPriorityQueue *criarExamPriorityQueue() {
    ExamPriorityQueue *fila = (ExamPriorityQueue *)malloc(sizeof(ExamPriorityQueue));
    fila->exams = (Exam **)malloc(sizeof(Exam *) * 10);
    fila->size = 0;
    fila->capacity = 10;
    return fila;
}

void destruirExamPriorityQueue(ExamPriorityQueue *fila) {
    for (int i = 0; i < fila->size; i++) {
        free(fila->exams[i]);
    }
    free(fila->exams);
    free(fila);
}

void enqueueExam(ExamPriorityQueue *fila, Exam *exame) {
    if (fila->size == fila->capacity) {
        fila->capacity *= 2;
        fila->exams = (Exam **)realloc(fila->exams, sizeof(Exam *) * fila->capacity);
    }
    fila->exams[fila->size++] = exame;
}

Exam *dequeueExam(ExamPriorityQueue *fila) {
    if (fila->size == 0) {
        return NULL;
    }
    Exam *exame = fila->exams[0];
    for (int i = 1; i < fila->size; i++) {
        fila->exams[i - 1] = fila->exams[i];
    }
    fila->size--;
    return exame;
}

int isEmptyExamPriorityQueue(ExamPriorityQueue *fila) {
    return fila->size == 0;
}

void gravarExameNoBancoDeDados(Exam *exame) {
    FILE *arquivo = fopen("db_exam.txt", "a");
    if (arquivo) {
        fprintf(arquivo, "ID: %d, Condição IA: %d, Nome: %s, Timestamp: %d\n", exame->id, exame->conditionIA, exame->conditionName, exame->timestamp);
        fclose(arquivo);
    }
}

void gravarLaudoNoBancoDeDados(Exam *exame, int tempo) {
    FILE *arquivo = fopen("db_report.txt", "a");
    if (arquivo) {
        fprintf(arquivo, "ID: %d, Condição Final: %d, Nome: %s, Tempo de Espera: %d\n", exame->id, exame->conditionFinal, exame->conditionName, tempo - exame->timestamp);
        fclose(arquivo);
    }
}
