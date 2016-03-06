#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//https://www.hackerrank.com/challenges/bfsshortreach

typedef struct SAdjNode SAdjNode;
typedef struct SAdjNode
{
	int vertex;
	SAdjNode *next;
}SAdjNode;

typedef struct SAdjList
{
	SAdjNode *head;
}SAdjList;

typedef struct SGraph{
	int V;
	SAdjList *array;
}SGraph;

typedef struct data
{
	int index;
}Sdata;
typedef struct SNode SNode;
typedef struct SNode
{
	int data;
	SNode *next;
}SNode;

typedef struct
{
	SNode *first;
	SNode *last;
}SQueue;

typedef struct SBFS
{
	bool *marked;
	int *dist;
}SBFS;

SGraph *createGraph(int V)
{
	SGraph *graph = calloc(1, sizeof(SGraph));

	graph->array = malloc(sizeof(SAdjList)*V);
	graph->V = V;

	for (int i = 0; i < V; i++)
	{
		graph->array[i].head = NULL;
	}

	return graph;
}

void destroyGraph(SGraph *graph)
{
	for (int i = 0; i < graph->V; i++)
	{
		if (graph->array[i].head != NULL)
		{
			SAdjNode *iterNode = graph->array[i].head;
			SAdjNode *iterNodeNext;
			while (iterNode != NULL)
			{
				iterNodeNext = iterNode->next;
				free(iterNode);
				iterNode = iterNodeNext;
			}
		}
	}
}

void addEdge(SGraph *graph, int source, int dest)
{
	if (source >= graph->V || dest >= graph->V)
		return;

	SAdjNode *nodeS = calloc(1, sizeof(SAdjNode));
	nodeS->next = graph->array[source].head;
	nodeS->vertex = dest;
	graph->array[source].head = nodeS;

	SAdjNode *nodeD = calloc(1, sizeof(SAdjNode));
	nodeD->next = graph->array[dest].head;
	nodeD->vertex = source;
	graph->array[dest].head = nodeD;

}

SAdjNode *getAdjListHead(SGraph *graph, int vertex)
{
	return graph->array[vertex].head;
}

bool isEmpty(SQueue *queue)
{
	return queue->first == NULL;
}
void Enqueue(SQueue *queue, int data)
{
	SNode* last = (SNode*)malloc(sizeof(SNode));
	SNode *oldlast = queue->last;

	last->data = data;
	last->next = NULL;

	if (isEmpty(queue))
	{
		queue->first = queue->last = last;
	}
	else
	{
		oldlast->next = last;
		queue->last = last;
	}


}

int Dequeue(SQueue *queue)
{
	int data = NULL;
	SNode *first = NULL;
	if (isEmpty(queue))
		return -1;

	first = queue->first;
	data = first->data;

	queue->first = first->next;
	if (isEmpty(queue))
		queue->last = NULL;

	return data;
}
//Queue version of DFS
void BFS(SBFS *dfs, SGraph *graph, int vertex)
{
	SQueue *queue = (SQueue*)calloc(1, sizeof(SQueue));
	int dequeData;
	SAdjNode *head;

	Enqueue(queue, vertex);

	while ((dequeData = Dequeue(queue)) != -1)
	{		
		//printf("Visiting Node %d\n", dequeData);

		SAdjNode *iterNode = head = getAdjListHead(graph, dequeData);

		while (iterNode != NULL)
		{
			if (!dfs->marked[iterNode->vertex])
			{
				dfs->marked[iterNode->vertex] = true;
				dfs->dist[iterNode->vertex] = dfs->dist[dequeData]+1;
				Enqueue(queue, iterNode->vertex);
			}

			iterNode = iterNode->next;
		}
	}


}
void main()
{
	
	SGraph *graph = createGraph(8);
	int i, T, N, M,j;
	int src, dest;
	int S;

	freopen("Input.txt", "r", stdin);

	scanf("%d", &T);

	for (i = 0; i < T; i++)
	{
		scanf("%d", &N);//Nodes
		scanf("%d", &M);//Edges

		SGraph *graph = createGraph(N);
		SBFS *dfs = calloc(1, sizeof(SBFS));
		dfs->marked = calloc(1, N * sizeof(bool));
		dfs->dist = calloc(1, N * sizeof(int));

		for (j = 0; j < M; j++)
		{
			scanf("%d", &src);
			scanf("%d", &dest);
			addEdge(graph, src-1, dest-1);
		}
		scanf("%d", &S);//Edges

		dfs->dist[S-1] = 0;

		BFS(dfs, graph, S-1);

		for (j = 0; j < N; j++)
		{
			if (j != S - 1)
			{
				if (dfs->marked[j])
					printf("%d ", dfs->dist[j] * 6);
				else
					printf("%d ", -1);
			}
		}
		printf("\n");
		destroyGraph(graph);
		free(dfs->marked);
		free(dfs->dist);
		free(dfs);
	}
}