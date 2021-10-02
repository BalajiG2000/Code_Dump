/*
#include<stdio.h>
main()
{
	int n,i,f,j;
	printf("Enter your choice:");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		f=0;
		if(n%i==0)
		{
			for(j=1;j<=i;j++)
			{
				if(i%j==0)
				{
					f=f+1;
				}
			}
			if(f==2)
			printf("%d ",i);
		}
	}
}    */

#include<stdio.h>
main()
{
	int n,i,f=0;
	printf("Enter your choice:");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		if(n%i==0)
		f=f+1;
	}
	if(f==1)
	printf("%d is neither prime nor composite number",n);
	else if(f==2)
	printf("%d is prime number",n);
	else
	printf("%d is composie number",n);
}
