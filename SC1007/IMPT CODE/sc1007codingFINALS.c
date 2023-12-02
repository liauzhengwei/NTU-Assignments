#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

//Infix
//1a)In2Pre     //read from right to left
/*void in2Pre(char* infix, char* prefix)
{
   Stack s;
   s.head = NULL;
   s.size = 0;

   char revInfix[SIZE];
   char revPrefix[SIZE];
   int i=0;
   int j = 0;
   char c;
   int count =0;

   //reverse the string
   while(infix[count]!='\0')count++;    //count finds length of string
   for(i=count-1;i>=0;i--)  
    revInfix[count-1-i] = infix[i];     //reverses string
   revInfix[count]='\0';

   i=0;
   while(i<SIZE && revInfix[i]!='\0')
    {
        c = revInfix[i++];
        switch(c)
        {
        case '*': //operators      
        case '/':
        case '+':
        case '-':
            while(isEmptyStack(s)==0 && peek(s) != ')' && precedence(peek(s)) > precedence(c) ) //note the precedence comparison
            {
                revPrefix[j++] = peek(s);
                pop(&s);
            }
            push(&s,c);
            break;
        case ')':
            push(&s,c);
            break;
        case '(':
            while(isEmptyStack(s)==0)
            {
                if(peek(s)!=')')
                {
                    revPrefix[j++]=peek(s);
                    pop(&s);
                }
                else
                {
                    pop(&s);
                    break;
                }
            }
            break;
        default: //operand
            revPrefix[j++] = c;
        }
    }
    while(isEmptyStack(s)==0)
    {
        revPrefix[j++] = peek(s);
        pop(&s);
    }
    revPrefix[j] = '\0';

   //reverse the string
  count=0;
  while(revPrefix[count]!='\0')count++;
    for(i=count-1;i>=0;i--)
    {
        prefix[count-1-i] = revPrefix[i];
    }
    prefix[count]='\0';

}

int precedence(char op)
{
    if(op == '*' || op == '/')      //times and divide
        return 1;
    else return 0;
}*/

//b)In2Post //eg.(7-((3*4)+8)/5) => 734*8+5/-
/*void in2Post(char* infix, char* postfix)  //read infix from left to right
{   
    //add every operator including brackets to the stack, unless ) encountered then pop the stack 
    //until '(' reached. Then, add the operator to postfix array
    
    //every number encountered is added to the postfix array

    Stack s;
    s.head = NULL;
    s.size = 0;

    int i = 0;
    int j = 0;
    char c;

    while(i<SIZE && infix[i]!='\0')     //while not at the end of the infix array
    {
        c = infix[i++];
        switch(c)
        {
        case '*': //operators
        case '/':
        case '+':
        case '-':
            while(isEmptyStack(s)==0 && peek(s) != '(' && precedence(peek(s)) >= precedence(c) )
            {                               //while not empty stack, top of stack is not '(' and 
                                            //priority of operator at top of stack greater than operator
                                            //prefix is on currently
                postfix[j++] = peek(s);         //assign top of stack to postfix and pop stack
                pop(&s);
            }
            push(&s,c);
            break;
        case '(':
            push(&s,c);
            break;
        case ')':
            while(isEmptyStack(s)==0)
            {
                if(peek(s)!='(')
                {
                    postfix[j++]=peek(s);
                    pop(&s);
                }
                else
                {
                    pop(&s);
                    break;
                }
            }
            break;
        default: //operand,number
            postfix[j++] = c;
        }
    }

    while(isEmptyStack(s)==0)       //stack is still not empty
    {
        postfix[j++] = peek(s);
        pop(&s);
    }
    postfix[j] = '\0';          //for strings
}*/

//2.Prefix  //only one to read from right to left
/*a)pre2In  //
    read prefix from right to left
    for numbers, push them to the stack
    for operators, pop two values from stack and make a string with these three values
        (top number, operator, number)      //infix
    push string to stack
    do until end of prefix expression
*/

//b)Pre2Post //
/*
    read prefix from right to left
    for numbers, push into the stack
    for operators, pop two numbers and make a string with these three values
        (number 1,number 2, operator)       //postfix
    push string to stack
    do until end of prefix expression
*/

//3.Postfix

//a)Post2In //
/*read post from left to right
  for numbers, push to the stack
  for operators, pop two numbers and create a string with these three values
      (number, operator, number)        //infix
  push back to stack
  do until end of postfix expression
*/

//b)Post2Pre //
/*
  read post from left to right
  for numbers, push to the stack
  for operators, pop two numbers and create a string with these three values
      (operator, 2nd number, top number)    //prefix
  push back to stack
  do until end of postfix expression
*/

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//HashTable
//Q1.Hash Insert and Hash Search(LAB)   // closed addressing, linked list for every index
/*int Hash(int key, int hSize){
    return key%hSize;
}

ListNode* HashSearch(HashTable Q3Hash, int key){
    int index;

    ListNode *temp;

    if(Q3Hash.hSize!=0){
        index = Hash(key, Q3Hash, hSize);   //HashTable not empty
    }
    else{
        return NULL;        //HashTable empty
    }

    temp = Q3Hash.Table[index].head;    //start of hashtable at index

    while(temp!=NULL){              //go through the linked list at the index
        if(temp->key==key){         // and check if they are the key to be found
            return temp;
        }
        temp = temp->next;
    }
    return NULL;        //all checked, cannot find
}

int HashInsert(HashTable* Q3HashPtr, int key){
    int index;
    ListNode *newNode;

    if(HashSearch(*Q3ashPtr, key)!=NULL)    //check for duplicates
        return 0;

    if(Q3HashPtr->hSize!=0)                 //HashTable not empty
        index = Hash(key,Q3HashPtr->hSize);

    newNode = (ListNode*)malloc(sizeof(ListNode));      //allocate mem
    newNode->key = key;                                 //assign key
    newNode->next = Q3HashPtr->Table[index].head;       //assign next as head
    Q3HashPtr->Table[index].head = newNode;             //set head as newNode

    Q3HashPtr->Table[index].size++;     //increase sizes
    Q3HashPtr->nSize++;

    return 1;
}
*/

