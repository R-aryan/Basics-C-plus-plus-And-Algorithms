#include<iostream>
using namespace std;

bool isprime(int n){
    int i;
    if(n==1)
        return false;
    for(i=2;i*i<=n;i++){
        if(n%i==0)
            return false;
    }
    return true;
}

int main(){
    int n;
    cin>>n;
    bool a= isprime(n);
    if(a)
        cout<<n<<" is prime..\n";
    else
        cout<<" not prime..\n";
}
