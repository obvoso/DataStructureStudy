#ifndef SIMDEF_H
# define SIMDEF_H

#include <stdlib.h>

#define FALSE 0
#define TRUE 1

typedef enum SimStatusType
{
	arrival, start, end 
} SimStatus;

typedef struct SimCustomerType
{
	SimStatus status;
	int arrivalTime;
	int serviceTime;
	int startTime;
	int endTime;
 } SimCustomer;

typedef struct DequeNodeType
{
	struct SimCustomerType data;
	struct DequeNodeType* pRLink;
	struct DequeNodeType* pLLink;
} DequeNode;

typedef struct LinkedDequeType
{
	int currentElementCount;
	DequeNode* pFrontNode;
	DequeNode* pRearNode;
} LinkedDeque;


void insertCustomer(int arrivalTime, int serviceTime, LinkedDeque *pArrivalDeque);
void processArrival(int currentTime, LinkedDeque *pArrivalDeque, LinkedDeque *pWaitDeque);
DequeNode* processServiceNodeStart(int currentTime, LinkedDeque *pWaitDeque);
DequeNode* processServiceNodeEnd(int currentTime, DequeNode *pServiceNode, int *pServiceUserCount, int *pTotalWaitTime);
void printSimCustomer(int currentTime, SimCustomer customer);
void printWaitDequeStatus(int currentTime, LinkedDeque *pWaitDeque);
void printReport(LinkedDeque *pWaitDeque, int serviceUserCount, int totalWaitTime);

LinkedDeque* createLinkedDeque();
int insertFrontLD(LinkedDeque* pDeque, DequeNode element);
int insertRearLD(LinkedDeque* pDeque, DequeNode element);
DequeNode* deleteFrontLD(LinkedDeque* pDeque);
DequeNode* deleteRearLD(LinkedDeque* pDeque);
DequeNode* peekFrontLD(LinkedDeque* pDeque);
DequeNode* peekRearLD(LinkedDeque* pDeque);
void deleteLinkedDeque(LinkedDeque* pDeque);
int isLinkedDequeFull(LinkedDeque* pDeque);
int isLinkedDequeEmpty(LinkedDeque* pDeque);

#endif