//Q2.Coalesce hashing
/*int HashInsert(int key, HashSlot hashTable[])
{   
    int i=0;
    int a=0;
    int b=0;
    if (HashFind(key, hashTable)!=-1){      //can find, means duplicate key to be inserted
        return -1;
    }
                                                //table full, return value larger than table
    while(hashTable[i].indicator==USED){
        i++;    
        if(i==TABLESIZE)
        {
            return TABLESIZE;
        }
    }

    int index = hash(key);
    if(hashTable[index].indicator==EMPTY){
        hashTable[index].key = key;
        hashTable[index].indicator = USED;
        return index;
    }
    else if(hashTable[index].indicator==USED) {        
        b=index;                            //index = 1;
        while (hashTable[b].next !=-1){    //1 7 -1     //go to the end of the hashtable index 
            b = hashTable[b].next;      
        }
        index = b;                         //index = 1; but is previous index
        while(hashTable[b].indicator!=EMPTY){   //linear probe
            b = (b+1)%TABLESIZE;
        }
        hashTable[index].next = b;      //index = 1;
    
        hashTable[b].key = key;         //b =2;
        hashTable[b].indicator = USED;
        hashTable[b].next = -1;
        return b;
    }
}

int HashFind(int key, HashSlot hashTable[])
{
    int index = hash(key);

    while(index!=-1){
        if(hashTable[index].key==key)
            return index;       //found
        index = hashTable[index].next;
    }
    return -1;      //not found
}*/

//Q3.Open addressing of double hashing
/*int HashInsert(int key, HashSlot hashTable[])
{   
    int a = 0;
    int index;
    int i;
    int b;
    int c=0;

    while(a<TABLESIZE){
        int index = hash1(key+a*hash2(key));

        if(index==0 && hashTable[0].key==key && hashTable[0].indicator==USED){      //check for 0 as initially all set to 0
            return -1;
        }
        else if(hashTable[index].key==key && hashTable[index].indicator==USED){     //check for duplicates
                return -1;
            }   
        else if(hashTable[index].indicator==DELETED){       //when deleted
            i = index;
            b = a;
            while(b<TABLESIZE){     
                int index = hash1(key+b*hash2(key));        //index from double hashing
                if(hashTable[index].key==key && hashTable[index].indicator==USED){      //check for duplicates
                    return -1;
                }
                else if(hashTable[index].indicator==USED){      //count number of used index passed
                    c++;
                }

                else if(hashTable[index].indicator==EMPTY){     //reached end of the double hashing for that index
                    hashTable[i].key = key;
                    hashTable[i].indicator = USED;
                    a = a+c;
                    return a;       //return number of comparisons
                } 
            b++;
            }
            hashTable[i].key = key;         
            hashTable[i].indicator = USED;
            a = a+c;
            return a;
        }

        else if(hashTable[index].indicator==EMPTY){     //if index is empty means it is the head
            hashTable[index].key = key;                 //add key and change to used
            hashTable[index].indicator = USED;
            return a;
        }
        else{
            a++;                    //try next double hashing index
        }
    }
    return TABLESIZE;
}

int HashDelete(int key, HashSlot hashTable[])
{   
    int a = 0;
    int index;
    int c;
    

    if(key<0){
        return TABLESIZE+1;
    }

    while (a != TABLESIZE) {
        c = a+1;
        index = hash1(key + a * hash2(key));
        if (hashTable[index].key == key && hashTable[index].indicator == USED) {        //found key
            hashTable[index].indicator = DELETED;   
            if(c>TABLESIZE){                //if c greater than size of hashtable
                return TABLESIZE+1;
            }
            else{
                return c;
            }
        }
        a++;        //try next index
    }
    return -1;
}*/

