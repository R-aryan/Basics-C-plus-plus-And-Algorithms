/* given two numbers eg 11 and 15 now you have to
calculate the minimum number of bits that needs to be changed
to convert a to b eg in this case from 11 to 15
solution - take Xor of the number and then calculate the number
of set bits... */

#include<iostream>
using namespace std;

int countBits(int n){
    int c=0;
    while(n>0){
        c+=n&1;
        n=n>>1;
    }
    return c;
}
//counting the number of set bits
int countBitsfast(int n){
    int c=0;
    while(n){
        c+=1;
        n=n&(n-1);
    }
    return c;

}
// getting the ith bit
int getithbit(int n,int i){
    return (n&(1<<i))!=0?1:0;
}

//setting ith bit to 1
void setIthbit(int &n,int i){
    /* you are given a number and you have to set it's ith bit to 1 */
    int mask= 1<<i;
    int a=n;
    n=n|mask;
    cout<<"value after setting "<<i<<" th bit " <<" of "<<a<<" is "<<n<<endl;

}

// to clear a bit

void clearBit(int &n,int i){
    int a=n;
    int mask = ~(1<<i);
    n=(n&mask);
    cout<<"value after clearing "<<i<<" th bit " <<" of "<<a<<" is "<<n<<endl;


}
int main(){
    int a,b,i;
    cout<<"Enter two numbers...\n";
    cin>>a>>b;
    int n= a^b;
    cout<<" number of transformation that needs to be done is... "<<countBits(n)<<endl;
    cout<<" enter the ith bit you want to see.."<<endl;
    cin>>i;
    cout<<"The "<<i <<" th bit of " <<a<<" is  "<<getithbit(a,i)<<endl;
    cout<<"The "<<i <<" th bit of " <<b<<" is  "<<getithbit(b,i)<<endl;
    cout<<"Enter the ith bit you want to set \n";
    cin>>i;
    setIthbit(a,i);
    setIthbit(b,i);
    cout<<"Enter the ith bit you want to clear \n";
    cin>>i;
    clearBit(a,i);
    clearBit(b,i);

}
