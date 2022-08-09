#include <stdio.h>
#include "simdef.h"

void processArrival(int currentTime, LinkedDeque *pArrivalDeque, LinkedDeque *pWaitDeque)
{
	(void)	currentTime;
	DequeNode *pWaitNode;

	pWaitNode = deleteFrontLD(pArrivalDeque);
	insertRearLD(pWaitDeque, *pWaitNode);
	free(pWaitNode);
}

DequeNode* processServiceNodeStart(int currentTime, LinkedDeque *pWaitDeque)
{
	DequeNode *pServiceNode;

	pServiceNode = deleteFrontLD(pWaitDeque);
	pServiceNode->data.startTime = currentTime;
	pServiceNode->data.endTime = pServiceNode->data.arrivalTime + pServiceNode->data.serviceTime;
	// printf(" %d %d\n", pServiceNode->data.arrivalTime, pServiceNode->data.serviceTime);
	// printf("endtime : %d\n", pServiceNode->data.endTime);
	pServiceNode->data.status = start;
	return (pServiceNode);
}

DequeNode* processServiceNodeEnd(int currentTime, DequeNode *pServiceNode, int *pServiceUserCount, int *pTotalWaitTime)
{
	*pTotalWaitTime += pServiceNode->data.startTime + pServiceNode->data.serviceTime - currentTime;
	*pServiceUserCount += 1;
	return (NULL);
}

void printSimCustomer(int currentTime, SimCustomer customer)
{
	printf("\n===========\ncurrentTime : %d\n", currentTime);
	printf("arrivalTime : %d\nserviceTime : %d\nstartTime : %d\nendTime : %d\n===========\n", customer.arrivalTime, customer.serviceTime, customer.startTime, customer.endTime);
}

void printWaitDequeStatus(int currentTime, LinkedDeque *pWaitDeque)
{
	DequeNode *now;

	now = pWaitDeque->pFrontNode;
	while (now)
	{
		printSimCustomer(currentTime, now->data);
		now = now->pRLink;
	}
	printf("end\n");
}

void printReport(LinkedDeque *pWaitDeque, int serviceUserCount, int totalWaitTime)
{
	(void)	pWaitDeque;
	printf("오늘 하루 손님^^ %d분\n", serviceUserCount);
	printf("대기 손님이 %d시간이나 기다리셨다 ㅜ.ㅜ 다음엔 더 빨리 해야지!!\n", totalWaitTime);
}

void insertCustomer(int arrivalTime, int serviceTime, LinkedDeque *pArrivalDeque)
{
	DequeNode *element;

	element = malloc(sizeof(DequeNode));
	element->data.status = arrival;
	element->data.arrivalTime = arrivalTime;
	element->data.serviceTime = serviceTime;
	element->data.startTime = -1;
	element->data.endTime = -1;
	insertRearLD(pArrivalDeque, *element);
	free(element);
}

void	initArrival(LinkedDeque *pArrivalDeque)
{
	insertCustomer(0, 3, pArrivalDeque);
	insertCustomer(2, 3, pArrivalDeque);
	insertCustomer(4, 2, pArrivalDeque);
	insertCustomer(6, 1, pArrivalDeque);
	insertCustomer(8, 2, pArrivalDeque);
}
int	main()
{
	LinkedDeque *pWaitDeque;
	LinkedDeque *pArrivalDeque;
	LinkedDeque	*pEndDeque;
	DequeNode *pServiceNode;
	int	pServiceUserCount = 0;
	int	pTotalWaitTime = 0;
	int	t = 0;

	pServiceNode = NULL;
	pWaitDeque = createLinkedDeque();
	if (!pWaitDeque)
		return (-1);
	pArrivalDeque = createLinkedDeque();
	if (!pArrivalDeque)
		return (-1);
	pEndDeque = createLinkedDeque();
	if (!pEndDeque)
		return (-1);
	initArrival(pArrivalDeque);
	while (t <= 10 && pServiceUserCount <= 5)
	{
		if (!isLinkedDequeEmpty(pArrivalDeque) && \
			pArrivalDeque->pFrontNode->data.arrivalTime == t)
			processArrival(t, pArrivalDeque, pWaitDeque);
		if (pServiceNode && pServiceNode->data.endTime == t)
		{
		//printWaitDequeStatus(t, pWaitDeque);
			pServiceNode->data.status = end;
			insertRearLD(pEndDeque, *pServiceNode);
			processServiceNodeEnd(t, pServiceNode, &pServiceUserCount, &pTotalWaitTime);
			free(pServiceNode);
			pServiceNode = NULL;
		}
		if (!pServiceNode && !isLinkedDequeEmpty(pWaitDeque))
			pServiceNode = processServiceNodeStart(t, pWaitDeque);
		++t;
	}
	printReport(pWaitDeque, pServiceUserCount, pTotalWaitTime);
	deleteLinkedDeque(pWaitDeque);
	deleteLinkedDeque(pArrivalDeque);
}