#ifndef PATIENT_QUEUE_H // Define um guarda de inclusão para evitar inclusões duplicadas do arquivo
#define PATIENT_QUEUE_H // Define a constante PATIENT_QUEUE_H para indicar que o arquivo já foi incluído

// Estrutura que representa um paciente
typedef struct Paciente {
    int id; // ID do paciente
    char nome[100]; // Nome do paciente
    int timestamp; // Carimbo de tempo da chegada do paciente
    struct Paciente *proximo; // Ponteiro para o próximo paciente na fila
} Paciente;

// Estrutura que representa uma fila de pacientes
typedef struct PatientQueue PatientQueue;

// Declaração das funções relacionadas à fila de pacientes
PatientQueue *criarPatientQueue(); // Cria uma nova fila de pacientes
Paciente *criarPaciente(int id, const char *nome, int timestamp); // Cria um novo paciente
void enqueuePaciente(PatientQueue *fila, Paciente *paciente); // Adiciona um paciente à fila
Paciente *dequeuePaciente(PatientQueue *fila); // Remove um paciente da fila
int estaVaziaPatientQueue(PatientQueue *fila); // Verifica se a fila está vazia
int tamanhoPatientQueue(PatientQueue *fila); // Retorna o tamanho da fila
void gravarPacienteNoBancoDeDados(Paciente *paciente); // Salva um paciente no banco de dados
void destruirPatientQueue(PatientQueue *fila); // Destrói uma fila de pacientes

#endif // Fim da definição do cabeçalho PATIENT_QUEUE_H