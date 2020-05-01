#include<iostream>
using namespace std;

int findUnique(int *a,int n){
    int cnt[64]={0};
    int i,j,no,p,ans;
    for(i=0;i<n;i++){
        j=0;
        no=a[i];
        while(no>0){
            cnt[j]+=(no&1);
            j++;
            no=no>>1;
        }}
        p=1;
        ans=0;
    for(i=0;i<64;i++){
        cnt[i]%=3;
        ans+=cnt[i]*p;
        p=p<<1;

    }
    return ans;



}


int main(){
  int n,i,u;
  cin>>n;
  int a[n];
  for(i=0;i<n;i++)cin>>a[i];
  u=findUnique(a,n);
  cout<<"uniaue number is.."<<u<<endl;

}
