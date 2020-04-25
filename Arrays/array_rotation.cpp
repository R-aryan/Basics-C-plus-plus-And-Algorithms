#include<iostream>
using namespace std;

int gcd(int a,int b){
    if(b==0)
        return a;
    else
        return gcd(b,a%b);
}

void left_rotate(int a[],int d,int n){
    int i,j,k;
    for(i=0;i<gcd(d,n);i++){
        int temp=a[i];
        j=i;
        while(1){
          k=j+d;
          if(k>=n)
                k=k-n;
          if(k==i)
            break;

          a[j]=a[k];
          j=k;
        }
        a[j]=temp;

    }
}

void printarray(int a[],int n){
    cout<<"\n array after rotation is....\n";
    int i;
    for(i=0;i<n;i++)cout<<a[i]<<" ";
}

int main(){
    int n,i,d;
    cout<<"Enter number of elements in the array...\n";
    cin>>n;
    int a[n];
    for(i=0;i<n;i++)cin>>a[i];
    cout<<"\n enter the number about which you want to rotate the array...\n";
    cin>>d;
    left_rotate(a,d,n);
    printarray(a,n);


}
