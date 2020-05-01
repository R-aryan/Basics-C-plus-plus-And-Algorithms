/* swap two numbers without using 3rd variable and any mathematical
operatos....
solution - this can be done using xor swapping

*/
#include<iostream>
using namespace std;

int main(){
    int a,b;
    cout<<"Enter two numbers...\n";
    cin>>a>>b;
    cout<<"Initial values of A and B are...."<<a<<" "<<b<<endl;
    a=a^b;
    b=b^a;
    a=a^b;
    cout<<" values of A and B after swapping are...."<<a<<" "<<b<<endl;

}
