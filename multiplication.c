#include<stdio.h>
struct form
{
int row;
int col;
int value;
};
 void tuple(int m,int n,int c,int arr[100][100],struct form a[100])
    {
        int i,j;
        int k=1;
        a[0].row=m;
        a[0].col=n;
        a[0].value=c;
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                if(arr[i][j]!=0)
                {
                    a[k].row=i;
                    a[k].col=j;
                    a[k].value=arr[i][j];
                    k++;
                }
            }
        }
    
        printf("\nThe tuple form of entered matrix is");
        for(i=0;i<c+1;i++)
        {
        
            printf("\n%d\t%d\t%d",a[i].row,a[i].col,a[i].value);
        }

   
    }

    int i,j,ra,ca,rb,cb;
    int a[100][100],b[100][100],k=1;
    int enter(int e[100][100],int m,int n)
    {   
        int c;
        printf("\nEnter the elements\n");
        for(i=0;i<m;i++)
        {
         for(j=0;j<n;j++)
         {
            scanf("%d",&e[i][j]);
            if(e[i][j]!=0)
                c++;
         }
        }
        printf("\nThe given matrix is\n");
        for(i=0;i<m;i++)
        {
         for(j=0;j<n;j++)
         {
            printf("%d \t",e[i][j]);
            
         }
         printf("\n");
        }
        return c;
    }
    void transpose(struct form t[100],int c)
    {
        int temp;
        for(i=1;i<c+1;i++)
        {
          temp=t[i].row;
          t[i].row=t[i].col;
          t[i].col=temp;
        }
        for(i=1;i<c+1;i++)
        for(j=1;j<=i-1;j++)
        {
           if(t[i].row<t[j].row)
           {
             temp=t[i].row;
             t[i].row=t[j].row;
             t[j].row=temp;
             temp=t[i].col;
             t[i].col=t[j].col;
             t[j].col=temp;
             temp=t[i].value;
             t[i].value=t[j].value;
             t[j].value=temp;
            }
            else if(t[i].row==t[j].row && t[i].col<t[j].col)
            {
              temp=t[i].col;
              t[i].col=t[j].col;
              t[j].col=temp;
              temp=t[i].value;
              t[i].value=t[j].value;
              t[j].value=temp;  
            }
        }
        printf("\nThe transpose of sparse matrix B \n");
        printf("row     column      value \n");
        for(i=0;i<c+1;i++)
        {
            printf("\n%d\t%d\t%d",t[i].row,t[i].col,t[i].value);
        }
    }
    void multiply(struct form at[100],struct form bt[100],struct form mul[100],int za,int zb)
    { 
        int k=1;
        mul[0].row=at[0].row;
        mul[0].col=bt[0].row;
        for(i=1;i<za+1;i++)
        {for(j=1;j<zb+1;j++)
         {
          if(at[i].col==bt[j].col)
          {
              mul[k].row=at[i].row;
              mul[k].col=bt[j].row;
              mul[k].value=at[i].value*bt[j].value;
              k++;
          }
         }
        } 
        
        
       
        
        int change=0;
        for(i=1;i<k-1;i++)
        for(int m=i+1;m<k-1;m++)
        {
          if(mul[i].row==mul[m].row && mul[i].col==mul[m].col)
          {
            mul[i].value=mul[i].value+mul[m].value;
           change++;
            for(int j=m;j<k;j++)
            {
              mul[j].row=mul[j+1].row;
              mul[j].col=mul[j+1].col;
              mul[j].value=mul[j+1].value;
              
            } 
            printf("\n\nMultiplied matrix of A and B \n");
        printf("row     column      value \n");
        for(i=0;i<k;i++)
        {
            printf("\n%d\t%d\t%d",mul[i].row,mul[i].col,mul[i].value);
        }
          }
          
        }
        mul[0].value=k-change-1;
        k=k-change;
        printf("\n\nMultiplied matrix of A and B \n");
        printf("row     column      value \n");
        for(i=0;i<k;i++)
        {
            printf("\n%d\t%d\t%d",mul[i].row,mul[i].col,mul[i].value);
        }
    }

    int main()
    {
      struct form at[100],bt[100],ct[100];
      int za,zb;
      printf("\n\tA:\n");
      printf("\nEnter the number of rows ");
      scanf("%d",&ra);
      printf("\nEnter the number of coloumns ");
      scanf("%d",&ca);
      za=enter(a,ra,ca);
      tuple(ra,ca,za,a,at);
      printf("\n\tB:\n");
      printf("\nEnter the number of rows ");
      scanf("%d",&rb);
      printf("\nEnter the number of coloumns ");
      scanf("%d",&cb);
      zb=enter(b,rb,cb);
      tuple(rb,cb,zb,b,bt);
      transpose(bt,zb);
      if(ca==rb)
        multiply(at,bt,ct,za,zb);
      else
        printf("Cannot be multiplied!");
    }