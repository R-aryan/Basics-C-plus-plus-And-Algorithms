#include<iostream>
#include<string>

using namespace std;

string spelling[10]= {"Zero","One","Two","Three","Four","Five","Six","Seven","Eight","Nine"};

void spell(int n){
    if(n==0)
        return;
    spell(n/10);
    cout<<spelling[n%10]<<" ";
}

int main(){
    int n;
    cin>>n;
    spell(n);
}
