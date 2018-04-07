#include"stdio.h"
#include"stdlib.h"
#include<stdbool.h>
struct treeNode
{
	int data;
	struct treeNode *left;
	struct treeNode *right;	
}*root=NULL;
void insert(int d)
{
	struct treeNode *p= (struct treeNode *)malloc(sizeof(struct treeNode));
	if(p == NULL)
	return;
	if(root == NULL)
	{
		root=p;
		root->data=d;
		root->left=NULL;
		root->right=NULL;
		return;
	}
	struct treeNode *temp=root;
	while(1)
	{		
	if(temp->data > d)
	{
		if(temp->left == NULL)
		{
			temp->left=p;
			temp=temp->left;
			temp->data=d;
			temp->left=NULL;
			temp->right=NULL;
			return;
		}
		else
		temp=temp->left;
	}
	else
	{
		if(temp->right == NULL)
		{
			temp->right=p;
			temp=temp->right;
			temp->data=d;
			temp->left=NULL;
			temp->right=NULL;
			return;
		}
		else
		temp=temp->right;
	}
	}
}
void inOrder(struct treeNode *rt)
{
	if(rt==NULL)
	return;
	inOrder(rt->left);
	printf("%d\t",rt->data);
	inOrder(rt->right);
}
void preOrder(struct treeNode *rt)
{
	if(rt==NULL)
	return;
	printf("%d\t",rt->data);
	preOrder(rt->left);	
	preOrder(rt->right);
}
void postOrder(struct treeNode *rt)
{
	if(rt==NULL)
	return;	
	postOrder(rt->left);	
	postOrder(rt->right);
	printf("%d\t",rt->data);
}
int min(struct treeNode *rt)
{
	if(rt==NULL)
	return;
	while(rt->left != NULL)
	rt=rt->left;
	return rt->data;
}
int max(struct treeNode *rt)
{
	if(rt==NULL)
	return;
	while(rt->right != NULL)
	rt=rt->right;
	return rt->data;
}
struct treeNode* delete(struct treeNode * rt,int key)
{
	if(rt==NULL)
	return rt;
	if(key<rt->data)
	rt->left=delete(rt->left,key);
	else if(key>rt->data)
	rt->right=delete(rt->right,key);
	else
	{
		//Leaf Node
		if(rt->left == NULL && rt->right == NULL)
		{
			struct treeNode *temp=rt;
			rt=NULL;
			free(temp);			
		}
		//Left Child only
		else if(rt->right == NULL)
		{
			struct treeNode *temp=rt;			
			rt=rt->left;
			free(temp);
		}
		//Right child only
		else if(rt->left == NULL)
		{
			struct treeNode *temp=rt;
			rt=rt->right;
			free(temp);
		}
		//Full Node
		else
		{
		rt->data=max(rt->left);		
		rt->left=delete(rt->left,rt->data);	
		}			
	}
	return rt;
}
int countLeaves(struct treeNode *rt)
{
	if(rt == NULL)
	return 0;
	if(rt->left == NULL && rt->right == NULL)
	return 1;
	else
	return countLeaves(rt->left)+countLeaves(rt->right);
}
int countFullNodes(struct treeNode *rt)
{
	if(rt == NULL)
	return 0;
	if(rt->left == NULL && rt->right == NULL)
	return 0;
	else if(rt->left != NULL && rt->right != NULL)
	return 1+countFullNodes(rt->left)+countFullNodes(rt->right);
	else
	return countFullNodes(rt->left)+countFullNodes(rt->right);
}
int countHalfNodes(struct treeNode *rt)
{
	if(rt == NULL)
	return 0;
	if(rt->left == NULL && rt->right == NULL)
	return 0;
	else if(rt->left != NULL && rt->right != NULL)
	return countHalfNodes(rt->left)+countHalfNodes(rt->right);
	else
	return 1+countHalfNodes(rt->left)+countHalfNodes(rt->right);
}
bool search(struct treeNode *rt,int key)
{
	if(rt == NULL)
	return false;
	if(rt->data < key)
	search(rt->right,key);
	else if(rt->data > key)
	search(rt->left,key);
	else
	return true;
}
int main(void)
{
	printf("Demonstration of Binary Search Tree in C\n@Nishant Amoli, B.Tech IT\n\n");
	insert(10);
	insert(15);
	insert(6);
	insert(11);
	insert(5);
	insert(1);
	insert(3);
	insert(20);
	printf("inOrder traversal:\n");
	inOrder(root);
	printf("\npreOrder traversal:\n");
	preOrder(root);
	printf("\npostOrder traversal:\n");
	postOrder(root);
	printf("\n\nMinimum:\t%d",min(root));
	printf("\nMaximum:\t%d\n",max(root));
	root=delete(root,1);
	printf("\nAfter deletion:\n");
	printf("\ninOrder traversal:\n");	
	inOrder(root);
	printf("\npostOrder traversal:\n");
	postOrder(root);
	printf("\npreOrder traversal:\n");
	preOrder(root);
	printf("\nNo. of leaf nodes:\t%d\n",countLeaves(root));
	printf("\nNo. of full nodes:\t%d\n",countFullNodes(root));
	printf("\nNo. of half nodes:\t%d\n",countHalfNodes(root));
	bool flag=search(root,11);
	if(flag)
	printf("\nThe key is present.\n");
	else
	printf("\nThere is no such element in the Binary Search Tree.\n");
}
