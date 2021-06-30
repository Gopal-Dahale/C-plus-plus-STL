// linear search implementation with template programming, forward iterator and comparator

#include <iostream>
using namespace std;

// book with name and its price
class book
{
private:
    string name;
    int price;

public:
    book(string name, int price) : name{name}, price{price} {}
    auto getName()
    {
        return this->name;
    }
    auto getPrice()
    {
        return this->price;
    }
};

// compare class
class bookCompare
{
public:
    bool operator()(book A, book B)
    {
        if (A.getName() == B.getName())
            return true;
        return false;
    }
};

// forward iterator example
// this depicts how stl search would have been implemented
template <typename ForwardIterator, typename T, typename Compare>
ForwardIterator mySearch(ForwardIterator start, ForwardIterator end, T key, Compare cmp)
{
    while (start != end)
    {
        if (cmp(*start, key))
            return start;
        ++start;
    }
    return end;
}

int main()
{
    // array of books
    book a[]{
        book("harry potter", 100),
        book("goosebumps", 90),
        book("Julius Caesar", 240),
        book("feynman", 120),
        book("Doomsday", 300),
        book("life is strange", 40),
        book("halo", 190)};
    int n = sizeof(a) / sizeof(book);

    /*
        Assume two books can have same name and may be same price (different editions)
        search for a book with the same name in the array
        For this, we will create a functor 'cmp' 
    */
    bookCompare cmp;
    auto res = mySearch(begin(a), end(a), book("feynman", 390), cmp);

    if (res == end(a))
        cout << "Element not found\n";
    else
        cout << "Element found at index " << res - a << "\n";
    return 0;
}
