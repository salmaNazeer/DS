#include<stdio.h>
#include<stdlib.h>

void insbeg();
void insmid();
void insend();
void delbeg();
void delmid();
void delend();
void display();
void creation();
void searching();

struct node
{
  int data;
  struct node *next,*prev;
};
struct node *head,*newnode,*temp,*temp1;

void main()
{
  int choice=0;
  clrscr();
  do
  {

    printf("\n\nenter the choice\n1.creation\n2.insertion at beginning\n"
    "3.insert at a position\n4.insert at end\n5.delete from beginning\n"
    "6.delete an element\n7.delete from end\n8.searching\n9.exit\n");
    scanf("%d",&choice);

    switch(choice)
    {
      case 1:creation();display();break;

      case 2:insbeg();display();break;

      case 3:insmid();display();break;

      case 4:insend();display();break;

      case 5:delbeg();display();break;

      case 6:delmid();display();break;

      case 7:delend();display();break;

      case 8:searching();display();break;

      case 9:exit(0);break;
    }

  }while(choice!=9);
getch();
}

//Creation of a doubly LL
void creation()
{
  int ch=1;
  head=0;
  while(ch)
  {
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("enter the element to be inserted\t:");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    newnode->prev=NULL;

    if(head==0)
    {
      head=temp=newnode;
    }

    else
    {
      temp->next=newnode;
      newnode->prev=temp;
      temp=newnode;
    }

    printf("do you want to continue(1/0):\t");
    scanf("%d",&ch);
  }
}

//Display List
void display()
{
  int count=0;
  temp=head;

  while(temp!=NULL)
  {
    count=count+1;
    printf("%d\t",temp->data);
    temp=temp->next;
  }

  printf("\nthe number of nodes is:\t %d\n",count);
}

//Insertion at beginning
void insbeg()
{
  newnode=(struct node*)malloc(sizeof(struct node));
  printf("enter the element to be inserted\t:");
  scanf("%d",&newnode->data);
  newnode->next=head;
  newnode->prev=NULL;
  head=newnode;
}

//Insertion at a position
void insmid()
{
  int pos,count=0,i=1;
  temp=head;

  while(temp!=NULL)
  {
    count=count+1;
    temp=temp->next;
  }

  printf("enter the position at which the element to be inserted\t:");
  scanf("%d",&pos);

  if(pos>count)
  {
    printf("INVALID CHOICE!!!");
  }

  else
  {
    temp=temp1=head;

    while(i<pos)
    {
      temp1=temp;
      temp=temp->next;
      i++;
    }

    printf("enter the element to be inserted\t:");
    newnode=(struct node*)malloc(sizeof(struct node));
    scanf("%d",&newnode->data);
    newnode->next=temp;
    temp->prev=newnode;
    newnode->prev=temp1;
    temp1->next=newnode;
  }
}

//Insertion at end
void insend()
{
  newnode=(struct node*)malloc(sizeof(struct  node));
  printf("enter the element to be inserted\t:");
  scanf("%d",&newnode->data);
  newnode->next=NULL;
  temp=head;

  while(temp->next!=NULL)
  {
    temp=temp->next;
  }

  temp->next=newnode;
  newnode->prev=temp;
}

//Delete from beginning
void delbeg()
{
  if(head==NULL)
    printf("NODE ABSENT\n");

  temp=head;
  head=temp->next;
  head->prev=NULL;
  free(temp);
}

//Delete any element
void delmid()
{
  int del;

  if(head==NULL)
    printf("NODE ABSENT\n");

  printf("enter the data to delete\t:");
  scanf("%d",&del);
  temp=head;

  while(temp->data!=del)
  {
    if(temp->next==NULL)
    {
      printf("GIVEN NODE IS NOT FOUND!!! \n");
      break;
    }
    else
    {
      temp=temp->next;
    }
  }

  while(temp->data==del)
  {
    if(temp==head)
    {
      head=NULL;
      free(temp);
    }
    else
    {
      temp->prev->next=temp->next;
      free(temp);
    }
  }
}

//Delete from end
void delend()
{
  if(head==NULL)
    printf("NODE ABSENT\n");

  temp=head;

  while(temp->next!=NULL)
  {
    temp1=temp;
    temp=temp->next;
  }

  temp1->next=NULL;
}

//Search an element
void searching()
{
  int item,i=1,flag=0;
  printf("Enter the element to search:");
  scanf("%d",&item);
  temp=head;

  while(temp!=NULL)
  {
    if(temp->data==item)
    {
      printf("\n\nITEM FOUND AT %d POSITION\n\n",i);
      flag=flag+1;
    }
    i=i+1;
    temp=temp->next;
  }

  if(flag==0)
  {
    printf("\nNOT FOUND!!! \n\n");
  }
}