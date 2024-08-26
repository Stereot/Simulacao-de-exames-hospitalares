#include "hospital.h"

#define DURACAO_SIMULACAO 43200

int main() {
    Hospital *hospital = criarHospital();
    inicializarHospital(hospital);

    for (int tempo = 0; tempo < DURACAO_SIMULACAO; tempo++) {
        processarChegadaPaciente(hospital, tempo);
        processarExames(hospital, tempo);
        processarLaudos(hospital, tempo);
    }

    imprimirRelatorio(hospital, DURACAO_SIMULACAO);
    finalizarHospital(hospital);

    return 0;
}
