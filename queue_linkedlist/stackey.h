#include <stdio.h>
#include <stdlib.h>

/*LIFO*/
struct node
{
  int data;
  struct node *ptr;
}*front, *rear, *temp;


void create_stack();
int size_stack();
void push(int data);
void display_stack();
int pop();
int top();
int empty_stack();

	void create_stack()
	{
 		front=rear=NULL;
	}

	void push(int data)
	{
		if(front==NULL)
	   	{
			front=malloc(1*sizeof (struct node)); // 1st way
			front->data=data;
			front->ptr=NULL;
			rear=front;
	   }
	   else
	   {
			temp= malloc(1*(sizeof *temp)); //2nd way; better way for type safety
			temp->data=data;
			temp->ptr=front;
			front=temp; 
	   }
	}

	void pop()
	{
	 	if(front!=NULL)
	  	{
		   temp=front;
		   free(front);
		   front=temp->ptr;
		   if(front==NULL)
		   {
		   		front=rear=NULL;
		   }
	  	}
	 	else 
	  	{
	   	   printf("No element to pop()\n");
	  	}
	}

	int top()
	{
	  if(front==NULL && rear==NULL)
	  {
		   printf("The stack is empty\n");
		   return 0; 
	  }
	  else
	   	   return front->data;  
	}

/*void search(int find)
{
 int flag=0;
 for(temp=front;temp!=NULL;temp=temp->ptr)
   {
     if(temp->data==find)
       {
        flag=1;
        printf("Element found\n");
       }
    }
  if(flag!=1)
    printf("Element not in the stack\n");
}*/

	void display()
	{
	  if(front==NULL && rear==NULL)
	  	printf("Stack is empty\n");
	  else
	  {
		  for(temp=front;temp!=NULL;temp=temp->ptr)
		  {
		     printf("%d\n", temp->data);        
		  }
	  }
	}




/*int main()
{
  createstack;
  push(10);
  push(12);
  push(13);
  push(14);
  search(14);
  search(13);
  search(12);
  search(10);
  search(11);
  display();
  pop();
  display();
  pop();
  display();
  pop();
  display();
  pop();
  display();
  display();
  pop();
  display();
  printf("The top elment is: %d\n",peek());
}



