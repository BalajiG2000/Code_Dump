#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct NODE
{
	int info;
	struct NODE *next;
};
typedef struct NODE *cnode;
cnode insertl(cnode ,int);
cnode insertb(cnode ,int);
cnode insertsp(cnode ,int,int);
cnode createnode(cnode,int);
cnode deletel(cnode);
cnode deleteb(cnode );
cnode deletesp(cnode,int);
int lsize(cnode);
void display(cnode);
void main()
{

	cnode start=NULL;
	int a,b,c,x,e,n ;
	clrscr();
	do
	{
	   printf("enter the choice \n 1: insert from begin\n 2:insert to last\n3:insert at specified position\n4:delete from first\n 5:delete at last\n 6: delete from specified position\n 7:display\n");
	   printf("\n8.size");
	   scanf("%d",&c);
	    switch(c)

		{
			case 1: printf("enter a no");
				scanf("%d",&x);
				start =insertb(start,x);
				break;
			case 2: printf("enter a no");
				scanf("%d",&x);
				start=insertl(start,x);

				break;
			case 3:printf("enter a no");
				scanf("%d",&x);
				printf("enter the position");
				scanf("%d",&a);
				start=insertsp(start,x,a);
				break;

			case 4:

				start=deleteb(start) ;
				break;

			case 5:

				start=deletel(start);
				break;
			case 6:
				printf("enter a position");
				scanf("%d",&e);
				start=deletesp(start,e);
				break;
			case 7:
				display(start);
				break;
			case 8:
				printf("length is =%d",lsize(start));
				break;

			default:
				printf("wrong choice");

}
  printf("if u want to continue press 1 ");
  scanf("%d",&b);

}while(b==1);

  getch();
}
void display(cnode f)
{
	cnode t;
	int i;
	if(f==NULL)
		printf("underflow");
	else
	{
		t=f;
		do
		{
			printf("%d\n",t->info);
			t=t->next;
		}while(t!=f);
	}
}

cnode insertb(cnode f, int x)
{
	cnode temp,t;
	temp=createnode(temp,x);
	if(f==NULL)
	{
		f=temp;
		temp->next=f;
		return f;
	}
	else
	{
		for(t=f;t->next!=f;t=t->next);
		t->next=temp;
		temp->next=f;
		f=temp;
		return f;
	}
}
cnode insertl(cnode f, int x)
{
	int i;
	cnode temp,t;
	temp=createnode(temp,x);

	if(f==NULL)
	{
		f=temp;
		temp->next=f;
		return f;
	}
	else
	{
		for(t=f;t->next!=f;t=t->next);
		t->next=temp;
		temp->next=f;

		return f;
	}
}
cnode createnode(cnode f,int x)
{
	f=(cnode)malloc(sizeof(struct NODE));
	f->info=x;
	f->next=NULL;
	return f;
}
cnode insertsp(cnode f, int x,int pos)
{
	int i,j;
	cnode temp,t;
	temp=createnode(temp,x);
	i=lsize(f);
	if(pos==1)
	{
		f=insertb(f,x);
		return f;
	}
	else if(pos==i+1)
	{
		f=insertl(f,x);
		return f;
	}

	else if(pos>(i+1))
	{
		printf("insertion at this position not possible");

		return f;
	}
	else  if(pos<=i)
	{
		cnode t1;
		temp=createnode(temp,x);
		for(t=f,j=1;j<(pos-1);j++,t=t->next);

		temp->next=t->next;
		t->next=temp;
		return f;
	}
}

int lsize(cnode f)
{
	int i;
	cnode t;
	if (f==NULL)
	 return 0;
	else
	{
	 for(i=0,t=f;t->next!=f;t=t->next,i++);
	 return i+1;
	}
}
cnode deleteb(cnode f)
{
	cnode t,t1;
	if(f==NULL)
	{
		printf("underflow");
		return f;
	}
	else if(f->next==f)
	{
		t=f;
		printf("deleted item=%d",t->info);
		f=NULL;
		free(t);
		return f;
	}
	else
	{
		for(t=f;t->next!=f;t=t->next);
		t1=f;
		f=t1->next;
		t->next=f;
		printf("deleted item=%d",t1->info);
		free(t1);
		return f;
	}
}
cnode deletel(cnode f)
{
	cnode t,t1;
	if(f==NULL)
	{
		printf("underflow");
		return f;
	}
	else if(f->next==f)
	{
		t=f;
		printf("deleted item=%d",t->info);
		free(t);
		f=NULL;
		return f;
	}
	else
	{
		for(t=f;t->next!=f;t1=t,t=t->next);
		t1->next=f;
		printf("deleted item=%d",t->info);
		free(t);
		return f;
	}
}

cnode deletesp(cnode f,int pos)
{
	cnode t,t1;
	int i,j;
	if(f==NULL)
	{
		printf("not posssible");
		return f;
	}
	i=lsize(f);
	if(pos==1)
	{
		f=deleteb(f);
		return f;
	}
	if(pos==i)
	{
	     f=deletel(f);
	     return f;
	}
	if(pos>i)
	{
		printf("not possible");
		return f;
	}
	if(pos>1 && pos <i)
	{
		for(t=f,j=1;j<(pos);t1=t,j++,t=t->next);
		t1->next=t->next;

		printf("%d\n ",t->info);
		free(t);
		return f;
	}
}
