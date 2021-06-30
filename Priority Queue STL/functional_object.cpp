#include <iostream>
#include <string>

using namespace std;

class Functor
{
private:
    /* data */
public:
    
    void operator()(string s)
    {
        cout << "hello " << s << "\n";
    }
};

int main()
{

    Functor A;

    // using objects like function
    A("Gopal");

    return 0;
}
