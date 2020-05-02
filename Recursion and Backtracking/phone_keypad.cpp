#include<iostream>
#include<string>
using namespace std;

char keypad[][10]={"","","ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WXYZ"};

void print_Keypad_String(char *in,char *out,int i,int j){
    //base case
    if(in[i]=='\0'){
        out[j]='\0';
        cout<<out<<endl;
        return;
    }
    // recursive case
    int digit=in[i]-'0';
    if(digit==1||digit==0){
        print_Keypad_String(in,out,i+1,j);
    }
    for(int k=0;keypad[digit][k]!='\0';k++){
        out[j]=keypad[digit][k];
        print_Keypad_String(in,out,i+1,j+1);
    }

}

int main(){
    cout<<"Enter the number (of any length) between 0 and 9 \n";
    char a[100];
    cin>>a;
    char out[100];
    cout<<"All the possible subsequence are...\n";
    print_Keypad_String(a,out,0,0);
}
