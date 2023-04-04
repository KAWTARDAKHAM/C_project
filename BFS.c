#include <stdio.h>
#include <stdlib.h>

/*queu data structure at last assignement*/
struct queue{
    int*arr;
    int front; 
    int rear;
    int allocated;
};

void push(struct queue *A,int elem){
    if(A->rear+1 == A->allocated) {
        A->allocated *= 2;
    int *newarr=(int*)malloc(sizeof(int)*(A->allocated));
    for (int i = 0; i < A->rear+1; i++) {
            newarr[i] = A->arr[i];
    }
    free(A->arr);
    A->arr = newarr;
    }
    if(A->front==-1 &&A->rear==-1){
        A->front=A->rear=0;
        A->arr[A->rear]=elem;
    }
    else{
        A->rear++;
        A->arr[A->rear]=elem;
    }
    }
/*pop function*/
int pop(struct queue *A){
    int item; 
    if(A->front==-1 && A->rear==-1){
        printf("there is no element to be removed");
        item=-1;
    }
    else if(A->front==A->rear){
        item = A->arr[A->front];
        A->front=A->rear=-1;
    }
    else{
        item = A->arr[A->front];
        A->front++;
    }
    return item;
}
/*peak function*/
int peak(struct queue *A){
    if(A->front==-1 && A->rear==-1){
        printf("the queu is empty");
        return 0;
    }
    else{
        return  A->arr[A->front];
    }
}
int isEmpty(struct queue* A) {
  if (A->rear == -1)
    return 1;
  else
    return 0;
}


struct node {
  int vertex;
  struct node* next;
};


struct Graph {
  int numVertices;
  struct node** adjLists;
  int* visited;
};
/*creating the graph*/
struct Graph* createGraph(int vertices) {
  struct Graph* graph = malloc(sizeof(struct Graph));
  graph->numVertices = vertices;

  graph->adjLists = malloc(vertices * sizeof(struct node*));
  graph->visited = malloc(vertices * sizeof(int));

  int i;
  for (i = 0; i < vertices; i++) {
    graph->adjLists[i] = NULL;
    graph->visited[i] = 0;
  }
  return graph;
}

/*function related to the graph*/

void addEdge(struct Graph* graph, int src, int dest) {
    struct node* newNode = malloc(sizeof(struct node));
    newNode->vertex = dest;
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    newNode = malloc(sizeof(struct node));
    newNode->vertex = src;
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}


// BFS algorithm
void BFS(struct Graph* graph, int startVertex) {
    struct queue A;
    A.front = -1;
    A.rear=-1;
    A.allocated = 1;
    A.arr = (int*) malloc(sizeof(int) * A.allocated);
   graph->visited[startVertex] = 1;
   push(&A, startVertex);

   while (!isEmpty(&A)) {          
    int currentVertex = pop(&A);
    printf("Visited %d\n", currentVertex);

    struct node* temp = graph->adjLists[currentVertex];

    while (temp) {
      int adjVertex = temp->vertex;

      if (graph->visited[adjVertex] == 0) {
        graph->visited[adjVertex] = 1;
        push(&A, adjVertex);
      }
      temp = temp->next;
    }
  }
};

int main(int argc, char *argv[]) {
    int numNodes, numEdges;
    numNodes = atoi(argv[1]);
    numEdges = atoi(argv[2]);
    struct Graph* graph = createGraph(numNodes);
    for (int i = 0; i < numEdges; i++) {
        int src, dest;
        scanf("%d%d", &src, &dest);
        addEdge(graph, src, dest);
    }
    BFS(graph, 0);
    return 0;
}