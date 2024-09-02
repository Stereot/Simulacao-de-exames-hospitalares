#include "patient_queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura que representa uma fila de pacientes
struct PatientQueue {
    Paciente *inicio;  // Ponteiro para o primeiro paciente na fila
    Paciente *fim;     // Ponteiro para o último paciente na fila
    int tamanho;       // Número de pacientes na fila
};

// Cria e inicializa uma nova fila de pacientes
PatientQueue *criarPatientQueue() {
    PatientQueue *fila = (PatientQueue *)malloc(sizeof(PatientQueue));
    fila->inicio = NULL; // Inicialmente, a fila está vazia
    fila->fim = NULL;    // Portanto, não há um paciente no fim
    fila->tamanho = 0;   // O tamanho da fila é zero
    return fila;
}

// Cria e inicializa um novo paciente com ID, nome e timestamp
Paciente *criarPaciente(int id, const char *nome, int timestamp) {
    Paciente *paciente = (Paciente *)malloc(sizeof(Paciente));
    paciente->id = id; // Atribui o ID ao paciente
    strcpy(paciente->nome, nome); // Copia o nome para a estrutura
    paciente->timestamp = timestamp; // Atribui o timestamp de chegada
    paciente->proximo = NULL; // Inicialmente, o paciente não aponta para outro
    return paciente;
}

// Adiciona um paciente ao final da fila
void enqueuePaciente(PatientQueue *fila, Paciente *paciente) {
    if (fila->fim == NULL) { // Se a fila estiver vazia
        fila->inicio = paciente; // O paciente é o primeiro
        fila->fim = paciente;    // E também o último
    } else { // Caso contrário
        fila->fim->proximo = paciente; // O último paciente aponta para o novo
        fila->fim = paciente;          // O novo paciente é o último da fila
    }
    fila->tamanho++; // Incrementa o tamanho da fila
    gravarPacienteNoBancoDeDados(paciente); // Grava o paciente no "banco de dados"
}

// Remove e retorna o paciente do início da fila
Paciente *dequeuePaciente(PatientQueue *fila) {
    if (fila->inicio == NULL) { // Se a fila estiver vazia
        return NULL; // Retorna NULL
    }
    Paciente *paciente = fila->inicio; // Armazena o paciente do início da fila
    fila->inicio = fila->inicio->proximo; // O início passa a ser o próximo paciente
    if (fila->inicio == NULL) { // Se a fila ficou vazia após a remoção
        fila->fim = NULL; // Não há mais um paciente no fim
    }
    fila->tamanho--; // Decrementa o tamanho da fila
    return paciente; // Retorna o paciente removido
}

// Verifica se a fila de pacientes está vazia
int estaVaziaPatientQueue(PatientQueue *fila) {
    return fila->tamanho == 0; // Retorna 1 (verdadeiro) se estiver vazia, 0 caso contrário
}

// Retorna o tamanho da fila de pacientes
int tamanhoPatientQueue(PatientQueue *fila) {
    return fila->tamanho; // Retorna o número de pacientes na fila
}

// Grava os dados do paciente em um arquivo de "banco de dados"
void gravarPacienteNoBancoDeDados(Paciente *paciente) {
    FILE *arquivo = fopen("db_patient.txt", "a"); // Abre o arquivo para adicionar
    if (arquivo != NULL) { // Se o arquivo foi aberto com sucesso
        fprintf(arquivo, "ID: %d, Nome: %s, Timestamp: %d\n", paciente->id, paciente->nome, paciente->timestamp); // Grava os dados do paciente
        fclose(arquivo); // Fecha o arquivo
    }
}

// Libera a memória alocada para a fila de pacientes
void destruirPatientQueue(PatientQueue *fila) {
    Paciente *atual = fila->inicio; // Começa pelo primeiro paciente
    while (atual != NULL) { // Enquanto houver pacientes na fila
        Paciente *temp = atual; // Armazena o paciente atual
        atual = atual->proximo; // Move para o próximo paciente
        free(temp); // Libera a memória do paciente atual
    }
    free(fila); // Libera a memória da estrutura da fila
}
