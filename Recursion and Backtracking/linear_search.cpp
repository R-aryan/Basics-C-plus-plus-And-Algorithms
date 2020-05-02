#include<iostream>
using namespace std;

int linear_search(int *a, int n,int i,int key){
    if(i==n)
        return -1;
    if(key==a[i])
        return i;
    return linear_search(a,n,i+1,key);
}

int main(){
    int i,n,key;
    cin>>n;
    int a[n];
    for(i=0;i<n;i++)cin>>a[i];
    cout<<"\n Enter key you want to search...\n";
    cin>>key;
     i= linear_search(a,n,0,key);
    if(i==-1)
        cout<<" key not present...\n";
    else
        cout<<" key present at index... "<<i+1<<endl;


}
