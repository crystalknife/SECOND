#include<stdio.h>
#define INFINITY 999
void main()
{
int i,j,k,n,a[20][20];
printf("\n\t\t ALL PAIRS SHORTEST PATH BY DYNAMIC PROGRAMMING \n");
printf("\n enter the number of vertices:\n”);
scanf("%d",&n);
printf("\n enter the cost adjacency matrix:\n");
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
scanf("%d",&a[i][j]);
}
}
for(k=0;k<n;k++)
{
for(j=0;j<n;j++)
{
for(i=0;i<n;i++)
{
a[i][j]=(a[i][j]<a[i][k]+a[k][j]?a[i][j]:a[i][k]+a[k][j]);
}
}
}
printf("|n THE SHORTEST PATH IS:\n");
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
printf("%d\t",a[i][j]);
}
printf("\n");
}
}