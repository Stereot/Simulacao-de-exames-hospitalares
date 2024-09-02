# Simulacao-de-exames-hospitalares - Trabalho de Estrutura de Dados em C

Aluno: Matheus Moroni Arçari Barcellos

Professor: Thiago Paixão

## Descrição do Projeto

Este projeto é uma simulação de um hospital que realiza exames de raio-X e diagnósticos utilizando algoritmos de Inteligência Artificial (IA). A simulação inclui a chegada de novos pacientes, a realização de exames, o processamento de diagnósticos e a emissão de laudos.

A cada unidade de tempo, há uma probabilidade de 20% de um novo paciente chegar ao hospital. Os pacientes são inseridos em uma fila e atendidos conforme a disponibilidade das máquinas de raio-X. O projeto é implementado em C, com uso de TADs para filas e gerenciamento de máquinas.

## Funcionalidades

- **Chegada de Pacientes**: Simula a chegada aleatória de novos pacientes ao hospital.
- **Fila de Pacientes**: Gerencia a fila de espera dos pacientes para exames.
- **Realização de Exames**: Realiza exames de raio-X utilizando máquinas disponíveis.
- **Diagnóstico via IA**: Processa o diagnóstico dos exames utilizando uma função de IA.
- **Emissão de Laudos**: Gera laudos finais após o processamento dos diagnósticos.
- **Relatórios de Simulação**: Imprime relatórios periódicos com o status da simulação.

## Estrutura do Projeto

- **main.c**: Função principal que inicia e controla a simulação.
- **hospital.c/h**: Gerencia a estrutura e as operações do hospital.
- **patient_queue.c/h**: Implementa a fila de pacientes.
- **xr_machine_manager.c/h**: Gerencia as máquinas de raio-X.
- **exam_priority_queue.c/h**: Implementa a fila de prioridade para exames.
- **diagnostico.c/h**: Processa os diagnósticos e laudos dos exames.

## Compilação e Execução

Para compilar o projeto, utilize o comando `make` e `./simulacao`:

```sh
make

./simulacao
