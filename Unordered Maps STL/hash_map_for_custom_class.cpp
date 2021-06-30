/*
    here we will use a custom class as key (student)
    Two things are needed here
    1. define hash function
    2. In the student class, overload == operator for comparison of two keys(students)

*/

#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class student
{
private:
    string firstName, LastName;
    int roll;

public:
    student(string f, string l, int r) : firstName{f}, LastName{l}, roll{r} {}

    string getFirstName() const
    {
        return this->firstName;
    }
    string getLastName() const
    {
        return this->LastName;
    }
    int getRoll() const
    {
        return this->roll;
    }

    // overloading ==
    bool operator==(const student &s) const
    {
        return s.roll == this->getRoll();
    }
};

// functor
class hash_function
{
public:
    // hash function which computes the length of their full name
    // two names with same length can collide
    size_t operator()(const student &s) const
    {
        return s.getFirstName().length() + s.getLastName().length();
    }
};

// overloading cout to print student data
ostream &operator<<(ostream &os, const student &s)
{
    cout << s.getFirstName() << " " << s.getLastName() << " " << s.getRoll();
    return os;
}

int main()
{

    // students
    student s1("Gopal", "Dahale", 32);
    student s2("Rahul", "Kumar", 20);
    student s3("Vinay", "Patil", 12);
    student s4("Kamal", "Singh", 3);
    student s5("Rahul", "Kumar", 9);
    student s6("Shubam", "Pandit", 40);

    // student and their marks
    unordered_map<student, int, hash_function> m;

    m.insert(make_pair(s1, 100));
    m.insert(make_pair(s2, 84));
    m.insert(make_pair(s3, 92));
    m.insert(make_pair(s4, 99));
    m.insert(make_pair(s5, 40));
    m.insert(make_pair(s6, 100));

    // iterate over all students
    for (auto &s : m)
        cout << s.first << " " << s.second << "\n";

    // find the marks of student s2
    cout << (*m.find(s2)).second << "\n"; // should return 84
    return 0;
}
