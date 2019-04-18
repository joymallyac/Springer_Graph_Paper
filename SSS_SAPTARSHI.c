#include<stdio.h>
#include <stdlib.h>
#include <math.h>
int V = 10;
int visited[10];
int E = 18;



//TEST INSTANCES ::: ----
int G[10][10] ={{0,0,0,1,1,0,1,0,1,0},{0,0,1,0,0,1,0,1,1,1},{0,1,0,1,1,0,0,0,1,0},{1,0,1,0,0,0,0,0,1,0},{1,0,1,0,0,1,0,0,0,1},{0,1,0,0,1,0,1,0,0,0},{1,0,0,0,0,1,0,0,1,1},{0,1,0,0,0,0,0,0,0,0},{1,1,1,1,0,0,1,0,0,0},{0,1,0,0,1,0,1,0,0,0}};
//int G[10][10] = {{0,0,0,1,0,0,0,0,0,0},{0,1,1,1,1,1,0,0,0,0},{0,1,0,1,0,0,1,1,1,0},{1,1,1,0,0,0,0,0,0,0},{0,1,0,0,0,1,0,0,0,0},{0,1,0,0,1,0,0,1,0,1},{0,0,1,0,0,0,0,1,1,1},{0,0,1,0,0,1,1,0,0,0},{0,0,1,0,0,0,1,0,0,0},{0,0,0,0,0,1,1,0,0,0}};
//int G[10][10] = {{0,0,0,0,1,0,0,0,0,0},{0,0,1,1,0,0,0,0,0,0},{0,1,1,1,1,0,0,0,0,1},{0,1,1,0,0,1,1,0,0,0},{1,0,1,0,0,0,1,0,0,1},{0,0,0,1,0,0,0,1,1,0},{0,0,0,1,1,0,0,0,0,0},{0,0,0,0,0,1,0,0,0,1},{0,0,0,0,0,1,0,0,1,1},{0,0,1,0,1,0,0,1,1,0}};
//int G[10][10] = {{0,1,0,1,0,0,0,0,0,0},{1,0,0,0,0,0,0,0,0,0},{0,0,0,1,0,1,1,1,0,0},{1,0,1,0,0,0,0,0,0,0},{0,0,0,0,0,1,0,0,0,0},{0,0,1,0,1,0,1,0,0,0},{0,0,1,0,0,1,0,1,1,1},{0,0,1,0,0,0,1,0,0,0},{0,0,0,0,0,0,1,0,0,0},{0,0,0,0,0,0,1,0,0,0}};
//int G[5][5] = {{0,1,0,1,1},{1,0,1,0,0},{1,0,0,1,1},{1,0,1,0,1},{1,0,1,1,0}};
//int G[10][10] = {{0,0,0,1,0,0,0,0,0,0},{0,1,1,1,1,1,0,0,0,0},{0,1,0,1,0,0,1,1,1,0},{1,1,1,0,0,0,0,0,0,0},{0,1,0,0,0,1,0,0,0,0},{0,1,0,0,1,0,0,1,0,1},{0,0,1,0,0,0,0,1,1,1},{0,0,1,0,0,1,1,0,0,0},{0,0,1,0,0,0,1,0,0,0},{0,0,0,0,0,1,1,0,0,0}};
//int G[10][10] ={{0,0,0,1,1,0,1,0,1,0},{0,0,1,0,0,1,0,1,1,1},{0,1,0,1,1,0,0,0,1,0},{1,0,1,0,0,0,0,0,1,0},{1,0,1,0,0,1,0,0,0,1},{0,1,0,0,1,0,1,0,0,0},{1,0,0,0,0,1,0,0,1,1},{0,1,0,0,0,0,0,0,0,0},{1,1,1,1,0,0,1,0,0,0},{0,1,0,0,1,0,1,0,0,0}};

