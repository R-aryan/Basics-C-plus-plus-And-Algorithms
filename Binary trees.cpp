#include<iostream>
#include<string>
using namespace std;
 struct node
 {
 	int data;
 	node *left;
 	node *right;
 };
 
 node* createnode(int d)
 {
 	node* newnode = new node();
 	newnode->data=d;
 	newnode->left=newnode->right= NULL;
 	return newnode;
 	
 }
 
 node* insertnode(node* root , int d)
 {
 	if(root== NULL)
 	{
 		root= createnode(d);
 		
	 }
	else if(d<=root->data)
	root->left = insertnode(root->left,d);
	else if(d> root->data)
	root->right = insertnode(root->right,d);
	return root;
 }
 
 bool search(node* root, int d)
 {
 if(root== NULL)
 return false;
 else if(root->data == d)
 return true;
 else if(d<= root->data)
 return search(root->left,d);
 else
 return search(root->right,d);
 	
 }
 
 void postorder(node* root)
 {
 	if(root==NULL)
 	return;
 	postorder(root->left);
 	postorder(root->right);
 	cout<<root->data<<"   ";
 }
 
 void preorder(node* root)
 {
 	if(root== NULL)
 	return;
 	cout<<root->data<<"  ";
 	preorder(root->left);
 	preorder(root->right);
 }
 
 void inorder(node* root)
 {
 	if(root== NULL)
 	return;
 	inorder(root->left);
 	cout<<root->data<<"  ";
 	inorder(root->right);
 	
 }
 
node* findmin(node* root)
{
	if(root==NULL)
	{
		cout<<"Eroor: Tree is Empty \n";
		return root;
	}
	node* cur=root;
	while(cur->left!=NULL)
	cur=cur->left;
	return cur;
}

int findmax(node* root)
{
	if(root==NULL)
	{
		cout<<"Eroor: Tree is Empty \n";
		return -1;
	}
	node* cur=root;
	while(cur->right!=NULL)
	cur=cur->right;
	return cur->data;
}

 int height(node* root) 
    {
    	int ld,rd;
        if (root==NULL) 
            return -1;
        else
        {
             /* compute the depth of each subtree */
             ld = height(root->left);
             rd = height(root->right);

              /* use the larger one */
              if (ld > rd) 
                    return(ld+1);
              else 
                   return(rd+1);
       }
    } 
 
 node* deletenode(node* root, int d)
 {
 	if(root==NULL)
 	return root;
 	else if(d< root->data)
 	{
 		root->left= deletenode(root->left,d);
	 }
	else if(d>root->data)
	{
		root->right= deletenode(root->right,d);
	}
	else
	{
		//case 1: when the node to be deleted contains no child i.e node is the leaf node
		if(root->left==NULL && root->right==NULL)
		{
			delete root;
			root= NULL;
			return root;
		 } 
		// case 2: when the node to be deleted contains one child
		else if(root->left==NULL)
		{
			node* temp=root;
			root = root->right;
			delete temp;
		}
		
		else if(root->right==NULL)
		{
			node* temp=root;
			root = root->left;
			delete temp;
		}
		
		// case 3: when the node to be deleted consists of two child;
		else
		{
			node* temp= findmin(root->right) ;// findmax(root->left) can also be used
			root->data= temp->data;
			root->right=deletenode(root->right,temp->data);
		}
		
		return root;
		
	
	
		}
	
 }
 
 int main()
 {
 	node* root= NULL; string ci;
 	do{
	 
 	cout<<"Enter Your Choice \n\n"<<"Press 1 to insert elements in the tree \n\n"<<"Press 2 for traversing the tree \n\n";
 	cout<<"Press 3 to find the Minimum or Maximum number in a tree \n\n"<<"Press 4 to find the height of a teee \n\n";
 	cout<<"Press 5 to delete a number from the tree \n\n"<<"Press 6 to search a number in the tree \n\n";
 	int ch; cin>>ch;
 	switch(ch)
 	{
 		case 1:
 			int i,n,a;
 			cout<<"enter the total number of integers you want to insert in the tree \n\n";
 			cin>>n;cout<<"\n Enter "<<n<<"  Numbers \n";
 			for(i=0;i<n;i++)
 			{
 				cin>>a;
 				root= insertnode(root,a);
			 }
			cout<<"Number Successfully inserted to the tree \n\n";
		break;
		case 2:
			char c;
			cout<<" Enter I for inorder traversal P for preorder traversal p(small) for postorder traversal \n\n ";
			cin>>c;
			if(c=='I')
			{
				cout<<"Inorder traversal of the tree is \n\n";
				inorder(root);
			}
			
			else if(c=='P')
			{
				cout<<"Preorder traversal of the tree is \n\n";
				preorder(root);
			}
			
			else if(c=='p')
			{
				cout<<"Postorder traversal of the tree is \n\n";
				postorder(root);
			}
		break;
		
		case 3:
			char ch;
			cout<<"Enter M to find maximum number m(small) to find minimum number in the tree \n\n";
			cin>>ch;
			if(ch=='M')
			{
				int num = findmax(root);
				cout<<"Maximum element in the tree is \t"<<num<<"\n\n";
			}
			else if(ch=='m')
			{
				node* t = findmin(root);
				cout<<"Minimum element in the tree is \t"<<t->data<<"\n\n";
			}
		break;
		
		case 4:
			int h; h = height(root);
			cout<<"Height of the tree is  "<<h<<"\n\n";
		break;
		
		case 5:
			cout<<"Enter the number you want to delete \n\n";
			int d;cin>>d;
			if(search(root,d)== true)
			{
				root = deletenode(root,d);
				cout<<"Number Successfully deleted and the new tree is \n\n";
				inorder(root);
			}
			
			else
			{
				cout<<"Sorry the number you entered id not present in th tree \n\n";
			}
		break;
		
		case 6:
			cout<<"Enter the number you want to search \n\n";
			int di;
			cin>>di;
			if(search(root,di))
			cout<<"Number found \n\n";
			else
			cout<<"number not present in the tree \n\n";
		break;
			
	 }
	 
	 cout<<"Enter 7 to contnue and any other key to terminate \n\n ";
	 cin>>ci;
	 if(ci!="7")
	 {
	 	cout<<"Thank You \n";break;
	 }
	 cout << string(50, '\n');
}while(ci=="7");
 	
}
