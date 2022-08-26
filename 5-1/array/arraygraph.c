#include "arraygraph.h"
#include <stdio.h>
#include <stdlib.h>

ArrayGraph* createArrayGraph(int maxVertexCount)
{
	ArrayGraph *pGraph;

	pGraph = (ArrayGraph *)malloc(sizeof(pGraph));
	if (!pGraph)
		exit(errno());
	pGraph->maxVertexCount = maxVertexCount;
	pGraph->currentVertexCount = 0;
	pGraph->graphType = GRAPH_UNDIRECTED;
	pGraph->ppAdjEdge = (int **)malloc(sizeof(int *) * (maxVertexCount - 1));
	if (!pGraph->ppAdjEdge)
		exit(errno());
	memset(pGraph->ppAdjEdge, NOT_USED, sizeof(pGraph->ppAdjEdge));
	pGraph->pVertex = (int *)malloc(sizeof(int) * (maxVertexCount - 1));
	if (pGraph->pVertex)
		exit(errno());
	memset(pGraph->pVertex, NOT_USED, sizeof(pGraph->pVertex));
	return (pGraph);
}

ArrayGraph* createArrayDirectedGraph(int maxVertexCount)
{
	ArrayGraph *pGraph;

	pGraph = (ArrayGraph *)malloc(sizeof(pGraph));
	if (!pGraph)
		exit(errno());
	pGraph->maxVertexCount = maxVertexCount;
	pGraph->currentVertexCount = 0;
	pGraph->graphType = GRAPH_DIRECTED;
	pGraph->ppAdjEdge = (int **)malloc(sizeof(int *) * (maxVertexCount - 1));
	if (!pGraph->ppAdjEdge)
		exit(errno());
	memset(pGraph->ppAdjEdge, NOT_USED, sizeof(pGraph->ppAdjEdge));
	pGraph->pVertex = (int *)malloc(sizeof(int) * (maxVertexCount - 1));
	if (pGraph->pVertex)
		exit(errno());
	memset(pGraph->pVertex, NOT_USED, sizeof(pGraph->pVertex));
	return (pGraph);
}

void deleteArrayGraph(ArrayGraph* pGraph)
{
	free(pGraph);
}

int isEmptyAG(ArrayGraph* pGraph)
{
	return (!pGraph->currentVertexCount);
}

int addVertexAG(ArrayGraph* pGraph, int vertexID)
{
	if (!pGraph)
		return (FALSE);
	if (vertexID < 0 || vertexID >= pGraph->maxVertexCount)
		return (FALSE);
	pGraph->pVertex[vertexID] = USED;
	pGraph->currentVertexCount++;
	return (SUCCESS);
}

int addEdgeAG(ArrayGraph* pGraph, int fromVertexID, int toVertexID)
{
	if (!pGraph)
		return (FALSE);
	if (fromVertexID < 0 || fromVertexID >= pGraph->maxVertexCount)
		return (FALSE);
	if (toVertexID < 0 || toVertexID >= pGraph->maxVertexCount)
		return (FALSE);
	
}
int addEdgewithWeightAG(ArrayGraph* pGraph, int fromVertexID, int toVertexID, int weight);

int checkVertexValid(ArrayGraph* pGraph, int vertexID);

int removeVertexAG(ArrayGraph* pGraph, int vertexID);

int removeEdgeAG(ArrayGraph* pGraph, int fromVertexID, int toVertexID);

void displayArrayGraph(ArrayGraph* pGraph);