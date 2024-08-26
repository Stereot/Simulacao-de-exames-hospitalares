#include "hospital.h"
#include "patient_queue.h"
#include "xr_machine_manager.h"
#include "exam_priority_queue.h"
#include "diagnostico.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>  

struct Hospital {
    PatientQueue *filaPacientes;
    XRMachineManager *gerenciadorMaquinas;
    ExamPriorityQueue *filaPrioridadeExames;
    int totalPacientes;
    int examesRealizados;
    int laudosEmitidos;
    int tempoUltimoLaudo;
};

Hospital *criarHospital() {
    Hospital *hospital = (Hospital *)malloc(sizeof(Hospital));
    hospital->filaPacientes = criarPatientQueue();
    hospital->gerenciadorMaquinas = criarXRMachineManager();
    hospital->filaPrioridadeExames = criarExamPriorityQueue();
    hospital->totalPacientes = 0;
    hospital->examesRealizados = 0;
    hospital->laudosEmitidos = 0;
    hospital->tempoUltimoLaudo = -30;  /* garantir que o primeiro laudo possa ser processado imediatamente*/
    return hospital;
}

void inicializarHospital(Hospital *hospital) {
    srand(time(NULL));
}

void processarChegadaPaciente(Hospital *hospital, int tempo) {
    if (rand() % 100 < 20) {
        char nomePaciente[20];
        sprintf(nomePaciente, "Paciente%d", hospital->totalPacientes + 1);
        Paciente *novoPaciente = criarPaciente(hospital->totalPacientes + 1, nomePaciente, tempo);
        enqueuePaciente(hospital->filaPacientes, novoPaciente);
        hospital->totalPacientes++;
    }
}

void processarExames(Hospital *hospital, int tempo) {
    if (!estaVaziaXRMachineManager(hospital->gerenciadorMaquinas) && !estaVaziaPatientQueue(hospital->filaPacientes)) {
        Paciente *paciente = dequeuePaciente(hospital->filaPacientes);
        Exam *exame = realizarExame(hospital->gerenciadorMaquinas, paciente, tempo);
        if (exame != NULL) {
            processarDiagnosticoIA(hospital, exame, tempo);
            enqueueExam(hospital->filaPrioridadeExames, exame);
            hospital->examesRealizados++;
        }
    }
}

void processarLaudos(Hospital *hospital, int tempo) {
    if (!isEmptyExamPriorityQueue(hospital->filaPrioridadeExames) && (tempo - hospital->tempoUltimoLaudo) >= 30) {
        Exam *exame = dequeueExam(hospital->filaPrioridadeExames);
        processarLaudo(hospital, exame, tempo);
        hospital->laudosEmitidos++;
        hospital->tempoUltimoLaudo = tempo;  
        sleep(1);  
    }
}

void imprimirRelatorio(Hospital *hospital, int tempo) {
    printf("Relatório de Simulação - Tempo: %d\n", tempo);
    printf("Total de Pacientes: %d\n", hospital->totalPacientes);
    printf("Pacientes na fila de exame: %d\n", tamanhoPatientQueue(hospital->filaPacientes));
    printf("Exames realizados: %d\n", hospital->examesRealizados);
    printf("Laudos emitidos: %d\n", hospital->laudosEmitidos);
}

void finalizarHospital(Hospital *hospital) {
    destruirPatientQueue(hospital->filaPacientes);
    destruirXRMachineManager(hospital->gerenciadorMaquinas);
    destruirExamPriorityQueue(hospital->filaPrioridadeExames);
    free(hospital);
}
