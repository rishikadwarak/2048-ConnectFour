#include<iostream.h>
#include<conio.h>
#include<process.h>
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
void C4(void);
void tzfe(void);
int locations(int);
void tables(char[][5], int);
int check(int, int,char[5][5]);
int gamewon(int);
const int ROW=5;
const int COLUMN=5;
char table[ROW][COLUMN]={ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
int i, j;
int grid[4][4];
void left(void);
void right(void);
void up(void);
void down(void);
void display(void);
int getLeft(int [4][4],int,int);
int getRight(int [4][4],int,int);
int getUp(int [4][4],int,int);
int getDown(int [4][4],int,int);
void main()
{
 clrscr();
 char intro;
 int opt_game,a;
 cout<<"\n\n\n\n                      ********************************";
 cout<<"\n                      *                              *";
 cout<<"\n                      *                              *";
 cout<<"\n                      *     LOGICAL GAME STATION     *";
 cout<<"\n                      *                              *";
 cout<<"\n                      *                              *";
 cout<<"\n                      ********************************";
 cout<<"\n\n                  Press '*' to continue \n                ";
 cin>>intro;
 switch(intro)
 { case '*':
   { goto choose;
   }
   default:
   { exit(0);
   }
 }
 choose:
  clrscr();
  cout<<"\n\n\n        Welcome to our logical games platform!!";
  cout<<"\n       You can get started by choosing one of these games :)";
  cout<<"\n\n        1. CONNECT FOUR                   2. 2048";
  cout<<"\n\n\n        (Enter 1 to play connect four)\n        (Enter 2 to play 2048)\n";
  cin>>opt_game;
  clrscr();
  switch(opt_game)
  { case 1:
    { C4();
      break;
    }
    case 2:
    { tzfe();
      break;
    }
  }
  clrscr();
  cout<<" \n\n\n\n                  THANKS FOR PLAYING!! :D\n";

   cout<<"\n\n\n\n     By:\n";
   cout<<"     Anweshaa Baruah\n";
   cout<<"     Rishika T D\n";
   cout<<"     XI - 'A'";
  cout<<" \n\n                  (Press 1 to continue)\n";
  cin>>a;
  if(a==1)
   exit(0);
  getch();
 }
void C4(void)
{
 clrscr();
 int c1, c2, k;
 int columns;
 cout<<" CONNECT FOUR \n \n\n";
 tables(table, ROW);
 cout<<" \n PLAYER 1 is X \n PLAYER 2 is O \n";
 for (int count=0; count <25; count ++)
 {
  cout<<"\n Player 1 "<<endl;
  c1=locations(columns);
  for(i=4; i>=0; i--)
  {
   if(table[i][c1]==' ')
   {
    table[i][c1]='X';  break;
   }
  } // break;

  tables(table, ROW);

// k =check(ROW, COLUMN, table);
  cout<<"\n Player 2 \n";
  c2= locations(columns);
  for(i=4; i>=0; i--)
  {
   if(table[i][c2]==' ')
   {
    table[i][c2]='O';
    break;
   } // break;
  }
 // cout<<"Hi";
  tables(table, ROW);
  //cout<<"hi";


 k =check(ROW, COLUMN, table);

 }
 int W=gamewon(k);
 cout<<"Hi";
 if(W==0)
  cout<<"YOU WON THE GAME!!";
 else if(W==1)
  cout<<"IT IS A DRAW \n";
}
 int locations(int columns)
{
 int column;
 cout<<"Enter a column";
 cin>>columns;
 while(columns<1 || columns>5)
 {
  cout<<"\n You must enter a number from 1-5 \n";
  cout<<"Enter a number for the column"<<endl;
  cin>>columns;
 }
  column=columns-1;
  return column;
}
void tables(char table[][5], int ROW)
{
 for(i=0; i<ROW; i++)
 {
  for(j=0; j<5;j++)
  {
   cout<<" "<<table[i][j]<<"|";
  }
  cout<<endl;
  cout<<"-----------------";
  cout<<endl;
 }
}
int check(int ROW, int COLUMN, char table[5][5])
{
 int H=1, V=1, D1=1, D2=1;
 for(i=0; i<ROW; i++)
 { for(j=0; j<COLUMN; j++)
   {
    if(table[i+1][j]==table[i][j])
     H++;

    if(table[i][j+1]==table[i][j])
     V++;

    if(table[i+1][j+1]==table[i][j])
     D1++;

    if(table[i+1][j-1]==table[i][j])
     D2++;

    }
 }
 if(H==4 || V==4 || D1==4 || D2==4)
  return 1;

 else
   return 0;
}
int gamewon(int k)
{ int a=0;
 //if(k==1)
 // a=0;
  //return a;
 //else if(k==0)
 if(k==0)
 {
  for(i=0; i<5; i++)
   for(j=0; j<5; j++)
    if(table[i][j]!=' ')
     a=1;
     }
     else
     a=0;
    return a;

}
void tzfe(void)
{clrscr();
cout<<"\n TWO ZERO FOUR EIGHT\n";
char a;
  display();
  cin>>a;

  if(a=='l')
  left();
  else if(a=='r')
  right();
  else if(a=='u')
  up();
  else if(a=='d')
  down();
}
void display(void)
{
   // system("cls");
    int x, y, i, j;
    unsigned int sval;
    time_t t;
    sval=(unsigned)time(&t);
    srand(sval);
    for( i=0;i<4; i++)
    {
	for( j=0; j<4; j++)
	 {   grid[i][j]=0;   }
	cout<<endl;
    }
    for(j=1;j<=4;j++)
    {
	while(grid[x][y]!=0)
	{
		x=random(5);
		y=random(5);
	}
	int k=random(10);
	if(k>4)
		grid[x][y]=4;
	else
		grid[x][y]=2;
    }
    for(i=0; i<4; i++)
    {
	for(j=0; j<4;j++)
    {	    cout<<grid[j][i];
     }	cout<<endl;

    }
    for(i=0;i<4;i++)
  {
   for(j=0;j<4;j++)
   {
    if(grid[i][j]==16)
    {
     cout<<"you won"<<endl;
     exit(0);}}
    }
}
void left(void)

{
int i,j,k;
  for( i=0;i<4; i++)
 {
  for( j=0; j<=3; j++)
  {
   if(grid[i][j]!=0)

    {
       int tempj=j;
     //for(int k=j+1; k<4; k++)
     // if(grid[i][k]==0)

     // k=getLeft(grid,i,tempj);
      while(getLeft(grid,i,tempj)==0)
      {
	tempj--;
	}
	if((getLeft(grid,i,tempj)!=0) && (getLeft(grid,i,tempj)==grid[i][j]))
	{
	  grid[i][tempj-1]+=grid[i][j];
	  grid[i][j]=0;
	  }
	  if(tempj!=j)
	  {
	     grid[i][tempj]=grid[i][j];
	     grid[i][j]=0;

       //	grid[i][j]=grid[i][k];
       //  }	grid[i][k]=0;
      }
    }
}}
for( i=0;i<4; i++)
   { for( j=0;j<4;j++)
     {  cout<<grid[i][j];
     }  cout<<"\n";
   }

 }
 int getLeft(int grid[4][4],int i,int j)
 {
 if(j>0)
     return grid[i][j-1];

     else
     return 1;
}

void right(void)
{
  int i,j,k;
  for(i=0;i<4;i++)
   {
     for(j=3;j>=0;j--)
     {
      if(grid[i][j]!=0)
       {
	int tempj=j;
	while(getLeft(grid,i,tempj)==0)
	{
	  tempj++;
	}
       if((getLeft(grid,i,tempj)!=0) && (getLeft(grid,i,tempj)==grid[i][j]))
       {
	grid[i][tempj+1]+=grid[i][j];
	grid[i][j]=0;
       }
       if(tempj!=j)
       {
	 grid[i][tempj]=grid[i][j];
	 grid[i][j]=0;
       }
    }
   }
 }
    for( i=0;i<4; i++)
     {
      for( j=0;j<4;j++)
      {
       cout<<grid[i][j];
      }
       cout<<"\n";
     }
  }

 int getRight(int grid[4][4],int i,int j)
 {
  if(j<3)
  return grid[i][j+1];
  else
   return 1;
 }
 void up(void)
 {
 int i,j;
 for(j=0;j<4;j++)
  {
   for(i=0;i<=3;i++)
   {
    if(grid[i][j]!=0)
    {
     int tempi=i;
     while(getUp(grid, tempi, j)==0)
     {
     tempi--;
     }
     if(getUp(grid, tempi, j)!=0 && getUp(grid, tempi, j)==grid[i][j])
     {
      grid[tempi-1][j]+=grid[i][j];
      grid[i][j]=0;
     }
     if(tempi!=i)
     {
     grid[tempi][j]=grid[i][j];
     grid[i][j]=0;
     }
    }
   }
   }
    for( i=0;i<4; i++)
     {
      for( j=0;j<4;j++)
      {
       cout<<grid[i][j];
      }
       cout<<"\n";
     }
  }
  int getUp(int grid[4][4],int i,int j)
 {
  if(i>0)
  return grid[i-1][j];
  else
   return 1;
 }
void down(void)
{
int i,j;
for( j=0;j<4;j++)
  {
   for( i=3;i>=0;i--)
   {
    if(grid[i][j]!=0)
    {
     int tempi=i;
     while(getDown(grid,tempi, j))
     {
     tempi++;
     }
     if(getDown(grid, tempi, j)!=0 && getDown(grid, tempi, j)==grid[i][j])
     {
     grid[tempi+1][j]+=grid[i][j];
      grid[i][j]=0;
     }
     if(tempi!=i)
     {
     grid[tempi][j]=grid[i][j];
     grid[i][j]=0;
     }
    }
   }
  }
 for( i=0;i<4; i++)
     {
      for( j=0;j<4;j++)
      {
       cout<<grid[i][j];
      }
       cout<<"\n";
     }
  }
 int getDown(int grid[4][4],int i,int j)
  {
  if(i<3)
  return grid[i+1][j];
  else
   return 1;
 }


