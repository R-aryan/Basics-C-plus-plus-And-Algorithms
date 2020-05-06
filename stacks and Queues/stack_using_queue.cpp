#include<iostream>
#include<stack>
#include<queue>

using namespace std;

class Stackusingqueues{
    queue<int> *q1,*q2;
public:
    Stackusingqueues(){
        q1=new queue<int>();
        q2=new queue<int>();
    }
    void push(int x){
        q1->push(x);

    }
    void pop(){
        int n,i;
        n=q1->size();
        for(i=0;i<n-1;i++){
            q2->push(q1->front());
            q1->pop();
        }
        if(!q1->empty()){
            q1->pop();
            swap(q1,q2);
        }
        }
    int top(){
        int n,i;
        n=q1->size();
        for(i=0;i<n-1;i++){
            q2->push(q1->front());
            q1->pop();
        }
        int tp=q1->front();
        if(!q1->empty()){
            q1->pop();
            swap(q1,q2);
        }
        return tp;
        }
        ~Stackusingqueues(){
            delete q1;
            delete q2;
        }

};

int main(){
    Stackusingqueues s;
    s.push(10);
    s.push(11);
    s.push(12);
    s.pop();
    cout<<s.top()<<endl;

}
