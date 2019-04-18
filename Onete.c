#include<stdio.h>
#include <stdlib.h>
//int V = 3;
//int G[3][3] = {{0,1,1},{1,0,1},{1,1,0}};
//int E = 6;
//int V = 4;
//int incidence[3][3] = {{1,0,1},{1,1,0},{0,1,1}};
/*int G[4][4] = {{0,1,1,1},{1,0,1,1},{1,1,0,1},{1,1,1,0}};
int incidence[4][6] = {{1,1,1,0,0,0},{1,0,0,1,1,0},{0,1,0,1,0,1},{0,0,1,0,1,1}};
int rw = 4;
int cl = 6;
int EDGE_NUMBER = 6;
int result1 [6][3];
int r1 = 6;
int c1 = 6;
int r2 = 6;
int c2 = 3;
int result2 [3][3][6];
int r11 = 3;
int c11 = 6;
int r12 = 6;
int c12 = 3;
int NoE = 6;
int V = 10;
int E = 11;
//int G[4][4] = {{0,1,1,1},{1,0,1,0},{1,1,0,1},{1,0,1,0}};
//int G[4][4] = {{0,1,1,1},{1,0,1,1},{1,1,0,1},{1,1,1,0}};*/
int G[10][10] = {{0,1,0,1,0,0,0,0,0,0},{1,0,0,0,0,0,0,0,0,0},{0,0,0,1,0,1,1,1,0,0},{1,0,1,0,0,0,0,0,0,0},{0,0,0,0,0,1,0,0,0,0},
{0,0,1,0,1,0,1,0,0,0},{0,0,1,0,0,1,0,1,1,1},{0,0,1,0,0,0,1,0,0,0},{0,0,0,0,0,0,1,0,0,0},{0,0,0,0,0,0,1,0,0,0}};
int NoE = 11;
int V = 10;
int E = 11;
int EDGE_NUMBER = 11;

struct AdjListNode
{
    int dest;
    struct AdjListNode* next;
};
struct AdjList
{
    struct AdjListNode *head;
};
struct Graph
{
    int V;
    struct AdjList* array;
};
struct EdgeList{
    int startVertex;
    int endVertex;
    int edgeNumber;
    struct EdgeList* next;
}*IN = NULL,*OUT = NULL;
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
    struct AdjListNode* newNode = newAdjListNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;
    newNode = newAdjListNode(src);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}
struct Graph* createGraph(int V)
{
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->V = V;
    graph->array = (struct AdjList*) malloc(V * sizeof(struct AdjList));
    int i,j;
    for (i = 0; i < V; ++i)
        graph->array[i].head = NULL;
    for(i=1;i<V;i++){
        for(j=0;j<i;j++){
        addEdge(graph, i, j);
        }
    }
    return graph;
}

