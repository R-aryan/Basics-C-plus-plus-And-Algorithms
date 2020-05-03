#include<iostream>
using namespace std;

bool issorted(int *a,int n){
    if(n==1)
        return true;
    if(a[0]<a[1] && issorted(a+1,n-1))
        return true;
    return false;
}

int main(){
    int n,i;
    cin>>n;
    int a[n];
    for(i=0;i<n;i++)cin>>a[i];

    if(issorted(a,n))
        cout<<"yes thr array is sorted \n";
    else
        cout<<"no the array is not sorted...\n";
}
