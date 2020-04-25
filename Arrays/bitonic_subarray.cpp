#include<iostream>
using namespace std;

int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int arr[n],inc[n],dec[n],ml,i;
        for(i=0;i<n;i++){cin>>arr[i];}
        inc[0]=1;
        dec[n-1]=1;
        for(i=1;i<n;i++){
            if(arr[i]>=arr[i-1]){
                inc[i]=inc[i-1]+1;
            }
            else
                inc[i]=1;
        }
        for(i=n-2;i>=0;i--){
            dec[i]=(arr[i]>=arr[i+1])?dec[i+1]+1:1;
        }
        ml=inc[0]+dec[0]-1;
        for(i=1;i<n;i++){
            if((inc[i]+dec[i]-1)>ml){
                ml=inc[i]+dec[i]-1;
                //cout<<ml<<" "<<i<<"\n";
            }
        }
        cout<<ml<<"\n";


    }
}
