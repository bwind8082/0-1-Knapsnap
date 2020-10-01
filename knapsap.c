#include<stdio.h>
#include<conio.h>

int max(int a,int b)
{
    if(a>b)
    return a;
    else
    return b;
}

void main()
{
    int i,j,k=0,n,w,t;
    printf("enter weight capacity:");
    scanf("%d",&w);
    printf("enter total number of product:");
    scanf("%d",&n);
    int weight[n+2];
    int value[n+2];
    int table[n+2][w+2];
    int z[n];
    
    
    for(i=2;i<n+2;i++)
    {
        printf("enter weight:");
        scanf("%d",&weight[i]);
        printf("enter value:");
        scanf("%d",&value[i]);
    }
    
    for(i=2;i<n+2;i++)
    for(j=2;j<n+1;j++)
    {
        if(weight[i]>weight[i+1])
        {
            t=weight[i];
            weight[i]=weight[i+1];
            weight[i+1]=t;
            t=value[i];
            value[i]=value[i+1];
            value[i+1]=t;
        }
    }

    for(i=1;i<=n+1;i++)
    table[i][0]=i-1;
    
    for(i=1;i<=w+1;i++)
    table[0][i]=i-1;

    for(i=1;i<=n+1;i++)
    table[i][1]=0;
    
    for(i=2;i<=w+1;i++)
    table[1][i]=0;

    for(i=2;i<=n+1;i++)
    {
        for(j=2;j<=w+1;j++)
        {
            if(weight[i]>table[0][j])
            table[i][j]=table[i-1][j];
            else
            table[i][j]=max(table[i-1][j],value[i]+table[i-1][1+table[0][j]-weight[i]]);
        }
    }
i=n+1;
j=w+1;
int x=0;
while(x!=table[n+1][w+1])
{
    while (table[i][j]==table[i-1][j] && i>1)
    {
        i--;
    }
    x+=value[i];
    z[k]=weight[i];
    k++;
    j=table[0][j]-weight[i]+1;    
    i--;
}
    printf("maximum profit is: %d\n",table[n+1][w+1]); 
    printf("weight of selected product is: ");
    for(i=0;i<k;i++)
    printf("%d ",z[i]);
    printf("/nend");
    getch();
    
}
