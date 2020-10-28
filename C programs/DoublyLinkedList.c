#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next,*prev;
};
struct node* create(struct node* head)                //create list
{
  struct node *last;
  int ch=1;
      printf("\nenter data in a node");
      scanf("%d",&head->data);
      head->prev=NULL;
      head->next=NULL;
  struct node *temp;

  while(ch==1)
  {
      temp=(struct node*)malloc(sizeof(struct node));
      printf("\nenter data in a node");
      scanf("%d",&temp->data);
      head->next=temp;
      temp->prev=head;
      head=head->next;
      printf("press 1 to add again");
      scanf("%d",&ch);
  }
   head->next=NULL;
   last=head;
   return last;
}
void display(struct node*head)                    //display in forward
{
    printf("\nDISPLAY IN FORWARD DIRECTION");
    printf("\n");
    while(head!=NULL)
    {
        printf("%d\t",head->data);
        head=head->next;
    }
}
void displayr(struct node*last)                           //display in reverse
{
    printf("\nDISPLAY IN REVERSE  DIRECTION");
    printf("\n");
    while(last!=NULL)
    {
        printf("%d\t",last->data);
        last=last->prev;
    }
}
void iinsert(struct node* head)                                //insert in bewt
{
    struct node*tempi;
    tempi=(struct node*)malloc(sizeof(struct node));
    int val;
    printf("\nenter the val after which you want to insert");
    scanf("%d",&val);
    while(head->data!=val)
    {
        head=head->next;
    }
    printf("\n enter the val to be inserted");
    scanf("%d",&tempi->data);
    tempi->next=head->next;
    head->next->prev=tempi;
    head->next=tempi;
    tempi->prev=head;
}
void linsert(struct node* head,struct node* last)                             //insert at last
{
    struct node*temp1;
    temp1=(struct node*)malloc(sizeof(struct node));
    printf("\nenter the value to be insert");
    scanf("%d",&temp1->data);
    last->next=temp1;
    temp1->prev=last;
    temp1->next=NULL;
    display(head);
}
struct node* finsert(struct node *head)                           //insert at first
{
    struct node*temp;
    temp=(struct node*)malloc(sizeof(struct node));   
   printf("\nenter the data to be inserted at first");
   scanf("%d",&temp->data);
   temp->prev=NULL;
   temp->next=head;
  head=temp;
display(head);
  return head;
}
void delete(struct node *head)            //delete intermediate
{
  struct node *newhead=head;
   int val,flag=0;
  printf("\n enter the value to be deleted");
  scanf("%d",&val);
   while(head!=NULL)
  {
    if(head->next->data==val)
     {
       flag=1;
      break;
     }
    head=head->next;
  }
  if(flag==1)
  {
    head->next=head->next->next;
    head->next->next->prev=head;
  }
  display(newhead);
}
 void ldelete(struct node *head,struct node *last)                   //delete the last node
{
    last->prev->next=NULL;
    last->prev=NULL;
    display(head);
}
 struct node* fdelete(struct node *head)                                        //delete the first node
{
 struct node *first=head;
   head->next->prev=NULL;
   first=head->next;
  head->next=NULL;
 display(first);
  return(first);
}
void modify(struct node *head)                                                       //modification
{
    struct node *first=head;
   int ndata;
   int val,flag=0;
printf("\n enter the value of node for which modification is required");
scanf("%d",&val);
while(head!=NULL)
{
  if(head->data==val)
   {
      flag=1;
      break;
   }
}
if(flag == 1)
{
  printf("\n record found");
  printf("\n enter the new data");
  scanf("%d",&ndata);
  head->data=ndata;
}
else
{
   printf("\n record not found");
}
  display(first);
}
int main()
{
  int ch,i;
  struct node *head,*last;
  head=(struct node*)malloc(sizeof(struct node));
for(i=0;i<10;i++)
{
  printf("\n 1.create the doubly linklist");
  printf("\n 2.display the doubly linklist in forward");
  printf("\n 3.display the doubly linklist in reverse");
  printf("\n 4.insert intermediate in the doubly linklist<after>");
  printf("\n 5.insert at last of the doubly linklist<after>");
  printf("\n 6.insert at first of the doubly linklist<after>");
  printf("\n 7.delete  (intermediate)in the doubly linklist");
  printf("\n 8.delete last node in the doubly linklist"); 
  printf("\n 9.delete first node in the doubly linklist"); 
  printf("\n 10.modify in the list");
  printf("\n enter your choice");
  scanf("%d",&ch);
 switch(ch)
{
case 1:
  last=create(head);
break;
case 2:
  display(head);
break;
case 3:
  displayr(last);
break;
case 4:
  iinsert(head);
  display(head);
break;
case 5:
  linsert(head,last);
break;
case 6:
  head=finsert(head);
  break;
case 7:
  delete(head);
break;
case 8:
 ldelete(head,last);
break;
case 9:
 head=fdelete(head);
break;
case 10:
  modify(head);
break;
}
}
}
