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

bool detect_cycle(node *head){
    node *slow=head;
    node *fast=head;
    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
        if(fast==slow)
            return true;

    }
    return false;

}

void insert_at_head(node *&head,int data){
    //passing the pointer variable by reference
    node *n=new node(data);
    n->next=head;
    head=n;

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

node* kth_position(node *head,int k){
    int i;
    if(k>length(head))
    {
        cout<<"Invalid position...\n";
        return head;
    }
    node *fast=head->next;
    node *slow=head;
    for(i=1;i<k-1;i++)
        fast=fast->next;

    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next;
        slow=slow->next;
    }
    return slow;


}

int main(){
    node *head=NULL;
    int n,i,a;
    cout<<"Enter the number of elements you want to insert...\n";
    cin>>n;
    cout<<"Enter "<<n<<" elements....\n"<<"Inserting at head...\n";
    for(i=0;i<n;i++){
        cin>>a;
        //cout<<"Inserting at head of list...\n";
        insert_at_head(head,a);
        print(head);
        }
        node *m=midpoint(head);
        cout<<"The data at midpoint of list is.... "<<m->data<<endl;
        cout<<"Enter the kth position from the end you want to search...\n";
        cin>>a;
        node *k=kth_position(head,a);
        if(k!=head){
        cout<<a<<"th position from end is... "<<k->data<<endl;}

}
