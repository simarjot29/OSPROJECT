#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct process_data {
	int pid;
	int arrivalT;
	int burstT;
	int priority;

	int startT;
	int finishT;
	int remainingT;
	int responseT;
	int waitingT;
} process_struct;

int nProcess = 0;
process_struct *inpProcesses;

int main() {
	printf("\nEnter number of processes : ");
	scanf("%d", &nProcess);

	inpProcesses = (process_struct *)calloc(nProcess, sizeof(process_struct));
	for(int i=0; i<nProcess; i++) {
		printf("\n");
		printf("\nProcess %d PID : ", i);
		scanf("%d", &inpProcesses[i].pid);
		printf("\nProcess %d Arrival Time : ", i);
		scanf("%d", &inpProcesses[i].arrivalT);
		printf("\nProcess %d Burst Time : ", i);
		scanf("%d", &inpProcesses[i].burstT);
		inpProcesses[i].remainingT = inpProcesses[i].burstT;
	}
}