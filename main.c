#include <stdio.h>
#include <stdlib.h>
//#include <stdbool.h>
#define N 8
int score=0;
void show(int x[],int jahat,int t)
{
	/*
	  **|     4   0
	    |**   3   1
	    |**   2   2
	    |**   1   3
	   &|**   0   4
	*/
	//system("color 02");
	char board[N][5];
	for(int i=N-1;i>=0;i--)
	{
		board[N-1-i][2]='|';
		if(x[i]==-1)
		{
          for(int j=0;j<2;j++)board[N-1-i][j]='*';
          for(int j=3;j<5;j++) board[N-1-i][j]=' ';        
		}
		else if(x[i]==0)
		{
		  for(int j=0;j<2;j++)board[N-1-i][j]=' ';
          for(int j=3;j<5;j++) board[N-1-i][j]=' ';      

		}		
		else if(x[i]==1)
		{
          for(int j=0;j<2;j++)board[N-1-i][j]=' ';
          for(int j=3;j<5;j++) board[N-1-i][j]='*';       
		}			
	}
	if(jahat==-1)board[N-1][1]='&';
	else if(jahat==1)board[N-1][3]='&';
	system("cls");	
	for(int i=0;i<N;i++)
	  {
	  	for(int j=0;j<5;j++)printf("%c",board[i][j]);
	  	
	  	printf("\n");
	  }
	
	printf("time:%d\n",t);
	printf("score:%d\n",score);
}

int main() {
    int x[N]={0,-1,0,-1,0,1,0,1};
    int p=0;
	int jahat=1;//+1 -1
    int flag=-1;
    int y=x[0];
    int t=8;
	while(t!=0){
		show(x,jahat,t);
		
        if(jahat*x[0]==1||jahat*y==1)
        {
        	break;
		}
		
		if ( kbhit() ) {
		   t++;
		   if(t>8)t=8;
		  char ch=getch();
		  if(ch=='d')jahat=1;	
          else if(ch=='a')jahat=-1;
          y=x[0];
		  for(int i=0;i<N-1;i++)
          {
        	x[i]=x[i+1];
		  } 
		  if(flag==1)x[N-1]=(rand()%3)-1;
		  else if(flag==-1)x[N-1]=0;
		  flag*=-1;
		  score++;
        }else
        {
         _sleep(600);
		 t--;   
         }
	  }
     printf("game over");
	 getch();     
	return 0;
}