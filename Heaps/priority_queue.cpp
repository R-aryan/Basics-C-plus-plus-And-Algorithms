#include<iostream>
#include<queue>
#include<vector>
#include<functional>

using namespace std;

int main(){
    int a[10]={5,6,8,1,45,35,62,89,12,10};
    int i;
    priority_queue<int> pq;//for max heap
    priority_queue<int,vector<int>,greater<int> >pq1;//for min heap

    for(i=0;i<10;i++){
        pq.push(a[i]);
        pq1.push(a[i]);
    }
    cout<<"Displaying results for max-heap....\n";
    while(!pq.empty()){
        cout<<pq.top()<<" is top of max heap \n";
        pq.pop();
    }
    cout<<endl<<" Displaying the results of min heap...\n";
    while(!pq1.empty()){
        cout<<pq1.top()<<" is top of in heap....\n";
        pq1.pop();
    }
}

