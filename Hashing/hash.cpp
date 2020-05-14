#include<iostream>
#include"hashtable.h"

using namespace std;

int main(){
    Hashtable<int> h;
    h.insert_data("Mango",100);
    h.insert_data("Apple",170);
    h.insert_data("Guava",130);
    h.insert_data("Grapes",140);
    //h.insert_data("Banana",120);

    h.print();
    string k;
    cout<<"Enter key you want to search...\n";
    cin>>k;
    int *p=h.search_data(k);
    if(p!=NULL)
        cout<<"Price is... "<<*p<<endl;
    else
        cout<<"Not found...\n";

}