//int G[19[19] = {{0,1,0,0,0,0,0,1,0,0,1,0,1,0,0,0,0,0,0},{1,0,1,0,1,0,1,1,1,0,1,0,0,0,0,0,0,0,0},{0,1,0,1,1,0,0,0,0,1,0,0,0,0,0,0,1,0,1},{0,0,1,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0},{0,1,1,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0},{0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,1,1,0},{0,1,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,1},{1,1,0,1,0,0,0,0,0,0,0,1,0,0,1,1,0,0,1},{0,1,0,0,0,1,0,0,0,0,0,0,0,0,1,1,0,0,0},{0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0},{1,1,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0},{1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},{0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,1},{0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,1,0,0},{0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,1,0,0,0},{0,0,0,0,0,1,0,0,0,0,0,0,1,1,0,0,0,0,0},{0,0,1,0,0,0,1,1,0,0,0,0,0,0,1,0,0,0,0}};
//int G[15][15] = {{0,1,1,1,1,0,0,1,0,0,0,0,0,1,0},{1,0,1,1,0,0,1,1,0,0,0,0,0,0,0},{1,1,0,1,0,0,0,1,0,1,0,0,0,0,0},{1,1,1,0,0,0,0,0,0,0,1,0,0,0,0},{1,0,0,0,0,1,0,0,0,1,0,0,0,1,0},{0,0,0,0,1,0,0,0,1,0,0,0,0,0,0},{0,1,0,0,0,0,0,0,0,1,0,1,0,0,0},{1,1,1,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,1,0,0,0,0,0,0,1,0,0},{0,0,1,0,1,0,1,0,0,0,0,0,0,0,1},{0,0,0,1,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,1,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,1,0,0,0,0,0,0},{1,0,0,0,1,0,0,0,0,0,0,0,0,0,1},{0,0,0,0,0,0,0,0,0,1,0,0,0,1,0}};
//int G[15][15] = {{0,0,0,0,0,0,0,0,1,0,0,0,0,0,0},{0,0,1,0,0,1,1,1,0,1,1,0,0,0,0},{0,1,1,0,0,1,0,0,0,0,0,0,0,0,1},{0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},{0,0,0,0,0,0,0,0,1,0,0,0,0,0,0},{0,1,1,0,0,1,0,0,0,0,0,0,0,1,0},{0,1,0,0,0,0,0,1,0,0,0,0,0,0,1},{0,1,0,0,0,0,1,1,0,0,0,0,0,0,0},{1,0,0,0,1,0,0,0,0,1,0,0,1,0,0},{0,1,0,0,0,0,0,0,1,0,1,0,1,0,1},{0,1,0,0,0,0,0,0,0,1,0,0,0,0,1},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{0,0,0,0,0,0,0,0,1,1,0,0,1,0,0},{0,0,0,1,0,1,0,0,0,0,0,0,0,0,0},{0,0,1,0,0,0,1,0,0,1,1,1,0,0,0}};


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

