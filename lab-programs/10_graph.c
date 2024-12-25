#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX 20

int adjMatrix[MAX][MAX];
bool visited[MAX];

struct Queue {
	int items[MAX];
	int front;
	int rear;
};

struct Queue *createQueue() {
	struct Queue *q = (struct Queue *) malloc(sizeof(struct Queue));
	q->front = -1;
	q->rear = -1;
	return q;
}

bool isEmpty(struct Queue *q) {
	return q->rear == -1;
}

void enqueue(struct Queue *q, int value) {
	if (q->rear == MAX - 1) {
		printf("Queue is full!\n");
	} 
	else{
		if (q->front == -1)
			q->front = 0;
		q->rear++;
		q->items[q->rear] = value;
	}
}

int dequeue(struct Queue* q) {
	int item;
	if (isEmpty(q)) {
		printf("Queue is empty!\n");
		return -1;
	} 
	else {
		item = q->items[q->front];
		q->front++;
		if (q->front > q->rear) {
			q->front = q->rear = -1;
		}
		return item;
	}
}

void bfs(int startVertex, int numVertices) {
	struct Queue  *q = createQueue();

	printf("BFS Traversal: ");
	visited[startVertex] = true;
	enqueue(q, startVertex);

	while (!isEmpty(q)) {
		int currentVertex = dequeue(q);
		printf("%d ", currentVertex);

		for (int i = 0; i < numVertices; i++) {
			if (adjMatrix[currentVertex][i] == 1 && !visited[i]) {
				visited[i] = true;
				enqueue(q, i);
			}
		}
	}
	printf("\n");
}

void dfs(int vertex, int numVertices) {
	printf("%d ", vertex);
	visited[vertex] = true;

	for (int i = 0; i < numVertices; i++) {
		if (adjMatrix[vertex][i] == 1 && !visited[i]) {
			dfs(i, numVertices);
		}
	}
}

int main() {
	int numVertices, numEdges, src, dest, startVertex;

	printf("Enter the number of vertices: ");
	scanf("%d", &numVertices);

	memset(adjMatrix, 0x00, sizeof(adjMatrix));
	memset(visited, 0x00, sizeof(visited));

	printf("Enter the number of edges: ");
	scanf("%d", &numEdges);

	printf("Enter the edges (source and destination):\n");
	for (int i = 0; i < numEdges; i++) {
		scanf("%d %d", &src, &dest);
		adjMatrix[src][dest] = 1;
		adjMatrix[dest][src] = 1; 
	}

	printf("Enter the starting vertex for traversal: ");
	scanf("%d", &startVertex);

	bfs(startVertex, numVertices);

	memset(visited, 0x00, sizeof(visited));
	
	printf("DFS Traversal: ");
	dfs(startVertex, numVertices);
	printf("\n");

	return 0;
}

