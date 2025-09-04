#include <iostream>
#include <stdexcept>

const int MAX_SIZE = 100;

class List
{
private:
    int arr[MAX_SIZE];
    int size;

public:
    List()
    {
        size = 0;
    }
    void create()
    {
        size = 0;
    }
    void add(int item, int index)
    {
        if (index < 0 || index > size)
        {
            throw std::out_of_range("Index out of range");
        }
        for (int i = size; i > index; --i)
        {
            arr[i] = arr[i - 1];
        }

        arr[index] = item;
        ++size;
    }
    void remove(int index)
    {
        if (index < 0 || index >= size)
        {
            throw std::out_of_range("Index out of range");
        }
        for (int i = index; i < size - 1; ++i)
        {
            arr[i] = arr[i + 1];
        }

        --size;
    }
    int listSize()
    {
        return size;
    }
    bool isEmpty()
    {
        return size == 0;
    }

    int get(int index)
    {
        if (index < 0 || index >= size)
        {
            throw std::out_of_range("Index out of range");
        }
        return arr[index];
    }
    int end()
    {
        return arr[size - 1];
    }
    int start()
    {
        return arr[0];
    }
};

int main()
{
    List myList;

    myList.add(10, 0);
    myList.add(20, 1);
    myList.add(30, 2);

    std::cout << "Size of the list: " << myList.listSize() << std::endl;
    std::cout << "Start of the list: " << myList.start() << std::endl;
    std::cout << "End of the list: " << myList.end() << std::endl;

    myList.remove(1);

    std::cout << "Size of the list after removing an element: " << myList.listSize() << std::endl;
    std::cout << "New start of the list: " << myList.start() << std::endl;

    return 0;
}
