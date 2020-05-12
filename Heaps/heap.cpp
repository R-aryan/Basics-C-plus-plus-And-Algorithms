#include<iostream>
#include<vector>
using namespace std;

class Heap{
    vector<int>v;
    bool minh;
    bool compare(int a,int b){
        if(minh)
            return a<b;
        else
            return a>b;

    }
    void heapify(int i){
        int left,right,minindex;
        left=2*i;
        right=(2*i)+1;
        minindex=i;

        if(left<v.size()&& compare(v[left],v[i]))
            minindex=left;

        if(right<v.size()&& compare(v[right],v[minindex]))
            minindex=right;

        if(minindex!=i){
            swap(v[i],v[minindex]);
            heapify(minindex);
        }

     }
public:
    Heap(bool type=true){
        minh=type;
        v.push_back(-1);
    }

    void push(int data){
        v.push_back(data);
        //maintain heap property
        int index,parent;
        index=v.size()-1;
        parent=index/2;
        while(index>1 && compare(v[index],v[parent])){
            swap(v[index],v[parent]);
            index=parent;
            parent=parent/2;
        }

    }
     int top(){
         return v[1];
     }
     bool empty(){
         return v.size()==1;
     }


     void pop(){
         //to remove top element
         int last;
         last=v.size()-1;
         // swap the first and the last element
         swap(v[1],v[last]);
         //pop the last element
         v.pop_back();
         // maintain the heap property
         heapify(1);

     }
};

int main(){
    Heap h(false);
    h.push(20);
    h.push(10);
    h.push(200);
    h.push(5);
    h.push(90);
    h.push(1);
    h.push(87);

    while(!h.empty()){
    cout<<h.top()<<" is the top element of the heap...\n";
    h.pop();
    }
}
