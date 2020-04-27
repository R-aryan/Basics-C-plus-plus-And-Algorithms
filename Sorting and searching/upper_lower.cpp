#include<iostream>
#include<algorithm>

using namespace std;

int first_occur(int a[],int n ,int key){
    int s,e,ans,mid;
    s=0;e=n-1;
    ans= -1;
    while(s<=e){
        mid=(s+e)/2;
        if(a[mid]==key){
            ans=mid;
            e=mid-1;//for finding out the last occurence just do
            //s=mid+1;
        }
        else if(a[mid]>key)
            e=mid-1;
        else
            s=mid+1;
    }
    return ans;

}

int main(){
    int i,n,sk;
    cout<<"Enter number of elements...\n";
    cin>>n;
    int a[n];
    for(i=0;i<n;i++)cin>>a[i];

    sort(a,a+n);
    cout<<"Enter the element you want to get the first occurance...\n";
    cin>>sk;
    int rs= first_occur(a,n,sk);
    cout<<rs<<" is returned...\n";
    if(rs==-1)
        cout<<"Element not found...\n";

    else
        cout<<"First occurence of element is found at index... "<<(rs+1)<<"\n";


}
