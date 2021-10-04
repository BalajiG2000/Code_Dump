#include<stdio.h>
int main()
{
int num[20];//create array size of 20
int n,i,count=0;
char like;
for(i=0;i<20;i++)
{
    printf("Enter number %d: ",i+1);//prompt user to enter 20 numbers
    scanf("%d",&num[i]);//stores numbers in an array
}
do{
    printf("\nEnter number you want to find : ");//prompt user to enter a number
    scanf("%d",&n);
    for(i=0;i<20;i++)
    {
        if( n==num[i])//counting the number user entered
        {
            count++;
        }
    }
    printf("Count=%d\n\n",count);
    count=0;
    printf("Do you want to count more (y/n) : ");//looping to prompt again
    getchar();
    scanf("%c",&like);
}
while(like=='y'|| like=='Y');
}
//By I.K.N.Manimendra