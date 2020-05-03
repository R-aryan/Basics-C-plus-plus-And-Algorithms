#include<iostream>
using namespace std;

int product(int a,int b){
    if(a<b){
        return product(b,a);
    }
    else if(a>0 && b>0){
        return a+product(a,b-1);

    }
    else if(a<0 && b<0){
        a*=-1;
        b*=-1;
        return a+product(a,b-1);
    }
    else if(a<0|| b<0)
        return -a+product(a,b+1);
    else
        return 0;

}

int main(){
    int a,b;
    cin>>a>>b;
    cout<<" product is ... "<<product(a,b)<<endl;

}
