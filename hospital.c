#include "hospital.h"
#include "patient_queue.h"
#include "xr_machine_manager.h"
#include "exam_priority_queue.h"
#include "diagnostico.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>  // Inclui a função sleep

// Estrutura que representa um hospital com filas de pacientes, gerenciador de máquinas de raio-X, fila de exames e contadores para estatísticas
struct Hospital {
    PatientQueue *filaPacientes;             // Fila de espera de pacientes
    XRMachineManager *gerenciadorMaquinas;   // Gerenciador de máquinas de raio-X
    ExamPriorityQueue *filaPrioridadeExames; // Fila de prioridade de exames
    int totalPacientes;                      // Contador de pacientes total
    int examesRealizados;                    // Contador de exames realizados
    int laudosEmitidos;                      // Contador de laudos emitidos
    int tempoUltimoLaudo;                    // Instante de tempo do último laudo emitido
    int intervaloRelatorio;                  // Intervalo de tempo para a impressão do relatório
};

// Cria e inicializa um novo hospital
Hospital *criarHospital() {
    Hospital *hospital = (Hospital *)malloc(sizeof(Hospital));
    hospital->filaPacientes = criarPatientQueue(); // Inicializa a fila de pacientes
    hospital->gerenciadorMaquinas = criarXRMachineManager(); // Inicializa o gerenciador de máquinas de raio-X
    hospital->filaPrioridadeExames = criarExamPriorityQueue(); // Inicializa a fila de exames
    hospital->totalPacientes = 0;
    hospital->examesRealizados = 0;
    hospital->laudosEmitidos = 0;
    hospital->tempoUltimoLaudo = -30;  // Configura o tempo do último laudo para antes do início da simulação
    hospital->intervaloRelatorio = 60; // Define o intervalo de tempo para os relatórios
    return hospital;
}

// Inicializa o hospital configurando a semente de geração aleatória
void inicializarHospital(Hospital *hospital) {
    srand(time(NULL)); // Semente para geração de números aleatórios
}

// Processa a chegada de um paciente com uma probabilidade de 20% a cada unidade de tempo
void processarChegadaPaciente(Hospital *hospital, int tempo) {
    if (rand() % 100 < 20) { // 20% de chance de um novo paciente chegar
        char nomePaciente[20];
        sprintf(nomePaciente, "Paciente%d", hospital->totalPacientes + 1); // Gera um nome de paciente
        Paciente *novoPaciente = criarPaciente(hospital->totalPacientes + 1, nomePaciente, tempo); // Cria um novo paciente
        enqueuePaciente(hospital->filaPacientes, novoPaciente); // Adiciona o paciente à fila
        hospital->totalPacientes++; // Incrementa o total de pacientes
    }
}

// Processa a realização de exames
void processarExames(Hospital *hospital, int tempo) {
    if (!estaVaziaXRMachineManager(hospital->gerenciadorMaquinas) && !estaVaziaPatientQueue(hospital->filaPacientes)) {
        Paciente *paciente = dequeuePaciente(hospital->filaPacientes); // Remove um paciente da fila
        Exam *exame = realizarExame(hospital->gerenciadorMaquinas, paciente, tempo); // Realiza o exame
        if (exame != NULL) {
            processarDiagnosticoIA(hospital, exame, tempo); // Processa o diagnóstico IA
            enqueueExam(hospital->filaPrioridadeExames, exame); // Adiciona o exame à fila de prioridade
            hospital->examesRealizados++; // Incrementa o total de exames realizados
        }
    }
}

// Processa a emissão de laudos para exames realizados
void processarLaudos(Hospital *hospital, int tempo) {
    if (!isEmptyExamPriorityQueue(hospital->filaPrioridadeExames) && (tempo - hospital->tempoUltimoLaudo) >= 30) {
        Exam *exame = dequeueExam(hospital->filaPrioridadeExames); // Remove o exame da fila de prioridade
        processarLaudo(hospital, exame, tempo); // Processa o laudo do exame
        hospital->laudosEmitidos++; // Incrementa o total de laudos emitidos
        hospital->tempoUltimoLaudo = tempo; // Atualiza o tempo do último laudo
        sleep(1); // Espera de 1 segundo para simular tempo de processamento
    }
}

// Imprime um relatório de estado atual da simulação
void imprimirRelatorio(Hospital *hospital, int tempo) {
    printf("Relatório de Simulação - Tempo: %d\n", tempo);
    printf("Total de Pacientes: %d\n", hospital->totalPacientes);
    printf("Pacientes na fila de exame: %d\n", tamanhoPatientQueue(hospital->filaPacientes));
    printf("Exames realizados: %d\n", hospital->examesRealizados);
    printf("Laudos emitidos: %d\n", hospital->laudosEmitidos);
}

// Imprime relatórios periódicos com base no tempo
void imprimirRelatorioPeriodico(Hospital *hospital, int tempo) {
    if (tempo % 20 == 0) { // Imprime o relatório a cada 20 unidades de tempo
        printf("\nRelatório Parcial de Simulação - Tempo: %d\n", tempo);
        printf("Total de Pacientes: %d\n", hospital->totalPacientes);
        printf("Pacientes na fila de exame: %d\n", tamanhoPatientQueue(hospital->filaPacientes));
        printf("Exames realizados: %d\n", hospital->examesRealizados);
        printf("Laudos emitidos: %d\n", hospital->laudosEmitidos);
    }
}

// Libera a memória utilizada pelo hospital e suas estruturas
void finalizarHospital(Hospital *hospital) {
    destruirPatientQueue(hospital->filaPacientes);
    destruirXRMachineManager(hospital->gerenciadorMaquinas);
    destruirExamPriorityQueue(hospital->filaPrioridadeExames);
    free(hospital);
}
