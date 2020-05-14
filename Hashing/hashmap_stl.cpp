#include<iostream>
#include<map>
#include<unordered_map>

using namespace std;

int main(){
    ///hashmap declaration
    unordered_map<string,int>m;
    ///insertion 1st method based on method overloading
    m["mango"]=100;
    ///2nd method to insert
    m.insert(make_pair("apple",130));
    m["banana"]=50;
    ///search a particular key
    if(m.count("apple"))
        cout<<"Found with value.... "<<m["apple"]<<endl;
    else
        cout<<" Not found....\n";
    ///delete a particular key...
    m.erase("apple");


}
