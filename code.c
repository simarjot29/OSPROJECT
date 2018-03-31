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
int totalExecTime = 0;

/* Fixed Priority Queue */
typedef struct node {
	process_struct* process;
	struct node* next;
} NODE;


void pq_push(NODE** root, process_struct* processPointer) {
	NODE* temp = (NODE *)malloc(sizeof(NODE));
	temp->process = processPointer;
	temp->next = NULL;

	// if root is null
	if(*root == NULL) {
		*root = temp;
	} else if((*root)->process->priority == processPointer->priority) { 
		// if the new node has same priority
		temp->next = (*root)->next;
		(*root)->next = temp;
	} else if((*root)->process->priority < processPointer->priority) { 
		// if the new node has high priority
		temp->next = *root;
		*root = temp;
	} else {
		// find a place to fit the node
		NODE* head = *root;
		while(head->next != NULL && head->next->process->priority > processPointer->priority)
			head = head->next;

		temp->next = head->next;
		head->next = temp;
	}
}


bool pq_isEmpty(NODE** root) {
	return ((*root) == NULL);
}


process_struct* pq_top(NODE** root) {
	if((*root) == NULL) {
		printf("\ntop on empty priority queue!\n");
		exit(-1);
	}
	return (*root)->process;
}


process_struct* pq_pop(NODE** root) {
	if((*root) == NULL) {
		printf("\npop on empty priority queue!\n");
		exit(-1);
	}
	NODE* temp = *root;
	*root = (*root)->next;
	process_struct* retProcess = temp->process;
	free(temp);
	return retProcess;
}

void pq_shift_priority(NODE** root, int value) {
	NODE *temp = *root;
	while(temp != NULL) {
		temp->process->priority += value;
		temp = temp->next;
	}
}

// Functions
int processSort(const void* a, const void* b) {
	process_struct *p1 = (process_struct *)a;
	process_struct *p2 = (process_struct *)b;

	if(p1->arrivalT > p2->arrivalT)
		return true;
	else if(p1->arrivalT < p2->arrivalT)
		return false;

	// if both have same priority
	if(p1->pid > p2->pid)
		return true;
	else
		return false;
}

// get total execution time
void calcTotalExecTime() {
	totalExecTime = inpProcesses[0].arrivalT;
	for(int i=0; i<nProcess; i++) {
		if(totalExecTime >= inpProcesses[i].arrivalT)
			totalExecTime += inpProcesses[i].burstT;
		else
			totalExecTime += (inpProcesses[i].arrivalT - totalExecTime) + inpProcesses[i].burstT;
	}
}

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
	qsort(inpProcesses, nProcess, sizeof(process_struct), processSort);
	calcTotalExecTime();	
}