//Q4 Doubly linked list
/*int HashInsert(HashTable* Q1Ptr, int key)
{
    ListNode *temp;
    ListNode *cur;
    int index;

    if(key<0){
        return 0;
    }

    //printf("%d",index);
    ListNode *newNode = (ListNode*)malloc(sizeof(ListNode));

    newNode->key = key;         //create newNode with key to be inserted
    newNode->pre = NULL;
    newNode->next = NULL;
    
    if(Q1Ptr->hSize!=0)     
    {
        index = Hash(key,Q1Ptr->hSize);     //hash value as index
    }
    else{
        free(newNode);
        return 0;
    }

    if((Q1Ptr->Table[index]).head == NULL){     //actually insert the newNode, when the index is empty
        Q1Ptr->Table[index].head = newNode;
        Q1Ptr->Table[index].size++;
        Q1Ptr->nSize++;
        return 1;
    }
    else{   
        temp = Q1Ptr->Table[index].head;        //actually insert the newNode,when the index is not empty
        cur = temp;             //set cur as the head of the hash table as an index
        while(temp!=NULL){
            if(temp->key == key){       //duplicate
                free(newNode);
                return 0;
            } 
            temp = temp->next;
        }
        temp = cur;     //set temp back to the head

        Q1Ptr->Table[index].head = newNode;
        newNode->next = temp;
        temp->pre = newNode;
    }
    Q1Ptr->Table[index].size++;     //increase size
    Q1Ptr->nSize++;
    return 1;
}

int HashDelete(HashTable* Q1Ptr, int key)
{
                                        //need account for: deleted
                                                          //not existing
    int index;
    ListNode *temp;
    ListNode *cur;
    ListNode *pit;

    if(key<0){          //key is less than 0
        return 0;
    }

    if(Q1Ptr->hSize>0)
    {
        index = Hash(key,Q1Ptr->hSize);
    }
    else{
        return 0;
    }

    temp = Q1Ptr->Table[index].head;
    if(Q1Ptr->Table[index].head==NULL){     //index is already empty
        return 0;
    }

    while(temp!=NULL){
        if(temp->key==key){
                                                    //delete, free the node and connect nodes
                                                    //first node,middle nodes, last node
            if(temp == Q1Ptr->Table[index].head){   //first node
                if(temp->next!=NULL){                   //more than 1 node in the index
                    cur = temp;
                    temp = temp->next;
                    //temp->pre = NULL;
                    Q1Ptr->Table[index].head = temp;

                    free(cur);                      
                    Q1Ptr->Table[index].size--;
                    Q1Ptr->nSize--;
                    return 1;
                }
                else{
                    Q1Ptr->Table[index].head->pre=NULL;     //only 1 node in the index so need to change after removal
    
                    Q1Ptr->Table[index].head = NULL;
                    Q1Ptr->Table[index].size=0;
                    Q1Ptr->nSize--;
                    return 1;
                }
            }
            else if(temp->next==NULL){      //last node
                cur = temp;
                temp = temp->pre;
                temp->next = NULL;      //break the connection
                free(cur);              //free the removed node
                Q1Ptr->Table[index].size--;
                Q1Ptr->nSize--;
                return 1;
            }
            else {              //middle node
                //cur = temp;
                temp = temp->pre;       
                pit = temp->next;
                temp->next = temp->next->next;  //connect left and right node
                if (pit->next != NULL) {
                    pit->next->pre = temp;      //assign pre to pit
                }
                free(pit);

                Q1Ptr->Table[index].size--;     //change the size
                Q1Ptr->nSize--;
                return 1;
            }
        }
        temp = temp->next;
    }
    return 0;
}*/

//Graph representation

//1.Convert Adjacency matrix to adjacency list
/*void adjM2adjL(Graph *g){
    int j;
    int i;
    ListNode **list;
    ListNode *temp;

    if(g->type ==ADJ_LIST){printf("Error"); return;}
    if(g->V<=0){printf("Empty graph!"); return;}

    list = (ListNode **)malloc(g->V*sizeof(ListNode*));     //create an empty adjlist 
    for(i=0;i<g->V;i++){
        list[i] = NULL;
    }

    for(i=0;i<g->V;i++){
        for(j=0;j<g->V;j++){
            if(g->adj.matrix[i][j] ==1){
                if(list[i] == NULL){                                    //when the index of the list is empty
                    list[i] = (ListNode*)malloc(sizeof(ListNode));      //create a new ListNode and store values
                    list[i]->vertex = j+1;
                    list[i]->next = NULL;
                    temp = list[i];
                }
                else{
                    temp->next = (ListNode*)malloc(sizeof(ListNode));   //when index of list is not empty
                    temp->next->vertex = j+1;
                    temp->next->next = NULL;
                    temp = temp->next;
                }
            }
        }
    }
    g->type = ADJ_LIST;

    for(i=0;i<g->V;i++){
        free(g->adj.matrix[i]);
    }
    free(g->adj.matrix);

    g->adj.list = list;
}*/

//2.Convert Adjacency list to adjacency matrix
/*void adjL2adjM(Graph *g){
    int i,j;
    ListNode* temp;

    if(g->type ==ADJ_MATRIX){printf("Error");return;}
    if(g->V<=0){printf("Empty grpah!");return;}

    int **mat = (int **)malloc(g->V*sizeof(int *));         //allocate mem for an adj matrix
    for(i=0;i<g->V;i++){
        mat[i] = (int*)malloc(g->V*sizeof(int));
    }

    for(i=0;i<g.V;i++){             //create an empty adj matrix
        for(j=0;j<g->V;j++){
            mat[i][j] = 0;
        }
    }

    for(i=0;i<g->V;i++){        //assign a value for adj matrix for every adj list value
        temp = g->adj.list[i];
        while(temp!=NULL){
            mat[i][(temp->vertex)-1]=1;
            temp = temp->next;
        }
    }

    g->type = ADJ_MATRIX;

    for(i=0;i<g->V;i++){
        free(g->adj.list[i]);
    }
    free(g->adj.list);

    g->adj.matrix = mat;
}*/

//3.Find degree of each vertex
/*void calDegreeV(Graph g, int *degreeV){
    int i,j;
    ListNode *temp = NULL;

    if(g.type ==ADJ_MATRIX){
        for(i=0;i<g.V;i++){
            degreeV[i] = 0;     //set degreeV for all i to be 0
            for(j=0;j<g.V;j++){
                degreeV[i] += g.adj.matrix[i][j];   //count degree for every i using the fact that adjmatrix[i][j] = 1 if there is an edge
            }
        }
    }
    else{
        for(i=0;i<g.V;i++){
            degreeV[i] = 0;
            ListNode *temp = g.adj.list[i];
            while(temp!=NULL){          //traverse the adj list and count
                degreeV[i]++;       
                temp = temp->next;
            }
        }
    }
}
*/

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//Graph traversal
//1.Depth First Search
//a)Recursive

/*void DFS_R(Graph g, int v){
    int i;
    g.visited[v-1] = 1;

    for(i=0;i<g.V;i++){
        if(g.matrix[v-1][i]==1 && g.visited[i] ==0){       //check connection exist and not visited
            DFS_R(g,i+1);                                  //call the function again 
        }
    }
    printf("%d ",v);
}*/

//b)Iterative

