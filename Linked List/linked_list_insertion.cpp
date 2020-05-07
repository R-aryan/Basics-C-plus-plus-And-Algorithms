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

/*class LinkedList{
    node *head;
    node *tail;
    LinkedList()
    {
        head=tail=NULL;
        }

};*/

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
void insert_at_middle(node *&head,int data,int pos){
    int c=1;
    if(head==NULL){
        insert_at_head(head,data);
    }
    else if(pos> length(head)){
        cout<<"Position Invalid so inserting at tail...\n";
        insert_at_tail(head,data);
    }
    else{
         node *temp= head;
        while(c<=pos-1){
            temp=temp->next;
            c+=1;
        }
        node *n=new node(data);
        n->next=temp->next;
        temp->next=n;
    }
}

void delete_at_head(node *&head){
    if(head==NULL)
        return;
    node *temp=head;
    head= temp->next;
    delete(temp);
    return;
}


void delete_at_tail(node *&head){
    //int c=1;
    if(head==NULL)
        return;
    node *temp=head;
    node *prev=NULL;
    while(temp->next!=NULL){
        prev=temp;
        temp=temp->next;
        }
    delete temp;
    prev->next=NULL;


}

void delete_from_middle(node *&head,int pos){
    if(head==NULL){
        return;
    }
    else if(pos>length(head)){
        cout<<"Invalid position...\n";
        return;
    }
    node *temp=head;
    node *next_add=NULL;
    node *prev=NULL;
    int c=1;
    while(c<=pos-1){
        prev=temp;
        temp=temp->next;
        next_add=temp->next;
        c+=1;
    }
    prev->next=next_add;
    delete  temp;


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
        /*cout<<"\n Inserting in middle(at position 8 and then 3 ...\n";
        insert_at_middle(head,32,8);
        print(head);
        insert_at_middle(head,45,3);
        print(head);
        cout<<"\n Inserting at tail of the list...\n";
        insert_at_tail(head,15);
        print(head);
        insert_at_tail(head,100);
        print(head);
        cout<<"Deleting from head..."<<" The list becomes...\n";
        delete_at_head(head);
        print(head);
        cout<<"Deleting from tail...."<<" The list becomes \n";
        delete_at_tail(head);
        print(head);*/
        cout<<" Deleting from middle...(from position 4) \n";
        delete_from_middle(head,4);
        print(head);


}
