#include<stdio.h>
#include<conio.h>
 struct Disjset
 {
  int parent[10];
  int rank[10];//rank[i] is the highest of the tree representing the set
  int n;
 }dis;

 //Create n single item sets
 void makeSet()
 {
  int i;
  for(i=1;i<=dis.n;i++)
  {
   dis.parent[i]=i;
   dis.rank[i]=0;
  }
 }

 //Displays Disjoint set
 void displaySet()
 {
  int i;
  printf("\n Parent Array \n");
  for(i=1;i<=dis.n;i++)
  {
   printf("%d\t",dis.parent[i]);
  }
  printf("\n Rank Array \n");
  for(i=1;i<=dis.n;i++)
   printf("%d\t",dis.rank[i]);
  printf("\n");
 }

 //Finds set of given item x
 int find(int x)
 {
  //Finds the representative of the set that x is an element
  if(dis.parent[x]!=x)
  {
   //if x is not the parent of itself, then x is not the repesentative of this set
   dis.parent[x]=find(dis.parent[x]);
   /*So we recursively call Find on its parent and move i's node directly under the
   representative of this set*/
  }
  return dis.parent[x];
 }

 //Do union of two sets represented by x and y.
 void Union(int x,int y)
 {
  //Find current sets of x and y
  int xset=find(x);
  int yset=find(y);

  //If they are already in same set
  if(xset==yset)
    return;

  //Put smaller ranked item under bigger ranked item if ranks are different
  if(dis.rank[xset]<dis.rank[yset])
  {
    dis.parent[xset]=yset;
    dis.rank[yset]=-1;
  }
  else if(dis.rank[xset]>dis.rank[yset])
  {
    dis.parent[yset]=xset;
    dis.rank[yset]=-1;
  }

  //If ranks are same, then increment rank
  else
  {
    dis.parent[yset]=xset;
    dis.rank[xset]=dis.rank[xset]+1;
    dis.rank[yset]=-1;
  }
 }

void main()
{
 int n,x,y,ch,wish;
 clrscr();
 printf("How many elements?\t");
 scanf("%d",&dis.n);
 makeSet();
 do
 {
 printf("\n*****MENU*****\n");
 printf(" 1.Union \n 2.Find \n 3.Display \n 4.Exit \n");
 printf("Enter choice \n");
 scanf("%d",&ch);
 switch(ch)
 {
   case 1:printf("Enter elements to perform union:\t");
	  scanf("%d%d",&x,&y);
	  Union(x,y);
	  break;

   case 2:printf("Enter elements to check if connected components:\t");
	  scanf("%d %d",&x,&y);
	  if(find(x)==find(y))
	    printf("Connected componenets \n");
	  else
	    printf("Not connected components \n");
	    break;
   case 3:displaySet();
	  break;
   case 4:exit(0);
  }
  printf("Do you wish to continue?(1/0)\n");
  scanf("%d",&wish);
 }while(wish==1);
 getch();
}