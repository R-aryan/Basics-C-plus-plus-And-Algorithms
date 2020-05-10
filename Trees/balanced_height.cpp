#include<iostream>
#include<queue>
#include<cmath>
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

class Hbpair{
public:
    int height;
    bool balanced;

};

Hbpair is_balanced(node *root){
    Hbpair p;
    if(root==NULL){
        p.height=0;
        p.balanced=true;
        return p;
    }
    Hbpair left= is_balanced(root->left);
    Hbpair right= is_balanced(root->right);

    p.height=max(left.height,right.height)+1;

    if(abs(left.height-right.height)<=1 && left.balanced && right.balanced ){
            p.balanced=true;

    }
    else{
        p.balanced=false;
    }
    return p;
}

int main(){
    node *root=build_tree();
    Hbpair p= is_balanced(root);
    if(p.balanced){
        cout<<"The tree is balanced...\n";
    }
    else
        cout<<"The tree is not balanced.....\n";
}
