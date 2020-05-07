#include<iostream>
using namespace std;

class node{
public:
    int data;
    node *next;

    node(int d){
        data=d;
        next=NULL;
    }
};

int length(node *head){
    int l=0;
    while(head!=NULL){
        head= head->next;
        l++;

    }
    return l;
}
void insert_at_head(node *&head,int data){//passing the pointer variable by reference
    node *n=new node(data);
    n->next=head;
    head=n;

}

void insert_at_tail(node *&head,int data){
    if(head==NULL){
        insert_at_head(head,data);
    }
    else{
        int c=1;
        node *temp=head;
        while(c<=length(head)-1){
            temp=temp->next;
            c+=1;
        }
        node *n=new node(data);
        n->next=temp->next;
        temp->next=n;
    }

}
void buildlist(node *&head){
    cout<<"enter the list elements except -1  \n"<<"You can enter -1 to terminate \n";
    int data;
    cin>>data;
    while(data!=-1){
        insert_at_tail(head,data);
        cin>>data;
    }

}
istream& operator>>(istream&is,node *&head){
    buildlist(head);
    return is;
}


node* midpoint(node *head){
    if(head==NULL||head->next==NULL){
        return head;
    }
    node *slow=head;
    node *fast=head->next;
    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;

}



void print(node *head){
    node *temp=head;
    cout<<"\n The list is..\n";
    while(temp!=NULL){
        cout<<temp->data<<" -> ";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}
ostream& operator<<(ostream &os,node *head){
    print(head);
    return os;
}

node* merge_list(node *a,node*b){
    //node *c;
    if(a==NULL)
        return b;
    else if(b==NULL)
        return a;

    node *c;

    if(a->data<b->data){
        c=a;
        c->next=merge_list(a->next,b);
        }
    else {
        c=b;
        c->next=merge_list(a,b->next);
        }
    return c;

}

node* merge_sort(node *head){
    if(head==NULL || head->next==NULL)
        return head;
     //rec case
     //1. finding midpoint
    node *mid= midpoint(head);
    node *a=head;
    node *b=mid->next;
    mid->next=NULL;
    //recursively sort
    a=merge_sort(a);
    b=merge_sort(b);
    //merge list
    node *c=merge_list(a,b);
    return c;

}

int main(){
    node *head=NULL;
    node *head2=NULL;
    cout<<"Enter elements of  linked list...\n";
    cin>>head;
    cout<<head<<endl;
    node *s=merge_sort(head);
    cout<<"After sorting...\n";
    cout<<s;
    //cout<<"Merging two lists...\n";
    //node *m=merge_list(head,head2);
    //cout<<m<<endl;    //buildlist(head);
    //print(head);

}
