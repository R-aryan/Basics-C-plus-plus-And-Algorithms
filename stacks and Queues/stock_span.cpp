#include<iostream>
#include<stack>
using namespace std;

void print_span(int a[],int n){
    stack<int>s;
    int d,cd,bd,span,i;
    int ans[n]={};
    for(d=0;d<n;d++){
        cd=a[d];
        while(s.empty()==false && a[s.top()]<a[d]){
            s.pop();
        }
        bd=s.empty()?0:s.top();
        span=d-bd;
        ans[d]=span;
        s.push(d);
    }
    for(i=0;i<n;i++)
            cout<<ans[i]<<" ";


}

int main(){
    int n;
    cout<<"Enter number of elements....\n";
    cin>>n;
    int a[n],i;
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    print_span(a,n);


}
