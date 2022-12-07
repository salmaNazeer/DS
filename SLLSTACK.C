#include<stdio.h>
#include<stdlib.h>

struct node
{
 int data;
 struct node* next;
};
struct node *temp,*newnode,*top=NULL;

void push();
void pop();
void display();
void peek();
void searching();

void main()
{
  int choice=0;
  clrscr();
  do
  {
    printf("\n\nenter the choice\n1:push\n2:pop\n3:peek\n4:search\n5:exit\n");
    scanf("%d",&choice);
    switch(choice)
    {
      case 1:push();
	     display();
	     break;
      case 2:pop();
	     display();
	     break;
      case 3:peek();
	     break;
      case 4:searching();
	     break;
      case 5:exit(0);
    }
  }while(choice!=5);
  getch();
}

//Push to stack
void push()
{
  int a,n=1;
  while(n)
  {
    printf("enter the data to be pushed:\t");
    scanf("%d",&a);
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=a;
    newnode->next=top;
    top=newnode;
    printf("do you want to continue:(1/0)\n");
    scanf("%d",&n);
  }
}

//Pop from stack
void pop()
{
  temp=top;

  if(top==NULL)
    printf("\nthe stack is empty!\n");

  else
  {
    printf("\nthe poped element is %d\n",top->data);
    top=top->next;
    free(temp);
  }
}

//display list
void display()
{
  printf("\nthe stack is:\t");
  temp=top;

  if(top==NULL)
    printf("the list is empty!!");

  else
  {
    while(temp!=NULL)
    {
      printf("%d\t",temp->data);
      temp=temp->next;
    }
  }
}

//Peek
void peek()
{

  if(top==NULL)
    printf("the stack is empty!!!");

  else
    printf("the element at top of stack is %d",top->data);

}

//Searching for an element in list
void searching()
{
  int item,i=1,flag=0;
  printf("Enter the element to search:");
  scanf("%d",&item);
  temp=top;

  while(temp!=NULL)
  {
    if(temp->data==item)
    {
      printf("\n\nITEM FOUND AT %d POSIOTION\n\n",i);
      flag=flag+1;
    }
    i=i+1;
    temp=temp->next;
  }

  if(flag==0)
    printf("\nNOT FOUND !! \n\n");

}
