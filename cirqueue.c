#include<stdio.h>
#include<stdlib.h>
void insert();
void delete();
void display();
void search();
int cq[100],front=-1,rear=-1,max,data,i;


void main()
{
  int cq[100],choice=0;
  clrscr();
  printf("Enter the maximum size of queue:\t");
  scanf("%d",&max);
  do
  {
    printf("\n\n1:insertion in CQ  \n2:deletion in CQ  \n3:Search an element \n4:exit\t");
    printf("\nEnter your choice:\t");
    scanf("%d",&choice);
    switch(choice)
    {
      case 1:insert();
	     display();
	     break;
      case 2:delete();
	     display();
	     break;
      case 3:display();
	     search();
	     break;
      case 4:exit(0);
    }
  }while(choice!=4);
  getch();
}


//Insertion in CQueue
void insert()
{
  if(front==((rear+1)%max))
    printf("queue overflow!!!!\n");

  else if(front==-1 && rear==-1)
  {
    front=0;
    rear=0;
    printf("enter the  element of CQ:\t");
    scanf("%d",&data);
    cq[rear]=data;
  }

  else
  {
    rear=(rear+1)%max;
    printf("enter the  element of CQ:\t");
    scanf("%d",&data);
    cq[rear]=data;
  }
}


//deletion from CQueue
void delete()
{
  if(front==-1)
    printf("cq is underflow!");

  else if(front==rear)
  {
    data=cq[front];
    front=-1;
    rear=-1;
    printf("the element deleted is %d\n",data);
  }

  else
  {
    data=cq[front];
    front=(front+1)%max;
    printf("the element deleted is %d\n",data);
  }
}


//display of Queue
void display()
{
  if(front==-1 && rear==-1)
    printf("\n there is no element to display\n");

  else
  {
    if(front==rear)
      printf("%d\t",cq[rear]);

    else if(front<rear)
    {
      for(i=front;i<=rear;i++)
	printf("%d\t",cq[i]);
    }

    else if(rear<front)
    {
      for(i=front;i<max;i++)
	printf("%d\t",cq[i]);
      for(i=0;i<=rear;i++)
	printf("%d\t",cq[i]);
    }
  }
}


//Search an element from CQueue
void search()
{
  int item,flag=0,i=front;
  printf("\nEnter the element to search:\t");
  scanf("%d",&item);

  if(front==-1||rear==-1)
    printf("OVERFLOW");

  else
  {
    if(i>rear)
    {
      while(i>rear)
      {
	if(cq[i]==item)
	{
	  flag=1;
	  break;
	}
	i=(i+1)%max;
      }
    }

    if(i<=rear)
    {
      for(;i<=rear;i++)
      {
	if(cq[i]==item)
	{
	  flag=1;
	  break;
	}
      }
    }
  }

  if(flag==1)
    printf("Item found at position\t\t%d\t",i+1);

  else
    printf("Not found");

}
