#include<iostream>
using namespace std;



void merge_array(int a[],int s, int e){
    int mid,i,j,k;
    int temp[100];
    mid=(s+e)/2;
    i=s;
    j=mid+1;
    k=s;//pointer for temporary array
    while(i<=mid && j<=e){
        if(a[i]<a[j]){
            temp[k++]=a[i++];
        }
        else{
            temp[k++]=a[j++];
        }
    }
    while(i<=mid)
        temp[k++]=a[i++];
    while(j<=e)
        temp[k++]=a[j++];
    for(i=s;i<=e;i++)
        a[i]=temp[i];

}
void merge_sort(int a[],int s,int e){
    if(s>=e)
        return;
    int mid= (s+e)/2;
    merge_sort(a,s,mid);
    merge_sort(a,mid+1,e);
    merge_array(a,s,e);

}



void print(int a[],int n){
    cout<<"Sorted array is..\n";
    int i;
    for(i=0;i<n;i++)
        cout<<a[i]<<" ";

}

int main(){
    cout<<"Enter number of elements..\n";
    int n,i;
    cin>>n;
    int a[n];
    cout<<"Enter "<<n<<" elements..\n";
    for(i=0;i<n;i++)cin>>a[i];
    merge_sort(a,0,n);
    print(a,n);

}
