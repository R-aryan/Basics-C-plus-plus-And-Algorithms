#include<iostream>
#include<algorithm>

using namespace std;

float squareroot(int n,int p){
    int s,e,mid,i;
    float ans;
    s=0;e=n;
    while(s<=e){
        mid=(s+e)/2;
        if(mid*mid==n){
            ans= mid;
            break;
        }
        else if(mid*mid<n){
            s=mid+1;
            ans=mid;
        }
        else
            e=mid-1;
    }
    float inc=0.1;
    for(i=0;i<p;i++){
        while(ans*ans<=n){
            ans+=inc;
        }
        ans-=inc;
        inc/=10;
    }
    return ans;
}

int main(){
    cout<<squareroot(10,3)<<endl;
    cout<<squareroot(25,3)<<endl;

}
