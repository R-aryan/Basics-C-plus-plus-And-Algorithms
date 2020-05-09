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
int main(){
    node *head=NULL;
    node *head2=NULL;
    cout<<"Enter the two sorted linked list...\n";
    cin>>head>>head2;
    cout<<head<<endl<<head2;
    cout<<"Merging two lists...\n";
    node *m=merge_list(head,head2);
    cout<<m<<endl;    //buildlist(head);
    //print(head);

}
