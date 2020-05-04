#include<iostream>
using namespace std;

template<typename T>

class Queue{
    T *arr;
    int f,r,cs,ms;
public:
    Queue(int ds=4){
       f=0;
       ms=ds;
       r=ms-1;
       arr=new T[ms];
       cs=0;
    }
    bool isfull(){
        return cs==ms;

    }
    bool isempty(){
        return cs==0;

    }
    void push(T data){
        if(!isfull()){
            r=(r+1)%ms;
            arr[r]=data;
            cs+=1;
        }
    }
    void pop(){
        if(!isempty()){
            f=(f+1)%ms;
            cs--;
        }
    }
    T getfront(){
        return arr[f];

    }
};

int main(){
    Queue<int>q;
    for(int i=1;i<=6;i++){
        q.push(i);
    }
    q.pop();
    q.push(8);
    while(!q.isempty()){
        cout<<q.getfront()<<endl;
        q.pop();
    }
    }
