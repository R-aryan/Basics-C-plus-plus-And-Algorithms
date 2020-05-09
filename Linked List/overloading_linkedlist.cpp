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

void buildlist(node *&head){
    cout<<"enter the list elements except -1  \n"<<"You can enter -1 to terminate \n";
    int data;
    cin>>data;
    while(data!=-1){
        insert_at_head(head,data);
        cin>>data;
    }

}

istream& operator>>(istream &is, node *&head){
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

int main(){
    node *head=NULL;
    node *head2=NULL;
    cin>>head>>head2;
    cout<<head<<endl<<head2;
    //buildlist(head);
    //print(head);

}

