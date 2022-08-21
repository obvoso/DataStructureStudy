#ifndef _HEAP_
#define _HEAP_

typedef struct heapNodeType
{
	int data;
} heapNode;

typedef struct heapType
{
	int maxElementCount;	
	int currentElementCount;
	heapNode *pElement;
} heap;

heap* createheap(int maxElementCount);
void deleteheap(heap* pList);
int isheapFull(heap* pList);
int addALElement(heap* pList, int position, heapNode element);
int minLeftAddALElement(heap* pList, int position, heapNode element);
int minRightAddALElement(heap* pList, int position, heapNode element);
int maxLeftAddALElement(heap* pList, int position, heapNode element);
int maxRightAddALElement(heap* pList, int position, heapNode element);
int	removeALElement(heap* pList);
void	maxRemoveHeapElement(heap *pList, int parent, int child);
void	minRemoveHeapElement(heap *pList, int parent, int child);
heapNode* getALElement(heap* pList, int position);
void displayheap(heap* pList);
void clearheap(heap* pList);
int getheapLength(heap* pList);

#endif

#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE		1
#define FALSE		0

#endif