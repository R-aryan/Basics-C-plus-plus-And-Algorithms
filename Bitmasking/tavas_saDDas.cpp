#include<iostream>
#include<cstring>
#define ll long long
using namespace std;

int main(){
    ll ans=0;
    char a[20];
    cout<<"Enter a number...\n";
    cin>>a;
    int pos=0,len,i;
    len= strlen(a);
    ans=(1<<len)-2;
    for(i=len-1;i>=0;i--,pos++){
        if(a[i]=='7'){
            ans+=(1<<pos);
        }
    }
    cout<<ans+1<<" is the position of the number...\n";




}
