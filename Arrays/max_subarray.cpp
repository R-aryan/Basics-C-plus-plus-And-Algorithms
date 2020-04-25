#include<iostream>

using namespace std;

int main()
{
    int a[1000] , maxsum=0 , currentsum=0,n;
    int cs[1000]={0},left=-1,right= -1,i,j;
    cout<<"enter number of elements \n";
    cin>>n;
    cout<<"enter first element \n";cin>>a[0];
    cs[0]=a[0];
    cout<<"Enter the rest "<<n-1<<" elements ";
    for(i=1;i<n;i++)
    {
        cin>>a[i];
        cs[i]=cs[i-1]+a[i];
    }

    for(i=0;i<n;i++)
    {
        for(j=i;j<n;j++)
        {
            currentsum=0;
            currentsum=cs[j]-cs[i-1];
            if(currentsum>maxsum)
            {
                maxsum=currentsum;
                left=i;
                right=j;
            }
        }
    }
    cout<<"maximum sum is "<<maxsum<<" and the subarray is \n";
    for(i=left;i<right;i++)
    {
        cout<<a[i]<<", ";

    }

}
