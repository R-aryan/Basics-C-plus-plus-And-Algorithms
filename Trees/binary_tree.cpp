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
        left=NULL;
        right=NULL;}

};

node* build_tree(){
    int d;
    cin>>d;
    if(d==-1)
        return NULL;
    node* root= new node(d);
    root->left=build_tree();
    root->right=build_tree();
    return root;

}

void print_tree_preorder(node *root){
    if(root==NULL)
        return;
    cout<<root->data<<" ";
    print_tree_preorder(root->left);
    print_tree_preorder(root->right);


}

void print_tree_inorder(node *root){
    if(root==NULL)
        return;

    print_tree_preorder(root->left);
    cout<<root->data<<" ";
    print_tree_preorder(root->right);

}

void print_tree_postorder(node *root){
    if(root==NULL)
        return;

    print_tree_preorder(root->left);
    print_tree_preorder(root->right);
     cout<<root->data<<" ";

}

int height(node* root){
    if(root==NULL)
        return 0;
    int ls= height(root->left);
    int rs= height(root->right);
    return max(ls,rs)+1;
}

void print_kth_level(node *root,int k){
    if(root==NULL)
        return;
    if(k==1)
        cout<<root->data<<" ";
    print_kth_level(root->left,k-1);
    print_kth_level(root->right,k-1);
}

void print_all_level(node *root){
    int h,i;
    h=height(root);
    for(i=1;i<=h;i++)
    {
        print_kth_level(root,i);
        cout<<endl;
    }
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
        if(f->left){
            q.push(f->left);
            }
        if(f->right){
            q.push(f->right);
        }
    }
    }
}

int count_nodes(node *root){
    if(root==NULL)
        return 0;
    return 1+count_nodes(root->left)+count_nodes(root->right);
}

int nodes_sum(node *root){
    if(root==NULL)
        return 0;

    return root->data+nodes_sum(root->left)+nodes_sum(root->right);
}


int diameter(node *root){
    if(root==NULL)
        return 0;
    int h1=height(root->left);
    int h2=height(root->right);
    int op1=h1+h2;
    int op2=diameter(root->left);
    int op3=diameter(root->right);

    return max(op1,max(op2,op3));

}

class Pair{
public:
    int height;
    int diameter;
};

Pair fastDiameter(node *root){
    Pair p;
    if(root==NULL){
        p.diameter=p.height=0;
        return p;
    }
    Pair left=fastDiameter(root->left);
    Pair right= fastDiameter(root->right);
    p.height=max(left.height,right.height)+1;
    p.diameter=max(left.height+right.height,max(left.diameter,right.diameter));
    return p;
}

int main(){
    node *root=build_tree();
    cout<<"The tree in preorder is....\n";
    print_tree_preorder(root);cout<<endl;
    cout<<"Height of the tree is .. "<<height(root)<<endl;
    cout<<"Level order traversal is.... \n";
    print_all_level(root);
    cout<<"\n BFS traversal...\n";
    bfs(root);
    cout<<"Total number of nodes is... "<<count_nodes(root)<<endl;
    cout<<"Sum of nodes is.... "<<nodes_sum(root)<<endl;
    cout<<"The diameter of the tree is.... "<<diameter(root)<<endl;
    Pair p= fastDiameter(root);
    cout<<"Diameter of the tree using fast approach.... "<<p.diameter<<endl;
}
