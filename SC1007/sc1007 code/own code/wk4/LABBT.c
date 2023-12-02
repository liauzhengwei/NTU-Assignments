////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

////////////////////////////////////////////////////////////////////


typedef struct _btnode{
	int item;
	struct _btnode *left;
	struct _btnode *right;

} BTNode;

////////////////////////////////////////////////////////////////////


void mirrorTree(BTNode *node);

void printSmallerValues(BTNode *node, int m);
int smallestValue(BTNode *node);
int hasGreatGrandchild(BTNode *node);

void printTree_InOrder(BTNode *node);

////////////////////////////////////////////////////////////////////

int main(int argc, const char * argv[]){

	int i;
	BTNode *root, *root2;
	BTNode btn[15];

	// Create the tree in Q1
	// Using manual dynamic allocation of memory for BTNodes

	root = malloc(sizeof(BTNode));
	root->item = 4;

	root->left = malloc(sizeof(BTNode));
	root->left->item = 5;

	root->right = malloc(sizeof(BTNode));
	root->right->item = 2;

	root->left->left = NULL;

	root->left->right = malloc(sizeof(BTNode));
	root->left->right->item = 6;

	root->left->right->left = NULL;
	root->left->right->right = NULL;

	root->right->left = malloc(sizeof(BTNode));
	root->right->left->item = 3;

	root->right->right = malloc(sizeof(BTNode));
	root->right->right->item = 1;

	root->right->left->left = NULL;

	root->right->left->right = NULL;

	root->right->right->left = NULL;

	root->right->right->right = NULL;

	printTree_InOrder(root);
	printf("\n");
	mirrorTree(root);
	printTree_InOrder(root);
	printf("\n\n");

	//question 2
	printf("\n input m for question 2:");
	scanf("%d", &i);
	printf("the values smaller than %d are:", i);
	printSmallerValues(root, i);
	printf("\n\n");

	//question 3
	printf("The smallest value in the tree is %d:\n", smallestValue(root));

	//question 4
	// Create a tree for Q4: Tall enough so some nodes have great-grandchildren
	// Use array of BTNodes, create tree by linking nodes together
	for (i = 0; i <= 6; i++){
		btn[i].item = i;
		btn[i].left = &(btn[i * 2 + 1]);
		btn[i].right = &(btn[i * 2 + 2]);
	}

	for (i = 7; i <= 14; i++){
		btn[i].item = i;
		btn[i].left = NULL;
		btn[i].right = NULL;
	}
	root2 = &btn[0];

	printf("The tree for question 4 visited by in-order is \n");
	printTree_InOrder(root2);
	printf("\nthe values stored in all nodes of the tree that have at least one great-grandchild are: ");

	hasGreatGrandchild(root2);

	return 0;
}

void mirrorTree(BTNode *node){
    //in order traversal used
	BTNode *temp;

	if(node==NULL)
    {
        return;
    }

    mirrorTree(node->right);
    mirrorTree(node->left);

    temp = node->right;
    node->right = node->left;
    node->left=temp;

}

int hasGreatGrandchild(BTNode *node){

	BTNode *temp;

	temp=node;

	if(temp==NULL)
    {
        return;
    }

    if(temp->left!=NULL||temp->right!=NULL)
    {
        if(temp->left->left!=NULL||temp->left->right!=NULL||temp->right->right!=NULL||temp->right->left!=NULL)
        {
            if(temp->left->left->left!=NULL||temp->left->left->right!=NULL||temp->left->right->left!=NULL||
            temp->left->right->right!=NULL||temp->right->right->right!=NULL||temp->right->right->left!=NULL
            ||temp->right->left->right!=NULL||temp->right->left->left!=NULL)
            {
                printf("%d",temp->item);
            }
        }
    }
    hasGreatGrandchild(temp->left);
    hasGreatGrandchild(temp->right);

    return;
}

void printSmallerValues(BTNode *node, int m){
    int a;
	BTNode *temp;

	if(node==NULL)
    {
        return;
    }
    a = node->item;

    printSmallerValues(node->right,m);
    printSmallerValues(node->left,m);

    if(a<m)
    {
        printf("%d",a);
    }


}

int smallestValue(BTNode *node) {
	//int l, r;
    BTNode *temp;

    temp = node;
    if(temp==NULL)
    {
        return;
    }

    while(temp->right!=NULL)
    {
        temp = temp->right;
    }

    return temp->item;
}


//////////////////////////////////////////////////////////////////

void printTree_InOrder(BTNode *node){

	if (node == NULL) return;
	printTree_InOrder(node->left);
	printf("%d, ", node->item);
	printTree_InOrder(node->right);
	return;
}