/*void DFS_I(Graph g,int v){
    Stack s;
    s.size = 0;
    s.head = NULL;

    int i;
    int w;

    int *visitV;                                            //create and initialised visitV array 
    visitV = (int*)malloc(sizeof(int)*g.V);
    for(i=0;i<g.V;i++) visitV[i] = 0;

    push(&s,v);                                            //push v into the stack
    visitV[v-1] = 1;                                       //make v visited

    int unvisited;
    while(isEmptyStack(s)==0){                              //while not empty stack, get top of stack and push its childs through checking for connection and not visited, then break after pushing each child
        w = peek(s);

        unvisited = 0;
        for(i=0;i<g.V;i++){
            if(g.matrix[w-1][i] == 1 &&visitV[i] ==0){
                push(&s,i+1);
                visitV[i] = 1;
                unvisited = 1;
                break;
            }
        }                               //this means theres only at most 2 item in the stack at all times
    
        if(unvisited==0){           //this makes it such that the top is now the recently pushed node
            printf("%d ",w);
            pop(&s);
        }
    }
    free(visitV);
}
*/

//c)Graph strongly connected qn //assignment
/*int CC (Graph g)
{
    //do dfs for every vertice
        //put any graph vertice on top of stack
        //take top item of stack and add to visited list
        //create list of vertex's adjacent nodes. Add unvisited adjacent to stack
        //repeat 2 and 3 until stack empty

    Stack s;
    s.head = NULL;
    s.size = 0;
    int visited[g.V];
    int i;
    int u;
    int m;
    int p;

    //another for loop for every vertice
    for(u=0;u<g.V;u++){
        for(i=0;i<g.V;i++){ //set all nodes to unvisited
            visited[i] = 0;
        }

        int m = g.list[u]->vertex;
        //push a node into the stack
        push(&s,m);

        while(!isEmptyStack(s)){
            p = peek(s);
            pop(&s);

            if(!visited[p-1]){
                visited[p-1] = 1;
                //get all adjacent of popped index
                ListNode* temp = g.list[p-1];
                while(temp!=NULL){
                    push(&s,temp->vertex);
                    temp = temp->next;
                }
            }
        }

        for(i=0;i<g.V;i++){
            if(visited[i]==0){
                return -1;
            }
        }
    }    
    return 1;
}*/

//d)City population qn  //dfs then lca method, prob wont come out
/*struct Node{
    int val;
    struct Node* next;
};

int parent[100000000];
struct Node* adj[100000000] = {NULL};
int depth[100000000];   //currently only 10^8

void dfs(int cur_node,int prev_node,int d){
    depth[cur_node] = d;
    parent[cur_node] = prev_node;
    struct Node* v = adj[cur_node];
    while(v!=NULL){
        if(prev_node != v->val){                    //no stack used to get correct parent[]
            dfs(v->val,cur_node,d+1);
        }
        v = v->next;
    }    
}

int lca(int t,int r, int* population, int test){
    int count = 0;

    while(depth[t]>depth[r]){
        if(population[t-1]<=test){
            count++;
        }
        t = parent[t];
    }
    while(depth[r]>depth[t]){
        if(population[r-1]<=test){
            count++;
        }
        r = parent[r];
    }

    while(t!=r){
        if(population[t-1]<=test){
            count++;
        }
        if(population[r-1]<=test){
            count++;
        }
        t = parent[t];
        r = parent[r];
    }
    
    if(population[r-1]<=test){
        count++;
    }
    return count;
}

int* city_population (int N, int* population, int** road, int Q, int** cities) 
{   
    int i;
    int *ans = (int*)malloc(Q*sizeof(int));
    
    for(i=0;i<Q;i++){
        ans[i] = 0;
    }

    for(int i = 0;i<N-1;i++){
        int u = road[i][0];
        int v = road[i][1];

        struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
        newNode->val = v;
        newNode->next = adj[u];
        adj[u] = newNode;

        newNode = (struct Node*) malloc(sizeof(struct Node));
        newNode->val = u;
        newNode->next = adj[v];
        adj[v] = newNode;
    }


    for(i=1;i<=N;i++){
        parent[i] = 0;
    }

    //int dep;
    int end;
    int count;
    int test;

    dfs(1,-1,1);

    for(i=0;i<Q;i++){
        int start= cities[i][0];
        count = 0;
        end = cities[i][1];
        test = cities[i][2];

        count = lca(start,end,population,test);

        ans[i] = count;
    }
    return ans;

}*/

//2.Breadth First Search 

/*a) void BFS(Graph g, int v){
    Queue q;
    q.size = 0;
    q.head = NULL;
    q.tail = NULL;

    int w; 
    int i;

    enqueue(&q,v);          //add to queue
    g.visited[v-1] =1;      //make it visited
    printf("%d ",v);

    while(isEmptyQueue(q)==0){      //while queue not empty
        w = dequeue(&q);            

        for(i=0;i<g.V;i++){                 //matrix
            if(g.matrix[w-1][i]==1 && g.visited[i] ==0){        //find children of top of queue node that are not visited
                g.visited[i] =1;                //make them visited
                printf("%d ",i+1);
                enqueue(&q,i+1);            //enqueue them
            }
        }
    }
}*/

//b)Shortest distance qn    //assignment
/*int BFS (Graph g, int v, int w){

    Queue q;
    int visited[g.V];
    int distance[g.V];
    int i;

    for(i=0;i<g.V;i++){
        visited[i] = 0;         //initialise visited and distance
        distance[i] = -1;
    }

    enqueue(&q,v);              //queue root and set visited and distance
    visited[v-1] = 1;
    distance[v-1] = 0;

    while(!isEmptyQueue(q)){
        int curr = getFront(q);
        dequeue(&q);

        if(curr==w){                        //node found, remove all items from queue, get distance of that node
            removeAllItemsFromQueue(&q);
            return distance[curr-1];
        }

        ListNode* temp = g.list[curr-1];
        while(temp!=NULL){                                  //linked list
            int neighbour = temp->vertex;
            if(!visited[neighbour-1]){
                enqueue(&q,neighbour);
                visited[neighbour-1] = 1;
                distance[neighbour-1] = distance[curr-1] +1;       //disance of each node is the culmulative distance of parent nodes
            }
            temp = temp->next;
        }
    }
    return -1;
}*/


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//BACKTRACKING

