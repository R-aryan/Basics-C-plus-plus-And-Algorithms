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

node *build_tree(){
    int d;
    cin>>d;
    if(d==-1)
        return NULL;
    node *root= new node(d);
    root->left=build_tree();
    root->right=build_tree();

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

node* create_tree_from_traversal(int *ino,int *pre,int s,int e){
    static int in=0;
    if(s>e)
        return NULL;

    node *root= new node(pre[in]);
    int j,index;
    index=-1;
    for(j=s;s<=e;j++){
        if(ino[j]==pre[in]){
            index=j;
            break;}
    }
    in++;
    root->left= create_tree_from_traversal(ino,pre,s,index-1);
    root->right= create_tree_from_traversal(ino,pre,index+1,e);

}

int main(){
    int in[]={3,2,8,4,1,6,7,5};
    int pre[]={1,2,3,4,8,5,6,7};
    node *root=create_tree_from_traversal(in,pre,0,7);
    cout<<"The BFS traversal of the tree formed is....\n";
    bfs(root);


}
