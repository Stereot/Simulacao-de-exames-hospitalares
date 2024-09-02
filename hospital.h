#ifndef HOSPITAL_H
#define HOSPITAL_H
#include "patient_queue.h" // Inclui a estrutura da fila de pacientes (patient_queue.h)
#include "xr_machine_manager.h" // Inclui a estrutura do gerenciador de máquinas de raio-x (xr_machine_manager.h)
#include "exam_priority_queue.h" // Inclui a estrutura da fila de prioridade de exames (exam_priority_queue.h)
typedef struct Hospital Hospital; // Define um tipo "Hospital" para a estrutura Hospital
// Declaração das funções relacionadas ao hospital
Hospital *criarHospital(); // Cria um novo hospital
void inicializarHospital(Hospital *hospital); // Inicializa um hospital já criado
void processarChegadaPaciente(Hospital *hospital, int tempo); // Processa a chegada de um paciente no hospital
void processarExames(Hospital *hospital, int tempo); // Processa os exames no hospital
void processarLaudos(Hospital *hospital, int tempo); // Processa os laudos no hospital
void imprimirRelatorio(Hospital *hospital, int tempo); // Imprime um relatório do hospital
void imprimirRelatorioPeriodico(Hospital *hospital, int tempo); // Imprime um relatório periódico do hospital
void finalizarHospital(Hospital *hospital); // Finaliza o hospital e libera a memória alocada
#endif