struct AdjListNode* newAdjListNode(int dest)
{
    struct AdjListNode* newNode = (struct AdjListNode*) malloc(sizeof(struct AdjListNode));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
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
struct EdgeList{
    int startVertex;
    int endVertex;
    int edgeNumber;
    struct EdgeList* next;
}*IN = NULL,*OUT = NULL;
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
    {
        printf(" %d", pCrawl->edgeNumber);
        printf("\t%d,%d\n", pCrawl->startVertex, pCrawl->endVertex);
        pCrawl = pCrawl->next;
    }
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

void callDFS(int dfsTree[] ,struct EdgeList* EL){
    int i;
    for(i=0;i<V;i++)
        visited[i]=0;
    DFS(dfsTree,0,EL);
}
void DFS(int dfsTree[], int i,struct EdgeList* EL)
{
    int j;
    //printf("\n%d",i);
    visited[i]=1;
    for(j=0;j<V;j++)
       if(!visited[j]&&G[i][j]==1)
       {
        struct EdgeList* pCrawl = EL;
        while (pCrawl)
        {   if(((pCrawl->startVertex == i) && (pCrawl->endVertex == j)) || ((pCrawl->startVertex == j) && (pCrawl->endVertex == i))){
                //printf("CONNECTED EDGE IS %d\n", pCrawl->edgeNumber);
                dfsTree[pCrawl->edgeNumber] = 1;

            }
            pCrawl = pCrawl->next;
        }
        DFS(dfsTree,j,EL);

       }

}
int noOfEdge(){
int i,j,count =0;
for( i= 0;i < V; i++){

    for(j = 0; j< V; j++){
    if(G[i][j] == 1)
        count++;
    }
}
return count/2;
}
int fact(int num)
{
     if ( num == 0 )
        return 1;
    return(num * fact(num - 1));
}

int numRowsFunction(int m,int n)
{
    int rows=fact(m+n)/(fact(m)*fact(n));
    return rows;
}

int lastOneIndexFunction(int a[],int cols)
{
int lastOneIndex = 0 , l;
     for( l = cols; l > 0; l--)
         {
             if(a[l]==1)
               {
                  lastOneIndex = l;
                  return lastOneIndex;
               }

          }
}

void updateDegree(int *im, int combination[V-1], int degree[V])
{
    int i, j;
    int NoE = noOfEdge();
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
                    deletePendantEdges(combination,degree,E);
                    for(i=0;i<V;i++)
                    {
                        degree[i] = 0;
                    }
                    updateDegreeAgain(combination,degree,E);
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
 void generateGrayCode(){

        int i,j,m,n,k,ro,co,u,z,t,lnx,q,rowNumbersTotal,relativeFirstIndex,CurrentRow,Zeroleft,ZeroleftOuter,cols,rowsToModify,OneLeft,highestIndexForOne;;
        int treeSerialNo = 1,numZero = 0,numOne = 0,ro1 = 1,cpy1 = 0,newNumberOfZero,newNumberOfOne;
        int *arr,size,*binaryarray,**mat;
        int storeTreeArrayCopy[V-1];
        int storeTreeArray[V-1];
        int cpy2,store;
        struct Graph* graph = createGraph(V);
        int mt[V][E+1];
        int dfsTreeSize = noOfEdge()+1;
        int dfsTree[dfsTreeSize];
        int dfsTreecopy[dfsTreeSize];
        dfsTree[0] = -1;
        // GETTING THE FIRST TREE FROM DFS AND STORING IT IN DFS TREE
        for(i = 1 ; i< dfsTreeSize; i++){
            dfsTree[i] = 0;
        }
        //printf("PRINT OF ADJACENCY LSIT OF THE GRAPH \n");
        //printGraph(graph);
        struct EdgeList* EL = createEdgelist(graph);
        printEdgelist(EL);
        callDFS(dfsTree,EL);
        // PRINTING THE DFS TREE
        for(i = 0 ; i< dfsTreeSize; i++){
            printf(" %d ",dfsTree[i]);
        }
        printf("\n");
        // COPYING THE DFS TREE AND COUNTING NUMBER OF 1 AND NUMBER OF 0
        for(i = 0 ; i < dfsTreeSize; i++){
            dfsTreecopy[i] = dfsTree[i];
            if(dfsTree[i] == 0){
                numZero++;
            }
             if(dfsTree[i] == 1){
                numOne++;
            }
        }
        // CREATING THE TREE BRANCH ARRAY( STORING INDEX OF 1) AND CHORD BRANCH ARRAY (STORING INDEX OF 0)
        int treebrancharray[numOne];
        int chordbrancharray[numZero];
        k = 0;
        for(i = 0 ; i < dfsTreeSize ; i++){
            if(dfsTree[i] == 1){
                treebrancharray[k] = i;
                k++;
            }
        }
        k = 0;
        for(i = 0 ; i < dfsTreeSize ; i++){
            if(dfsTree[i] == 0){
                chordbrancharray[k] = i;
                k++;
            }
        }
        // PREPARATION FOR GENERATING GRAY CODES
        size = pow(2,numZero);
        arr = (int*) calloc(numZero, sizeof(int));// THIS ARRAY WILL CONTAIN THE RIGHT PART ( GRAY CODE ) OF TATM
        for(i = 0; i< numZero; i++){
             arr[i] = 0;
        }
        // FOR LOOP TO GENERATE GRAY CODE ONE BY ONE
        for(u = 1; u < size; u++){
                    lnx = floor(log(u)/log(2))+1;
                    binaryarray = (int*) calloc(lnx, sizeof(int));
                    generateBinary(binaryarray,u,lnx);
                    for(z = 0; z< numZero; z++){
                            arr[z] = 0;
                    }
                        for(j = lnx -1, k = numZero-1 ; j >= 0; j--,k--){
                            arr[k] = binaryarray[j];

                        }
                       // FOR PRINTING GRAY CODES OF LENGTH n
                        /*for(m = 0; m < numZero; m++){
                            printf("%d",arr[m]);
                        }
                        printf("\n");*/
                        newNumberOfZero = 0;
                        for(t = 0; t< numZero; t++){
                            if( arr[t] == 1)
                                newNumberOfZero++;
                        }
                        newNumberOfOne = numOne - newNumberOfZero;
                        rowNumbersTotal = numRowsFunction(newNumberOfOne,newNumberOfZero);
                        cols = newNumberOfOne + newNumberOfZero;
                        mat = (int **)calloc(rowNumbersTotal , sizeof(int*));
                        for( i = 0; i < rowNumbersTotal; i++)
                        {
                            mat[i] = (int *)calloc(cols , sizeof(int));

                        }

                        for(j = 0; j < newNumberOfOne; j++)
                        {
                            CurrentRow=0;
                            while(CurrentRow != rowNumbersTotal)
                            {
                                relativeFirstIndex = (j==0) ? 0 : (lastOneIndexFunction(mat[CurrentRow],cols)+1);
                                ZeroleftOuter = newNumberOfZero - (relativeFirstIndex-j);
                                OneLeft = newNumberOfOne-j;
                                highestIndexForOne = cols-OneLeft+1;
                                for( m = relativeFirstIndex; m < highestIndexForOne; m++)
                                {
                                    Zeroleft = (ZeroleftOuter- (m-relativeFirstIndex) <0) ? 0 : (ZeroleftOuter-m +relativeFirstIndex) ;
                                    rowsToModify = numRowsFunction(newNumberOfOne-j-1,Zeroleft);
                                        for(n = 0; n < rowsToModify; n++)
                                        {
                                            mat[n+CurrentRow][m]=1;
                                        }
                                    CurrentRow = CurrentRow + rowsToModify;
                                }
                            }

                        }
                        int printTreeArray[dfsTreeSize],cpy;
                        printTreeArray[0] = -1;
                        // THIS IS FOR PRINTING THE COMBINATIONS OF 0 & 1 , NOT THE TREE
                           /*for( ro = 0 ; ro < rowNumbersTotal ; ro++){
                              for( co = 0 ; co < cols ; co++){
                                    printf("%d",mat[ro][co]) ;
                               }
                               printf("\n");
                            }*/
                        // THIS IS FOR PRINTING THE FINAL TREE AND ALSO TREE CHECKING
                            ro = 0;
                            while(ro < rowNumbersTotal){
                                ro1 = 1;
                              for( cpy = 0 ; cpy < cols ; cpy++){
                                    printTreeArray[ro1] = mat[ro][cpy] ;
                                    ro1++;
                               }
                               cpy1 = 0;
                               while(ro1 < dfsTreeSize){
                                    printTreeArray[ro1] = arr[cpy1];
                                    ro1++;
                                    cpy1++;
                               }
                            // PRINTING THE FINAL COMBINATIONS

                               /*for(cpy = 1 ; cpy < dfsTreeSize ; cpy++){
                                   printf(" %d ",printTreeArray[cpy]);
                                }
                                printf("\n");*/

                            // PRINTING THE FINAL TREES
                                store = 0;
                                for(cpy = 1 ; cpy <= numOne ; cpy++){
                                    if(printTreeArray[cpy] == 1)
                                       storeTreeArray[store++] = treebrancharray[cpy-1];
                                }
                                for(cpy2 = numZero -1 ; cpy2 >= 0 ; cpy2--){
                                    if(arr[cpy2] == 1){
                                        storeTreeArray[store++] = chordbrancharray[cpy2];
                                    }
                                }
                               // CALL THE TREE CHECKING ALGORITHM HERE
                                for(q = 0; q < V-1 ; q++ ){
                                    storeTreeArrayCopy[q] = storeTreeArray[q];
                                }
                                //int E = noOfEdge();
                                createIncedenceMatrix(mt,EL);
                                if(( treeTest(storeTreeArray,mt,EL) == 1)){
                                    for(q = 0; q < V-1 ; q++ ){
                                    storeTreeArray[q] = storeTreeArrayCopy[q];
                                }
                                    printf(" TREE NO %d ----> ", treeSerialNo);
                                for(store = 0; store < V-1; store++ ){
                                        printf(" %d ",storeTreeArray[store]);
                                }
                                treeSerialNo++;
                                printf("\n");
                                }
                              ro++;
                            }

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
   /* printf("\n Incidence Matrix :\n");
    for(row=0;row<V;row++)
    {
        for(column=0;column<E+1;column++)
        {
            printf(" %d  ",im[row][column]);
        }
        printf("\n");
    }*/
}
    void generateBinary(int *array,int x , int lnx){

                int quotient,i,j;
                if(x>0){
                    quotient = x;
                    i=lnx;
                    while(quotient!=0){
                        array[i-1]= quotient % 2;
                        quotient = quotient / 2;
                        i--;
                    }
                }
    }
void main()
{
    generateGrayCode();

}
