#include<iostream>
using namespace std;


void insertionsort(int a[],int n){
    int i,j,no;
    for(i=1;i<n;i++){
        j=i-1;
        no=a[i];
        while(j>=0&& a[j]>no){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=no;
    }


}

void printarray(int a[],int n){
    cout<<"The array after sorting is.....\n";
    int i;
    for(i=0;i<n;i++)cout<<a[i]<<" ";
    cout<<"\n";
}
int main(){
    cout<<"Enter the number of elements in the array...\n";
    int n,i;
    cin>>n;
    int a[n];
    for(i=0;i<n;i++)cin>>a[i];
    insertionsort(a,n);
    printarray(a,n);


}
