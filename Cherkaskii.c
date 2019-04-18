#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 5
int V = 4;
int G[4][4] = {{0,1,1,1},{1,0,1,0},{1,1,0,1},{1,0,1,0}};
int ROW = 4;
int COL = 4;
int E = 4;

struct AdjListNode
{
    int dest;
    struct AdjListNode* next;
};

// A structure to represent an adjacency list
struct AdjList
{
    struct AdjListNode *head;  // pointer to head node of list
};

// A structure to represent a graph. A graph is an array of adjacency lists.
// Size of array will be V (number of vertices in graph)
struct Graph
{
    int V;
    struct AdjList* array;
};

// A utility function to create a new adjacency list node
struct AdjListNode* newAdjListNode(int dest)
{
    struct AdjListNode* newNode =
            (struct AdjListNode*) malloc(sizeof(struct AdjListNode));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}
void addEdge(struct Graph* graph, int src, int dest)
{
    // Add an edge from src to dest.  A new node is added to the adjacency
    // list of src.  The node is added at the begining
    struct AdjListNode* newNode = newAdjListNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    // Since graph is undirected, add an edge from dest to src also
    newNode = newAdjListNode(src);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}
// A utility function that creates a graph of V vertices
struct Graph* createGraph(int V)
{
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->V = V;
    // Create an array of adjacency lists.  Size of array will be V
    graph->array = (struct AdjList*) malloc(V * sizeof(struct AdjList));

     // Initialize each adjacency list as empty by making head as NULL
    int i,j;
    for (i = 0; i < V; ++i)
        graph->array[i].head = NULL;
    for(i=1;i<V;i++){
        for(j=0;j<i;j++){
            if(G[i][j] == 1)
        addEdge(graph, i, j);
        }


    }
    return graph;
}
void printGraph(struct Graph* graph)
{
    int v;
     printf("\n Adjacency list ::\n");
    for (v = 0; v < graph->V; ++v)
    {
        struct AdjListNode* pCrawl = graph->array[v].head;
            printf("%d",v);
        while (pCrawl)
        {
            printf("-> %d", pCrawl->dest);
            pCrawl = pCrawl->next;
        }
        printf("\n");
    }
}
struct EdgeList{
    int startVertex;
    int endVertex;
    int edgeNumber;
    int vertexNumber;
    struct EdgeList* next;
}*IN = NULL,*OUT = NULL;
struct EdgeList* newEdge(int src, int dest, int count , int vertexNumber)
{
    struct EdgeList* newE = (struct EdgeList*) malloc(sizeof(struct EdgeList));
    newE->startVertex = src;
    newE->endVertex = dest;
    newE->edgeNumber = count;
    newE->vertexNumber = vertexNumber;
    newE->next = NULL;
    return newE;
}
struct EdgeList* createEdgelist(struct Graph* graph){
    int i,j,c = 1;
    struct EdgeList* E = (struct EdgeList*) malloc(sizeof(struct EdgeList));
    struct EdgeList* temp;
    for(i=0;i<graph->V;i++){
        for(j=0;j<graph->V;j++){
            if(G[i][j]!=0 ){
                if(c==1){
                    E->startVertex = i;
                    E->endVertex = j;
                    E->edgeNumber = c;
                    E->vertexNumber = i;
                    E->next = NULL;
                    temp = E;
                }
                else{
                    temp->next = newEdge(i,j,c,i);
                    temp = temp->next;
                }
                c++;
            }
        }
    }
    return E;
}

void printEdgelist(struct EdgeList* edge)
{
    struct EdgeList* pCrawl = edge;
    printf("\n Edge list:\n");
    while (pCrawl)
    {
        printf(" %d", pCrawl->edgeNumber);
        printf("\t%d,%d\t%d\n", pCrawl->startVertex, pCrawl->endVertex, pCrawl->vertexNumber);
        pCrawl = pCrawl->next;
    }
}
main()
{
    struct Graph* graph = createGraph(V);
    printf("PRINT OF ADJACENCY LSIT OF THE GRAPH \n");
    printGraph(graph);
    printf("\n");
    struct EdgeList* edgeList = createEdgelist(graph);
    printEdgelist(edgeList);
    return 0;

}

