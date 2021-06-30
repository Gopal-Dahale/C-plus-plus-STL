#include <iostream>
#include <cstring> // for strtok

/*
    char * strtok(char str[], const char *delims);

    * returns a token on each subsequent call
    * on the first call function should be passed with a string argument
    * on the subsequent calls, null is passed as string argument

*/

using namespace std;

int main()
{
    //cook your dish here
    char a[100] = "Happiness is a way of travel. Not a destination.";

    // delimeter is " "
    char *ptr = strtok(a, " ");
    cout << ptr << "\n";

    while (ptr)
    {
        ptr = strtok(NULL, " ");
        cout << ptr << "\n";
    }

    return 0;
}