//1.Coloring Problem

/*int count = 0;
int V;

void printSolution(int *color){         //print solution via color array
    printf("Solution Exists:"
    "Following are the assigned colors \n");
    for(int i=0; i<V;i++){
        printf(" %d ",color[i]);
        printf("\n");
    }
}

int isSafe(int v, int **graph, int* color, int c){
    for(int i=0;i<V;i++){
        if(graph[v][i] && c==color[i]){     //if there is a path btw 2 regions and color is the same
            return 0;
        }
    }
    return 1;
}

int graphColoring(int** graph, int m, int* color, int v){
    if(v==V){   //initial v is 0
        count++;    //count number of solutions found
        return 1;
    }

    int isFound = 0;
    for(int c = 1; c<=m; c++){  //find the safe color and repeat for next node 
        if(isSafe(v,graph,color,c)){
            color[v] = c;
            if(graphColoring(graph,m,color,v+1)==1){    //due to recursion, every solution will be counted
                isFound = 1;    //solution found
            }
            color[v] == 0;  //reset the color array 
        }
    }
    return isFound;
}

int main(){
    int m;
    int** graph;
    int* color;

    printf("Enter number of colors:\n");
    scanf("%d",&m);

    printf("Enter number of regions:\n");
    scanf("%d",&V);

    int i,j;
    color = (int*)malloc(V* sizeof(int));   //1d array
    graph = (int**)malloc(V*sizeof(int*));  //2d array

    for(i=0;i<V;i++){
        graph[i] = (int*)malloc(V*sizeof(int));
    }

    printf("Input the adjacency matrix:\n");
    for(i=0;i<V;i++){
        for(j=0;j<V;j++){
            scanf("&d",&graph[i][j]);   //get inputs for creating graph[V][V]
        }
    }

    for(i=0;i<V;i++){
        color[i] = 0;   //set all colors to 0
    }

    graphColoring(graph,m,color,0);

    printf("There is/are total %d solution(s)",count);
    return 0;
}*/

//2.NQueen problem
/*int nQueens(int **board, int N, int col);
int isSafe(int** board, int N, int row, int col);
void printSolution(int** board, int N);

int main(){
    int **board;
    int BSize;

    int i,j;

    printf("Enter the size of the chessboard:\n");
    scanf("%d",&BSize);

    board = (int**)malloc(BSize*sizeof(int*));
    for(i=0;i<BSize;i++){
        board[i] = (int*)malloc(BSize*sizeof(int));     //allocate mem for board
    }
    for(i=0;i<BSize;i++){           //inititalise all to 0
        for(j=0;j<BSize;j++){
            board[i][j] = 0;
        }
    }
    nQueens(board,BSize, 0);

    return 0;
}

int nQueens(int**board, int BSize, int col){
    if(col==BSize){             //reached the end of the board
        printSolution(board,BSize);
        return 1;
    }
    int i;
    int found = 0;
    for(i=0;i<BSize;i++){   //check row by row in the col^th column
        if(isSafe(board,BSize,i,col)){  //safe to place
            board[i][col] = 1;  //place queen in this square

            found = NQueens(board,BSize,col+1)||found;  //recursive next column placement, if found ans, then set all found to 1

            board[i][col] = 0;  //delete the queen and backtrack
        }
    }
    return found;
}

int isSafe(int**board, int BSize, int row, int col){
    int i,j;

    for(i=0;i<col;i++){                     //horizontal check
        if(board[row][i])
            return 0;
    }

    for(i=row,j=col;i>=0&&j>=0;i--,j--){    //upper left diagonal check
        if(board[i][j])
            return 0;
    }

    for(i=row,j=col;j>=0 && i<BSize;i++,j--){   //lower left diagonal check
        if(board[i][j])
            return 0;
    }
    return 1;
}

void printSolution(int**board, int BSize){
    int i,j;
    for(i=0;i<BSize;i++){
        for(j=0;j<BSize;j++){
            if(board[i][j]==1){
                printf(" Q ");
            }
            else{
                printf(" + ");
            }
        }
        printf("\n");
    }
    printf("\n");
}*/

