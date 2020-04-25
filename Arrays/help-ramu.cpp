#include<iostream>

using namespace std;

int main()
{
    int t,c1,c2,c3,c4,n,m,i;
    int rick[1005],cab[1005];
    cin>>t;
    while(t--)
    {
        cin>>c1>>c2>>c3>>c4;
        cin>>n>>m;
        for(i=0;i<n;i++){
            cin>>rick[i];
        }
        for(i=0;i<m;i++){
            cin>>cab[i];
        }

        int rc=0,cab_c=0,fa;
        for(i=0;i<n;i++){
            rc+=min(c1*rick[i],c2);
        }
        rc=min(rc,c3);
        for(i=0;i<m;i++){
            cab_c+=min(c1*cab[i],c2);
        }
        cab_c=min(cab_c,c3);
        fa=min(c4,rc+cab_c);
        cout<<"Minimum cost is \n"<<fa;



    }
}
