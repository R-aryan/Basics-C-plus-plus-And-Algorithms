#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    int n,m,ts,i,j;

    cin>>n>>m;
    int arr[n][m],con[n*m];
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    cin>>ts;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            con[i*n+j]=arr[i][j];
        }
    }
    if(binary_search(con,con+(n*m),ts)){
        cout<<"1 \n";
    }
    else
        cout<<"0 \n";


}
