#include"stdio.h"
#include"stdlib.h"
struct node
{
	int data;
	struct node *next;
}*head=NULL,*tail=NULL;
void insert(int d)
{
	struct node *p=(struct node*)malloc(sizeof(struct node));
	if(head==NULL)
	{
		head=p;
		head->data=d;
		head->next=NULL;
		tail=head;		
	}
	else
	{
		tail->next=p;
		tail=p;
		tail->data=d;
		tail->next=NULL;		
	}
}
void display()
{
	if(head==NULL)
	return;
	else
	{
		struct node *temp=head;
		while(temp)
		{
			printf("%d ",temp->data);
			temp=temp->next;
		}
	}
}
void delete(int d)
{
	if(head==NULL)
	return;
	else if(head->data==d)
	{
		struct node * temp=head;
		head=head->next;
		free(temp);
	}
	else if(tail->data==d)
	{
		struct node * temp=head;
		while(temp->next != tail)
		temp=temp->next;
		tail=temp;
		free(tail->next);	
		tail->next=NULL;			
	}
	else
	{
		struct node * temp=head;
		while(temp->next->data!=d)
		temp=temp->next;
		struct node * temp2=temp->next;
		temp->next=temp->next->next;
		free(temp2);
		
	}
}
int main(void)
{
	printf("Demonstration of Singly Link List in C\n@Nishant Amoli, B.Tech IT\n");
	insert(1);
	insert(2);
	insert(3);
	insert(4);
	insert(5);
	insert(6);
	insert(7);
	printf("1st display:\n");
	display();
	delete(1);
	delete(7);
	delete(5);
	printf("\n2nd display:\n");
	display();
	printf("\ntail.data: %d",tail->data);
}
