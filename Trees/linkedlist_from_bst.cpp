#include<iostream>
#include<queue>

using namespace std;

class node{
public:
    int data;
    node *left;
    node *right;
    node(int d){
        data=d;
        left=right=NULL;
    }

};

node* insert_into_bst(node *root,int d){
    if(root==NULL)
        return new node(d);
    if(root->data>=d)
        root->left=insert_into_bst(root->left,d);
    else
        root->right=insert_into_bst(root->right,d);
    return root;

}

node* build_tree(){
    int d;
    node *root=NULL;
    cin>>d;
    while(d!=-1){
        root= insert_into_bst(root,d);
        cin>>d;

    }
    return root;
}

class Linkedlist{
public:
    node *head;
    node *tail;
};

Linkedlist list_from_bst(node *root){
    Linkedlist l;
    if(root==NULL)
    {

        l.head=l.tail=NULL;
        return l;
    }
    //leaf node
    if(root->left==NULL && root->right==NULL)
    {
        l.head=l.tail=root;
        return l;
    }
    if(root->left!=NULL && root->right==NULL){
        Linkedlist leftl= list_from_bst(root->left);
        leftl.tail->right=root;

        l.head=leftl.head;
        l.tail=root;

        return l;
    }
    if(root->right!=NULL && root->left==NULL){
        Linkedlist rightl= list_from_bst(root->right);
        root->right=rightl.head;

        l.head=root;
        l.tail=rightl.tail;

        return l;

    }
    Linkedlist leftl=list_from_bst(root->left);
    Linkedlist rightl=list_from_bst(root->right);

    leftl.tail->right=root;
    root->right=rightl.head;

    l.head= leftl.head;
    l.tail=rightl.tail;

    return l;

}

void inorder(node *root){
    if(root==NULL)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);

}

int main(){
    node *root=build_tree();
    inorder(root);
    cout<<endl<<"\n";

    Linkedlist l= list_from_bst(root);
    node *temp= l.head;

    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->right;
    }
    cout<<"\n\n\n";

}

