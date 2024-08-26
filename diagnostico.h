#ifndef DIAGNOSTICO_H
#define DIAGNOSTICO_H

#include "hospital.h"
#include "exam_priority_queue.h"

void processarDiagnosticoIA(Hospital *hospital, Exam *exame, int tempo);
void processarLaudo(Hospital *hospital, Exam *exame, int tempo);

#endif
