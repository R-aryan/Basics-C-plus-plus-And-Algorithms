#include<iostream>
#include<unordered_map>
#include<map>
using namespace std;

#define hashmap unordered_map<char,node*>

class node{
public:
    char data;
    hashmap h;
    bool isterminal;
    node(char d){
        data=d;
        isterminal=false;
    }
};

class trie{
public:

    node *root;
    trie(){
        root= new node('\0');

    }

    void add_word(char *word){
        node *temp=root;
        int i;
        for(i=0;word[i]!='\0';i++){
            char ch=word[i];
            if(temp->h.count(ch)==0){
                node *child=new node(ch);
                temp->h[ch]=child;
                temp=child;
            }
            else{
                temp=temp->h[ch];
            }
        }
        temp->isterminal=true;
    }

    bool search_word(char *word){
        node *temp=root;
        for(int i=0;word[i]!='\0';i++){
            char ch=word[i];
            if(temp->h.count(ch)){
                temp=temp->h[ch];
            }
            else
                return false;

        }
        return temp->isterminal;
    }

};

int main(){
    char a[10][100]={"apple","ape","rabbit","coding blocks","grape","papaya","ritesh","avi","mango","banana"};
    trie t;
    int i;
    for(i=0;i<10;i++){
        t.add_word(a[i]);
    }
    cout<<"Enter the word you want to search....\n";
    char word[100];
    cin.getline(word,100);
    if(t.search_word(word))
        cout<<word<<" found..\n";
    else
        cout<<"Not found \n";
}
