
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void create();
void display();
void insertpos(int);
void insert_beg();
void delete();
void delpos(int);
void del_beg();
struct node
{
    int sem,usn;
    char name[20];
    struct node *next;
};

struct node *head=NULL;
int count=0;
int main()
{
    int choice,ele,a;
    
    do
    {
    printf("\n1.Insert at the end \n2.Insert at the beginning  \n3. Insert at a position \n4.Delete at the end \n5.Delete at the beginning \n6.Delete at a position \n7.Display\n8.Exit");
    printf("\nEnter your choice : ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1: create(); break;
        case 2:insert_beg();
        break;
        case 3: printf("Enter the position to be inserted\n");
                scanf("%d",&ele);
                insertpos(ele);
                break;
        case 4:delete();break;
        case 5:del_beg();break;
        case 6:printf("Enter the position to be deleted in");
        scanf("%d",&a);
        delpos(a);
        
        break;
        case 7:display();
        break;
        
        case 8:exit(0);
    }
	
    }while(choice!=8);
}

void create()
{
   struct node *newnode,*temp;
    int sem1,usn1;
    char name1[20];
    printf("Enter the name USN semester of student : ");
    scanf("%s %d %d",name1,&usn1,&sem1);
    newnode =(struct node *) malloc (sizeof(struct node));
    
    strcpy(newnode->name,name1);
    newnode->usn=usn1;
    newnode->sem=sem1;
    if (head==NULL)
     { 
       newnode->next=NULL;
      head=newnode; 
      printf("Node created\n");
     }
     else 
    {
    temp=head;
       while(temp->next!=NULL)
       {
                temp=temp->next;
        }
      temp->next=newnode;
      newnode->next=NULL;
       printf("Node created\n");
       count++;
   }  
}

void display()
{
    struct node *ptr=NULL;
    ptr=head;
     
    if(ptr==NULL)
    {
        printf("Nothing to print\n");
    }
    else
    {
        while(ptr!=NULL)
       {
        printf("%s ",ptr->name);
        printf("%d ",ptr->usn);
        printf("%d ",ptr->sem);
        printf("\n");
        ptr=ptr->next;
       }
    }
    
}

void insertpos(int p)
{
    struct node *newnode;
    int sem1,usn1;
    char name1[20];
    if(count+2<p)
	printf("the position exceeds the number of nodes");
	else if(head==NULL&& p>1)
    {
      printf("node empty enter in first position");  
    }
	else
	{
    printf("Enter the name USN semester of student : ");
    scanf("%s %d %d",name1,&usn1,&sem1);
    newnode =(struct node *) malloc (sizeof(struct node));
    
    strcpy(newnode->name,name1);
    newnode->usn=usn1;
    newnode->sem=sem1;
    
    
    
    if(p==1)
    {
		printf("inserted at the beginning\n");
		newnode->next=head;
		head=newnode;
		count++;
		
	}
    
	else
	{
	    
	   
	    int i;
		struct node *temp1;
		temp1=head;
		for(i=2;i<p;i++)
		{
		temp1= temp1->next;
		}
		newnode->next=temp1->next;
		temp1->next=newnode;
		
		printf("Node inserted at %d position in linked list\n",p);
		count++;
	    }
	}
}

 void insert_beg()
 {
    struct node *newnode;
    int sem1,usn1;
    char name1[20];
    printf("Enter the name USN semester of student : ");
    scanf("%s %d %d",name1,&usn1,&sem1);
    newnode =(struct node *) malloc (sizeof(struct node));
    
    strcpy(newnode->name,name1);
    newnode->usn=usn1;
    newnode->sem=sem1;
    newnode->next=head;
    head=newnode;
    count++;
 }
 
void delete()
 {
     struct node *temp=NULL;
     int sem1,usn1;
    char name1[20];
     if(head==NULL)
     printf("linked list is empty");
     else
     {
         temp=head;
         while(temp->next->next!=NULL)
         {
             temp=temp->next;
         }
         strcpy(name1,temp->next->name);
         sem1=temp->next->sem;
         usn1=temp->next->usn;
         printf("the student info deleted = %s %d %d",name1,usn1,sem1);
         temp->next=NULL;
         count--;
     }
 }
 
 
 void del_beg()
{
    struct node *temp=NULL;
    int sem1,usn1;
    char name1[20];
    if(head==NULL)
     printf("linked list is empty");
     else
     {
         strcpy(name1,head->name);
         sem1=head->sem;
         usn1=head->usn;
         printf("the student info deleted = %s %d %d",name1,usn1,sem1);
        temp=head;
        head=temp->next;
        free(temp);
        count--;
     }
} 
void delpos(int p)
{
    struct node *temp=NULL;
    int sem1,usn1;
    char name1[20];
    if(head==NULL)
     printf("linked list is empty");
     else if(count+1<p)
    printf("the position exceeds the number of nodes");
    else if(p==1)
    {
        strcpy(name1,head->name);
         sem1=head->sem;
         usn1=head->usn;
         printf("the student info deleted = %s %d %d",name1,usn1,sem1);
        temp=head;
        head=temp->next;
        free(temp);
        count--;
    }
    else 
    {
        int i;
		struct node *temp,*ptr;
		temp=head;
		for(i=2;i<p;i++)
		{
		temp= temp->next;
		}
		 
         strcpy(name1,temp->next->name);
         sem1=temp->next->sem;
         usn1=temp->next->usn;
         printf("the student info deleted = %s %d %d",name1,usn1,sem1);
         ptr=temp->next;
         temp->next=temp->next->next;
         free(ptr);
         count--;
    }
    
}
