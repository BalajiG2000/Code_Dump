//Program for taking nodes input in Linked List from user in C++
#include<iostream>
#include<cstdlib>
using namespace std;
struct Node{
	int data;
	Node*next;
};
Node*Create_Node_In_Linked_list(Node*head)
{
	int data;
	cout<<"Enter the data of Linked List:\t";
	cin>>data;
	Node*p=(Node*)malloc(sizeof(Node));
	p->data=data;
	p->next=NULL;
	Node*ptr;
	if(head==NULL)
	{
		head=p;
		ptr=head;
		return head;
	}
	else
	{
		ptr->next=p;
		ptr=p;
		return head;
	}
}
void print_Linked_List(Node*head)
{
	Node*p=head;
	while(p!=NULL)
	{
		cout<<"Element is:\t"<<p->data<<"\n";
		p=p->next;
	}
}
int main()
{
	int n,i;
	cout<<"Enter the number of Nodes you want in Linked List:\t";
	cin>>n;
	Node*head=NULL;
	for(i=0;i<n;i++)
	{
		head=Create_Node_In_Linked_list(head);
	}
	print_Linked_List(head);
	return 0;
}

