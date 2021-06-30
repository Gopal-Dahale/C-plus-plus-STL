#include <iostream>
#include <string>
using namespace std;

void greeting(string name)
{
    cout << "hello " << name << "\n";
}

int main()
{
    //simple hello world message
    greeting("Gopal");

    // auto greet = greeting();
    // The above line will result into an error as we are calling greeting() which is of type void and hence returns nothing

    auto greet = greeting;
    /*
        The above line gets the address of greeting(). Functions are basically CPU instructions and are stored in binary file with some address.
        The below is also valid but we can omit "&" because there is an implicit conversion

        auto greet = &greeting
    */

    // we can call function using greet
    greet("Pranay");

    // what is type of auto here?

    void (*Greet)(string); // type of new variable Greet

    Greet = greeting;
    Greet("Ajay");

    /*
        This code snippet is also valid

        void (*Greet)() = greeting;
        Greet();
    */

    return 0;
}
