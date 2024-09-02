#include "exam_priority_queue.h" // Inclui o cabeçalho da fila de prioridade de exames (exam_priority_queue.h)
#include <stdlib.h> // Inclui funções da biblioteca padrão para alocação de memória (malloc, free, etc.)
#include <stdio.h> // Inclui funções da biblioteca padrão para entrada e saída (printf, scanf, etc.)
#include <string.h> // Inclui funções da biblioteca padrão para manipulação de strings (strcpy, strcmp, etc.)
#include "patient_queue.h" // Inclui a estrutura da fila de pacientes (patient_queue.h)

Exam *criarExam(Paciente *paciente, int timestamp) {
    // Alocação de memória para um novo exame
    Exam *exame = (Exam *)malloc(sizeof(Exam));
    // Atribuição de ID, condição IA, condição final e carimbo de tempo ao exame
    exame->id = paciente->id; 
    exame->conditionIA = -1;
    exame->conditionFinal = -1;
    exame->timestamp = timestamp;
    // Inicialização do nome da condição como "Desconhecido"
    strcpy(exame->conditionName, "Desconhecido");  
    // Retorna o ponteiro para o exame criado
    return exame;
}

ExamPriorityQueue *criarExamPriorityQueue() {
    // Alocação de memória para uma nova fila de prioridade de exames
    ExamPriorityQueue *fila = (ExamPriorityQueue *)malloc(sizeof(ExamPriorityQueue));
    // Alocação de memória para um array de exames com capacidade inicial de 10
    fila->exams = (Exam **)malloc(sizeof(Exam *) * 10);
    // Inicialização do tamanho da fila e da capacidade
    fila->size = 0;
    fila->capacity = 10;
    // Retorna o ponteiro para a fila de prioridade de exames criada
    return fila;
}

void destruirExamPriorityQueue(ExamPriorityQueue *fila) {
    // Libera a memória alocada para cada exame na fila
    for (int i = 0; i < fila->size; i++) {
        free(fila->exams[i]);
    }
    // Libera a memória alocada para o array de exames
    free(fila->exams);
    // Libera a memória alocada para a fila de prioridade de exames
    free(fila);
}

void enqueueExam(ExamPriorityQueue *fila, Exam *exame) {
    // Verifica se a fila está cheia
    if (fila->size == fila->capacity) {
        // Dobra a capacidade da fila
        fila->capacity *= 2;
        // Realloca memória para o array de exames com a nova capacidade
        fila->exams = (Exam **)realloc(fila->exams, sizeof(Exam *) * fila->capacity);
    }
    // Adiciona o exame à fila
    fila->exams[fila->size++] = exame;
}

Exam *dequeueExam(ExamPriorityQueue *fila) {
    // Verifica se a fila está vazia
    if (fila->size == 0) {
        // Retorna NULL se a fila estiver vazia
        return NULL;
    }
    // Recupera o primeiro exame da fila
    Exam *exame = fila->exams[0];
    // Desloca os exames para preencher a posição do exame removido
    for (int i = 1; i < fila->size; i++) {
        fila->exams[i - 1] = fila->exams[i];
    }
    // Decrementa o tamanho da fila
    fila->size--;
    // Retorna o exame removido
    return exame;
}

int isEmptyExamPriorityQueue(ExamPriorityQueue *fila) {
    // Retorna 1 se a fila estiver vazia, 0 caso contrário
    return fila->size == 0;
}

void gravarExameNoBancoDeDados(Exam *exame) {
    // Abre o arquivo db_exam.txt em modo de escrita anexada
    FILE *arquivo = fopen("db_exam.txt", "a");
    // Verifica se o arquivo foi aberto com sucesso
    if (arquivo) {
        // Escreve os dados do exame no arquivo
        fprintf(arquivo, "ID: %d, Condição IA: %d, Nome: %s, Timestamp: %d\n", exame->id, exame->conditionIA, exame->conditionName, exame->timestamp);
        // Fecha o arquivo
        fclose(arquivo);
    }
}

void gravarLaudoNoBancoDeDados(Exam *exame, int tempo) {
    // Abre o arquivo db_report.txt em modo de escrita anexada
    FILE *arquivo = fopen("db_report.txt", "a");
    // Verifica se o arquivo foi aberto com sucesso
    if (arquivo) {
        // Escreve os dados do laudo (incluindo o tempo de espera) no arquivo
        fprintf(arquivo, "ID: %d, Condição Final: %d, Nome: %s, Tempo de Espera: %d\n", exame->id, exame->conditionFinal, exame->conditionName, tempo - exame->timestamp);
        // Fecha o arquivo
        fclose(arquivo);
    }
}