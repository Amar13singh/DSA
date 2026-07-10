#include <iostream>
using namespace std;

template<class T>
void sum(T a, T b){
    cout << "Inside Template " << a + b << endl;
}

void sum(int a, int b){
    cout << "Inside Overload " << a + b << endl;
}

int main()
{
    // Template Function will be called.
    sum(4.5,9.8);
    
    // Overload will be called.
    sum(5,7);
    
	return 0;
}
