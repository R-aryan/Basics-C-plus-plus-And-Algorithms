#include<iostream>
#include<algorithm>
using namespace std;

int binarySearch(int a[],int n,int key){
    int s,e,mid;
    s=0;
    e=n-1;
    while(s<=e){
        mid=(s+e)/2;
        if(a[mid]==key)
            return mid;
        else if(a[mid]>key)
            e=mid-1;
        else
            s=mid+1;

    }
    return -1;
}

int main(){
    int i,n,sk;
    cout<<"Enter number of elements...\n";
    cin>>n;
    int a[n];
    for(i=0;i<n;i++)cin>>a[i];

    sort(a,a+n);
    cout<<"Enter the element you want to search...\n";
    cin>>sk;
    int rs= binarySearch(a,n,sk);
    cout<<rs<<" is returned...\n";
    if(rs==-1)
        cout<<"Element not found...\n";

    else
        cout<<"Element found at index... "<<(rs+1)<<"\n";

}
