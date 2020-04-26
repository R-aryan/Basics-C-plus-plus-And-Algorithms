#include<iostream>
#include<cstdio>
#include<cstring>
#define RANGE 25

using namespace std;

void printarray(int a[],int n){
    int i;
    cout<<"array after sorting...\n";
    for(i=0;i<n;i++)cout<<a[i]<<" ";
    cout<<"\n";


}

void countingsort(int a[],int n){
    int freq[RANGE+1],i,j;
    memset(freq,0,sizeof(freq));
    for(i=0;i<n;i++){
        freq[a[i]]+=1;
    }
    j=0;
    for(i=0;i<RANGE;i++){
        int temp=freq[i];
        while(temp--){
            //cout<<temp<<"\n";
            a[j]=i;
            j++;

        }
    }



}

int main(){
    cout<<"Enter the number of elements in the array...\n";
    int n,i;
    cin>>n;
    int a[n];
    for(i=0;i<n;i++)cin>>a[i];
    countingsort(a,n);
    printarray(a,n);


}
