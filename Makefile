CC = gcc
CFLAGS = -Wall -g

all: simulacao

simulacao: main.o hospital.o patient_queue.o xr_machine_manager.o exam_priority_queue.o diagnostico.o
	$(CC) $(CFLAGS) -o simulacao main.o hospital.o patient_queue.o xr_machine_manager.o exam_priority_queue.o diagnostico.o

main.o: main.c hospital.h
	$(CC) $(CFLAGS) -c main.c

hospital.o: hospital.c hospital.h patient_queue.h xr_machine_manager.h exam_priority_queue.h diagnostico.h
	$(CC) $(CFLAGS) -c hospital.c

patient_queue.o: patient_queue.c patient_queue.h
	$(CC) $(CFLAGS) -c patient_queue.c

xr_machine_manager.o: xr_machine_manager.c xr_machine_manager.h patient_queue.h
	$(CC) $(CFLAGS) -c xr_machine_manager.c

exam_priority_queue.o: exam_priority_queue.c exam_priority_queue.h patient_queue.h
	$(CC) $(CFLAGS) -c exam_priority_queue.c

diagnostico.o: diagnostico.c diagnostico.h hospital.h exam_priority_queue.h
	$(CC) $(CFLAGS) -c diagnostico.c

clean:
	rm -f *.o simulacao
