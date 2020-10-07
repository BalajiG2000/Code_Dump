# include <stdio.h>
# include <stdlib.h>

void swap (int *x, int *y)
{

    int temp=*x;
    *x=*y;
    *y=temp;

}

void selectionSort(int *q,int n)
{
    int i,j,minindex;
    for(i=0;i<n-1;i++)
    {
        minindex=i;
        for(j=i+1;j<n;j++)
        {
            if(q[minindex]>q[j])
            {

                minindex=j;
            }

            swap(&q[minindex],&q[i]);

    }
        minindex=j;
    }
}

void printArray(int *a,int n){
int i;
for(i=0;i<n;i++)
{printf("%d-",a[i]);
}
printf("\n");


}
int main ( void )
{

int *a;
int n,i,j;
printf("enter size of array  : \n");
scanf("%d",&n);
a=(int*)calloc(n,sizeof(n));
for(i=0;i<n;i++){
printf("enter element number %d : \n",(i+1));
scanf("%d",&a[i]);
}
printf("The original array is : \n");
printArray(a,n);
selectionSort(a,n);
printf("The sorted array is :\n ");
printArray(a,n);
return 0;

}