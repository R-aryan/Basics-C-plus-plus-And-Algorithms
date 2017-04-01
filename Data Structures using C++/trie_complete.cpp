#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<unordered_map>
#include<limits>

using namespace std;


/*
#include <algorithm>


template <typename T>
const bool Contains( std::vector<T>& Vec, const T& Element )
{
    if (std::find(Vec.begin(), Vec.end(), Element) != Vec.end())
        return true;

    return false;
}
*/
class node
{
    public:
    bool isleaf;
   unordered_map<char,node*> children;
   node()
   {

       isleaf = false;
   }

};

class trie
{
    public:
    node *root;
    trie()
    {
        root = new node();
    }

    void insert_word(string s);
    bool search_word(string s);
    bool delete_word(node *root,string s,int index);
    int validate(int ch);

};
//for dealing with unexpected inputs like entering character/string instead of integer values
int trie::validate(int ch)
{
    /*
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    This line ignores the rest of the current line, up to '\n' or EOF - whichever comes first:
   '\n' sets the delimiter, i.e. the character after which cin stops ignoring
    numeric_limits<streamsize>::max() sets the maximum number of characters to ignore.
    Since this is the upper limit on the size of a stream, you are effectively telling cin that
    there is no limit to the number of characters to ignore
    */
    while(!(cin >> ch)){
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid input.  Try again: ";
	}
	return ch;
}

void trie::insert_word(string s)
{
    int l,i;
    node *temp=root;
    l=s.size();
    for(i=0;i<l;i++)
    {
        auto it=temp->children.find(s[i]);
        if(it!=temp->children.end())
        {
            temp=it->second;
        }
        else
        {
         node *newnode= new node();
         temp->children.insert(make_pair(s[i],newnode));
         temp=newnode;

        }
    }
    temp->isleaf=true;
    cout<<"string successfully inserted into the trie \n\n";

}

bool trie::search_word(string s)
{
    node *temp= root;
    int l,i;
    l= s.length();
    for(i=0;i<l;i++)
    {
        auto it= temp->children.find(s[i]);
        if(it==temp->children.end())
        {
            return false;
        }

            temp=it->second;

    }

    return temp->isleaf;

}

bool trie::delete_word(node *current,string s,int index)
{
char ch;bool should_delete_node;
    ch= s[index];
if(index==s.length())
{
    if(!current->isleaf) //word not present
        return false;
    current->isleaf=false; //setting the isleaf of last character to false

    return current->children.size()==0;
}

    auto temp = current->children.find(ch);
    if(temp== current->children.end())
        return false;
    should_delete_node = delete_word(temp->second,s,index+1);
    if(should_delete_node)
    {
        current->children.erase(ch);

        return current->children.size()==0;
    }

}


int main()
{
    trie T;
    vector<string>s;string a,choice;
    int i,ch=0,n=0,l,check;

    do{
    cout<<"enter 1 to insert word in a trie \n\n"<<"enter 2 to search a word \n\n";
    cout<<"enter 3 to delete a word \n\n";

    l=T.validate(ch);
	cout << "You enterd: " << l<< endl;
    switch(l)
    {
    case 1:
        cout<<"enter the number of words you want to enter \n\n";
        check = T.validate(n);
        cout<<"enter  "<<check<<"   strings \n\n";
        for(i=0;i<check;i++)
        {
            cin>>a;
            s.push_back(a);
            T.insert_word(a);
        }
        break;

    case 2:
        cout<<"enter the word you want to search in the trie \n\n";
        cin>>a;
        bool re;re=T.search_word(a);
        if(re)
            cout<<"Your word  "<<a<<"  is present in the trie\n\n";
        else
            cout<<"sorry your word is not present the trie \n\n";
        break;

   case 3:
        cout<<"enter the word you want to delete \n\n";
        cin>>a;
        if(s.size()!=0)
        {
           sort(s.begin(),s.end());
           if(binary_search(s.begin(),s.end(),a))
           {

           if(T.delete_word(T.root,a,0))
            {
            cout<<"the word  "<<a<<"  has been deleted \n\n";
           }
           }
           else
           {
               cout<<"SORRY! the word is not present the trie \n\n";
           }
        }
        else
            cout<<"Sorry! your trie is empty \n\n";
        break;

    default:
        cout<<"Sorry! wrong choice try again \n\n";
        }
        cout<<"enter 0(zero) to exit or any other key to continue \n\n";
        cin>>choice;cout<<"\n";
    }while(choice!="0");

}


