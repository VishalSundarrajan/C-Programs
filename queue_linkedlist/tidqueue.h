#ifndef _Queue_H
#define _Queue_H

#include <stdio.h>
#include <stdlib.h>
 
struct node
{
    int info;
    struct node *ptr;
}*front,*rear,*temp,*front1;
 
int tidpeek();
void tidenq(int data);
void tiddeq();
int tidempty();
void tiddisplay();
void tidcreate();
void tidqueuesize();
 
int tcount = 0;
 

 
/* Create an empty queue */
void tidcreate()
{
    front = rear = NULL;
}
/* Returns queue size */
void tidqueuesize()
{
    printf("\n Queue size : %d", tcount);
}
 
/* Enqueing the queue */
void tidenq(int data)
{
    if (rear == NULL)
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
void tiddisplay()
{
    front1 = front;
 
    if ((front1 == NULL) && (rear == NULL))
    {
        printf("\nQueue is empty");
        return;
    }
    while (front1 != rear)
    {
        printf("\n%d ", front1->info);
        front1 = front1->ptr;
    }
    if (front1 == rear)
    printf("\n%d", front1->info);
}
 
/* Dequeing the queue */
void tiddeq()
{
    front1 = front;
 
    if (front1 == NULL)
    {
        return;
    }
    else
        if (front1->ptr != NULL)
      {
            front1 = front1->ptr;
            //printf("\n Dequed value : %d", front->info);
            free(front);
            front = front1;
        }
        else
        {
            //printf("\n Dequed value : %d", front->info);
            free(front);
            front = NULL;
            rear = NULL;
        }
        tcount--;
}
 /* Returns the front element of queue */
int tidpeek()
{
    if ((front != NULL) && (rear != NULL))
        return(front->info);
    else
        return 0;
}
 
/* Display if queue is empty or not */
int tidempty()
{
     if ((front == NULL) && (rear == NULL))
        return 1;
    else
        return 0;
}
 


#endif
