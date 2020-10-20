#include<stdio.h>
#include<stdlib.h>
#define size 5
struct stack 
{
    int item;
    int stack[size];
}s;
int top=-1;
void push()
{
    if(top==size-1)
    {
        printf("stack is full element cannot be pushed");
    }
    else
    {
        top=top+1;
        printf("enter element");
        scanf("%d",&s.item);
        s.stack[top]=s.item;
    }
    return(0);
}
void pop()
{
    if(top==-1)
    {
        printf("stack is empty element cannot be poped");
    }
    else
    {
        s.item=s.stack[top];
        top=top-1;
        printf("deleted data is %d",s.item);
    }
    return(0);
}
void display()
{
    int i;
    if(top==-1)
    {
        printf("stack empty nthg to display");   
    }
    else
    {
      for(i=top;i>0;i--)
     {
        printf("%d",s.stack[i]);
     }
    }
}
    
int main() {
    int c;
    
    while(1) {
    printf("enter a choice :");
    scanf("%d",&c);
    switch(c){
        case1:push();
              break;
        case2:
              
              pop();
              break;
        case3:display();
              break;
        default:return(0);
    }
    }
}
