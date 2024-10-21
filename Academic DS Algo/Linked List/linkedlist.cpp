#include<iostream>
using namespace std;

class node
{
public:
    int data;
    node* next;
};
node* final=NULL;
node* head=final;
void insert(int n)
{
    //int n; cin>>n;
    node* newnode=new node;
    newnode->data=n;
    if(head==NULL)
    {
        newnode->next=NULL;
        head=newnode;
    }
    else
    {
        newnode->next=head;
        head=newnode;
    }
}
void deletemiddle()
{
    int abir; cin>>abir;
    node* tmp=head, *ex=head;
    while(tmp->data!=abir)
    {
        ex=tmp;
        tmp=tmp->next;
    }
    ex->next=tmp->next;
    delete tmp;
}
//we will insert data before x
void insertbefore(int x,int data)
{
    //temp will be the address of x, prev will be the address of previous node of x
    node *prev=head,*temp=head;

    node *newnode =new node;
    newnode->data=data;
    //x is the head
    while(temp->data!=x)
    {
        prev=temp;
        temp=temp->next;
    }
    if(temp==head)
    {
        newnode->next=head;
        head=newnode;
    }
    else
    {
        newnode->next=prev->next;
        prev->next=newnode;
    }
}

void traverse()
{
    node* tmp=head;
    while(tmp!=NULL)
    {
        cout<<tmp->data<<" ";
        tmp=tmp->next;
    }
}
int main()
{
    insert(5);
    insert(6);
    insert(9);
    insertbefore(5,4);
    insertbefore(6,1);
    insertbefore(9,10);
    insertbefore(10,100);
    //deletemiddle();
    traverse();
}
