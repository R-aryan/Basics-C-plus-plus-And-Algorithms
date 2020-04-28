#include<iostream>
using namespace std;

int main(){
    int n,i=0;
    cin>>n;
    while(n>0){
        i+=1;
        n=n&(n-1);
    }
    cout<<"Minimum number of jumps required is...\n"<<i<<endl;

}
