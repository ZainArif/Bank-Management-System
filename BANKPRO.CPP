#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<stdlib.h>
struct customer
 {
  char name[25];
  long int bal,acno;
 }cust;
void acc(void);
void deposit(void);
void withdraw(void);
void detail(void);
void del(void);

void main(void)
{
 clrscr();
 int  gd = DETECT, gm;
      initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");

 {
  setfillstyle(1,CYAN);
  bar(0,0,640,480);
  setfillstyle(1,BLUE);
  bar(0,200,640,245);

  settextstyle(7,0,4);
  outtextxy(100,200,"Bank Management System");

  settextstyle(7,0,1);
  outtextxy(100,350,"Loading....");

  setfillstyle(1,BLACK); delay(1000);
  bar(10,400,100,402);
  setfillstyle(1,BLACK); delay(1000);
  bar(100,400,300,402);
  setfillstyle(1,BLACK); delay(1000);
  bar(300,400,500,402);
  setfillstyle(1,BLACK); delay(1000);
  bar(500,400,630,402);
  settextstyle(7,0,1);
  outtextxy(450,405,"Press any key...");
  delay(3000);
 }
getch();
bms:

setfillstyle(1,CYAN);
bar(0,0,640,480);

setfillstyle(1,BLACK);
bar(135,3,485,45);
setfillstyle(1,9);
bar(140,8,480,40);

settextstyle(1,0,3);
outtextxy(150,10,"BANK MANAGEMENT SYSTEM");
delay(1000);

setfillstyle(1,BLACK);
bar(150,90,460,285);

setfillstyle(1,9);
bar(160,100,450,125);
settextstyle(1,0,2);
outtextxy(162,100," 1.NEW ACCOUNT");

setfillstyle(1,9);
bar(160,130,450,155);
settextstyle(1,0,2);
outtextxy(162,130," 2.DEPOSIT");

setfillstyle(1,9);
bar(160,160,450,185);
settextstyle(1,0,2);
outtextxy(162,160," 3.WITHDRAW");

setfillstyle(1,9);
bar(160,190,450,215);
settextstyle(1,0,2);
outtextxy(162,190," 4.LIST OF ACCOUNTS");

setfillstyle(1,9);
bar(160,220,450,245);
settextstyle(1,0,2);
outtextxy(162,220," 5.ACCOUNT DELETION");

setfillstyle(1,9);
bar(160,250,450,275);
settextstyle(1,0,2);
outtextxy(162,250," 6.CLOSE APPLICATION ");

switch( getche() )
     {
     case 49: clrscr();
	      acc();
	      goto bms;

     case 50: clrscr();
	      deposit();
	      goto bms;

     case 51: clrscr();
	      withdraw();
	      goto bms;

     case 52: clrscr();
	      detail();
	      goto bms;

     case 53: clrscr();
	      del();
	      goto bms;

     case 54: exit(0);

     default: clrscr();
	      setfillstyle(1,DARKGRAY);
	      bar(0,0,640,480);
	      setbkcolor(DARKGRAY);
	      gotoxy(27,4);
	      printf("\nEnter only selections listed.");
	      getch() ;
    }
    closegraph();
}

void acc(void)
{
  FILE *fp;
  clrscr();
  fp=fopen("bank.rec","ab+");
 do
  {
   setfillstyle(1,DARKGRAY);
   bar(0,0,640,480);
   setbkcolor(DARKGRAY);
   gotoxy(27,3);
   printf("ADDING ACCOUNTS");
   gotoxy(27,4);
   printf("*************");
   gotoxy(15,7);
   printf("Account No.:");
   scanf("%ld",&cust.acno);
   gotoxy(15,9);
   printf("Customer Name :");
   fflush(stdin);
   gets(cust.name);
   gotoxy(15,11);
   printf("Amount :");
   scanf("%ld",&cust.bal);
   fwrite(&cust,sizeof(cust),1,fp);
   gotoxy(23,16);
   printf("Add More Account?(y/n)");
   fflush(stdin);
  }
  while( getche() == 'y');
  fclose(fp);
  gotoxy(23,23);
  printf("Press any key to cotinue");
  getch();
}

