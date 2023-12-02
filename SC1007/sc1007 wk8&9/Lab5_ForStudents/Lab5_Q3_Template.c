#include <stdio.h>
#include <stdlib.h>

#define LOAD_FACTOR 3

typedef struct _listnode{
    int key;
    struct _listnode *next;
} ListNode;

typedef struct _linkedlist{
   int size;
   ListNode *head;
} HashTableNode;

typedef struct _hashTable{
   int hSize;
   int nSize;
   HashTableNode *Table;
} HashTable;

int Hash(int,int);

ListNode* HashSearch(HashTable, int);
int HashInsert(HashTable *, int);

//In Practice, we will not do it
void HashPrint(HashTable);

int main()
{
    int opt;
    int size;

    int i;
    int key;

    //Create a HashTable
    HashTable Q3Hash;
    Q3Hash.hSize = 0;
    Q3Hash.nSize = 0;
    Q3Hash.Table = NULL;

    printf("============= Hash Table ============\n");
    printf("|1. Create a hash table             |\n");
    printf("|2. Insert a key to the hash table  |\n");
    printf("|3. Search a key in the hash table  |\n");
    printf("|4. Print the hash table            |\n");
    printf("|5. Quit                            |\n");
    printf("=====================================\n");

    printf("Enter selection: ");
    scanf("%d",&opt);
    while(opt>=1 && opt <=4){
        switch(opt){
        case 1:
            printf("Enter number of data to be inserted:\n");
            scanf("%d",&size);

            Q3Hash.hSize = (int)size/ LOAD_FACTOR;
            Q3Hash.nSize = 0;

            Q3Hash.Table = (HashTableNode *) malloc(sizeof(HashTableNode)*(Q3Hash.hSize));

            for(i=0;i<Q3Hash.hSize;i++){
               Q3Hash.Table[i].head = NULL;
               Q3Hash.Table[i].size = 0;
            }
            printf("HashTable is created.\n");
            break;
        case 2: //Insertion
            printf("Enter a key to be inserted:\n");
            scanf("%d",&key);

            if(HashInsert(&Q3Hash,key))
                printf("%d is inserted.\n",key);
            else
                printf("%d is a duplicate. No key is inserted.\n",key);
            break;
        case 3: //Search
            printf("Enter a key for searching in the HashTable:\n");
            scanf("%d",&key);
            ListNode* node = HashSearch(Q3Hash, key);

            if(node!=NULL)
                printf("%d is found.\n",key);
            else
                printf("%d is not found.\n",key);
            break;
        case 4:
            HashPrint(Q3Hash);
            break;
        }

    printf("Enter selection: ");
    scanf("%d",&opt);
    }

    for(i=0;i<Q3Hash.hSize;i++)
    {
        while(Q3Hash.Table[i].head)
        {
            ListNode *temp;
            temp = Q3Hash.Table[i].head;
            Q3Hash.Table[i].head = Q3Hash.Table[i].head->next;
            free(temp);
        }
    }
    free(Q3Hash.Table);

    return 0;

}

int Hash(int key,int hSize)
{
    return key%hSize;
}

ListNode* HashSearch(HashTable Q3Hash, int key)
{
    int index = Hash(key,Q3Hash.hsize);         //get index with hash function
    ListNode *temp = Q3Hash.Table[index].head;  //temp ListNode for head of LL

    while(temp!=NULL){          //key search via node traversal
        if(temp->key ==key)
            return temp;
        temp = temp->next;
    }
    return NULL;
}

int HashInsert(HashTable* Q3HashPtr, int key)   //similar to insertNode
{
    HashTable Q3Hash = *Q3HashPtr;
    if(HashSearch(Q3Hash,key)!=NULL)
        return 0;
    
    int index = Hash(key,Q3Hash.hSize);
    ListNode *newNode = (ListNode*)malloc(sizeof(ListNode));
    newNode->key=key;
    newNode->next = Q3Hash.Table[index].head;
    Q3Hash.Table[index].head = newNode;
    Q3Hash.Table[index].size++;
    Q3Hash.nSize++;

    //resize hash table if needed
    if((float)Q3Hash.nSize/Q3Hash.hSize >LOAD_FACTOR)   
    {
        HashTableNode *oldTable = Q3Hash.Table;
        int oldSize = Q3Hash.hSize;

        Q3Hash.hSize = Q3Hash.hSize*2+1;    //increase the hsize
        Q3Hash.nSize = 0;
        Q3Hash.Table = (HashTableNode *)malloc(sizeof(HashTableNode)*(Q3Hash.hSize));   //allocate memory

        int i;
        for(i=0;i<Q3Hash.hSize;i++)         //clear the hashtable and change size to 0 
        {
            Q3Hash.Table[i].head = NULL;
            Q3Hash.Table[i].size = 0;
        }

        for(i=0;i<oldSize;i++)                  //reinsert everything from the old HashTable
        {
            ListNode *temp = oldTable[i].head;
            while(temp!=NULL)
            {
                HashInsert(&Q3Hash,temp->key);
                ListNode *temp2 = temp;
                temp = temp->next;
                free(temp2);
            }
        }
        free(oldTable);
    }
    *Q3HashPtr = Q3Hash;
    return 1;
}

void HashPrint(HashTable Q3Hash)
{
    int i;
    ListNode *temp;
    for(i=0;i<Q3Hash.hSize;i++)
    {
        temp =Q3Hash.Table[i].head;
        printf("%d:  ",i);
        while(temp !=NULL)
        {
            printf("%d -> ", temp->key);
            temp = temp->next;
        }
        printf("\n");
    }
}
