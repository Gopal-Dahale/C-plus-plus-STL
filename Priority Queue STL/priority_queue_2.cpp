#include <iostream>
#include <queue>

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
    bool operator()(book &A, book &B)
    {
        return A.getPrice() < B.getPrice();
    }
};

int main()
{
    // using comparator to compare books
    priority_queue<book, vector<book>, bookCompare> pq;

    pq.emplace(book("harry potter", 100));
    pq.emplace(book("goosebumps", 90));
    pq.emplace(book("Julius Caesar", 240));
    pq.emplace(book("feynman", 120));
    pq.emplace(book("Doomsday", 300));
    pq.emplace(book("life is strange", 40));
    pq.emplace(book("halo", 190));

    // print top three most expensive books
    // faster than sorting 
    // klog(n)
    int k = 3;

    for (int i = 0; i < k; i++)
    {
        book temp = pq.top();
        cout << temp.getName() << " ," << temp.getPrice() << "\n";
        pq.pop();
    }

    return 0;
}
