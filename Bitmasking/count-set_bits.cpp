#include<iostream>
using namespace std;

int main(){
    int t,n,c;
    cin>>t;
    while(t--){
        cin>>n;
        c=0;
        while(n>0){
            c+=1;
            n=n&(n-1);
        }
        cout<<c<<"\n";

    }

}
