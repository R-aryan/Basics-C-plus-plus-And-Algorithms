// all the numbers are occuring twice while any two of the
// number is occuring once

#include<iostream>

using namespace std;

void findunique(int a[],int n){
    int r=0,i,temp,mask,fn=0,j,sn;
    for(i=0;i<n;i++){
        r=r^a[i];
    }

    i=0;
    temp=r;
    while(temp>0){
        if(temp&1)
            break;
        i+=1;
        temp=temp>>1;
    }
    cout<<i<<endl;
    mask=(1<<i);
    for(j=0;j<n;j++){
        if((mask&a[j])!=0)
             fn=fn^a[j];
        }
    sn=r^fn;
    cout<<"Unique numbers are...\n"<<fn<<" "<<sn<<endl;

}

int main(){
    int n,i;
    cin>>n;
    int a[n];
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    findunique(a,n);

}
