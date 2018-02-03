#ifndef _Queue_H
#define _Queue_H

#include <stdio.h>
#include <stdlib.h>
 
struct node
{
    int info;
    struct node *ptr;
}*front,*rear,*temp;
 

void create_q();
int size_q();
void enq(int data);
void display_q();
int deq();
int peek();
int empty_q();

 
int tcount = 0;
  
	/* Create an empty queue */
	void create_q()
	{
    	front = rear = NULL;
	}

	/* Returns queue size */
	int size_q()
	{
    	return tcount;
	}
 
	/* Enqueing */
	void enq(int data)
	{
		if (front == NULL) //
		{
			front = (struct node *)malloc(1*sizeof(struct node));
			front->ptr = NULL;
			front->info = data;
			rear = front;
		}
    	else
    	{
        	temp=(struct node *)malloc(1*sizeof(struct node));
        	rear->ptr = temp;
        	temp->info = data;
        	temp->ptr = NULL;
 			rear = temp;
    	}
    	tcount++;
	}
 
	/* Displaying the queue elements */
	void display_q()
	{
		temp = front;
 		if (temp==NULL)
    	{
        	printf("Queue is empty");
        	return;
    	}
    	while (temp != rear)
    	{
        	printf("%d\n", temp->info);
        	temp = temp->ptr;
    	}
    	if (temp == rear)
    		printf("%d\n", temp->info);
	}
 
	/* Dequeing the queue and returns the dequeued element */
	int deq()
	{
    	temp = front;
    	int data;
 		if (temp == NULL)
    	{
        	return 0;
    	}
        if (temp->ptr != NULL)
      	{
            data = temp->info;
            temp = temp->ptr;
            free(front);
            front = temp;
        }
        else
        {
            data = temp->info;
            free(temp);
            front = NULL;
            rear = NULL;
        }
        tcount--;
        return data;
	}

 	/* Returns the top element of queue but does not delete */
	int peek()
	{
    	if (front != NULL)
        	return(front->info);
    	else
        	return 0;
	}
 
	/* Display if queue is empty or not */
	int empty_q()
	{
     	if ((front == NULL) && (rear == NULL))
        	return 1;
    	else
        	return 0;
	}
 
#endif
