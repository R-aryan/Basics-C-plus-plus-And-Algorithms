#include<iostream>
#include<cstring>


char *mystrtok(char str[],char delim){

int i;
static char *input=NULL;
if(str!=NULL)
{
    input=str;
}
if(input==NULL){
            return NULL;
        }
char *output= new char[strlen(input)+1];

for(i=0;input[i]!='\0';i++){
        if(input[i]!=delim){
            output[i]=input[i];
        }
        else{
            output[i]='\0';
            input=input+1+i;
            return output;
        }

}
output[i]='\0';
input=NULL;
return output;


}
using namespace std;
int main(){

char str[]="Hello this C++ interview classes..!!";
char *ptr;
ptr=mystrtok(str,' ');
//ptr=strtok(str," "); //default function available in C++
while(ptr!=NULL)
{
    cout<<ptr<<endl;
    ptr=mystrtok(NULL,' ');

}
}
