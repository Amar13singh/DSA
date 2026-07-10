#include<bits/stdc++.h>
using namespace std;

class Dog {
    public:
        string breed;
        string color;

    // Default Constructor
    Dog() {
        cout << "Default Constructor Called" << endl;
    }

    // Parameterized Constructor
    Dog(string b, string c): breed(b), color(c) {
      cout << "Parameterized Constructor Called" << endl;
    }

    // Copy Constructor
    Dog(const Dog &d) {
      breed = d.breed;
      color = d.color;
      cout << "Copy Constructor Called" << endl;
    }
};

int main() {
    Dog d1; // Default Constructor Called
    Dog d2("Labrador", "Black"); // Parameterized Constructor Called
    Dog d3 = d2; // Copy Constructor Called
    return 0;
}