//3.Project Matching
/*typedef struct _listnode
{
   int vertex;
   struct _listnode *next;
} ListNode;
typedef ListNode StackNode;

typedef struct _graph{
   int V;
   int E;
   ListNode **list;
}Graph;

typedef ListNode QueueNode;

typedef struct _queue{
   int size;
   QueueNode *head;
   QueueNode *tail;
} Queue;

typedef struct _stack
{
   int size;
   StackNode *head;
} Stack;

void insertAdjVertex(ListNode** AdjList,int vertex);
void removeAdjVertex(ListNode** AdjList,int vertex);
int matching(Graph g);
int dfs(Graph g, int v, int u,int a[]);

void enqueue(Queue *qPtr, int item);
int dequeue(Queue *qPtr);
int getFront(Queue q);
int isEmptyQueue(Queue q);
void removeAllItemsFromQueue(Queue *qPtr);
void printQ(QueueNode *cur);
//////STACK///////////////////////////////////////////
void push(Stack *sPtr, int vertex);
int pop(Stack *sPtr);
int peek(Stack s);
int isEmptyStack(Stack s);
void removeAllItemsFromStack(Stack *sPtr);
//////////////////////////////////

int main()
{
   int Prj, Std, Mtr; //Project, Student and Mentor;
   int maxMatch;
   int np,nm; //number of projects and number of mentors

   int i,j;
   int k;
   
   ListNode* temp;
   scanf("%d %d %d", &Std, &Prj, &Mtr);

   //build graph
   Graph g;
   
   g.V = Prj + Std + Std + Mtr + 2;
   g.list = (ListNode **)malloc(g.V * sizeof(ListNode*));       //allocate mem to an adj list

   for(i=0;i<g.V;i++){
      g.list[i] = NULL;
   }
   for(i=0;i<Std;i++){                                   //std 1,2,3,4 to std 5,6,7,8, repeated to deal with exceptional case where all students to one project/mentor
      scanf("%d %d",&np,&nm);
      insertAdjVertex(&g.list[i], Std+i+1);  
      g.E++;

      for(j=0;j<np;j++){                                    //prj 9,10,11 to std 1,2,3,4
         scanf("%d",&k);
         insertAdjVertex(&g.list[Std + Std + k -1], i +1);    
         g.E++;
      }
      for(j=0;j<nm;j++){                                        //std 5,6,7,8 to mtr 12,13,14
         scanf("%d",&k);
         insertAdjVertex(&g.list[Std + i], Std + Std +Prj + k); 
         g.E++;
      }
   }

   for(j=0;j<Prj;j++){                                          //source 15 to prj 9,10,11 
      insertAdjVertex(&g.list[Std + Std + Prj + Mtr], Std + Std + j + 1);
      g.E++;
   }

   for(j=0;j<Mtr;j++){                                              //mtr 12,13,14, to sink 16
      insertAdjVertex(&g.list[Std + Std + Prj + j], Std + Std + Prj + Mtr + 2);
      g.E++;
   }*/

   /*ListNode *temp;            //used to chack if grpah is properly made
      for(i=0;i<g.V;i++){
         printf("%d: ",i+1);
         temp = g.list[i];
         while(temp!=NULL){
            printf("%d -> ",temp->vertex);
            temp = temp->next;
         }
         printf("\n");
      }
   */
   //apply Ford Fulkerson algorithm
   // use DFS or BFS to find a path
   /*
   maxMatch = matching(g);
   printf("%d\n", maxMatch);
   return 0;
}

int matching(Graph g)
{
   int a[60];
   int i=0;
   int j=0;
   int r1,r2;

   ListNode* cur;

   for(i=0;i<60;i++){
      a[i] = 0;
   }

   while(dfs(g, (g.V-1),g.V,a)==1){ //v is source 15, u is sink 16
      j=0;
      while(a[j+1]!=-1){                        //while not at end of array
         r1 = a[j];                              //this is the sink node initially
         r2 = a[j+1];                           //node before sink node
         insertAdjVertex(&g.list[r1-1], r2);    //create an backwards edge
         removeAdjVertex(&g.list[r2-1], r1);    //remove the forwards edge
         j++;
      }
      for(i=0;i<60;i++){                    //reset array to empty
         a[i] = 0;
      }
   }
   i=0;
   cur = g.list[g.V-1];                     //count the number of backwards edges form sink,representing number of paths
   while(cur!=NULL){
      i++;
      cur = cur->next;
   }
   return i;
}

int dfs(Graph g, int v, int u, int a[]){
    Stack s;
    s.size = 0;
    s.head = NULL;

    ListNode *cur;
    int i,t;
    int y=0;
    int *visited;
    visited = malloc(sizeof(int)*g.V);

    for(i=0;i<g.V;i++){
      visited[i] = 0;
    }

    push(&s,v);
    visited[v-1] = 1;    //source visited
    int unvisited;
    while(isEmptyStack(s)==0){    //while not empty stack
        t = peek(s);

        unvisited = 0;
        cur = g.list[t-1];
        while(cur!=NULL){
            if(visited[cur->vertex-1]==0){   //if not visited, visit it and set visited
                push(&s,cur->vertex);
                visited[cur->vertex-1]=1;
                unvisited = 1;
                break;      //leave the loop once visited
            }
            cur = cur->next;
        }
        if(unvisited ==0){   //all neighbour nodes visited
            if(t!=u){         //check if top of stack is sink
                pop(&s);    //not sink then pop
            }
            else{    //is sink
                while(isEmptyStack(s)==0){
                    t = peek(s);
                    a[y] = t;      //store all the values of nodes traversed in an array
                    y++;
                    pop(&s);
                }
                a[y] = -1;  //last value of array is -1
                return 1;   //path found
            }
        }
    }
    //go another route after popping stack
    return 0;   //no path found
}

void removeAdjVertex(ListNode** AdjList,int vertex)
{
   ListNode *temp, *preTemp;
   if(*AdjList != NULL)
   {
      if((*AdjList)->vertex ==vertex){//first node
         temp = *AdjList;
         *AdjList = (*AdjList)->next;
         free(temp);
         return;
      }
      preTemp = *AdjList;
      temp = (*AdjList)->next;
      while(temp!=NULL && temp->vertex != vertex)
      {
         preTemp= temp;
         temp = temp->next;
      }
      preTemp->next = temp->next;
      free(temp);
   }
}

void insertAdjVertex(ListNode** AdjList,int vertex)
{
   ListNode *temp;
   if(*AdjList==NULL)
   {
      *AdjList = (ListNode *)malloc(sizeof(ListNode));
      (*AdjList)->vertex = vertex;
      (*AdjList)->next = NULL;
   }
   else{
      temp = (ListNode *)malloc(sizeof(ListNode));
      temp->vertex = vertex;
      temp->next = *AdjList;
      *AdjList = temp;
   }
}

void enqueue(Queue *qPtr, int vertex) {
   QueueNode *newNode;
   newNode = malloc(sizeof(QueueNode));
   if(newNode==NULL) exit(0);

   newNode->vertex = vertex;
   newNode->next = NULL;

   if(isEmptyQueue(*qPtr))
      qPtr->head=newNode;
   else
      qPtr->tail->next = newNode;

   qPtr->tail = newNode;
   qPtr->size++;
}

int dequeue(Queue *qPtr) {
   if(qPtr==NULL || qPtr->head==NULL){ //Queue is empty or NULL pointer
      return 0;
   }
   else{
      QueueNode *temp = qPtr->head;
      qPtr->head = qPtr->head->next;
      if(qPtr->head == NULL) //Queue is emptied
         qPtr->tail = NULL;

      free(temp);
      qPtr->size--;
      return 1;
   }
}

int getFront(Queue q){
   return q.head->vertex;
}

int isEmptyQueue(Queue q) {
   if(q.size==0) return 1;
   else return 0;
}

void removeAllItemsFromQueue(Queue *qPtr)
{
  while(dequeue(qPtr));
}

void printQ(QueueNode *cur){
   if(cur==NULL) printf("Empty");

   while (cur != NULL){
      printf("%d ", cur->vertex);
      cur = cur->next;
   }
   printf("\n");
}

void push(Stack *sPtr, int vertex)
{
   StackNode *newNode;
   newNode= malloc(sizeof(StackNode));
   newNode->vertex = vertex;
   newNode->next = sPtr->head;
   sPtr->head = newNode;
   sPtr->size++;
}

int pop(Stack *sPtr)
{
   if(sPtr==NULL || sPtr->head==NULL){
      return 0;
   }
   else{
      StackNode *temp = sPtr->head;
      sPtr->head = sPtr->head->next;
      free(temp);
      sPtr->size--;
      return 1;
   }
}

int isEmptyStack(Stack s)
{
   if(s.size==0) return 1;
   else return 0;
}

int peek(Stack s){
   return s.head->vertex;
}

void removeAllItemsFromStack(Stack *sPtr)
{
   while(pop(sPtr));
}*/

