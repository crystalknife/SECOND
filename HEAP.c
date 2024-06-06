#include<stdio.h>
int i;
void swap(int a[],int x,int y)
{
    int temp = a[x];
    a[x]=a[y];
    a[y]=temp;
}

void heapify(int a[], int n, int i)
{
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;

    if(left<n && a[left] > a[largest]){
        largest = left;
    }

    if(right < n && a[right] > a[largest]){
        largest = right;
    } 

    if(largest!=i){
        swap(a,i,largest);
        heapify(a,n,largest);
    }
}

void heapsort(int a[], int n)
{
    for(i=n/2;i>=0;i--)
    {
        heapify(a,n,i);
    }    

    for(i=n-1;i>0;i--){
        swap(a,0,i);
        heapify(a,i,0);
    }
}

void printarray(int a[],int n)
{
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
    printf("\n");
}

int main()
{
    int a[50],n;
    printf("ENTER THE NUMBER OF ELEMENTS\n");
    scanf("%d",&n);
    printf("ENTER THE NUMBER OF ELEMENTS\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("UNSORTED ARRAY\n");
    printarray(a,n);
    heapsort(a,n);
    printf("SORTED ARRAY\n");
    printarray(a,n);
    return 0;
}