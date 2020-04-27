#include<iostream>
#define N 1000000
using namespace std;

int p[N+1]={0};

void primesieve(int n){
    p[0]=p[1]=0;
    p[2]=1;
    //lets mark all the odd numbers as prime
    int i,j;
    for (i=3;i<=n;i+=2){
        p[i]=1;

    }
    //sieve login to mark all prime numbers as zero
    //optimization 1. iterate over odd numbers
    //
    for(i=3;i<=n;i+=2){
            if(p[i]){
                    for(j=i*i;j<=n;j+=(2*i)){
                        p[j]=0;
                    }}

    }
    return;

}

int main(){
    int n,i;
    cin>>n;
    primesieve(n);
    cout<<" All prime numbers between 0 and  "<<n<<" are \n";
    for(i=0;i<=n;i++){
        if(p[i])
            cout<<i<<" ";
    }

}
