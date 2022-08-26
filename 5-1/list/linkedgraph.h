#ifndef _GRAPH_ADJLIST_
#define _GRAPH_ADJLIST_

typedef struct LinkedGraphType
{
	int maxVertexCount;		// 최최대  노노드드의  개개수수
	int currentVertexCount;	// 현재 사사용용되되는 노노드드의  개개수수
	int currentEdgeCount;	// 현재 간간선선의  개개수수
	int graphType;			// 그래프 종종류류: 1-Undirected, 2-Directed
	LinkedList** ppAdjEdge;	// 간선 저저장장을  위위한  연결리스트(포인터)의  배배열열
	int *pVertex;			// 노드 저저장장을  위위한  1차원 배배열열
} LinkedGraph;

// 그래프 생생성성
LinkedGraph* createLinkedGraph(int maxVertexCount);
LinkedGraph* createLinkedDirectedGraph(int maxVertexCount);

// 삭제
void deleteLinkedGraph(LinkedGraph* pGraph);

// ���� �׷��� ���� �Ǵ�
int isEmptyLG(LinkedGraph* pGraph);

// 노드 추가
int addVertexLG(LinkedGraph* pGraph, int vertexID);

// 간선 추추가가
int addEdgeLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID);
int addEdgewithWeightLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID, int weight);

// 노드의 유유효효성  점점검검
int checkVertexValid(LinkedGraph* pGraph, int vertexID);

// 노드 제거
int removeVertexLG(LinkedGraph* pGraph, int vertexID);

// �간선 제거
int removeEdgeLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID);
void deleteGraphNode(LinkedList* pList, int delVertexID);
int findGraphNodePosition(LinkedList* pList, int vertexID);

// 간선 개개수  반반환환
int getEdgeCountLG(LinkedGraph* pGraph);

// 노드 개개수  반반환환
int getVertexCountLG(LinkedGraph* pGraph);

// 최대 노노드  개개수  반반환
int getMaxVertexCountLG(LinkedGraph* pGraph);

//그그래래프  종종류  반반환환
int getGraphTypeLG(LinkedGraph* pGraph);

// 그래프 정정보  출출력력
void displayLinkedGraph(LinkedGraph* pGraph);
#endif

#ifndef _COMMON_GRAPH_DEF_
#define _COMMON_GRAPH_DEF_

#define TRUE				1
#define FALSE				0

#define USED				1
#define NOT_USED			0

#define SUCCESS				1
#define FAIL				0

#define GRAPH_UNDIRECTED	1
#define GRAPH_DIRECTED		2

#endif