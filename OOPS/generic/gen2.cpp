#include <iostream>
using namespace std;
class Person{
    private:
        int age;
        string name;
    public:
        Person(string _name, int _age)
        {
            age = _age;
            name = _name;
        }
        void toString()
        {
            cout << name << " is " << age << " years old."<< endl;
        }
};

template < class T > 
void printTheData(T &obj){
	obj.toString();
}


int main()
{
    Person p1 = Person("Tommy Vercetti", 21);
    
    printTheData(p1);
    
    return 0;
}