void deposit(void)
{
 FILE *fp,*ft;
 int f=0;
 long int ano,balance;
 do
 {
   setfillstyle(1,DARKGRAY);
   bar(0,0,640,480);
   setbkcolor(DARKGRAY);
   gotoxy(27,3);
   printf("UPDATION OF DEPOSIT");
   gotoxy(26,4);
   printf("***************");
   gotoxy(15,7);
   printf("Account No.  :");
   scanf("%ld",&ano);
   fp=fopen("bank.rec","rb+");
   ft=fopen("customer.rec","ab+");
   while( (fread(&cust,sizeof(cust),1,fp) == 1 ) )
   {
     setfillstyle(1,DARKGRAY);
     bar(0,0,640,480);
     if(cust.acno==ano)
     {
       f=1;
       gotoxy(15,9);
       printf("Customer Name :");
       puts(cust.name);
       gotoxy(15,11);
       printf("Balance :");
       printf("%ld",cust.bal);
       gotoxy(15,13);
       printf("Deposit Amount :");
       scanf("%ld",&balance);
       cust.bal=balance+cust.bal;
       fwrite(&cust,sizeof(cust),1,ft);
      }
      else
	{
	  fwrite(&cust,sizeof(cust),1,ft);
	}
    }
   if(f==0)
    {
     clrscr();
     setfillstyle(1,DARKGRAY);
     bar(0,0,640,480);
     setfillstyle(1,DARKGRAY);
     bar(0,0,640,480);
     gotoxy(15,10);
     printf("Account No. not found!!");
     }
     fclose(fp);
     fclose(ft);
     remove("bank.rec");
     rename("customer.rec","bank.rec");
     gotoxy(23,16);
     printf("Do You Want To Enter A/C No. Again?? (y/n)");
     fflush(stdin);
  }while( getche()== 'y');
gotoxy(23,23);
printf("Press any key to continue.");
getch();
}

void withdraw(void)
{
  int f=0;
  long int ano,balance;
  char ch;
  FILE *fp,*ft;
  do
   {
     setfillstyle(1,DARKGRAY);
     bar(0,0,640,480);
     setbkcolor(DARKGRAY);
     gotoxy(27,3);
     printf("WITHDRAWING FROM A/C");
     gotoxy(26,4);
     printf("***********************");
     gotoxy(15,7);
     printf("Account No.  :");
     scanf("%ld",&ano);
     fp=fopen("bank.rec","rb+");
     ft=fopen("customer.rec","ab+");
     while( (fread(&cust,sizeof(cust),1,fp) == 1 ) )
     {
       setfillstyle(1,DARKGRAY);
       bar(0,0,640,480);
       if(cust.acno==ano)
	{
	  f=1;
	  gotoxy(15,9);
	  printf("Customer Name  :");
	  fflush(stdin);
	  puts(cust.name);
	  gotoxy(15,11);
	  printf("Balance   :");
	  printf("%ld",cust.bal);
	  gotoxy(15,13);
	  printf("Withdrawal Amount :");
	  scanf("%ld",&balance);

	  if(cust.bal>balance)
		cust.bal=cust.bal-balance;
	  else if(cust.bal==balance)
		 cust.bal=0;
	  else
	      {
		 gotoxy(20,16);
		 printf("Sorry! Your requirement is larger than your A/C amount!");
	       }
	  fwrite(&cust,sizeof(cust),1,ft);
	  }
	  else
	    {
	      fwrite(&cust,sizeof(cust),1,ft);
	    }
     }
      if(f==0)
	{
	 clrscr();
	 setfillstyle(1,DARKGRAY);
	 bar(0,0,640,480);
	 gotoxy(15,10);
	 printf("A/C No. not found!!");
	 }
	 fclose(fp);
	 fclose(ft);
	 remove("bank.rec");
	 rename("customer.rec","bank.rec");
	 gotoxy(23,18);
	 printf("Do You Want To Enter A/C No. Again?? (y/n)");
	 fflush(stdin);
  }while( getche() == 'y');
gotoxy(23,23);
printf("Press any key to continue.");
getch();
}

