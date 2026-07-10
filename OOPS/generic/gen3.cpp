#include <iostream>
#include <typeinfo>
using namespace std;

template<class T>
class Container {
private:
    T data;

public:
    static int count;

    Container() {
        count++;
    }

    static void displayStaticVariable() {
        cout << "For " << typeid(T).name()
            << " count = " << count << endl;
    }
};

template<class T>
int Container<T>::count = 0;

int main() {
    Container<int> obj1;
    Container<float> obj2;
    Container<int> obj3;

    Container<int>::displayStaticVariable();
    Container<float>::displayStaticVariable();

    return 0;
}