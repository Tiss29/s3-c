#include<stdio.h>



void matrix(int r,int c,int a[5][5]);
void tuple(int a[5][5],int b[6][3],int r,int c);
void transpose(int p[6][3],int b[6][3]);
void ntranspose(int a[5][5],int t[5][5],int r,int c);


void main()
   {
       int r,c,a[5][5],b[6][3],p[6][3],t[5][5];
       printf("Entering matrix in normal form\n");
       printf("Enter the num of rows and columns:");
       scanf("%d %d",&r,&c);     
       matrix(r,c,a);
       printf("Tuple form of the matrix:\n");
       tuple(a,b,r,c);
       printf("Transpose of Tuple form:\n");
       transpose(p,b);
       printf("The normal form of transpose:\n");
       ntranspose(a,t,r,c);
       
   }
       
void matrix(int r,int c,int a[5][5])

{
    int i,j; 
    
    for(i=0;i<r;i++)
  {  printf("Enter row %d:",i);
     {for(j=0;j<c;j++)
      {scanf("%d",&a[i][j]);
      }
     }
   } 
   for(i=0;i<r;i++) 
     {for(j=0;j<c;j++)
     {
     printf("%d\t",a[i][j]);
     }
     printf("\n");
    }
    
    
}   
   void tuple(int a[5][5],int b[6][3],int r,int c)
{
   int k=1,i,j;
   
   for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
            {
                if(a[i][j]!=0)
                {
                    b[k][0]=i;
                    b[k][1]=j;
                    b[k][2]=a[i][j];
                    k++;
                }
            }
        }
     k=k-1;
     b[0][0]=r;
     b[0][1]=c;
     b[0][2]=k;
     for(i=0;i<=k;i++)
      {
       printf("%d\t%d\t%d\n",b[i][0],b[i][1],b[i][2]);
      }
}
void transpose(int p[6][3],int b[6][3])
{   
    int n=1,i,j;
    int k=b[0][2];
    
    
    p[0][0]=b[0][1];
    p[0][1]=b[0][0];
    p[0][2]=b[0][2];  
    for(i=0;i<p[0][0];i++) 
     {for(j=1;j<=k;j++)
      {if(b[j][1]==i)
       {
       p[n][0]=b[j][1];
       p[n][1]=b[j][0];
       p[n][2]=b[j][2];  
       n++;
       }
      }
     }
     for(i=0;i<=k;i++)
      {
       printf("%d\t%d\t%d\n",p[i][0],p[i][1],p[i][2]);
      }
}
      void ntranspose(int a[5][5],int t[5][5],int r,int c)
      {
          int i,j;
          for(i=0;i<c;i++) 
           {for(j=0;j<r;j++)
            {t[i][j]=a[j][i];}
           }
           for(i=0;i<r;i++) 
           {for(j=0;j<c;j++)
           {
           printf("%d\t",t[j][i]);
           }
           printf("\n");
           }
      }