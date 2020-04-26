#include <iostream>
using namespace std;



void bubblesort(int a[],int n){

int i,j;
for(i=0;i<n;i++){
        bool swapped=false;
    for(j=0;j<n-i-1;j++){
        if(a[j]>a[j+1]){
            int temp=a[j];
            a[j]=a[j+1];
            a[j+1]=temp;
            swapped=true;
        }
    }
if(swapped==false)
    break;
}

}

void printarray(int a[], int n){
    cout<<"The sorted array is....\n";
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<"\n";
}
int main(){
int n,i;
cout<<"Enter number of elements in the  array \n";
cin>>n;
int a[n];
for(i=0;i<n;i++)cin>>a[i];
 bubblesort(a,n);
 printarray(a,n);

}
