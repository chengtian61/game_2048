#include <stdio.h>

#define SIZE 4

int stop_pos;

int find_target(int array[SIZE],int x)
{
  int t=x;
  if(x == 0 )
      return x;
  for(t=x-1;t>=0;t--)
  {
    if(array[t]!=0)
    {
        if(array[t]!=array[x])
            return t+1;
        return t;
    }
    else
        {
         if(t==stop_pos)
             return t;
         }
    
  }
  return x;
}

int slide_array(int array[SIZE])
{
  int t,x;
  stop_pos=0;
  for(x=0;x<SIZE;x++)
  {
    if(array[x]!=0)
    {
        t=find_target(array,x);
     if(t!=x)
     {
       if(array[t]==0)
           array[t]=array[x];
       else if(array[t] == array[x])
       {
           array[t]+=array[x];
           stop_pos=t+1;
       }
      array[x]=0;
     }
    }
  }
}
int rotate(int array[SIZE][SIZE])
{
  int i,j,temp;
  int n=SIZE;
  for(i=0;i<n/2;i++)
  {
      for(j=i;j<n-i-1;j++)
        {
            temp=array[i][j];
            array[i][j]=array[j][n-1-i];
            array[n-1-i][n-1-j]=array[n-1-j][i];
            array[n-1-j][i]=temp;
        }
  }
}
int move_up(int array[SIZE][SIZE])
{
   int i;
   for(i=0;i<SIZE;i++)
     slide_array(array[i]);
}
int move_left(int array[SIZE][SIZE])
{
    rotate(array);
    rotate(array);
    rotate(array);
    move_up(array);
    rotate(array);
}

int main()
{
   int board[SIZE][SIZE]={{0,0,2,2},{2,4,8,16},{2,2,2,2},{4,8,8,16}};
   int i,j;
   printf("before:\n");
   for(i=0;i<4;i++)
   {
     for(j=0;j<4;j++)
    {
       printf("%5d",board[i][j]);
    }
     printf("\n");
   }
   move_left(array)
   printf("\nafter:\n");
   for(j=0;j<4;j++)
   {
     for(i=0;i<4;i++)
    {
       printf("%5d",board[i][j]);
    }
     printf("\n");
   }
}






