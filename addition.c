#include<stdio.h>
int ta[100][3],tb[100][3],ts[100][3];
void tuple( int nzero,int r,int co,int a[100][100],int p [100][3])
{  int i,j; 
   int sr=nzero+1;
    
    p[0][0]=r;
    p[0][1]=co;
    p[0][2]=nzero;
    int s=1;
    for(i=0;i<r;i++)
	for(j=0;j<co;j++)
	{
	  if(a[i][j]!=0)
        	{
	        p[s][0]=i;
			p[s][1]=j;
			p[s][2]=a[i][j];
			s++;
		}
        }
  printf("\ntuple form of the matrix\n");
     for(i=0;i<sr;i++)
	{
		for(j=0;j<3;j++)
		printf("%5d",p[i][j]);
		printf("\n");
	}

}
void add(int c,int d )
{  int i,j,t;
    i=0;
    j=0;
     t=1;
     
    
    while(i<c+1 && j<d+1)
    {
        if(ta[i][0]<tb[j][0] || (ta[i][0]==tb[j][0] && ta[i][1]<tb[j][1]))
        {
        ts[t][0]=ta[i][0];
        ts[t][1]=ta[i][1];
        ts[t][2]=ta[i][2];
        i++;
        t++;
        }
        else if(tb[j][0]<ta[i][0] || (ta[i][0]==tb[j][0] && tb[j][1]<ta[i][1]))
        {
              ts[t][0]=tb[j][0];
              ts[t][1]=tb[j][1];
              ts[t][2]=tb[j][2];
              j++;
              t++;
        }
       else if(ta[i][0]==tb[j][0] && tb[j][1]==ta[i][1])
       {
              ts[t][0]=tb[j][0];
              ts[t][1]=tb[j][1];
              ts[t][2]=tb[j][2]+ta[i][2];
              i++;
              j++;
              t++;
       }
    }
    while(i<c+1)
    {
        ts[t][0]=ta[i][0];
        ts[t][1]=ta[i][1];
        ts[t][2]=ta[i][2];
        i++;
        t++;
        }
    while(j<d+1)
     {
              ts[t][0]=tb[j][0];
              ts[t][1]=tb[j][1];
              ts[t][2]=tb[j][2];
              j++;
              t++;
        }
   
    printf("\n\n\n\n sum\n\n");
    for(i=1;i<t;i++)
     {
       for(j=0;j<3;j++)
         printf("%d ",ts[i][j]);
       printf(" \n");
     }
    }
void main()
{
    int a[100][100],b[100][100],j,i;
    int non0a=0,non0b=0,m,n;
    printf("enter no of rows and columns of matrix: \n");
    scanf("%d %d",&m,&n);
   
    printf("enter matrix values of matrix A:");
    for(i=0;i<m;i++)
     {for(j=0;j<n;j++)
       {
        scanf("%d",&a[i][j]);
        if(a[i][j]!=0)
         non0a++;
       }
     }    
    for(i=0;i<m;i++)
     {
       for(j=0;j<n;j++)
         printf("%d ",a[i][j]);
       printf(" \n");
     }
     tuple( non0a, m, n, a,ta);
      printf("enter matrix values of matrix B");
    for(i=0;i<m;i++)
     {for(j=0;j<n;j++)
      {
        scanf("%d",&b[i][j]);
        if(a[i][j]!=0)
         non0b++;
      }
     }
    for(i=0;i<m;i++)
     {
       for(j=0;j<n;j++)
         printf("%d ",b[i][j]);
       printf(" \n");
     }
    tuple( non0b, m, n, b,tb);
    add(non0a,non0b);
}