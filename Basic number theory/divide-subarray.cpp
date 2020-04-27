#include<iostream>
#include<cstring>
#define ll long long
using namespace std;

ll a[100005],psum[100005];

int main(){
    int t,n,i;
    cin>>t;
    while(t--){
        cin>>n;
        ll sum=0;
        memset(psum,0,sizeof(psum));
        for(i=0;i<n;i++){
                cin>>a[i];
                sum+=a[i];
                sum%=n;
                sum=(sum+n)%n;
                psum[i]++;
        }
        ll ans=0,no;
        for(i=0;i<n;i++){
            //cout<<psum[i]<<" ";
            no=psum[i];
            ans+=(no*(no-1))/2;
        }
        cout<<ans<<"\n";
            }

}
