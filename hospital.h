#ifndef HOSPITAL_H
#define HOSPITAL_H

#include "patient_queue.h"
#include "xr_machine_manager.h"
#include "exam_priority_queue.h"

typedef struct Hospital Hospital;

Hospital *criarHospital();
void inicializarHospital(Hospital *hospital);
void processarChegadaPaciente(Hospital *hospital, int tempo);
void processarExames(Hospital *hospital, int tempo);
void processarLaudos(Hospital *hospital, int tempo);
void imprimirRelatorio(Hospital *hospital, int tempo);
void finalizarHospital(Hospital *hospital);

#endif
