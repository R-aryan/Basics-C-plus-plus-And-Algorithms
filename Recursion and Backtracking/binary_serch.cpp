#include<iostream>
using namespace std;

int binary_Search(int *a,int low,int high,int key){
    if(low>high)
        return -1;
    int mid=(low+high)/2;
    if(a[mid]==key)
        return mid;
    else if(key>a[mid])
        return binary_Search(a,mid+1,high,key);
    else
        return binary_Search(a,low,mid-1,key);

}


int main(){
    int i,n,key;
    cin>>n;
    int a[n];
    for(i=0;i<n;i++)cin>>a[i];
    cout<<"\n Enter key you want to search...\n";
    cin>>key;
     i= binary_Search(a,0,n,key);
    if(i==-1)
        cout<<" key not present...\n";
    else
        cout<<" key present at index... "<<i+1<<endl;


}
