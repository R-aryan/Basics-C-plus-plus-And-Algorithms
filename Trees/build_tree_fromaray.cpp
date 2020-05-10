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

node* build_tree_fromarray(int *a,int s,int e){
    if(s>e)
        return NULL;
    //recursive case
    int mid=(s+e)/2;
    node *root= new node(a[mid]);
    root->left= build_tree_fromarray(a,s,mid-1);
    root->right=build_tree_fromarray(a,mid+1,e);
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

int main(){
    cout<<"Enter the number of elements....\n";
    int n,i;
    cin>>n;
    int a[n];
    for(i=0;i<n;i++)
        cin>>a[i];
    node *root= build_tree_fromarray(a,0,n-1);
    cout<<"The level order traversal of the tree is...\n";
    bfs(root);

}
