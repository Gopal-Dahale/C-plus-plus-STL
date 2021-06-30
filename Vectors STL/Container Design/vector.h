// designing our own vector class

template <typename T>
class Vector
{
private:
    int currentSize; // current size of array
    int maxSize;     // maximum size of array , used for capacity
    T *a;            // pointer to array
public:
    Vector() : currentSize{0}, maxSize{1}
    {
        a = new T[maxSize];
    }
    void push_back(T data)
    {

        if (currentSize == maxSize)
        {
            T *ptr = a;
            maxSize = 2 * maxSize;
            a = new T[maxSize];
            for (int i = 0; i < currentSize; i++)
                a[i] = ptr[i];

            // clear the prvevious memory
            delete[] ptr;
        }
        a[currentSize] = data;
        currentSize++;
    }

    void pop_back()
    {
        currentSize--;
    }

    // const is writtern as no elements are modified inside the function and its a goog practice in such cases
    T front() const
    {
        return a[0];
    }
    T back() const
    {
        return a[currentSize - 1];
    }

    T capacity() const
    {
        return maxSize;
    }

    T size() const
    {
        return currentSize;
    }

    T at(const int index) const
    {
        return a[index];
    }
    bool empty() const
    {
        return (currentSize == 0);
    }

    // operator overloading
    // able to access elements using a[i]
    T operator[](const int index)
    {
        return a[index];
    }
};
