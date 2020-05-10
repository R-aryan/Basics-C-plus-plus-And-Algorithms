#include<iostream>
#include<queue>
#include<climits>
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

void inorder(node *root){
    if(root==NULL)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);

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

node* insert_into_bst(node *root,int d){
    if(root==NULL)
        return new node(d);
    if(root->data>=d)
        root->left=insert_into_bst(root->left,d);
    else
        root->right=insert_into_bst(root->right,d);
    return root;

}

node* build_bst(){
    int d;
    node *root=NULL;
    cin>>d;
    while(d!=-1){
        root=insert_into_bst(root,d);
        cin>>d;

    }
    return root;

}

node* delete_in_bst(node *root,int d){
    if(root==NULL)
        return NULL;
    if(root->data>d){
        root->left=delete_in_bst(root->left,d);
        return root;
        }
    else if(root->data==d){
            //data is found now 3 cases
            //case1 - leaf node
            if(root->left==NULL && root->right==NULL){
                delete root;
                return NULL;
            }
            //case 2- only one child is there
            if(root->left!=NULL && root->right==NULL){
                node *temp=root->left;
                delete root;
                return temp;
            }
            if(root->right!=NULL && root->left==NULL){
                node *temp=root->right;
                delete root;
                return temp;
            }
            // case 3 when both of the child exists

                node *rp=root->right;
                //find successor in the right subtree
                while(rp->left!=NULL){
                    rp=rp->left;
                }
                root->data=rp->data;
                root->right=delete_in_bst(root->right,rp->data);
                return root;


    }
    else{
        root->right=delete_in_bst(root->right,d);
        return root;
    }

}

bool is_bst(node *root,int minv=INT_MIN,int maxv=INT_MAX){
    if(root==NULL)
        return true;
    if(root->data>=minv && root->data<=maxv && is_bst(root->left,minv,root->data)&& is_bst(root->right,root->data,maxv) )
        return true;

    return false;
}

int main(){
    int d;
    cout<<"Enter the number you want to insert in BST except -1...\n";
    node *root=build_bst();
    cout<<"The BFS traversal of the tree before deletion is...\n";
    bfs(root);
    cout<<"The in-order traversal of the before deletion tree is...\n";
    inorder(root);
    /*cout<<"\n Enter the element you want to delete....\n";
    cin>>d;
    root=delete_in_bst(root,d);
    cout<<"\n In-order traversal after deletion....\n";
    inorder(root);
    cout<<"\n Bfs traversal after deletion..\n";
    bfs(root);*/
    if(is_bst(root))
        cout<<"\n The tree is bst...\n";
    else
        cout<<"\n The tree is not bst...\n";

}
