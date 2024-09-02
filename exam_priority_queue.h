#ifndef EXAM_PRIORITY_QUEUE_H
#define EXAM_PRIORITY_QUEUE_H

#include <stdio.h>
#include "patient_queue.h"

typedef struct Exam {
    int id;
    int conditionIA;
    int conditionFinal;
    int timestamp;
    char conditionName[50];
} Exam;

typedef struct ExamPriorityQueue {
    Exam **exams;
    int size;
    int capacity;
} ExamPriorityQueue;

Exam *criarExam(Paciente *paciente, int timestamp);
ExamPriorityQueue *criarExamPriorityQueue();
void destruirExamPriorityQueue(ExamPriorityQueue *fila);
void enqueueExam(ExamPriorityQueue *fila, Exam *exame);
Exam *dequeueExam(ExamPriorityQueue *fila);
int isEmptyExamPriorityQueue(ExamPriorityQueue *fila);
void gravarExameNoBancoDeDados(Exam *exame);
void gravarLaudoNoBancoDeDados(Exam *exame, int tempo);

#endif
