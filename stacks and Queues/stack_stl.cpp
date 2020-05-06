#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main(){
    stack<string>s;
    s.push("aryan");
    s.push("aditi");
    s.push("sr");
    s.push("avi");
    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }
}
