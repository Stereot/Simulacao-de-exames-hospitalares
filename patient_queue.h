#ifndef PATIENT_QUEUE_H
#define PATIENT_QUEUE_H

typedef struct Paciente {
    int id;
    char nome[100];
    int timestamp;
    struct Paciente *proximo;
} Paciente;

typedef struct PatientQueue PatientQueue;

PatientQueue *criarPatientQueue();
Paciente *criarPaciente(int id, const char *nome, int timestamp);
void enqueuePaciente(PatientQueue *fila, Paciente *paciente);
Paciente *dequeuePaciente(PatientQueue *fila);
int estaVaziaPatientQueue(PatientQueue *fila);
int tamanhoPatientQueue(PatientQueue *fila);
void gravarPacienteNoBancoDeDados(Paciente *paciente);
void destruirPatientQueue(PatientQueue *fila);

#endif