void detail(void)
{
 int f=0;
 long int ano;
 FILE *fp;
 clrscr();
 do
 {
   setfillstyle(1,DARKGRAY);
   bar(0,0,640,480);
   setbkcolor(DARKGRAY);
   gotoxy(23,3);
   printf("DETAILS OF A CUSTOMER");
   gotoxy(22,4);
   printf("*********************");
   gotoxy(15,7);
   printf("Account No.  :");
   scanf("%ld",&ano);
   fp=fopen("bank.rec","rb+");
   while(fread(&cust,sizeof(cust),1,fp)==1)
   {
    setfillstyle(1,DARKGRAY);
    bar(0,0,640,480);
    if(cust.acno==ano)
     {
      f=1;
      gotoxy(15,9);
      printf("Customer Name :");
      fflush(stdin);
      puts(cust.name);
      gotoxy(15,11);
      printf("Balance  :");
      printf("%ld",cust.bal);
      break;
      }
     if(f==0)
      {
     clrscr();
     setfillstyle(1,DARKGRAY);
     bar(0,0,640,480);
     gotoxy(15,10);
     printf("Account No. not found!!");
     }
   }
    fclose(fp);
    gotoxy(23,16);
    printf("Do You Want To Enter A/C No. Again??(y/n)");
    fflush(stdin);
 }while( getche() == 'y');
   gotoxy(23,23);
   printf("Press any key to continue.");
   getch();
}

void del(void)
{
  int f=0;
  long int ano;
  FILE *fp,*ft;
  clrscr();
  setfillstyle(1,DARKGRAY);
  bar(0,0,640,480);
  do
   {
	setfillstyle(1,DARKGRAY);
	bar(0,0,640,480);
	setbkcolor(DARKGRAY);
	gotoxy(27,3);
	printf("DELETE AN ACCOUNT ");
	gotoxy(26,4);
	printf("***********************");
	gotoxy(15,7);
	printf("Account No.  :");
	scanf("%ld",&ano);
	fp=fopen("bank.rec","rb+");
	ft=fopen("customer.rec","ab+");
	while(fread(&cust,sizeof(cust),1,fp)==1)
	{
	  setfillstyle(1,DARKGRAY);
	  bar(0,0,640,480);
	  if(cust.acno==ano)
	    {
	     f=1;
	     gotoxy(15,9);
	     printf("Customer Name  :");
	     fflush(stdin);
	     puts(cust.name);
	     gotoxy(15,11);
	     printf("Balance   :");
	     printf("%ld",cust.bal);
	     gotoxy(15,13);
	     setbkcolor(DARKGRAY);
	     printf("If You Want to delete this Account press d \n Else press any other key");
	     if( getch() == 'd')
		{
		  gotoxy(20,17);
		  printf("Are You Sure(y/n)?");
		  fflush(stdin);
		  if( getch() == 'y')
		  {
		  printf("Your Account Has Been Deleted");
		  continue;
		  }
		 else
		   {
		    clrscr();
		    setfillstyle(1,DARKGRAY);
		    bar(0,0,640,480);
		    gotoxy(15,10);
		    printf("Account is not deleted!");
		   }
		}
	 fwrite(&cust,sizeof(cust),1,ft);
	 }
	 else
	   {
	     fwrite(&cust,sizeof(cust),1,ft);
	    }
	}
      if(f==0)
	{
	  clrscr();
	  setfillstyle(1,DARKGRAY);
	  bar(0,0,640,480);
	  gotoxy(15,10);
	  printf("Account No. not found!!");
	}
fclose(fp);
fclose(ft);
remove("bank.rec");
rename("customer.rec","bank.rec");
gotoxy(23,18);
printf("Delete another Account?? (y/n)");
fflush(stdin);
}while( getch()=='y');
gotoxy(23,23);
printf("Press any key to continue.");
}
