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
   for(i=0;i<SIZE;i++)
      slide_array(board[i]);
   printf("\nafter:\n");
   for(i=0;i<4;i++)
   {
     for(j=0;j<4;j++)
    {
       printf("%5d",board[i][j]);
    }
     printf("\n");
   }
}






