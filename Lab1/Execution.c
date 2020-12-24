#include <stdio.h>
#define size 3
int top=-1;
void push(int [], int);
int pop(int[]);
void display(int []);
void main()
{
	int stack[size];
    int choice,element;
    char ch;
    do
    {
    printf("Enter your choice\n");
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Display\n");
    printf("4.Exit\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1: printf("Enter the element to be pushed \n");
                scanf("%d",&element);
                push(stack,element);
                break;
        case 2: element=pop(stack);
                if(element==-1)
                    printf("Stack Underflow");
                else
                   printf("Poped element is %d \n",element);
                break;
        case 3: display(stack);
                break;
        case 4: 
                break;
        default: printf("Invalid choice\n");
    }
    }while(choice!=4);
    
	
}

void push(int stack[], int ele)
{
    if (top==size-1)
    {
        printf("Stack overflow");
    }
    else
    {
        top++;
        stack[top]=ele;
    }
}

int pop(int stack[])
{
    int popele;
    if(top==-1)
    
       return -1;
      
    else
    {
        popele=stack[top];
        top--;
        return (popele);
    }
     
     
}

void display(int stack[])
{
    int i;
    printf("The stack elemements\n");
    for(i=top;i>=0;i--)
    {
        
        printf("%d\t",stack[i]);
    }
}
