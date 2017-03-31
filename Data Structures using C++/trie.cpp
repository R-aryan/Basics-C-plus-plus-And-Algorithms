#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<algorithm>
// Converts key current character into index
// use only 'a' through 'z' and lower case
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')
 
 // Alphabet size (# of symbols)
#define ALPHABET_SIZE (26)
 

using namespace std;

struct Trienode
{
	Trienode *children[ALPHABET_SIZE];
	bool isleaf;
};

Trienode* getnode()
{
	
	
	Trienode* pnode=NULL;
	pnode= new Trienode();
	if(pnode)
	{
		int i;
		pnode->isleaf=false;
		for(i=0;i<ALPHABET_SIZE;i++)
		{
			pnode->children[i]=NULL;
		}
	}
	
	return pnode;
}


void insertnode(Trienode *root, string s)
{
	Trienode *pcrawl=root;
	int i,index,l;l=s.length();
	for(i=0;i<l;i++)
	{
		index= CHAR_TO_INDEX(s[i]);
		if(!pcrawl->children[index])
		pcrawl->children[index]=getnode();
		
		pcrawl=pcrawl->children[index];
	}
	
	pcrawl->isleaf=true;
	
	cout<<"your string is successfully inserted into the trie \n";
	
	
}

bool searchkey(Trienode *root, string s)
{
	int l,i,index;
	Trienode *pcrawl=root;
	l= s.length();
	for(i=0;i<l;i++)
	{
		index= CHAR_TO_INDEX(s[i]);
		if(!pcrawl->children[index])
		return false;
		
		pcrawl=pcrawl->children[index];
	}
	return (pcrawl!=NULL && pcrawl->isleaf);
}
int main()
{
	int l,i;
	cout<<"Enter the number of strings you want to insert into the Trie \n\n";
	cin>>l;
	cout<<"\n\n Enter  "<<l<<"strings \n\n";
	string s[l],data;
	for(i=0;i<l;i++)
	{
		cin>>s[i];
		cout<<"\n\n";
	}
	Trienode *root= getnode();
	for(i=0;i<l;i++)
	{
		transform(s[i].begin(), s[i].end(), s[i].begin(), ::tolower);
		insertnode(root,s[i]);
	}
	
	cout<<"Enter the string you want to search \n\n";
	cin>>data;
	transform(data.begin(), data.end(), data.begin(), ::tolower);
	cout<<data<<"\n\n";
	bool fi = searchkey(root,data);
	if(fi)
	cout<<"Your key string is present in the trie \n\n";
	else
	cout<<"SORRY! Your key string is not present in the trie \n\n";
	
	/*if(!23)
	cout<<"this is null statement \n";
	else
	cout<<"not null statement \n"; */
}
	
	

