#include<iostream>
using namespace std;

int main()
{

    int t,i;
    cin>>t;
    int bh[t],lmax[t],rmax[t],tc[t],lm,rm;
    for(i=0;i<t;i++)
    {
        cin>>bh[i];
    }
    lm=bh[0];
    lmax[0]=bh[0];

    lm=bh[0];//cout<<"initial "<<lm<<"\n";
    for(i=0;i<t;i++)
    {
        if(bh[i]>lm)
        {
            lm=bh[i];
            lmax[i]=lm;
            //cout<<lm<<" is Changed... \n";
        }
        else{
            lmax[i]=lm;
        }
        //cout<<lmax[i]<<" ";
    }
    //for(i=0;i<t;i++)cout<<lmax[i]<<" ";
    rm=bh[t-1];
    //cout<<rm<<" initial \n";
    rmax[t-1]=bh[t-1];
    for(i=t-1;i>=0;i--)
    {

        if(bh[i]>rm)
        {
            rm=bh[i];
            rmax[i]=rm;
            //cout<<lm<<" is Changed... \n";
        }
        else{
            rmax[i]=rm;
        }
    }
    //for(i=0;i<t;i++)cout<<rmax[i]<<" ";
    int s=0;
    for(i=0;i<t;i++)
    {
        tc[i]=min(lmax[i],rmax[i])-bh[i];
        s+=tc[i];
    }
    cout<<s<<endl;

}
