#include "hospital.h" // Inclui o arquivo de cabeçalho do hospital (hospital.h)

#define DURACAO_SIMULACAO 43200 // Define a duração da simulação em unidades de tempo (43200 unidades de tempo equivalem a 12 horas)

int main() {
    // Cria um novo hospital
    Hospital *hospital = criarHospital();
    // Inicializa o hospital (por exemplo, inicializa o gerador de números aleatórios)
    inicializarHospital(hospital);

    // Loop principal da simulação
    for (int tempo = 0; tempo < DURACAO_SIMULACAO; tempo++) {
        // Processa a chegada de pacientes no hospital
        processarChegadaPaciente(hospital, tempo);
        // Processa os exames no hospital
        processarExames(hospital, tempo);
        // Processa os laudos no hospital
        processarLaudos(hospital, tempo);
        // Imprime um relatório periódico da simulação
        imprimirRelatorioPeriodico(hospital, tempo); 
    }

    // Imprime um relatório final da simulação
    imprimirRelatorio(hospital, DURACAO_SIMULACAO);
    // Finaliza o hospital (libera a memória alocada)
    finalizarHospital(hospital);

    // Retorna 0 para indicar que a execução do programa foi bem-sucedida
    return 0;
}