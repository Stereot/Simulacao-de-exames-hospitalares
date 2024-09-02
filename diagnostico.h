#ifndef DIAGNOSTICO_H // Verifica se a constante DIAGNOSTICO_H já foi definida
#define DIAGNOSTICO_H // Define a constante DIAGNOSTICO_H para evitar inclusões duplicadas do arquivo

#include "hospital.h" // Inclui a estrutura do hospital (hospital.h)
#include "exam_priority_queue.h" // Inclui a estrutura da fila de prioridade de exames (exam_priority_queue.h)

// Declaração das funções relacionadas ao diagnóstico
void processarDiagnosticoIA(Hospital *hospital, Exam *exame, int tempo); // Processa o diagnóstico inicial (IA) de um exame
void processarLaudo(Hospital *hospital, Exam *exame, int tempo); // Processa a emissão do laudo final para um exame

#endif // Fim da definição do cabeçalho DIAGNOSTICO_H