#include<iostream>
#include<string>

using namespace std;

int main(){

long int m,n=0,r;
string s="";

cin>>m;

while(m>0){
    int c=m%10;
    int r=9-c;
    if(c>r)
    {
        c=r;
    }
    s=to_string(c)+s;
    m=m/10;

}
cout<<"Minimum possible number is \n"<<s;
}
