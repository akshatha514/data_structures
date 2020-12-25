#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
	struct node *prev;
};
struct node *head=NULL;

void insert_left()
{
	 struct node *new_node;
	 new_node=(struct node*)malloc(sizeof(struct node));
	 printf("Enter the data\n");
	 scanf("%d",&new_node->data);
	 new_node->next=NULL;
	 new_node->prev=NULL;

	 if(head==NULL)
	 {
			head=new_node;
	 }
	 else
	 {
			new_node->next=head;
			head->prev=new_node;
			head=new_node;
	 }

}
void insert_right()
{
	struct node *new_node,*temp;
	new_node=(struct node*)malloc(sizeof(struct node));
	printf("Enter the data\n");
	scanf("%d",&new_node->data);
	new_node->next=NULL;
	new_node->prev=NULL;
	if(head==NULL)
	{
		head=new_node;
	}
	else
	{
		 temp=head;
		 while(temp->next!=NULL)
		 temp=temp->next;
		 temp->next=new_node;
		 new_node->prev=temp;

	}

}
void insert_leftnode()
{
    if(head==NULL)
    {
        printf("The list is empty\n"); return;
    }
	int ele;
	struct node *new_node,*temp;
	printf("Enter the element in the list after which you want to enter\n");
	scanf("%d",&ele);
	new_node=(struct node*)malloc(sizeof(struct node));
	printf("Enter the data of the new node\n");
	scanf("%d",&new_node->data);
	new_node->next=NULL;
	new_node->prev=NULL;
    
	temp=head;
	if(temp->data==ele)
	{
	    new_node->next=head;
			head->prev=new_node;
			head=new_node;
	}
	else if(temp->next==NULL)
	{
	    printf("Element was not found in the list\n");
	}
	else
	{
	while(temp->next->data!=ele)
	{
		temp=temp->next;
		if(temp==NULL)
		{
			printf("Element was not found in the list\n");
			return;
		}
	}
	
	new_node->next=temp->next;
	temp->next=new_node;
	new_node->prev=temp;
	new_node->next->prev=new_node;
	}
	 
	
}
void delete()
{
	struct node *temp;
	int ele;
    if(head==NULL)
    {
        printf("The list is empty \n");
        return;
    }
	printf("Enter the element to be deleted\n");
	scanf("%d",&ele);
	temp=head;
	while(temp->data!=ele)
	{
		temp=temp->next;
		if(temp==NULL)
		{
		 printf("Element was not found in the list\n");
		 return;
		}
	 }
	 if(temp==head)  
	 {
		 head=head->next;
	 }
	 else if(temp->next==NULL)
	 {
			temp=temp->prev;
			temp->next=NULL;
	 }

	 else 
	 {
		 temp->prev->next=temp->next;
		 temp->next->prev=temp->prev;
		 free(temp);
	 }
	 
}
void display()
{
    if(head==NULL)
    {
        printf("List is empty \n");
    }
	 else
	 {
	     struct node *temp;
	 temp=head;
	 while(temp!=NULL)
	 {
		 printf("%d\t",temp->data);
		 temp=temp->next;
	 }
	 printf("\n");
	 }
}


int main()
{
	int choice;
    do
	 {
			printf(" 1. Insert at the left \n");
			printf(" 2. Insert at the left of a specific node \n");
			printf(" 3. Insert at the right \n");
			printf(" 4. Delete a specific value\n");
			printf(" 5. Display\n");
			printf(" 6. Exit\n");
			printf("Enter your choice\n");
			scanf("%d",&choice);
			switch(choice)
			{
				 case 1: insert_left(); break;
				 case 2: insert_leftnode(); break;
				 case 3: insert_right(); break;
				 case 4: delete(); break;
				 case 5: display(); break;
				 case 6: exit(0);
			}
	 }while(choice!=6);
}