//4.SumToC
/*void sumToC(LinkedList* ll, int C, ArrayList* al)
{
	int t = C;		//removeNode returns 1 and 0
	int index = 0;
	int a = 1;
	int b;
	int v;

	while(a<=C){        //incerease the counter
		if(t<a){            //if the counter greater than the remainder
			index--;
			a = findNode(*ll, index)->item;
			removeNode(ll,index);           //remove the prev add node
			//find value of node removed and add to t

			t = t+a;
			a++;        //increase counter a
		}
		insertNode(ll, index, a);   //insert the next node
		index++;
		t = t-a;                //minus value of t

		if(t==0){ 
			int *newArray = (int*)malloc(sizeof(int)*(ll->size));       //allocate mem for new array
			ListNode *curListNode = ll->head;
			
			for(int i=0;i<ll->size;i++){                    //initialise the new array and make a linked list from it
				newArray[i] = curListNode->item;
				curListNode = curListNode->next;
			}
			
			ArrayNode *curArrNode = (ArrayNode*)malloc(sizeof(ArrayNode));      //allocate mem for an array node
			curArrNode->itemArray = newArray;               //each array node contains an array
			curArrNode->sizeArray = ll->size;               
			curArrNode->next = NULL;
			
			
			if(al->head==NULL){
				al->head = curArrNode;      //set head as cur array node if head is empty
				al->size++;
			}
			else{
				ArrayNode *newArrNode = al->head;   
				while(newArrNode->next!=NULL){          //go to end of the array node linked list    
					newArrNode = newArrNode->next;
				}
				newArrNode->next = curArrNode;      //add cur array node to it
				al->size++;
			}

			if(a == C){         //reached the end of the big while looop
				break;
			}

			index--;                        //havent reached the end of the while loop
			b = findNode(*ll, index)->item;     //remove twice and add the value of each item removed back to t
			removeNode(ll,index);
			t = t+b;

			index--;
			a = findNode(*ll, index)->item;
			removeNode(ll,index);
			t = t+a;
		}
	a++;        //increase a
	}
}*/

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//DYNAMIC PROGRAMMING

//1. KNAPSACK, time complexity is O(nC)
//a)Bottom Up

//int **temp_array;

/*int bottom_up_dp(int n,int *s,int *v, int C){
    int i;
    int j;

    if(n==0||C==0){ //if the number of items is 0 or the capacity is 0;
        return 0;
    }

    for(i=1;i<=n;i++){      //forms a table
        for(j=1;j<=C;j++){
            if(s[i]<=j){                        //if size of item less than Capacity
                if(temp_array[i-1][j] >= temp_array[i-1][j-s[i]] + v[i]){   //if sum in current array is greater than sum in 
                                                                            //array of same number of items but with removed
                                                                            //capacity + value of item
                    temp_array[i][j] = temp_array[i-1][j];      //bring current array to the array one size up
                }
                else{                                               //if sum of cur array < (sum in array of same number of items but with removed capacity + value of item)
                    temp_array[i][j] = temp_array[i-1][j-s[i]] +v[i];   //bring the array with (same number of items but with 
                                                                        //removed capacity + value of item) to the array one size up
                }
            }
            else{   //if size of item is not less than capcity, make next item size have same value as cur size
                temp_array[i][j] = temp_array[i-1][j];
            }
        }
    }

    for(i=1;i<=n;i++){
        for(j=1;j<=C;j++){
            printf("%d ",temp_array[i][j]);
        }
        printf("\n");       //print results in temp_array
    }
    return temp_array[n][C];    //return the array;
}*/

//b)Top down

