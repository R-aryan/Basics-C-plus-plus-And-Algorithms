#include<iostream>
using namespace std;


void wave_sort(int a[],int n){
    int i;
    for(i=0;i<n;i+=2){
        if(i>0 && a[i-1]>a[i]){
            swap(a[i],a[i-1]);
        }
        if(i<=n-2 && a[i+1]>a[i]){
            swap(a[i],a[i+1]);
        }
    }

}

void printarray(int a[],int n){
    int i;
    cout<<"The array after performing wave sort is....\n";
    for(i=0;i<n;i++)cout<<a[i]<<" ";
    cout<<"\n";
}
int main(){
    int n,i;
    cout<<"Enter number of elements in the array...\n";
    cin>>n;
    int a[n];
    for(i=0;i<n;i++)cin>>a[i];
    wave_sort(a,n);
    printarray(a,n);


}
