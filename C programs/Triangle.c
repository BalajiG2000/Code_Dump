#include <stdio.h>
#include <conio.h>
int main() {
         int a,b,c;
         printf("Enter the three sides of the triangle \n");
         scanf("%d %d %d",&a,&b,&c);
            
      if (a+b>c && b+c>a && a+c>b){
            
            if (a==b && b==c)
                printf("The triangle is Equilateral \n");
            
            else if (a==b || b==c || a==c)
                printf("The triangle is Isosceles \n");
            
            else
                printf("The triangle is scalene \n");
        
    }
        
    else
        printf("The given sides can not form a traingle as sum of 2 sides of a triangle must be greater than 3rd side \n");

    return 0;
}

