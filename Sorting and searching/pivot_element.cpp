#include<iostream>
using namespace std;

int main(){
    int s,e,mid,n;
    int a[]={6,7,8,10,1,2,3,4,5};
    n= sizeof(a)/sizeof(int);
    s=0;
    e=n-1;
    while(s<=e){
        mid=(s+e)/2;
        if(mid<e && a[mid]>a[mid+1]){
                cout<<"Pivot indx at "<<mid<<"\n";
                break;

        }
        if(mid>s && a[mid]<a[mid-1]){
            cout<<"Pivot index at.. "<<mid-1<<"\n";
            break;
        }
        if(a[s]>=a[mid])
            e=mid-1;
        else
            s=mid+1;

        if(s>e){
            cout<<"Pivot element does not exist...\n";

        }

    }

}
