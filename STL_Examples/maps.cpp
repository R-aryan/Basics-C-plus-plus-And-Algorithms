#include<iostream>
#include<map>
#include<string>

using namespace std;


//demonstrating the use of custom objects as map keys

class Person
{
private:
    string name;int age;

public:

    Person(): name(" "),age(0){
    }
    Person(string n, int a)
    {
        name=n;age=a;
    }
    /*Person(const Person &other)
    {
        //cout<<"Copy Constructor running  ....\n";
        name=other.name;
        age=other.age;
    } */
    void print_details()
    {
        cout<<"Name is : "<<name<<" Age is :"<<age<<"\n";
    }

    void print() const
    {
        cout<<"Name is : "<<name<<" Age is :"<<age<<"\n";
    }

    bool operator<(const Person &other)const
    {
        if(name==other.name)
        {
            return age<other.age;
        }
        else
            return name<other.name;
    }
};

int main()
{
    map<int,Person>people;
    people[0]=Person("Aryan",20);
    people[1]=Person("Avi",21);
    people[2]=Person("Adi",20);

    for(map<int,Person>::iterator it=people.begin();it!=people.end();it++)
    {
        it->second.print_details();
    }

     map<Person,int>peo;
     peo[Person("Aryan",20)]= 3200;
     peo[Person("Ananad",32)]= 4200;
     peo[Person("Bansal",40)]= 5200;
     peo[Person("Animesh",50)]= 6200;

     for(map<Person,int>::iterator it=peo.begin();it!=peo.end();it++)
    {

        cout<<it->second<<" : ";it->first.print();cout<<"\n";

    }

//iterating through a range of keys
//pair<map<int,string>::iterator,map<int,string>::iterator>its=people.equal_range(2);

/*for(map<int,string>::iterator it= its.first;it!=its.second;it++){
    cout<<it->first<<" : "<<it->second;
} */



}
