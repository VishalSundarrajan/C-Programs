#ifndef _Queue_H
#define _Queue_H

#include <stdio.h>
#include <stdlib.h>
 
struct node
{
    int info;
    struct node *ptr;
}*front,*rear,*temp;
 
int peek();
void enq(int data);
void deq();
int empty();
void display();
void create();
void queuesize();
 
int tcount = 0;
  
	/* Create an empty queue */
	void create()
	{
    	front = rear = NULL;
	}

	/* Returns queue size */
	int size()
	{
    	return tcount;
	}
 
	/* Enqueing the queue */
	void enq(int data)
	{
    	if (rear == NULL) //
    	{
        	rear = (struct node *)malloc(1*sizeof(struct node));
        	rear->ptr = NULL;
        	rear->info = data;
        	front = rear;
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
	void display()
	{
		temp = front;
 		if (temp==NULL)
    	{
        	printf("\nQueue is empty");
        	return;
    	}
    	while (temp != rear)
    	{
        	printf("\n%d ", temp->info);
        	temp = temp->ptr;
    	}
    	if (temp == rear)
    		printf("\n%d", temp->info);
	}
 
	/* Dequeing the queue and returns the dequeued element */
	void deq()
	{
    	temp = front;
 
    	if (temp == NULL)
    	{
        	return;
    	}
        if (temp->ptr != NULL)
      	{
            temp = temp->ptr;
            free(front);
            front = temp;
        }
        else
        {
            free(front);
            front = NULL;
            rear = NULL;
        }
        tcount--;
	}

 	/* Returns the front element of queue */
	int peek()
	{
    	if (front != NULL)
        	return(front->info);
    	else
        	return 0;
	}
 
	/* Display if queue is empty or not */
	int empty()
	{
     	if ((front == NULL) && (rear == NULL))
        	return 1;
    	else
        	return 0;
	}
 
#endif
