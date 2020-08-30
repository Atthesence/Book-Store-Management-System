#include<stdio.h>
#include<conio.h>
#include<string.h>
int n=0,s,i=0,p=0,p1=0,p2=0,j=0,c,s1,nb,qnty,idgenerate=1;
long int id,id1,i1=0;
char name[20],nauthor[20],npub[20],pubyear[20],ch,str[20],str1[20]="1234";
long int ncost,nrtp,nid;
void admin();
void sell();
void menu();
void input();
void edit();
void show();

struct record
{
 char title[20];
 long int b_id;
 char author[30];
 int qty;
 long int cost;
 long int retailprice;
 long int total_sales;
 int unit;
 long int profit;
}o[100];
void main()
{
 textcolor(yellow);
 menu();
 getch();
}
void input()
{
  printf(" title : \t");
  scanf("%s",o[i].title);
  printf("author : \t");
  scanf("%s",o[i].author);
  printf("enter the number of quantity : \t");
  scanf("%d",&o[i].qty);
  printf("cost : \t");
  scanf("%ld",&o[i].cost);
  printf("enter the book retail price : \t ");
  scanf("%ld",&o[i].retailprice);
  o[i].b_id=idgenerate;
  printf("\n unique id of this book is : %d \n\n",o[i].b_id);
  i=i+1;
  n=n+1;
  idgenerate=idgenerate+1;
}

void edit()
{
 printf("press the id number for showing details\n");
 scanf("%ld",&id1);
 printf("\n\n");
 for(j=0;j<n;j++)
 {
  if(o[j].b_id==id1)
  {
   printf("what you want to edit ? \n");
   printf("1: name \n");
   printf("2: id \n");
   printf("3: author \n");
   printf("4: quantity \n");
   printf("5: cost \n");
   printf("6: retail price \n");
   printf("7: back to main menu \n");
   scanf("%d",&c);
   switch(c)
   {
    case 1:
	    printf("enter the new \n");
	    scanf("%s",name);
	    strcpy(o[j].title,name);
	    printf("\n");
	    printf("\n\n sucessfully updated \n\n");
	    break;
    case 2:
	    printf("enter the new \n");
	    scanf("%ld",&nid);
	    o[j].b_id=nid;
	    printf("\n");
	    printf("\n\n sucessfully updated \n\n");
	    break;
    case 3:
	    printf("enter the new \n");
	    scanf("%s",nauthor);
	    strcpy(o[j].author,nauthor);
	    printf("\n");
	    printf("\n\n sucessfully updated \n\n");
	    break;
    case 4:
	    printf("enter the number of books to be added in the stock \n");
	    scanf("%d",&nb);
	    o[j].qty=o[j].qty+nb;
	    printf("\n");
	    printf("\n\n sucessfully updated \n\n");
	    break;

    case 5:
	    printf("enter the new \n");
	    scanf("%ld",&ncost);
	    o[j].cost=ncost;
	    printf("\n");
	    printf("\n\n sucessfully updated \n\n");
	    break;
    case 6:
	    printf("enter the new \n");
	    scanf("%s",nrtp);
	    o[j].retailprice=nrtp;
	    printf("\n");
	    printf("\n\n sucessfully updated \n\n");
	    break;
    case 7:
	    menu();
	    break;
    default:
	    printf("invalid choice\n\n");
   }
   p1=p1+1;
  }
 }
 if(p1==0)
  printf("no record found\n");
}

void show()
{
 printf("press the id number for showing details\n");
 scanf("%ld",&id);
 printf("\n\n");
 for(j=0;j<n;j++)
 {
  if(o[j].b_id==id)
  {
   printf("id                  : \t %ld \n",o[j].b_id);
   printf("name                : \t %s \n",o[j].title);
   printf("author              : \t %s \n",o[j].author);
   printf("quantity            : \t %d \n",o[j].qty);
   printf("cost                : \t%ld \n",o[j].cost);
   printf("retail price        :\t %ld \n",o[j].retailprice);
   printf("number of book sold :\t %d \n",o[j].unit);
   printf("total amount        : \t %ld \n",o[j].total_sales);
   printf("total profit        : \t %ld \n\n\n",o[j].profit);
   p=p+1;
  }
 }
}

void admin()
{
 i1=0;
 c=' ';
 printf("\n\nenter the 4 digit password\n\n");
 for(i1=0;i1<4;i1++)
 {
  c=getch();
  str[i1]=c;
  c='*';
  printf("%c",c);
 }
 if(strcmp(str,str1)==0)
 {
   while(1)
   {
   printf("\n\n ******** admin panel ********* \n\n");
   printf("press 1 for adding new book \n");
   printf("press 2 for print book record \n");
   printf("press 3 for edit a book \n");
   printf("press 4 for back to main menu \n");
   scanf("%d",&s);
   clrscr();
   switch(s)
   {
    case 1:
	   input();
	   break;

   case 2:
	   show();
	   break;

   case 3:
	  edit();
	  break;

   case 4: menu();

   default:
	  printf("invalid choice\n\n");
  }
 }
 }
 else
 {
  printf("wrong");
  return;
 }
}
void staff()
{
 long int bill=0;
 int ch1;
 j=0;
 printf("enter the book id \n");
 scanf("%ld",&id1);
 printf("enter the number of quantity \n");
 scanf("%d",&qnty);
 for(j=0;j<n;j++)
 {
  if(o[j].b_id==id1)
  {
   if(o[j].qty == 0)
   {
    printf("\nsorry ! this book is out of stock \n\n");
    return;
   }
   if(o[j].qty<qnty)
   {
    printf("\nsorry ! only %d piece available in stock \n\n",o[j].qty);
    return;
   }
   o[j].qty=o[j].qty-qnty;
   bill=bill+o[j].retailprice*qnty;
   o[j].total_sales=o[j].total_sales+bill;
   o[j].unit=o[j].unit+qnty;
   o[j].profit=o[j].profit+qnty*(o[j].retailprice-o[j].cost);
   p2=p2+1;
  }
 }
 if(p2==0)
 {
  printf("\ninvalid book id \n\n");
  return;
 }
 printf("\ntotal price = %ld\n\n",bill);
}

void menu()
{
 while(1)
 {
  printf("\n\n********* main menu **********\n\n");
  printf("press 1 for continue as an administrator \n");
  printf("press 2 for continue as a staff \n");
  printf("press 3 for close \n");
  scanf("%d",&s1);
  clrscr();
  switch(s1)
  {
   case 1:
	   admin();
	   break;
   case 2:
	   staff();
	   break;
   case 3:
	   exit(0);
   default:
	   printf("wrong choice \n\n");
  }
 }
}
