#include <iostream>
#include <vector>
using namespace std;

template<class T1 = int, class T2 = double>
class pairs {
    T1 first;
    T2 second;

public:
    pairs() : first(0), second(0) {}
    pairs(T1 a, T2 b) : first(a), second(b) {}

    T1 getFirst() const {
        return first;
    }

    T2 getSecond() const {
        return second;
    }

    // Display the pair
    void display() const {
        cout << "(" << first << ", " << second << ")";
    }
};

int main() {
    // Create instances of pairs with different template arguments
    pairs<> defaultpair(2, 3.3);
    defaultpair.display();

    pairs<char, char> custompair('3', 'h');
    custompair.display();

    pairs<char,string> custompair1('B', "hi");
    custompair1.display();

    return 0;
}
