#include <stdio.h>
void towerOfHanoi(int,char,char,char);
main()
{
 int n;
 printf("Enter no of disks\n");
 scanf("%d",&n);
 towerOfHanoi(n, 'A', 'C', 'B');

}
void towerOfHanoi(int n, char from, char to, char temp)
{
 if (n == 1) 
{
 printf("Move disk 1 from %c to %c\n", from, to);
 return;
 
}
 towerOfHanoi(n-1, from, temp, to);
 printf("Move disk %d from %c to %c\n", n, from, to);
 towerOfHanoi(n-1, temp, to, from);

}
