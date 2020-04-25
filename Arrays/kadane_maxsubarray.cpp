#include<iostream>

using namespace std;

int main()
{
    int n,i,cs=0,maxsum=0;
    cout<<"Enter number of elements \n";
    cin>>n;
    int a[1000];
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }

    //kadane's algorithm
    for(i=0;i<n;i++)
    {
        cs+=a[i];
        if(cs<0){
            cs=0;
        }
        maxsum=max(cs,maxsum);
    }
    cout<<"Maximum sum is "<<maxsum;


}
