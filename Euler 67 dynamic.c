#include <stdio.h>
#include<math.h>
int maxsum(int (*a)[100], int i, int k);
int max(int a, int b);
int sum=0;
int sol[100][100]={0};


int main()
{
   int i,j,k;

 int a[100][100];

 
 for(i=0;i<100;i++)
 {
     for(j=i+1;j<100;j++)
     {
        a[i][j]=0; 
     }
 }
 for(i=0;i<100;i++)
 {
     for(j=0;j<=i;j++)
     {
        scanf("%d",&a[i][j]); 
     }
 }
 
 sum=maxsum(a,0,0);
printf("%d\n",sum);
/* for(i=0;i<4;i++)
 {
     for(j=0;j<4;j++)
     {
        printf("%d  ",sol[i][j]); 
     }  printf("\n");
 }*/
}

int maxsum(int (*a)[100],int i,int k)
{
    if(i==99) {return sol[i][k]=a[i][k]; }
    else 
    {   if(sol[i+1][k]>0 && sol[i+1][k+1]>0) return (sol[i][k]=max(sol[i+1][k],sol[i+1][k+1]));
        else if(sol[i+1][k]>0) return sol[i][k]=a[i][k]+max(sol[i+1][k],maxsum(a,i+1,k+1));
        else if (sol[i][k+1]>0)return sol[i][k]=a[i][k]+max(maxsum(a,i+1,k),sol[i+1][k+1]);
        else return sol[i][k]=a[i][k]+max(maxsum(a,i+1,k),maxsum(a,i+1,k+1));
        
        
    }
}

int max(int a, int b) {if(a>b)return a; else return b;}