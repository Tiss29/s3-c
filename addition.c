#include<stdio.h>
struct tup{
int row;
int col;
int value;
}ta[100],tb[100],add[100];

 
int tuple(struct tup t[100],int a[100][100],int r,int c)
{ t[0].row=r;
         t[0].col=c;
        int k=1;
  for (int i=0;i<r;i++)
     for(int j=0;j<c;j++)
     {  if(a[i][j]!=0)
      {   t[k].row=i;
         t[k].col=j;
         t[k].value=a[i][j];
         k++;
     }
     }
     t[0].value=k-1;
       printf("\ntuple\n");
     for (int i=0;i<k;i++)
     {   printf("%d %d  %d\n",t[i].row,t[i].col,t[i].value);
     }
     return k;
}
void addt(int k1,int k2)
{ int k3=1,i=1,j=1;
    while(i<k1&&j<k2)
    
    {
        if(ta[i].row<tb[j].row||(ta[i].row==tb[j].row)&&(ta[i].col<tb[j].col))
        {
            add[k3].row=ta[i].row;
            add[k3].col=ta[i].col;
            add[k3].value=ta[i].value;
            k3++;i++;
        }
       else if(ta[i].row>tb[j].row||(ta[i].row==tb[j].row)&&(ta[i].col>tb[j].col))
        {
            add[k3].row=tb[j].row;
            add[k3].col=tb[j].col;
            add[k3].value=tb[j].value;
            k3++;j++;
        }
         else 
        {
            add[k3].row=tb[j].row;
            add[k3].col=tb[j].col;
            add[k3].value=tb[j].value+ta[i].value;
            k3++;i++;j++;
        }
    }
        while(i<k1)
        {
           add[k3].row=ta[i].row;
            add[k3].col=ta[i].col;
            add[k3].value=ta[i].value;
            k3++;i++; 
        }
         while(j<k2)
        {
           add[k3].row=tb[j].row;
            add[k3].col=tb[j].col;
            add[k3].value=tb[j].value;
            k3++;j++;
        }
    add[0].row=ta[0].row;
    add[0].col=ta[0].col;
    add[0].value=k3-1;
     printf("\nadd tuple\n");
     for (int i=0;i<k3;i++)
     {   printf("%d %d  %d\n",add[i].row,add[i].col,add[i].value);
     }
}

void main()
{  int a[100][100],b[100][100];
    int r;
    int c;
    int value;
    printf("enter the no of row and column");
    scanf("%d,%d",&r,&c);
    printf("A:\n");
    for (int i=0;i<r;i++)
     for(int j=0;j<c;j++)
     {  scanf("%d",&value);
         a[i][j]= value;
     }
     printf("\narr\n");
     for (int i=0;i<r;i++)
 {    for(int j=0;j<c;j++)
     {   printf("%d\t",a[i][j]);
         
     }printf("\n");
}printf("B:\n");
   for (int i=0;i<r;i++)
     for(int j=0;j<c;j++)
     {   scanf("%d",&value);
         b[i][j]= value;
     }
     printf("\narr\n");
     for (int i=0;i<r;i++)
 {    for(int j=0;j<c;j++)
     {   printf("%d\t",b[i][j]);
         
     }printf("\n");
}
    int k1= tuple(ta,a,r,c);
     int k2=tuple(tb,b,r,c);
     addt(k1,k2);
    
}
