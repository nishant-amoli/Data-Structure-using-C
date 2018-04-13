#include"stdio.h"
#include"stdlib.h"
#include<stdbool.h>
struct treeNode
{
	int data;
	struct treeNode *left;
	struct treeNode *right;	
};
void insert(struct treeNode **rt,int d)
{
  struct treeNode *p=(struct treeNode *) malloc(sizeof(struct treeNode));
  if(p == NULL)
    return;
  p->data = d;
  p->left = p->right = NULL;
  //Iterative Code
  if(*rt==NULL)
  {
    *rt=p;
    return;
  }
  struct treeNode *temp=*rt;
  while(true)
  {
    if(d < temp->data)
    {
      if(temp->left==NULL)
      {
        temp->left=p;
        return;
      }
      else
        temp=temp->left;
    }
    else
    {
      if(temp->right==NULL)
      {
        temp->right=p;
        return;
      }
      else
        temp=temp->right;
    }
  }
	//Recursive Code
	/*else
	{
		if(d < (*rt)->data)
		insert(&(*rt)->left,d);
		else
		insert(&(*rt)->right,d);
	}*/
}
void inOrder(struct treeNode *rt)
{
	if(rt==NULL)
	return;
	inOrder(rt->left);
	printf("%d\t",rt->data);
	inOrder(rt->right);
}
int main(void)
{
	printf("Demonstration of Insertion in a Binary Search Tree using Double Pointers in C\n@Nishant Amoli, B.Tech IT\n\n");
	struct treeNode *root=NULL;
	insert(&root,10);
	insert(&root,15);
	insert(&root,6);
	insert(&root,11);
	insert(&root,5);
	insert(&root,7);
	insert(&root,20);
	printf("inOrder traversal:\n");
	inOrder(root);
	return 0;
}
