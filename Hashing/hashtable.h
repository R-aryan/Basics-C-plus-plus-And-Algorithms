#include<iostream>
#include<string>
#include<cstring>

using namespace std;

template<typename T>
class Node{
public:
    string key;
    T value;
    Node<T> *next;
    Node(string k,T v){
        key=k;
        value=v;
    }
    ~Node(){
        if(next!=NULL)
            delete next;
    }


};

template<typename T>
class Hashtable{
public:
    int cs;///currentsize
    int ts;///total bucket size
    Node<T>**bucket;
    Hashtable(int ds=7){
        cs=0;
        ts=ds;
        bucket=new Node<T>*[ts];
        for(int i=0;i<ts;i++)
            bucket[i]=NULL;
    }

    int hash_function(string key){
        int l=key.length();
        int s,p,i,ans;
        ans=0;
        s=0;p=1;
        for(i=0;i<l;i++){
            ans+=key[l-i-1]*p;
            p*=37;
            p%=ts;
            ans%=ts;
        }
        return ans;
    }

    void rehash(){
        Node<T>**oldbuckets=bucket;
        int oldts,i;
        oldts=ts;
        ts*=2;
        cs=0;
        bucket=new Node<T>*[ts];
        for(i=0;i<ts;i++)
            bucket[i]=NULL;
        for(i=0;i<oldts;i++){
            Node<T>*temp=oldbuckets[i];
            if(temp!=NULL){
                while(temp!=NULL){
                    insert_data(temp->key,temp->value);
                    temp=temp->next;
                }

            }
            delete oldbuckets[i];
        }
        delete []oldbuckets;

    }

    void insert_data(string key,T value){
        int i=hash_function(key);
        Node<T>*n=new Node<T>(key,value);
        n->next=bucket[i];
        bucket[i]=n;

        cs++;
        float lf= (float)cs/ts;
        if(lf>0.7){
            cout<<"Load factor is... "<<lf<<"\n so rehashing..."<<endl;
            rehash();

        }

    }
    void print(){
        for(int i=0;i<ts;i++){
            Node<T>*temp=bucket[i];
            cout<<"Bucket... "<<i<<" ->";
            while(temp!=NULL)
            {
                cout<<temp->key<<",";
                temp=temp->next;
            }
            cout<<endl;
        }
    }
    T* search_data(string key){
        int i= hash_function(key);
        Node<T>*temp=bucket[i];
        while(temp!=NULL){
            if(temp->key==key)
                return &(temp->value);
            temp=temp->next;
        }
        return NULL;
    }

};
