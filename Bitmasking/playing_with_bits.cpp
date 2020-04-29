#include<iostream>
using namespace std;

int main(){
    int t,a,b,i,c,temp;
    cin>>t;
    while(t--){
        cin>>a>>b;
        c=0;
        for(i=a;i<=b;i++){
            temp=i;
            while(temp>0){
                c+=1;
                temp=temp&(temp-1);

            }
        }
        cout<<c<<"\n";
    }

}
