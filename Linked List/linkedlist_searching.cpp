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
bool search_recursive(node *&head,int key){
    if(head==NULL)
        return false;
    else if(head->data==key)
        return true;
    else
        return search_recursive(head->next,key);

}

bool search_iterative(node *head,int key){
    while(head!=NULL){
        if(head->data==key)
            return true;
        else
            head=head->next;

    }
    return false;

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
    cout<<"Enter the element you want to search in the list....\n";
    cin>>a;
    if(search_iterative(head,a)){
            cout<<"Element "<<a<<" is present..\n";
        }
    else
        cout<<"Element not present...\n";
}
