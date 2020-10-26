/* Selin Sezi Elevli 201812023 Lab-1 */


#include <stdio.h>
#include <math.h>
void lastdigit(){
    int i1,i2;
    printf("Enter two non-negative number: ");
    scanf("%d", &i1);
    scanf("%d", &i2);
    if(i1%10 == i2%10)
        printf("true\n");
    else
        printf("false\n");
}
void ternary(){
    int t,deci=0, i=0;
    printf("enter a non-negative number: ");
    scanf("%d", &t);
    int sezi=t;
    while( t!=0 ){
        deci += (t%10) * pow(3,i);
        i++;
        t/=10;


    }
    printf("Decimal equivalent of %d is %d.\n", sezi,deci);

}
void youngadult(){
    int a1,a2,a3;

    printf("Enter three ages: ");
    scanf("%d", &a1);
    scanf("%d", &a2);
    scanf("%d", &a3);
    if((18<=a1&&a1<=30)||(18<=a2&&a2<=30)||(18<=a3&&a3<=30))
        printf("true\n");
    else
        printf("false\n");




}
void nines(){
    printf("Input a non-negative integer: ");
    int x;
    int count=0;
    scanf("%d",&x);

    while(x !=0){
        if(x%10==9)
            count++;
        x=x/10;
    }
    if (count==2)
        printf("true\n");
    else
        printf("false\n");
}



int main() {
    lastdigit();//compare 2 int. for finding that they have eaqual last digit.
    ternary();//convert a to ternary number to decimal number.
    youngadult();// Compare 3 in a range
    nines();//Are there any nine more than 2. 

    return 0;
}
