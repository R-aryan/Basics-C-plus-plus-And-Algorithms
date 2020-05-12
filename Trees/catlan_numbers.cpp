#include<iostream>
#include<queue>
using namespace std;

int dp[100]={0};
int catlan(int n){
    if(n==0)
        return 1;
    int ans=0;int i;
    for(i=1;i<=n;i++)
        ans+=catlan(i-1)*catlan(n-i);
    return ans;
}

int catlan_optimized(int n){
    if(n==0)
        return 1;
    if(dp[n]!=0)
        return dp[n];
    int ans=0;int i;
    for(i=1;i<=n;i++)
        ans+=catlan_optimized(i-1)*catlan_optimized(n-i);
    dp[n]=ans;
    return ans;

}
int main(){
    int i,n;
    cout<<"enter number of terms...\n";
    cin>>n;
    cout<<"The first "<<n<<"  catlan numbers are...\n";
    for(i=0;i<=n;i++){
        cout<<catlan_optimized(i)<<" ";
    }
}
