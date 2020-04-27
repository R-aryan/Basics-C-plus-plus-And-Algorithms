#include<iostream>
using namespace std;

void selectionsort(int a[],int n){
    int i,j;
    for(i=0;i<n-1;i++){
        int min_ind=i;
        for(j=i+1;j<n;j++){
            if(a[j]<a[min_ind])
                min_ind=j;
        }
        swap(a[min_ind],a[i]);

    }

}

void printarray(int a[],int n){
    int i;
    for(i=0;i<n;i++)cout<<a[i]<<" ";
    cout<<"\n";
}

int main(){
int n,i;
cout<<"Enter number of elements in the  array \n";
cin>>n;
int a[n];
for(i=0;i<n;i++)cin>>a[i];
 selectionsort(a,n);
 printarray(a,n);


}
