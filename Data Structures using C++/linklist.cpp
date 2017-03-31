#include<iostream>
#include<cstdio>
using namespace std;
struct node
{
    int data;
    node* next;
};
node* A;
void print()
{
    node* temp1= A;
    cout<<"the list is \n";
    while(temp1!= NULL)
    {
        cout<<temp1->data<<" ";
        temp1= temp1->next;
    }
    cout<<"\n";
}
void reverse_print(node* temp)
{
    if(temp==NULL)
        return;
    reverse_print(temp->next);
    cout<<temp->data<<"  ";

}
void insertion(int x,int n)
{
    node* temp1= new node();
    temp1->data= x;
    temp1->next=NULL;
    if(n==1)
    {
        temp1->next = A;
        A= temp1;
        return;
    }
    node* temp2=A;
    for(int j= 0;j<n-2;j++)
        temp2=temp2->next;
    temp1->next=temp2->next;
    temp2->next=temp1;
    cout<<"number successfully inserted and \n";
    print();
}
void ins(int x)
{
    node* temp = new node();
    temp->data= x;
    temp->next = NULL;
    if(A==NULL)
        A=temp;
    else
    {
        node *temp1= A;
        while(temp1->next!= NULL)
        {
            temp1=temp1->next;
        }
        temp1->next=temp;
    }
    cout<<"number successfully inserted at the tail and \n";
    print();

}

void append(int x)
{
    node* temp = new node();
    temp->data= x;
    temp->next= A;
    A = temp;
    cout<<"number successfully inserted at the head and  \n";
    print();
}
void del(int n)
{
    node* temp1=A;
    if(n==1)
    {
        A= temp1->next;
        delete(temp1);
    }
     node* temp2;node* temp3;
    for(int i= 0;i< n-2;i++)
        temp1=temp1->next;
    temp2= temp1->next;
    temp3= temp2->next;
    temp1->next= temp3;
    delete(temp2);

    cout<<"number successfully deleted \n";
    print();

}

void revers()
{
    node *current,*prev,*next;
    current = A;
    prev=NULL;
    while(current!=NULL)
    {
        next=current->next;
        current->next=prev;
        prev = current;
        current= next;
    }
    A=prev;
    cout<<"list is successfully reversed and \n";
    print();
}

int main()
{
    A= NULL;
    int c,n,i,a;
    ch:while(1)
    {
    cout<<"enter your choice \n"<<"1 for insertion at head of the link list \n";
    cout<<"2 for insertion at tail of the link list \n"<<"3 for insertion at n th position of the link list \n"<<"4 for deletion of element from link list \n";
    cout<<"5 for revrsing the contents of the linked list \n "<<"6 for printing the list in reverse order \n";

    cin>>c;
    switch(c)
    {
    case 1:
        cout<<"enter the number of numbers you want to insert in the list \n";
        cin>>n;cout<<"\n";
        cout<<"enter  "<<n<<"numbers \n";
        for(i=0;i<n;i++)
        {
           cin>>a;
           append(a);
        }
        break;
        case 2:
        cout<<"enter the number of numbers you want to insert in the list \n";
        cin>>n;cout<<"\n";
        cout<<"enter  "<<n<<"numbers \n";

        for(i=0;i<n;i++)
        {
           cin>>a;
           ins(a);
        }
        break;
        case 3:
        cout<<"enter the number of numbers you want to insert in the list \n";
        cin>>n;cout<<"\n";
        cout<<"enter  "<<n<<"numbers along with their positions \n";
         int pos;
        for(i=0;i<n;i++)
        {
           cin>>a>>pos;
           insertion(a,pos);
        }
        break;
        case 4:
            cout<<"enter the position you want to delete \n";
            int p;
            cin>>p;
            del(p);
            break;
        case 5:
            revers();
            break;
        case 6:
            cout<<"the list in reverse order is \n";
            reverse_print(A);


    }
    cout<<"enter 0 to exit and  any other key to continue \n";
    int an;cin>>an;
    if(an==0)
        break;
    }
}
