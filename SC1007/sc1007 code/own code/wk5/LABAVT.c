//////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

///////////////////////////////////////////////////////////////////////

typedef struct _btnode{
int item;
struct _btnode *left;
struct _btnode *right;
} BTNode;

///////////////////////////////////////////////////////////////////////

void insertBSTNode(BTNode **node, int value);
void printBSTInOrder(BTNode *node);
int isBST(BTNode *node, int min, int max);
BTNode *removeBSTNode(BTNode *node, int value);

//BSTs are a form a BT where the data is sorted and there are no duplicates

///////////////////////////////////////////////////////////////////////

int main(){
	int i=0;

	BTNode *root=NULL;

	//question 1
	do{
		printf("input a value you want to insert(-1 to quit):");

		scanf("%d",&i);
		if (i!=-1)
			insertBSTNode(&root,i);
	}while(i!=-1);

	//question 2
	printf("\n");
	printBSTInOrder(root);

	//question 3
	if ( isBST(root,-1000000, 1000000)==1)
		printf("It is a BST!\n");
	else
		printf("It is not a BST!\n");

	//question 4
	do{
		printf("\ninput a value you want to remove(-1 to quit):");
		scanf("%d",&i);
		if (i!=-1)
		{
			root=removeBSTNode(root,i);
			printBSTInOrder(root);
		}
	}while(i!=-1);


	return 0;
}

//////////////////////////////////////////////////////////////////////

void insertBSTNode(BTNode **node, int value)
{
	if(*node ==NULL)
    {
        *node = malloc(sizeof(BSTNode));

        if(*node!=NULL){
            (*node)->item = value;
            (*node)->left = NULL;
            (*node)->right = NULL;
        }
    }
    else
    {
        if(value < (*node)->item)
        {
            insertBSTNode(&((*node)->left),value);
        }
        else if(value>(*node)->item)
        {
            insertBSTNode(&((*node)->right),value);
        }
        else
            return;
    }
}

//////////////////////////////////////////////////////////////////////

void printBSTInOrder(BTNode *node)
{
	BTNode *cur;

	cur = node;

	if(cur==NULL)
        return;

    printBSTInOrder(cur->left);
    printf("%d",cur->item);
    printBSTInOrder(cur->right);
    return;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int isBST(BTNode *node, int min, int max) // the item stored in node has to be smaller than max and larger than min
{
	if(node==NULL)
        return;

    int cur;

    cur = node->item;
    min = node->left->item;
    max = node->right->item;

    if(min<cur&&cur<max||min<cur&&max==NULL||min==NULL&&cur<max||min==NULL&&max==NULL)
    {
        isBST(BTNode node->left, int min, int max);
        isBST(BTNode node->right, int min, int max);
    }
    else
    {
        return -1;
    }
    return 1;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

BTNode *removeBSTNode(BTNode *node, int value) //prob wrong, look at slides
{
	BTNode *temp;

	if(node==NULL)
        return;

    else if(node->left==NULL&&node->right==NULL)
    {
        free(node);
        node=NULL;
    }
    //x has one child y, replace x with y
    else if(node->left==NULL&&node->right!=NULL)
    {
        node->item = node->right->item;
        removeBSTNode(node->right, node->right->item);
    }
    else if(node->left!=NULL&&node->right==NULL)
    {
        node->item = node->left->item;
        removeBSTNode(node->left, node->left->item);
    }
    //x has two children, swap x with successor and perform case 1 or 2 to remove it
    //successor is the leftest node in the right subtree
    else if(node->left!=NULL&&node->right!=NULL)
    {
        temp = node->right;
        while(temp!=NULL)
        {
            temp = temp->left;
        }
        node->item = temp->item;
        removeBSTNode(temp,temp->item);
        //create temp node, while temp->next!=NULL, go to node->left
        //if that node has no child, do case 1, if it has 1 child, do case 2
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
