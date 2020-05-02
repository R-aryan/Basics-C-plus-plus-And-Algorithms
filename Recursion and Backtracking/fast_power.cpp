#include<iostream>
using namespace std;

int power_raise(int a,int b){
    if(b==0)
        return 1;
    else
        return a*power_raise(a,b-1);

}

int fast_power(int a,int b){
    if(b==0)
        return 1;
    int sa= fast_power(a,b/2);
    sa*=sa;
    if(b&1)
        return a*sa;
    return sa;



}
int main(){
    int a,b;
    cin>>a>>b;
    cout<<a<<" raised to power "<<b<<" is "<<power_raise(a,b)<<endl;
    cout<<a<<" raised to power "<<b<<" is using fast power "<<fast_power(a,b)<<endl;


}
