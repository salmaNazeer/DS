#include<stdio.h>

void input();
void display();
void Union();
void intersection();
void diff();

int a[]={0,0,0,0,0,0,0,0,0};
int b[]={0,0,0,0,0,0,0,0,0};
int c[]={0,0,0,0,0,0,0,0,0};

void main()
{
  int ch;
  clrscr();
  printf("**************SET OPERATION**************\n\n");

  do
  {
    printf("\n1.input\n2.union\n3.intersection\n4.difference\n5.exit\n");
    printf("\n enter choice:");
    scanf("%d",&ch);

    switch(ch)
    {
      case 1:input();
	     break;

      case 2:Union();
	     break;

      case 3:intersection();
	     break;

      case 4:diff();
	     break;

      case 5:exit(0);

      default:printf("\nINVALID CHOICE!!!\n");
    }
  }while(ch!=5);
}

//Input set1 and set2
void input()
{
  int n1,n2,x,i;
  printf("\n Enter size of set 1:");
  scanf("%d",&n1);
  printf("\n Enter elemets of set 1:");

  for(i=1;i<=n1;i++)
  {
    scanf("%d",&x);
    a[x]=1;
  }

  printf("\n Enter the size of set 2:");
  scanf("%d",&n2);
  printf("\n Enter the elements of set 2:");

  for(i=1;i<=n2;i++)
  {
    scanf("%d",&x);
    b[x]=1;
  }

  printf("\n set 1 : { ");
  for(i=1;i<=9;i++)
  {
    printf("%d ",a[i]);
  }
  printf("}");

  printf("\n set 2 : { ");
  for(i=1;i<=9;i++)
  {
    printf("%d ",b[i]);
  }
  printf("}");
}

//Display elements in set where value is 1
void display(int c[])
{
  int i;
  printf("\n\t{ ");
  for(i=1;i<=9;i++)
  {
    if(c[i]!=0)
      printf("%d ",i);
  }
  printf("}");
}

//Display Union of set1 and set2
void Union()
{
  int c[10],i;
  for(i=1;i<=9;i++)
  {
    if(a[i]!=b[i])
      c[i]=1;

    else
      c[i]=a[i];
  }

  printf("\n set is :{ ");
  for(i=1;i<=9;i++)
  {
    printf("%d ",c[i]);
  }
  printf("}");
  display(c);
}

//Intersection of set1 and set2
void intersection()
{
  int c[10],i;
  for(i=1;i<=9;i++)
  {
    if(a[i]==b[i])
      c[i]=a[i];

    else
      c[i]=0;
  }
  printf("\n set is:{ ");
  for(i=1;i<=9;i++)
  {
    printf("%d ",c[i]);
  }
  printf("}");
  display(c);
}

//display set1-set2
void diff()
{
  int c[10],i;
  for(i=1;i<=9;i++)
  {
    if(a[i]==1&&b[i]==0)
      c[i]=1;

    else
      c[i]=0;
  }
  printf("\n set is :{ ");
  for(i=1;i<=9;i++)
  {
    printf("%d ",c[i]);
  }
  printf("}");
  display(c);
}