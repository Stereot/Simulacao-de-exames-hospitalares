#include "xr_machine_manager.h"
#include <stdlib.h>

struct XRMachineManager {
    int maquinasDisponiveis;
};

XRMachineManager *criarXRMachineManager() {
    XRMachineManager *manager = (XRMachineManager *)malloc(sizeof(XRMachineManager));
    manager->maquinasDisponiveis = 5;
    return manager;
}

void destruirXRMachineManager(XRMachineManager *manager) {
    free(manager);
}

int estaVaziaXRMachineManager(XRMachineManager *manager) {
    return manager->maquinasDisponiveis == 0;
}

Exam *realizarExame(XRMachineManager *manager, Paciente *paciente, int timestamp) {
    if (manager->maquinasDisponiveis > 0) {
        manager->maquinasDisponiveis--;
        Exam *exame = criarExam(paciente, timestamp); 
        manager->maquinasDisponiveis++;
        return exame;
    }
    return NULL;
}
