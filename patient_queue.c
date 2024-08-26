#include "patient_queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct PatientQueue {
    Paciente *inicio;
    Paciente *fim;
    int tamanho;
};

PatientQueue *criarPatientQueue() {
    PatientQueue *fila = (PatientQueue *)malloc(sizeof(PatientQueue));
    fila->inicio = NULL;
    fila->fim = NULL;
    fila->tamanho = 0;
    return fila;
}

Paciente *criarPaciente(int id, const char *nome, int timestamp) {
    Paciente *paciente = (Paciente *)malloc(sizeof(Paciente));
    paciente->id = id;
    strcpy(paciente->nome, nome);
    paciente->timestamp = timestamp;
    paciente->proximo = NULL;
    return paciente;
}

void enqueuePaciente(PatientQueue *fila, Paciente *paciente) {
    if (fila->fim == NULL) {
        fila->inicio = paciente;
        fila->fim = paciente;
    } else {
        fila->fim->proximo = paciente;
        fila->fim = paciente;
    }
    fila->tamanho++;
    gravarPacienteNoBancoDeDados(paciente);
}

Paciente *dequeuePaciente(PatientQueue *fila) {
    if (fila->inicio == NULL) {
        return NULL;
    }
    Paciente *paciente = fila->inicio;
    fila->inicio = fila->inicio->proximo;
    if (fila->inicio == NULL) {
        fila->fim = NULL;
    }
    fila->tamanho--;
    return paciente;
}

int estaVaziaPatientQueue(PatientQueue *fila) {
    return fila->tamanho == 0;
}

int tamanhoPatientQueue(PatientQueue *fila) {
    return fila->tamanho;
}

void gravarPacienteNoBancoDeDados(Paciente *paciente) {
    FILE *arquivo = fopen("db_patient.txt", "a");
    if (arquivo != NULL) {
        fprintf(arquivo, "ID: %d, Nome: %s, Timestamp: %d\n", paciente->id, paciente->nome, paciente->timestamp);
        fclose(arquivo);
    }
}

void destruirPatientQueue(PatientQueue *fila) {
    Paciente *atual = fila->inicio;
    while (atual != NULL) {
        Paciente *temp = atual;
        atual = atual->proximo;
        free(temp);
    }
    free(fila);
}
