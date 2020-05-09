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

void insert_at_head(node *&head,int data){//passing the pointer variable by reference
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


void reverse_list(node *&head){
    node *current=head;
    node *pre=NULL;
    node *n;
    while(current!=NULL){
        //save the next node
        n=current->next;
        // make the current node point to previous
        current->next=pre;
        // update current and previous
        pre=current;
        current=n;

    }
    head=pre;

}

node* reverse_rec(node *head){
    if(head->next==NULL||head==NULL)
        return head;
    node *smallhead= reverse_rec(head->next);
    node *current=head;
    current->next->next=current;
    current->next=NULL;
    return smallhead;
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
        /*reverse_list(head);
        cout<<"The list after reversing is...\n";
        print(head);*/

        head=reverse_rec(head);
        cout<<"The list after reversing using recurrence function is...\n";
        print(head);
}
