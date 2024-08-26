#ifndef XR_MACHINE_MANAGER_H
#define XR_MACHINE_MANAGER_H

#include "patient_queue.h"
#include "exam_priority_queue.h" 

typedef struct XRMachineManager XRMachineManager;

XRMachineManager *criarXRMachineManager();
void destruirXRMachineManager(XRMachineManager *manager);
int estaVaziaXRMachineManager(XRMachineManager *manager);
Exam *realizarExame(XRMachineManager *manager, Paciente *paciente, int timestamp);

#endif
