#include<iostream>
#include<set>

using namespace std;


class Test
{
    int id;
    string name;

public:
    Test(int id, string name):id(id),name(name){
    }

    void print()const
    {
        cout<<id<<" : "<<name<<"\n";
    }

    //operator overloading for comparison of class attributes

    bool operator<(const Test &other)const
    {
        if(name==other.name)
        {
            return id<other.id;
        }
        else
            return name<other.name;
    }


};

int main()
{
    set<int>numbr;
    numbr.insert(10);
    numbr.insert(60);
    numbr.insert(30);
    numbr.insert(40);

    set<int>::iterator it;
    for(it=numbr.begin();it!=numbr.end();it++)
    {
        cout<<*it<<"\n";
    }
    set<int>::iterator itf= numbr.find(30);
    if(itf!=numbr.end())
    {
        cout<<"Found :"<<*itf<<endl;
    }
    if(numbr.count(30))
    {
        cout<<"Number Found:"<<endl;
    }

    //using classes as type in sets

    set<Test>tests;
    tests.insert(Test(10,"Mike"));
    tests.insert(Test(20,"Rachel"));
    tests.insert(Test(30,"Joe"));

    for(set<Test>::iterator it= tests.begin();it!=tests.end();it++)
    {
        it->print();
    }

}
