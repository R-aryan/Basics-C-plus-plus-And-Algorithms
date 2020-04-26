#include<iostream>
using namespace std;

#define ll long long int


bool isvalidconfig(ll books[],ll n,ll k ,ll ans){
    int s=1,i;
    int cp=0;
    for(i=0;i<n;i++){
            if(cp+books[i]>ans){
                    cp=books[i];
                    s+=1;
                    if(s>k)
                        return false;


            }

       else{
        cp+=books[i];}

    }
    return true;
}

ll binarysearch_books(ll b[],ll n,ll k){
    ll tp=0,i,s=0;
    ll mid,e=0,fs;
    fs=0;

    for(i=0;i<n;i++){
        tp+=b[i];
        s=max(s,b[i]);
    }
    e=tp;
    fs=s;
    while(s<=e){
        mid=(s+e)/2;
        if(isvalidconfig(b,n,k,mid)){
            fs=mid;
            e=mid-1;
        }
        else{
            s=mid+1;

        }

    }
    return fs;
}

int main(){
    ll n,k,i;
    cout<<"Enter number of books and number of students...\n";

    cin>>n>>k;
    cout<<"Enter number of pages in "<<n<<" books..\n";
    ll a[n];
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<"Maximum number of pages a student has to read .... "<<binarysearch_books(a,n,k)<<endl;
}
