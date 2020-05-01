#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter number of elements...\n";
    cin>>n;
    int a[n],i,j;
    cout<<"Enter "<<n<<" Elements of the array...\n";
    for(i=0;i<n;i++){
            cin>>a[i];
            j=a[i]^j;

    }
    cout<<"The unique number is...\t"<<j<<"\n";


}
