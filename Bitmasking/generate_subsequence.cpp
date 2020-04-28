#include<iostream>
#include<cstring>
using namespace std;


void filterchar(char *a,int no){
    int i=0;
    while(no>0){
        ((no&1)?cout<<a[i]:cout<<"");
        i++;
        no=no>>1;
    }
    cout<<endl;

}

void generatesubsets(char *a){
    int n,i,range;
    n=strlen(a);
    range=(1<<n)-1;
    for(i=0;i<=range;i++){
            filterchar(a,i);

    }
}
int main(){
    char a[100];
    cout<<"Enter the string...\n";
    cin>>a;
    cout<<"All possible subsets are...\n";
    generatesubsets(a);
}
