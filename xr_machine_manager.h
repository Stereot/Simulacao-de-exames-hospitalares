#ifndef XR_MACHINE_MANAGER_H // Define um guarda de inclusão para evitar inclusões duplicadas do arquivo
#define XR_MACHINE_MANAGER_H // Define a constante XR_MACHINE_MANAGER_H para indicar que o arquivo já foi incluído

#include "patient_queue.h" // Inclui o arquivo de cabeçalho da fila de pacientes (patient_queue.h)
#include "exam_priority_queue.h" // Inclui o arquivo de cabeçalho da fila de prioridade de exames (exam_priority_queue.h)

// Estrutura que representa o gerenciador de máquinas de raio-X
typedef struct XRMachineManager XRMachineManager;

// Declaração das funções relacionadas ao gerenciador de máquinas de raio-X
XRMachineManager *criarXRMachineManager(); // Cria um novo gerenciador de máquinas de raio-X
void destruirXRMachineManager(XRMachineManager *manager); // Destrói o gerenciador de máquinas de raio-X
int estaVaziaXRMachineManager(XRMachineManager *manager); // Verifica se há máquinas de raio-X disponíveis
Exam *realizarExame(XRMachineManager *manager, Paciente *paciente, int timestamp); // Realiza um exame de raio-X

#endif // Fim da definição do cabeçalho XR_MACHINE_MANAGER_H