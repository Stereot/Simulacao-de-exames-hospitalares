#include "xr_machine_manager.h" // Inclui o arquivo de cabeçalho do gerenciador de máquinas de raio-X (xr_machine_manager.h)
#include <stdlib.h> // Inclui funções da biblioteca padrão para alocação de memória (malloc, free, etc.)

// Estrutura que representa o gerenciador de máquinas de raio-X
struct XRMachineManager {
    int maquinasDisponiveis; // Número de máquinas de raio-X disponíveis
};

// Cria um novo gerenciador de máquinas de raio-X
XRMachineManager *criarXRMachineManager() {
    // Alocação de memória para o gerenciador
    XRMachineManager *manager = (XRMachineManager *)malloc(sizeof(XRMachineManager));
    // Inicializa o número de máquinas disponíveis como 5
    manager->maquinasDisponiveis = 5;
    // Retorna o ponteiro para o gerenciador criado
    return manager;
}

// Destrói o gerenciador de máquinas de raio-X
void destruirXRMachineManager(XRMachineManager *manager) {
    // Libera a memória alocada para o gerenciador
    free(manager);
}

// Verifica se há máquinas de raio-X disponíveis
int estaVaziaXRMachineManager(XRMachineManager *manager) {
    // Retorna 1 se não houver máquinas disponíveis, 0 caso contrário
    return manager->maquinasDisponiveis == 0;
}

// Realiza um exame de raio-X
Exam *realizarExame(XRMachineManager *manager, Paciente *paciente, int timestamp) {
    // Verifica se há máquinas disponíveis
    if (manager->maquinasDisponiveis > 0) {
        // Decrementa o número de máquinas disponíveis
        manager->maquinasDisponiveis--;
        // Cria um novo exame para o paciente
        Exam *exame = criarExam(paciente, timestamp); 
        // Incrementa o número de máquinas disponíveis (a máquina é liberada após o exame)
        manager->maquinasDisponiveis++;
        // Retorna o exame criado
        return exame;
    }
    // Retorna NULL se não houver máquinas disponíveis
    return NULL;
}