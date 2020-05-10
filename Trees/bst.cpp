#include<iostream>
#include<queue>
using namespace std;

class node{
public:
    int data;
    node *right;
    node *left;
    node(int d){
        data=d;
        right=left=NULL;
    }

};

node* insert_into_bst(node *root,int d){
    if(root==NULL){
        return new node(d);
    }
    if(d<=root->data){
       root->left=insert_into_bst(root->left,d);
    }
    else{
        root->right=insert_into_bst(root->right,d);
    }
    return root;
}


node* build_bst(){
    int d;
    cin>>d;
    node *root=NULL;
    while(d!=-1){
        root=insert_into_bst(root,d);
        cin>>d;

    }

    return root;
}

void bfs(node *root){
    queue<node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node *f=q.front();
        if(f==NULL){
            cout<<endl;
            q.pop();
            if(!q.empty())
                q.push(NULL);
        }
        else{
            cout<<f->data<<" ";
            q.pop();
            if(f->left)
                q.push(f->left);
            if(f->right)
                q.push(f->right);
        }
    }

}

void inorder(node *root){
    if(root==NULL)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);

}

bool searching(node *root,int d){
    if(root==NULL)
        return false;
    if(root->data==d)
        return true;
    if(d<=root->data)
        return searching(root->left,d);
    else
        return searching(root->right,d);

}

int main(){
    int d;
    cout<<"Enter the number you want to insert in BST except -1...\n";
    node *root=build_bst();
    cout<<"The BFS traversal of the tree is...\n";
    bfs(root);
    cout<<"The in-order traversal of the tree is...\n";
    inorder(root);
    cout<<"\n Enter the element you want to search....\n";
    cin>>d;
    if(searching(root,d))
        cout<<"The data "<<d<<" is present..\n";
    else
        cout<<"The data "<<d<<" is not present....\n";



}
