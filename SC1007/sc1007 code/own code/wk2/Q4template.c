
#include <stdio.h>
#include <stdlib.h>

typedef struct _listnode{
    int item;
    struct _listnode *next;
} ListNode;


void printList(ListNode *cur);
ListNode * findNode(ListNode *cur, int index);
int insertNode(ListNode **ptrHead, int index, int item);
void deleteList(ListNode **ptrHead);
int duplicateReverse(ListNode *cur,ListNode **ptrNewHead);

int main()
{
    ListNode *head=NULL;
    ListNode *dupRevHead=NULL;
    int size =0;
    int item;

    printf("Enter a list of numbers, terminated by any non-digit character: \n");
    while(scanf("%d",&item))
        if(insertNode(&head,size, item)) size++;
    scanf("%*s");

    printf("\nBefore duplicateReverse() is called:\n");
    printList(head);

    duplicateReverse(head,&dupRevHead);

    printf("\nAfter duplicateReverse() was called:\n");
    printf("The original list:\n");
    printList(head);
    printf("The duplicated reverse list:\n");
    printList(dupRevHead);

    if(head!=NULL)
       deleteList(&head);
    if(dupRevHead)
       deleteList(&dupRevHead);

    return 0;
}

void printList(ListNode *cur){
    printf("Current List: ");
    while (cur != NULL){
        printf("%d ", cur->item);
        cur = cur->next;
    }
    printf("\n");
}

ListNode *findNode(ListNode* cur, int index)
{
   if (cur==NULL || index<0)
      return NULL;
   while(index>0){
      cur=cur->next;
      if (cur==NULL)
         return NULL;
      index--;
   }
   return cur;
}

int insertNode(ListNode **ptrHead, int index, int item){
    ListNode  *pre, *newNode;
    // If empty list or inserting first node, update head pointer
    if (index == 0){
        newNode = malloc(sizeof(ListNode));
        newNode->item = item;
        newNode->next = *ptrHead;
        *ptrHead = newNode;
        return 1;
    }
    // Find the nodes before and at the target position
    // Create a new node and reconnect the links
    else if ((pre = findNode(*ptrHead, index-1)) != NULL){
        newNode = malloc(sizeof(ListNode));
        newNode->item = item;
        newNode->next = pre->next;
        pre->next = newNode;
        return 1;
    }
    return 0;
}

void deleteList(ListNode **ptrHead){
    ListNode *cur = *ptrHead;
    ListNode *temp;
    while (cur!= NULL) {
        temp=cur->next;
        free(cur);
        cur=temp;
    }
    *ptrHead=NULL;
}

int duplicateReverse(ListNode *cur,ListNode **ptrNewHead)
{
    //get index of last node
    //make that the head
    //get index of second last node
    //repeat until index==-1
    int b=0;
    int count=0;
    int c=0;
    ListNode *curl;
    ListNode *cur2;
    int a=0;
    ListNode *j;

    curl = cur;
    while(curl!=NULL)
    {
        count++;
        curl = curl->next;
    }

    printf("%d count\n",count);
    curl=cur;

    c=count-1;

    while(c!=-1)
    {

        //get values in reverse order
        j = findNode(curl,c);
        a = j->item;
        printf("%d gii\n",c);
        printf("%d adr\n",a);

        insertNode(ptrNewHead,b,a); //get the last node and move backwards, inserting its value in a new linked list

        b++;
        c--;
    }

}
