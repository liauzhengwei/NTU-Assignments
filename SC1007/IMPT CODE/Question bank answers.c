/*
Linked list
1.insertSortedLL()  //assignment
//int insertSortedLL(LinkedList *ll,int item){
    ListNode *temp;
    temp=ll->head;

    int index=0;

    if((ll->size==0)||(item<temp->item)){
        insertNode(ll,index,item);
        return index;
    }         

    while((item>temp->item)&&(temp->next!=NULL)){
        if(item<temp->next->item){
            insertNode(ll,index+1,item);
            return index+1;
        }
        temp = temp->next;
        index++;
    }
    if(item==temp->next) return -1;
    else{
        insertNode(ll,index+1,item);
        return index+1;
    }
}

2.alternateMergeLL()    //assignment
//void alternateMergeLinkedList(LinkedList *ll1,LinkedList *ll2){
    int count = 1,double_size = (ll1->size)*2;

    if(ll1->size>ll2->size){
        while(ll2->size!=0){
            insertNode(ll1,count,ll2->head->item);
            removeNode(ll2,0);
            count+=2;
        }
    }
    else{
        while(ll1->size!=double_size){
            insertNode(ll1,count,ll2->head->item);
            removeNode(ll2,0);
            count+=2;
        }
    }
}

3.moveoddItemsToBackLL()    //assignment
//void moveOddItemsToBack(LinkedList *ll){
    int i,count=0;
    ListNode *temp;
    temp = ll->head;

    for(i=0;i<(ll->size);i++){
        if((temp->item%2)!=0){
            insertNode(ll,ll->size,temp->item);
            temp=temp->next;
            removeNode(ll,count);
        }
        else{
            temp = temp->next;
            count++;
        }
    }
}

4.frontBackSplitLL()    //assignment
//void frontBackSplitLinkedList(LinkedList *ll,LinkedList *resultFontList, LinkedList *resultBackList){
    int i, back_index = 0, front_index = 0;
    ListNode *temp;
    temp = ll->head;

    for(i=0;i<(ll->size);i++){
        if(i>((ll->size-1)/2)){
            insertNode(resultBackList,back_index,temp->item);
            temp=temp->next;
            back_index++;
        }
        else{
            insertNode(resultFrontList,front_index,temp->item);
            temp=temp->next;
            front_index++;
        }
    }
}

5.moveEvenItemsToBackLL()   //tutorial
//void moveEvenItemsToBack(LinkedList *ll){
    ListNode *cur;
    int d,s,i,j;

    s=ll->size;

    if(s<2)
        return;
    cur = ll->head;
    j=0;
    for(i=0;i<s;i++){
        if(cur->item%2==0){
            d = cur->item;
            cur = cur->next;
            removeNode(ll,j);
            insertNode(ll,ll->size,d);
        }
        else{
            cur = cur->next;
            j++;
        }
    }
}

6.moveMaxToFrontLL()    //prac qn &tutorial
//int moveMaxToFront(ListNode **ptrHead){
    ListNode *pre,*cur;
    ListNode *preMax = NULL;
    int maxItem;

    if(*ptrHead ==NULL) return -1;

    if((*ptrHead)->next ==NULL) return 0;

    cur = (*ptrHead);
    maxItem = (*ptrHead)->item;

    while(cur!=NULL){
        if(cur->item>maxItem){
            maxItem = cur->item;
            preMax = pre;
        }
        pre = cur;
        cur = cur->next;
    }

    if(preMax == NULL) return 0;

    cur = preMax->next;
    preMax->next = preMax->next->next;
    cur->next = *ptrHead;
    *ptrHead = cur;
    return 0;
} 

7.removeDuplicatesSortedLL()    //tutorial
//void removeDuplicatesSortedLL(LinkedList *ll){
    ListNode *current, *temp;
    current = ll->head;
    if(current ==NULL)
        return;
    while(current->next!=NULL)
    {
        if(current->item ==current->next->item)
        {
            temp = current->next->next;
            free(current->next);
            current->next = temp;
            ll->size--;
        }
        else
        {
            current=current->next;
        }
    }
}

8.split()   //lab
//int split(ListNode *head,ListNode **ptrEvenList, ListNode **ptrOddList){
    int even = 1, evenSize = 0, oddSize = 0;
    ListNode *cur = head;

    if(cur==NULL)
        return -1;
    while(cur!=NULL){
        if(even==1){
            insertNode(ptrEvenList,evenSize,cur->num);
            evenSize++;
        }
        else{
            insertNode(ptrOddList,oddSize,cur->num);
            oddSize++;
        }
    cur = cur->next;
    even = -even;
    }
    return 0;
}

9.duplicateReverse()    //lab
//int duplicateReverse(ListNode *head,ListNode **ptrNewHead){
    ListNode *cur = head;

    if(cur ==NULL)return -1;

    while(cur!=NULL){
        if(insertNode(ptrNewHead,0,cur->num)==-1)
            return -1;
        cur = cur->next;
    }
    return 0;
}

10.concatenate()    //prac qn
//int concatenate(ListNode **ptrHead1,ListNode *head2)[
    ListNode *temp = *ptrHead1;

    if(*ptrHead1 ==NULL && head2 ==NULL)
        return -1;

    if(temp ==NULL){
        *ptrHead1 = head2;
        return 0;
    }

    if(head2==NULL)
        return 0;

    while(temp->next !=NULL)
        temp = temp->next;
    temp->next = head2;
    return 0;
]

11.combineAlternating() //prac qn
//int combineAlternating(ListNode **ptrHead,ListNode *head1,ListNode *head2){
    ListNode *temp;
    if(head1==NULL && head2 == NULL) return -1;

    while(head1!=NULL||head2!=NULL){
        if(*ptrHead == NULL){
            if(head1 !=NULL){
                *ptrHead = malloc(sizeof(ListNode));
                (*ptrHead)->num = head1->num;
                head1 = head1->next;
                temp = *ptrHead;
                if(head2!= NULL){
                    temp->next = malloc(sizeof(ListNode));
                    temp->next->num = head2->num;
                    temp = temp->next;
                    head2 = head2->next;
                }
            }
            else{
                *ptrHead = malloc(sizeof(ListNode));
                (*ptrHead)->num = head2->num;
                head2 = head2->next;
                temp = *ptrHead;
            }
        }
        else{
            if(head1 !=NULL){
                temp->next = malloc(sizeof(ListNode));
                temp->next->num = head1->num;
                temp = temp->next;
                head1 = head1->next;
            }
            if(head2 !=NULL){
                temp->next = malloc(sizeof(ListNode));
                temp->next->num = head2->num;
                temp = temp->next;
                head2 = head2->next;
            }
        }
    }
    temp->next=NULL;
    return 0;
}

Other qns not on exam list(not impt)
1.insertDbl()
2.weird prac qns 1-4 on Dynamic Allocation thing

Stacks and Queues
1.createQueueFromLinkedList()+removeOddValues()   //assignment
//void createQueueFromLinkedList(LinkedList *ll,Queue *q){
    ListNode *temp;
    temp = ll->head;

    while(temp!=NULL){
        enqueue(q,temp->item);
        temp = temp->next;
    }
}

void removeOddValues(Queue *q){
    int num;
    Queue *temp = malloc(sizeof(Queue));
    temp->ll.head = NULL;
    temp->ll.size = 0;

    while(!isEmptyQueue(q)){
        num = dequeue(q);
        if(num%2!=0)continue;
        else{
            enqueue(temp,num);
        }
    }
    while(!isEmptyQueue(temp)){
        enqueue(q,dequeue(temp));
    }
    free(temp);
}

2.createStackFromLinkedList()+removeEvenValues()   //assignment
//void createStackFromLinkedList(LinkedList *ll,Stack *s){
    ListNode *temp;
    temp = ll->head;
    
    while(temp!=NULL){
        push(s,temp->item);
        temp = temp->next;
    }
}

void removeEvenValues(Stack *s){
    int num;
    Stack *temp = malloc(sizeof(Stack));
    (temp->ll).head = NULL;
    (temp->ll).size = 0;

    while(!isEmptyStack(s)){
        num = pop(s);
        if(num%2==0){
            continue;
        }
        else push(temp,num);
    }

    while(!isEmptyStack(temp)){
        push(s,pop(temp));
    }

    free(temp);
}

3.isStackPairwiseConsecutive()  //assignment
//int isStackPairwiseConsecutive(Stack *s){
    if(isEmptyStack(s)) return 0;

    while(!isEmptyStack(s)){
        if(abs(pop(s)-pop(s)) ==1){
            continue;
        }
        else return 0;
    }
    return 1;
}

4.reverseQueue()    //assignment
//void reverse(Queue *q){
    Stack *temp = malloc(sizeof(Stack));
    temp->ll.head =NULL;
    temp->ll.size=0;

    while(!isEmptyQueue(q)){
        push(temp,dequeue(q));
    }
    while(!isEmptyStack(temp)){
        enqueue(q,pop(temp));
    }
    free(temp);
}

5.removeUntil()     //lab
//void removeUntil(Stack *s,int value){
    while(!isEmptyStack(s)){
        if(peek(s)!=value)
            pop(s);
            else break;
    }
}

6.recursiveReverse()    //lab
//void recursiveReverse(Queue *q){
    int i;
    if(isEmptyQueue(q)) return;

    i = dequeue(q);
    recursiveReverse(q);
    enqueue(q,i);
}

7.palindrome()      //lab
//void palindrome(char *word){
    int i;
    Stack s; Queue q;
    s.ll.head = NULL;
    s.ll.tail = NULL;
    s.ll.size = 0;
    q.ll.head = NULL;
    q.ll.tail = NULL;
    q.ll.size = 0;

    printf("%s\n",word);
    while(*word){
        if(*word!=' '){
            push(&s, toupper(*word));
            enqueue(&q,toupper(*word));
        }
        word++;
    }

    i = s.ll.size/2;

    while(i>0){
        if(pop(&s)!=dequeue(&q)){               //compare back half(stack) and front half(queue)
            printf("The string is not a palindrome\n");
            return;
        }
        i--;
    }
    printf("The string is a palindrome\n");
}

8.balance()     //lab
//int balanced(char *expression){
    Stack s;
    s.ll.head = NULL;
    s.ll.tail = NULL;
    s.ll.size = 0;

    printf("%s\n",expression);

    while(*expression){
        if(*expression=='('||*expression=='['||*expression=='{'){
            push(&s, *expression);
        }
        else if(*expression==')'){
            if(isEmptyStack(&s)||pop(&s)!='(')
            return -1;
        }
        else if(*expression==']'){
            if(isEmptyStack(&s)||pop(&s)!='[')
            return -1;
        }
        else if(*expression=='}'){
            if(isEmptyStack(&s)||pop(&s)!='{')
            return -1;
        }
        expression++;
    }
    if(isEmptyStack(&s)) return 0;
    else
        return -1;
}

9.reverseStack()    //tutorial
//void reverseStack(Stack *s){
    Queue q;
    q.ll.head = NULL;
    q.ll.size = 0;
    q.ll.tail = NULL;

    while(!isEmptyStack(s)){
        enqueue(&q,pop(s));
    }
    while(!isEmptyQueue(&q)){
        push(s,dequeue(&q));
    }
}

10.reverseFirstKItems()     //tutorial
//void reverseFirstKItems(Queue *q,int k){
    Stack s;
    int i,j;
    if(k<=0)
        return;
    if(isEmptyQueue(q)||k>q->ll.size)
        return;
    
    s.ll.head = NULL;
    s.ll.tail = NULL;
    s.ll.size = 0;
    
    for(i=0;i<k;i++){
        push(&s,dequeue(q));
    }
    while(!isEmptyStack(&s)){
        enqueue(q,pop(&s));
    }
    j = q->ll.size; 

    for(i=0;i<j-k;i++){
        enqueue(q,dequeue(q));
    }
}

11.sortStack()      //tutorial      //draw out better
//void sortStack(Stack *s){
    int temp;
    Stack ts;
    ts.ll.head = NULL;
    ts.ll.tail = NULL;
    ts.ll.size = 0;

    while(!isEmptyStack(s)){
        push(&ts,pop(s));
    }
    while(!isEmptyStack(&ts)){
        temp = pop(&ts);

        while(!isEmptyStack(s) && peek(s)<temp){
            push(&ts,pop(s));
        }
        push(s,temp);
    }
}

Other qns
1.Prefix, PostFix, Infix

Binary Trees and Binary Search Trees
1.identical()   //assignment
//int identical(BTNode *tree1,BTNode *tree2){
    if(tree1==NULL&&tree2==NULL)
        return 1;
    if(tree1==NULL&&tree2!=NULL)
        return 0;
    if(tree1!=NULL&&tree2==NULL)
        return 0;
    if(tree1!=NULL&&tree2!=NULL)
    {
        return (tree1->item==tree2->item && identical(tree1->left,tree2->left) && 
        identical(tree1->right,tree2->right));
    }
}

2.maxHeight()   //prac qn
//int maxHeight(BTNode *node){
    int lheight,rheight;

    if(node==NULL){
        return -1;
    }
    else{
        lheight = maxHeight(node->left);
        rheight = maxHeight(node->right);

        if(lheight>rheight)
            return lheight+1;

        else{
            return rheight+1;
        }
    }
}

3.maxDepth()    //tutorial
//int maxDepth(BTNode *node){
    int ldepth,rdepth;
    
    if(node==NULL)
        return -1;
    
    else{
        ldepth = maxDepth(node->left);
        rdepth = maxDepth(node->right);

        if(ldepth>rdepth)
            return ledpth+1;
        else{
            return rdepth+1;
        }
    }
}

4.countOneChildNodes()  //prac qn
//int countOneChildNodes(BTNode *node){
    int count;
    count=0;
    if(node==NULL)
        return count;
    if((node->left==NULL && node->right!=NULL)||(node->left!=NULL && node->right==NULL))
    {    count = 1;
    }
    return(count + countOneChildNodes(node->left)+ countOneChildNodes(node->right));
}

5.sumOfOddNodes()   //prac qn
//int sumOfOddNodes(BTNode *node){
    int sum;
    if(node==NULL)
        return 0;
    sum = 0;
    if(abs(node->item)%2==1)
        sum = node->item;
    return(sum + sumOfOddNodes(node->left)+sumOfOddNodes(node->right));
}

6.mirrorTree()  //lab
//void mirrorTree(BTNode *node){
    BTNode *temp;

    if(node == NULL)
    return;

    temp = node->left;
    node->left = node->right;
    node->right = temp;
    mirrorTree(node->left);
    mirrorTree(node->right);
}

7.printSmallerValues()  //lab
//void printSmallerValues(BTNode *node,int m){
    if(node==NULL)return;
    
    if(node->item<m)
        printf("%d, ",node->item);
    printSmallerValues(node->left,m);
    printSmallerValues(node->right, m);

    return;
}

8.smallestValue()   //lab
//int smallestValue(BTNode *node){
    int l,r;
    if(node==NULL)
        return 10000;

    l = smallestValue(node->left);
    r = smallestValue(node->right);
    if(l<node->item && l<r)
        return l;
    else if(r<node->item && r<l)
        return r;
    else return node->item;
}

9.hasGreatGrandchild()  //lab
//int hasGreatGrandchild(BTNode *node){
    int l,r;

    if(node==NULL)
        return -1;

    l = hasGreatGrandchild(node->left);
    r = hasGreatGrandchild(node->right);

    if(r>l)
        l=r;
    if(l>1)                 //1 can be changed to other values and is the hieght of the node
        printf("%d ",node->item);

    return(l+1);
}

10.levelOrderTraversal()    //tutorial
//void levelOrderTraversal(BSTNode* root){
    Queue q;
    q.head = NULL;
    q.tail = NULL;
    BSTNode *temp;
    temp = root;

    if(temp!=NULL)
    {
        enqueue(&q.head,&q.tail,temp);
        while(!isEmpty(q.head))
        {
            temp = dequeue(&q.head,&q.tail);
            printf("%d",temp->item);
            if(temp->left!=NULL)
                enqueue(&q.head,&q.tail,temp->left);
            if(temp->right!=NULL)
                enqueue(&q.head,&q.tail,temp->right);
        }
    }
}

11.inOrderTraversal()   //assignment
//void inOrderTraversal(BSTNode *root){
    Stack s;
    s.top=NULL;
    BSTNode *cur;
    BSTNode *temp;

    cur=root;
    if(cur==NULL&&s.top==NULL)
    {
        return;
    }
    while(cur!=NULL)
    {
        push(&s,cur);
        cur=cur->left;
    }
    while(cur==NULL&&s.top!=NULL)
    {
        temp = pop(&s);
        printf("%d ",temp->item);
        cur = temp->right;
        while(cur!=NULL)
        {
            push(&s,cur);
            cur = cur->left;
        }
    }
}

12.preOrderIterative()  //tutorial
//void preOrderIterative(BSTNode *root){
    Stack s;
    s.top = NULL;
    BSTNode *temp;
    temp = root;

    if(temp==NULL)
        return;
    
    push(&s,temp);

    do{
        temp = pop(&s);
        printf("%d",temp->item);
        if(temp->right!=NULL)
            push(&s,temp->right);
        if(temp->left!=NULL)
            push(&s,temp->left);
    }(while !isEmpty(&s))   
}

13.postOrderIterativeS1()   //assignment
//void postOrderIterativeS1(BSTNode *root){
    Stack s;
    s.top = NULL;
    BSTNode *temp;

    if(root==NULL)
    {
        return;
    }

    do{
        while(root!=NULL)
        {
                if(root->right!=NULL)
                {
                    push(&s, root->right);
                }
                push(&s,root);
                root = root->left;
        }
        root = pop(&s);
        temp = root->right;

        if(temp!=NULL&&peek(&s)==temp)
        {
            pop(&s);
            push(&s, root);
            root=root->right;
        }
        else
        {
            printf("%d ",root->item);
            root=NULL;
        }
    }while(!isEmpty(&s));
}

14.postOrderIterativeS2()   //assignment
//void postOrderIterativeS2(BSTNode *root){
    Stack s1,s2;
    s1.top = NULL;
    s2.top = NULL;
    BSTNode *a;

    if(root==NULL)
    {
        return;
    }
    push(&s1, root);

    while(!isEmpty(&s1))
    {
        a = pop(&s1);
        if(a!=NULL)
        {
            push(&s2, a);
        }
        if(a->left!=NULL)
        {
            push(&s1, a->left);
        }
        if(a->right!=NULL)
        {
            push(&s1,a->right);
        }
    }
    while(!isEmpty(&s2))
    {
        printf("%d ",peek(&s2)->item);
        pop(&s2);
    }
}

15.printBSTInOrder()    //BST lab
//void printBSTInOrder(BSTNode *node){
    if(node==NULL)
        return;

    printBSTInOrder(node->left);
    printf("%d, ",node->item);
    printBSTInOrder(node->right);

    return;
}

16.isBST()  //BST lab
//int isBST(BSTNode *node,int min, int max){
    if(node==NULL)
        return 1;
    if(node->item>=max||node->item<=min)
        return 0;

    return isBST(node->left,min,node->item) && isBST(node->right,node->item,max);
}
*/