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

node* build_tree(){
     int d;
     cin>>d;
     if(d==-1)
        return NULL;
     node *root=new node(d);
     root->left=build_tree();
     root->right=build_tree();
     return root;
}


int replace_sum(node *root){
    if(root==NULL)
        return 0;
    if(root->left==NULL && root->right==NULL)
        return root->data;
    //recursive part
    int ls=replace_sum(root->left);
    int rs=replace_sum(root->right);

    int temp=root->data;
    root->data=ls+rs;
    return temp+root->data;
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

int main(){
    node *root=build_tree();
    cout<<"BFS traversal before sum replacement is...\n";
    bfs(root);
    cout<<"Tree after sum replacement...\n";
    replace_sum(root);
    bfs(root);

}