struct EdgeList* newEdge(int src, int dest, int count)
{
    struct EdgeList* newE = (struct EdgeList*) malloc(sizeof(struct EdgeList));
    newE->startVertex = src;
    newE->endVertex = dest;
    newE->edgeNumber = count;
    newE->next = NULL;
    return newE;
}
struct EdgeList* createEdgelist(struct Graph* graph){
    int i,j,c = 1;
    struct EdgeList* E = (struct EdgeList*) malloc(sizeof(struct EdgeList));
    struct EdgeList* temp;
    for(i=0;i<graph->V;i++){
        for(j=0;j<graph->V;j++){
            if(G[i][j]!=0 && i<j){
                if(c==1){
                    E->startVertex = i;
                    E->endVertex = j;
                    E->edgeNumber = c;
                    E->next = NULL;
                    temp = E;
                }
                else{
                    temp->next = newEdge(i,j,c);
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
    {   printf(" %d", pCrawl->edgeNumber);
        printf("\t%d,%d\n", pCrawl->startVertex, pCrawl->endVertex);
        pCrawl = pCrawl->next;
    }
}
void createIncedenceMatrix(int im[V][E+1], struct EdgeList* EL)
{
    struct EdgeList* temp = EL;
    int row, column, r, c, y = 0;
    for(row=0;row<V;row++)
    {
        for(column=0;column<E+1;column++)
        {
            im[row][column]=0;
        }
    }
    for(row=0;row<V;row++)
    {

            im[row][0] = row;

    }
    for(row=0;row<V;row++)
    {
        for(column=0;column<E+1;column++)
        {
            while(temp)
            {
                if(temp->edgeNumber==column)
                {
                    if(temp->startVertex==row || temp->endVertex==row)
                    {
                        r = row;
                        c = column;
                        y = 1;
                        break;
                    }
                }
                temp = temp->next;
            }
            if(y==1)
            {
                im[r][c] = 1;
                y = 0;
            }
            temp = EL;
        }
    }
    printf("\n Incidence Matrix :\n");
    for(row=0;row<V;row++)
    {
        for(column=0;column<E+1;column++)
        {
            printf(" %d  ",im[row][column]);
        }
        printf("\n");
    }
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
void createDiagonal(){
int i,j;
int matrix[EDGE_NUMBER][EDGE_NUMBER];
    for(i=0;i<EDGE_NUMBER;i++){
        for(j=0;j<EDGE_NUMBER;j++){
            if(i==j){
                matrix[i][j] = 1;
            }
            else
                matrix[i][j] = 0;
        }
    }
    for(i=0;i<EDGE_NUMBER;i++){
        for(j=0;j<EDGE_NUMBER;j++){
        printf("%d\t",matrix[i][j]);
        }
        printf("\n");
    }
}


/*void onete(){

    // Making reduced incidence matrix
    int Rinc[rw-1][cl],i,j,k,l,row;
    // Making diagonal matrix

        int diagonal[EDGE_NUMBER][EDGE_NUMBER],count = 1;
        for(i=0;i<EDGE_NUMBER;i++){
            for(j=0;j<EDGE_NUMBER;j++){
                if(i==j){
                    diagonal[i][j] = count++ ;
                }
                else
                    diagonal[i][j] = 0;
            }
        }
    for(row = 0; row<rw; row++){
            for(i=0;i<rw-1;i++){
                for(j=0;j<cl;j++){
                    Rinc[i][j] = 0;
                }
            }
            for(i=0;i<rw;i++){
                for(j=0;j<cl;j++){
                    if(i < row)
                    {
                        Rinc[i][j] = incidence[i][j];
                    }
                    if(i > row)
                    {   k = i-1;
                        Rinc[k][j] = incidence[i][j];
                    }

                }
            }

        // Making transpose of reduced incidence matrix

        int RincT[cl][rw-1];
        for(i=0;i<cl;i++){
                for(j=0;j<rw-1;j++){
                    RincT[i][j] = Rinc[j][i];
                }
            }

        // Multiplying diagonal matrix and transpose of reduced incidence matrix

       l = 0;
        for (i = 0; i < r1; i++) {
              for (j = 0; j < c2; j++) {
                for (k = 0; k < r2; k++) {
                  l = l + diagonal[i][k]*RincT[k][j];
                }
                    result1[i][j] = l;
                    l =0;
              }
        }


        // Multiplying result1 matrix with reduced induced matrix

        for (i = 0; i < r11; i++) {
          for (j = 0; j < c12; j++) {
            for (k = 0; k < c11; k++) {
              l = Rinc[i][k]*result1[k][j];
              result2[i][j][k]=l;
            }
          }
        }
        printf("\nDisplaying values:\n");

        for(i = 0; i < r11; ++i) {
            for (j = 0; j < c12; ++j) {
                for(k = 0; k < c11; ++k ) {
                    if(k == c11-1)
                    printf("%d", result2[i][j][k]);
                    else
                    printf("%d+", result2[i][j][k]);
                }
                printf("\t");
            }
            printf("\n");
        }
    }
}*/

void updateDegree(int *im, int combination[V-1], int degree[V])
{
    int i, j;
    for(i=0;i<V-1;i++)
    {
        for(j=0;j<V;j++)
        {
            if(*(im + j*(NoE+1) + combination[i])==1 && combination[i]!=0)
            {
                degree[j] = degree[j]+1;
            }
            if(combination[i]==0)
            {
                degree[j] = -1;
            }
        }
    }
    /*printf("\n");
    for(i=0;i<V;i++)
    {
        printf(" %d  ",degree[i]);
    }*/
}
void deletePendantEdges(int combination[V-1], int degree[V], struct EdgeList *E)
{
    int i, j, eno = 0;
    struct EdgeList *e = E;
    for(i=0;i<V;i++)
    {
        if(degree[i]==1)
        {
            for(j=0;j<V-1;j++)
            {
                eno = combination[j];
                while(e)
                {
                    if(e->edgeNumber==eno)
                    {
                        if(e->startVertex==i || e->endVertex==i)
                        {
                            combination[j] = 0;
                        }
                        break;
                    }
                    e = e->next;
                }
                e = E;
            }
        }
    }
}
void updateDegreeAgain(int combinationCopy[V-1], int degree[V], struct EdgeList *E)
{
    int i;
    struct EdgeList *e = E;
    for(i=0;i<V-1;i++)
    {
        if(combinationCopy[i]!=0)
        {
            while(e)
            {
                if(e->edgeNumber==combinationCopy[i])
                {
                    degree[e->startVertex] = degree[e->startVertex]+1;
                    degree[e->endVertex] = degree[e->endVertex]+1;
                    break;
                }
                e = e->next;
            }
            e = E;
        }
    }
}
int treeTest(int combination[V-1], int *IM, struct EdgeList *E)
{
    int i, degree[V], combinationCopy[V-1], dCounter = 0, degCounter = 0, flag = 0;
    for(i=0;i<V;i++)
    {
        degree[i] = 0;
    }
    updateDegree(IM,combination,degree);
    while(1)
    {
        for(i=0;i<V;i++)
        {
            if(degree[i]==1)
            {
                dCounter++;
            }
        }
        if(dCounter>=2)
        {
            for(i=0;i<V;i++)
            {
                if(degree[i]>1)
                {
                    degCounter++;
                }
            }
            if(degCounter>=3)
            {
                if(dCounter>=1)
                {
                    for(i=0;i<V-1;i++)
                    {
                        combinationCopy[i] = combination[i];
                    }
                    deletePendantEdges(combinationCopy,degree,E);
                    for(i=0;i<V;i++)
                    {
                        degree[i] = 0;
                    }
                    updateDegreeAgain(combinationCopy,degree,E);
                    dCounter = 0;
                    degCounter = 0;
                }
                else
                {
                    flag = 0;
                    break;
                }
            }
            else
            {
                flag = 1;
                break;
            }
        }
        else
        {
            flag = 0;
            break;
        }
    }
    return flag;
}
main(){

   struct Graph* graph = createGraph(V);
    printGraph(graph);
    struct EdgeList* EL = createEdgelist(graph);
    printEdgelist(EL);
    int m[V][E+1];
    createIncedenceMatrix(m,EL);
    //onete();
    int combination[] = {1,2,3,4,5,7,9,10,11};
    printf(" %d ",treeTest(combination,m,EL));

}
