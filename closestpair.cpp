#include<stdio.h>

#include<stdlib.h>

#include<limits.h>

#include<math.h>
typedef struct Point
{
     int x;
     int y;
}Point;
typedef struct Ans
{
    double dMin;
    Point P1;
    Point P2;
}Ans;
int SortWrtX(Point*L,Point*R,int i,int j)
{
    if(L[i].x<=R[j].x)
    {
        return 1;
    }
    else
        return 0;
}
int SortWrtY(Point*L,Point*R,int i,int j)
{
    if(L[i].y<=R[j].y)
        return 1;
    else
        return 0;
}
void inputPoints(Point* arr,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%d%d",&(arr[i].x),&(arr[i].y));
    }
}
void printPoints(Point* arr,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d %d\n",arr[i].x,arr[i].y);
    }
}
void merge(Point* arr,int l,int m,int r,int info)
{
    int(*func_ptr)(Point*,Point*,int,int);
    int i,j,k;
    int n1=m-l+1;
    int n2=r-m;
    Point*L=(Point*)calloc(n1,sizeof(Point));
    Point*R=(Point*)calloc(n2,sizeof(Point));
    for(i=0;i<n1;i++)
    {
        L[i].x=arr[l+i].x;
        L[i].y=arr[l+i].y;
    }
    for(j=0;j<n2;j++)
    {
        R[j].x=arr[m+1+j].x;
        R[j].y=arr[m+1+j].y;
    }
    i=0;j=0;k=l;
    if(info==1)
        func_ptr=&SortWrtX;
    else
        func_ptr=&SortWrtY;
    while(i<n1&&j<n2)
    {
        if(func_ptr(L,R,i,j))
        {
            arr[k].x=L[i].x;
            arr[k].y=L[i].y;
            i++;
        }
        else{
            arr[k].x=R[j].x;
            arr[k].y=R[j].y;
            j++;
        }
        k++;
    }
    while(i<n1)
    {
            arr[k].x=L[i].x;
            arr[k].y=L[i].y;
            i++;
            k++;
    }
    while(j<n2){
            arr[k].x=R[j].x;
            arr[k].y=R[j].y;
            j++;
            k++;
    }
}
void mergeSort(Point* arr,int l,int r,int info)
{
    if(l<r)
    {
        int m=l+(r-l)/2;
        mergeSort(arr,l,m,info);
        mergeSort(arr,m+1,r,info);
        merge(arr,l,m,r,info);
    }
}
double calDistance(Point P1,Point P2)
{
    return sqrt((P1.x-P2.x)*(P1.x-P2.x)+(P1.y-P2.y)*(P1.y-P2.y));
}
Ans bruteForce(Point* Px,int n)
{
    int i,j; double min=(double)INT_MAX;Ans ans;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(calDistance(Px[i],Px[j])<min)
            {
                min=calDistance(Px[i],Px[j]);
                ans.dMin=min;
                ans.P1=Px[i];
                ans.P2=Px[j];
            }
        }
    }
    return ans;
}
void constructQx(Point*Px,Point*Qx,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        Qx[i]=Px[i];
    }
}
void constructRx(Point*Px,Point*Rx,int l,int n)
{
    int i;
    for(i=l;i<n;i++)
    {
        Rx[i-l]=Px[i];
    }
}
void constructQy(Point*Py,Point*Qy,int n)
{
    int m,i,j=0;m=n/2;
    for(i=0;i<n;i++)
    {
        if(Py[i].x<=Py[m-1].x)
        {
            Qy[j]=Py[i];
            j++;
        }
    }
}
void constructRy(Point*Py,Point*Ry,int n)
{
    int i,j=0,m=(n/2);
    for(i=0;i<n;i++)
    {
        if(Py[i].x>Py[m-1].x)
        {
            Ry[j]=Py[i];
            j++;
        }
    }
}
Ans closestStrip(Point*Sy,int n,double d)
{
    double min=d; int i,j; Ans ans;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n&&(Sy[j].y-Sy[i].y)<min;j++)
        {
            if(calDistance(Sy[i],Sy[j])<min)
            {
                min=calDistance(Sy[i],Sy[j]);
                ans.dMin=min;
                ans.P1=Sy[i];
                ans.P2=Sy[j];
            }
        }
    }
    return ans;
}
Ans closestPair(Point*Px,Point*Py,int n)
{
    if(n<=3)
    {
        return bruteForce(Px,n);
    }
    int m=n/2;
    Point* Qx=(Point*)calloc(m,sizeof(Point));
    Point* Qy=(Point*)calloc(m,sizeof(Point));
    Point* Rx=(Point*)calloc((n-m),sizeof(Point));
    Point* Ry=(Point*)calloc((n-m),sizeof(Point));
    constructQx(Px,Qx,m);
    constructRx(Px,Rx,m,n);
    constructQy(Py,Qy,n);
    constructRy(Py,Ry,n);
    Ans ans1=closestPair(Qx,Qy,m);
    Ans ans2=closestPair(Rx,Ry,(n-m));
    double dmin=(ans1.dMin)>(ans2.dMin)?ans2.dMin:ans1.dMin;
    Ans ans=(ans1.dMin)>(ans2.dMin)?ans2:ans1;
    Point* Sy=(Point*)calloc(n,sizeof(Point));
    int i,j=0;
    for(i=0;i<n;i++)
    {
        if((Py[i].x-Py[m-1].x)>=(-1*dmin)&&(Py[i].x-Py[m-1].x)<=(dmin))
        {
            Sy[j]=Py[i];
            j++;
        }
    }
    Ans ans3=closestStrip(Sy,n,dmin);
    return (ans.dMin)<dmin?ans3:ans;
}
void copyPx(Point*arr,Point*Px,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        Px[i]=arr[i];
    }
}
void copyPy(Point*arr,Point*Py,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        Py[i]=arr[i];
    }
}
int main()
{
    int n;
    printf("Number of points to be inserted\n");
    scanf("%d\n",&n);
    Point* arr=(Point* )calloc(n,sizeof(Point));
    Point* Px=(Point* )calloc(n,sizeof(Point));
    Point* Py=(Point* )calloc(n,sizeof(Point));
    inputPoints(arr,n);
    printPoints(arr,n);
    mergeSort(arr,0,n-1,1);
    copyPx(arr,Px,n);
   mergeSort(arr,0,n-1,0);
    copyPy(arr,Py,n);
    printPoints(Px,n);
    printPoints(Py,n);
    Ans answer=closestPair(Px,Py,n);
    printf("%lf Minimum Distance: \n",answer.dMin);
    printf("%d %d Point 1: \n",answer.P1.x,answer.P1.y);
    printf("%d %d Point 2: \n",answer.P2.x,answer.P2.y);
}
