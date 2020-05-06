#include<iostream>
#include<queue>
#include<stack>
using namespace std;

void transfer(stack<int>& s1, stack<int>& s2,int n){
    int i;
    for(i=0;i<n;++i){
        s2.push(s1.top());
        s1.pop();
    }

}

void reverse_stack(stack<int>& s1){
    stack<int>s2;
    int n,i,x;
    n=s1.size();
    for(i=0;i<n;++i){
        x=s1.top();
        s1.pop();
        transfer(s1,s2,n-i-1);
        s1.push(x);
        transfer(s2,s1,n-i-1);
    }}
void insert_at_bottom(stack<int>& s,int x){
    if(s.empty()){
        s.push(x);
        return;
        }
    int y= s.top();
    s.pop();
    insert_at_bottom(s,x);
    s.push(y);

}

void reverse_stack_recursion(stack<int>& s){
    if(s.empty())
        return;
    int x= s.top();
    s.pop();
    reverse_stack_recursion(s);
    insert_at_bottom(s,x);

}

void print_stack(stack<int>s1){
    while(!s1.empty()){
        cout<<s1.top()<<endl;
        s1.pop();
    }

}
int main(){
    stack<int>s1;
    int i;
    for(i=0;i<=5;i++)
        s1.push(i*i);
    reverse_stack(s1);
    cout<<"reversing stack using iterative approach...\n";
    print_stack(s1);
    cout<<"reversing stack using recursive approach...\n";
    reverse_stack_recursion(s1);
    print_stack(s1);


}
