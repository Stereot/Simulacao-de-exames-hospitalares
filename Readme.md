Simulação de Hospital - Trabalho de Estrutura de Dados em C
Aluno: Matheus Moroni Arçari Barcellos
Professor: Thiago Paixão

Descrição do Projeto
Este projeto simula o processo de gestão de um hospital, com ênfase na realização de exames de raio-X de tórax e na organização da fila para laudo médico. A simulação abrange a chegada de pacientes, a realização dos exames e o processamento dos laudos. O projeto implementa diversos Tipos Abstratos de Dados (TADs), como Paciente (Patient) e Exame (Exam), que modelam o fluxo de trabalho do hospital.

Estrutura do Projeto
O projeto está organizado nos seguintes arquivos:

hospital.h: Contém as definições das estruturas e funções para manipulação dos TADs, além de gerenciar a lógica principal da simulação.
hospital.c: Implementa as funções definidas no arquivo hospital.h.
main.c: Função principal que executa a simulação completa, gerenciando o fluxo de pacientes e exames.
patient_queue.h/patient_queue.c: Implementa a fila de pacientes que aguardam para realizar exames.
xr_machine_manager.h/xr_machine_manager.c: Gerencia as máquinas de raio-X e a realização dos exames.
exam_priority_queue.h/exam_priority_queue.c: Implementa a fila de prioridade de exames aguardando laudos.
diagnostico.h/diagnostico.c: Responsável pelo processamento dos diagnósticos e pela geração dos laudos.
Makefile: Arquivo para compilar o projeto utilizando o comando make.
db_exam.txt: Armazena os registros dos exames realizados.
db_report.txt: Armazena os laudos emitidos.
Tipos Abstratos de Dados (TADs)
Paciente (Patient)
O TAD Patient representa um paciente no sistema:

Atributos:

Identificação única do paciente (int id)
Nome do paciente (char* name)
Instante de chegada (int timestamp)
Funções Associadas:

Patient* criarPaciente(int id, const char *name, int timestamp): Cria e inicializa um novo paciente.
void destruirPaciente(Patient *patient): Libera a memória alocada para um paciente.
int getPatientId(Patient* patient): Retorna a identificação do paciente.
const char* getPatientName(Patient* patient): Retorna o nome do paciente.
int getPatientTimestamp(Patient* patient): Retorna o instante de chegada do paciente.
Exame (Exam)
O TAD Exam representa um exame realizado por um paciente:

Atributos:

Identificação única do exame (int id)
Diagnóstico preliminar gerado por IA (int conditionIA)
Diagnóstico final (int conditionFinal)
Instante de realização do exame (int timestamp)
Funções Associadas:

Exam* criarExam(Paciente *paciente, int timestamp): Cria e inicializa um novo exame para um paciente.
void destruirExam(Exam *exam): Libera a memória alocada para um exame.
int getExamId(Exam *exam): Retorna a identificação do exame.
int getExamConditionIA(Exam *exam): Retorna o diagnóstico preliminar gerado por IA.
int getExamConditionFinal(Exam *exam): Retorna o diagnóstico final.
int getExamTimestamp(Exam *exam): Retorna o instante de realização do exame.
Compilação e Execução
Para compilar e executar o projeto, siga os passos abaixo:

Clone o repositório ou faça o download dos arquivos necessários.

Abra um terminal e navegue até o diretório onde os arquivos foram salvos.

Execute o comando make para compilar o projeto.
Execute o comando ./simulacao para rodar o programa.