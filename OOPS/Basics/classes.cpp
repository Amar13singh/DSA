#include<bits/stdc++.h>
using namespace std;

class Dog{                         
    public:                        //Access specifiers
        string breed, color;       //Data members
}; 

int main(){

//We can access these data members breed and color by (.) operator.

Dog dog;                //declaring object of class Dog
dog.breed="Pug";        //accessing public data members
dog.color="Brown";

}
