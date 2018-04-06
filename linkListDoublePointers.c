#include"stdio.h"
#include"stdlib.h"
struct node
{
	int data;
	struct node *next;
};
void insert(struct node **h,struct node **t,int d)
{
	struct node *p=(struct node*)malloc(sizeof(struct node));
	if(*h==NULL)
	{
		*h=p;
		(*h)->data=d;
		(*h)->next=NULL;
		*t=*h;		
	}
	else
	{
		(*t)->next=p;
		*t=p;
		(*t)->data=d;
		(*t)->next=NULL;		
	}
}
void display(struct node **h)
{
	if(*h == NULL)
	return;
	struct node *temp=*h;
	while(temp)
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}
}
void delete(struct node **h,struct node **t,int d)
{
	if(*h==NULL)
	return;
	else if((*h)->data==d)
	{
		struct node * temp=*h;
		*h=(*h)->next;
		free(temp);
	}
	else if((*t)->data==d)
	{
		struct node * temp=*h;
		while(temp->next != *t)
		temp=temp->next;
		*t=temp;
		free((*t)->next);	
		(*t)->next=NULL;			
	}
	else
	{
		struct node * temp=*h;
		while(temp->next->data!=d)
		temp=temp->next;
		struct node * temp2=temp->next;
		temp->next=temp->next->next;
		free(temp2);
		
	}
}
int main(void)
{
	printf("Demonstration of Singly Link List using double pointers in C\n@Nishant Amoli, B.Tech IT\n");
	struct node *head=NULL,*tail=NULL;
	insert(&head,&tail,1);
	insert(&head,&tail,2);
	insert(&head,&tail,3);
	insert(&head,&tail,4);
	insert(&head,&tail,15);
	display(&head);
	delete(&head,&tail,4);
	printf("\n");
	display(&head);
	return;
}
