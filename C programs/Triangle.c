#include "Triangle.h"

int main() {
    printf("Enter the three sides of the triangle \n");
       int a,b,c;
       scanf("%d %d %d",&a,&b,&c);
            
    if (a+b>c && b+c>a && a+c>b){
            
            if (a==b && b==c)
                printf("The triangle is Equilateral \n");
            
            else if (a==b || b==c || a==c)
                printf("The triangle is Isosceles \n");
            
            else if(a!=b && b!=c && a!=c)
                printf("The triangle is scalene \n");
        
    }
        
    else
        printf("The given sides can not form a traingle \n");

    return 0;
}