/*int max(int a, int b){
    if(a>=b){   //max function
        return a;
    }
    else{
        return b;
    }
}

int top_down(int n, int *s, int *v, int C){     //feels like something wrong with this code, prob cuz 
                                                //s array not used
    int i;
    int j;

    if(n==0||C==0){     //if the number of items is 0 or the capacity is 0;
        return 0;
    }

    temp_array[0][0] = 0;   

    if(temp_array[n][C]!=0){
        return temp_array[n][C];
    }
    for(i=1;i<=n;i++){
        int row = n-i;  //start from largest row number
        for(j=1;j<=C;j++){
            int col = C-j;  //start from largest col number
            temp_array[n][C] = max(temp_array[row][col],top_down(row,s,v,col)+v[row]);    //recursive
        }
    }

    for(i=1;i<=n;i++){
        for(j=1;j<=C;j++){
            printf("%d ",temp_array[i][j]);
        }
        printf("\n");   //print temp_array
    }
    return temp_array[n][C];
}

int main(){
    int n,C;
    int function;
    int *s;     //size
    int *v;     //value
    int i,j;
    printf("Enter the number of items n:\n");
    scanf("%d",&n);
    printf("Enter the capacity C:\n");
    scanf("%d",&C);
    s = (int *)malloc(sizeof(int)*(n+1));   //create array s[n+1]
    v = (int *)malloc(sizeof(int)*(n+1));

    temp_array = (int **)malloc(sizeof(int*) * (n+1));
    for(i=0;i<=n;i++){
        temp_array[i] = (int*)malloc(sizeof(int)*(C+1));    //create temp_array[n+1][C+1]
    }

    for(i=0;i<=n;i++){
        for(j=0;j<=C;j++){
            temp_array[i][j] = 0;
        }
    }

    printf("Enter the sizes of items (as a list, separate by spacing:\n");
    for(i=1;i<=n;i++){
        scanf("%d",&s[i]);      //s[0] not assigned
    }

    printf("Enter the values of items (as a list, separate by spacing:\n");
    for(i=1;i<=n;i++){
        scanf("%d",&v[i]);  //v[0] not assigned
    }

    //printf("The maximum value is: %d \n", bottom_up_dp(n,s,v,C));   //pass int n,C and arrays s and v
    printf("The maximum value is: %d \n", top_down(n,s,v,C)); 
}*/

//2.Fibonnaci
//a) Top down

/*FibTD(n){     //O(n) complexity
    if(n==0){                   //base value
        M[0] = 0; return 0;
    }
    if(n==1){                   //base value
        M[1] = 1; return 1;
    }

    if(M[n-1]==-1){         //initially M[] values all set to -1
        M[n-1] = FibTD(n-1);
    }

    if(M[n-2]==-1){
        M[n-2] = FibTD(n-2);
    }

    M[n] = M[n-1] + M[n-2]
    return M[n];
}*/

//b) Bottom up

/*FibBU(n){     //O(n) complexity
    M[0] = 0;       //base values
    M[1] = 1;

    int i;
    for(i=2;i<=n;i++){          //build up from base values
        M[i] = M[i-1] + M[i-2];
    }
    return M[n];
}*/

//c)Recursive,FYI, similar to top down
/*FibRec(n){
    if(n==0){
        return 0;
    }
    else if(n==1){
        return 1;
    }
    else{
        return FibRec(n-1)+ FibRec(n-2);
    }
}*/

//3. Rod Cutting
//a) Recursive, FYI
/*int cutrod(int *p,int n){
    if(n==0) return 0;      //there is no rod/rod of length 0

    int i;
    q = -10000;     //set q to be a super negative value
    for(i=1;i<=n;i++){
        q = max(q,p[i] + cutrod(p,n-1));
    }
    return q;
}*/

//b) Top down
/*int TDCutRod(int *p,int n){
    int i;
    
    if(n==0)return 0;

    r[0] = 0;       //base value
    if(r[n]>0)return r[n];
    else{
        int q = -10000;
        for(i=1;i<=n;i++){
            q = max(q,p[i] + TDCutRod(p,n-i));
        }
        r[n] = q;
    }
    return q;
}*/

//c)Bottom up
/*BUCutRod(int []p,int n){
    int i ,j;
    r[0] = 0;
    if(n==0)return 0;
    for(j=1;j<=n;j++){
        for(i=1;i<=j;i++){
            r[j] = max(r[j],p[i]+r[j-i]);
        }
    }
    return r[n];
}*/

//c)i) Bottom up print
/*BUprint(int *p,int n){
    int i,j;
    r[0]= 0;

    int firstCut[n+1];
    for(i=0;i<=n;i++){
        firstCut[i] = 0;
    }

    for(i=1;i<=n;i++){
        int position = 0;
        for(j=1;j<=i;j++){
            int temp = p[j] + r[i-j];
            if(temp>r[i]){
                position = j;
                r[j] = temp;
            }
        }    
        firstCut[i] = position;
    }
    printf("Length of each piece is:\n");
    print_pos(n,firstCut);
    printf("\n");
    return r[n];
}

void print_pos(int rlength, int first_cut[]){
    if(rlength ==0)
        return;
    int pos = first_cut[rlength];
    printf("%d ",pos);
    printf_pos(rlength - pos, first_cut);
}*/

//4.Ways to score
//int score[3] = {3,5,10};

//a) Recursive,FYI
/*int waysToScore(int n, int* score){
    if(n<0)return 0;
    if(n==0)return 1;

    return waysToScore(n-score[0],score) + 
            waysToScore(n-score[1],score) +
            waysToScore(n-score[2],score);
}*/
    
//b) Bottom Up approach
/*int waysToScore(int n, int*score){
    int *arr;
    arr = (int*)malloc(sizeof(int)*n);
    int i;
    for(i=0;i<n;i++){
        arr[i] = 0;
    }
    arr[0] =1;

    for(i=0;i<=n;i++){
        if(i-score[0]>=0) arr[i] += arr[i-score[0]];
        if(i-score[1]>=0) arr[i] += arr[i-score[1]];
        if(i-score[2]>=0) arr[i] += arr[i-score[2]];
    }
    return arr[n];
}*/

//------------------------------------------------------------------